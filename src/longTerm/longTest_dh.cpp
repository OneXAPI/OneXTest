#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <cmath>

#include "OneXAPI.hpp"
#include "../../include/testKeys.hpp"
#include "tgbot/tgbot.h"

using namespace std;
using namespace rapidjson;
using namespace OneXAPI::Internal::Util;

TgBot::Bot *errorTgBot = new TgBot::Bot(TELEGRAM_TOKEN);
uint64_t errorCnt = 0;

vector<OneXAPI::Internal::Exchange::SpotBase*> spotClients = {};
vector<OneXAPI::Internal::Exchange::FuturesBase*> futuresClients = {};

vector<vector<pair<string,string>>> spotGroupA = {};
vector<vector<pair<string,string>>> spotGroupB = {};
vector<vector<pair<string,string>>> spotGroupC = {};
vector<vector<pair<string,string>>> spotGroupD = {};
vector<vector<pair<string,string>>> futuresGroupA = {};
vector<vector<pair<string,string>>> futuresGroupB = {};
vector<vector<pair<string,string>>> futuresGroupC = {};
vector<vector<pair<string,string>>> futuresGroupD = {};

void sendTgMsg(string msg){
    try{
        errorTgBot->getApi().sendMessage(TELEGRAM_ID, msg);
    }
    catch(...){
        LOGGER.critical("failed to send telegram");
        LOGGER.critical(msg);
    }
}

std::string pairToRequest(const vector<pair<string,string>>& wsPair){
    std::string ret = R"({"market":[)";

    bool first = true;
    for(const auto pair : wsPair){
        if(first){
            ret.append(R"({"baseCurrency":")");
            first = false;
        }
        else{
            ret.append(R"(,{"baseCurrency":")");
        }
        ret.append(pair.first);
        ret.append(R"(","quoteCurrency":")");
        ret.append(pair.second);
        ret.append(R"("})");
    }
    ret.append(R"(]})");

    return ret;
}

void websocketTest(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        Document orderbookRespDoc, tickerRespDoc;
        std::string orderbookResp = spotClients[idx]->getSubscribingOrderbooks();
        std::string tickerResp = spotClients[idx]->getSubscribingTickers();
        parseJson(orderbookRespDoc, orderbookResp);
        parseJson(tickerRespDoc, tickerResp);

        if( !orderbookRespDoc["success"].GetBool() ||
            !tickerRespDoc["success"].GetBool()){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing success \n" + orderbookResp + "\n" + tickerResp);
        }
        else if(orderbookRespDoc["data"]["orderbooks"].Size() != spotGroupA[idx].size() ||
                tickerRespDoc["data"]["tickers"].Size() != spotGroupD[idx].size()){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing size \n" + orderbookResp + "\n" + tickerResp);
        }
        for(const auto& orderbook : orderbookRespDoc["data"]["orderbooks"].GetArray()){
            pair<string, string> pair{boost::to_upper_copy(string(orderbook["baseCurrency"].GetString())), boost::to_upper_copy(string(orderbook["quoteCurrency"].GetString()))};
            if(!IN_VECTOR(spotGroupA[idx], pair)){
                throw(tag + exchangeInfo + " Ws Error : subscribingOrderbooks find \n" + orderbookResp);
            }
        }
        for(const auto& ticker : tickerRespDoc["data"]["tickers"].GetArray()){
            pair<string, string> pair{boost::to_upper_copy(string(ticker["baseCurrency"].GetString())), boost::to_upper_copy(string(ticker["quoteCurrency"].GetString()))};
            if(!IN_VECTOR(spotGroupD[idx], pair)){
                throw(tag + exchangeInfo + " Ws Error : subscribingTickers find \n" + tickerResp);
            }
        }

        uint64_t timestampMax = 0;
        std::string maxOrderbook = "";
        /* Orderbook */
        for(auto symbol:spotGroupA[idx]){
            Document orderbookDoc;

            std::string orderbook = spotClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);

            if( !orderbookDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook);
            }
            else if(string("websocket").compare(orderbookDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + orderbook);
            }
            else if(orderbookDoc["data"]["timestamp"].GetUint64() < getCurrentMsEpoch()-1800000){
                throw(tag + exchangeInfo + " Ws Error : fetchOrderbook timestamp \n" + orderbook);
            }

            if(timestampMax < orderbookDoc["data"]["timestamp"].GetUint64()){
                timestampMax = orderbookDoc["data"]["timestamp"].GetUint64();
                maxOrderbook = orderbook;
            }
        }
        if(timestampMax < getCurrentMsEpoch()-60000){
            throw(tag + exchangeInfo + " Ws Error : fetchOrderbook timestamp Max \n" + maxOrderbook);
        }

        /* Ticker */
        for(auto symbol:spotGroupD[idx]){
            Document tickerDoc;

            std::string ticker = spotClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(tickerDoc, ticker);

            if( !tickerDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + ticker);
            }
            else if(tickerDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + ticker);
            }
            else if(string("websocket").compare(tickerDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + ticker);
            }
            else if(tickerDoc["data"]["openTime"].GetUint64() < getCurrentMsEpoch()-170000000){
                throw(tag + exchangeInfo + " Ws Error : fetchTicker openTime \n" + ticker);
            }
        }
    }

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        Document orderbookRespDoc, tickerRespDoc, marketInfoRespDoc;
        std::string orderbookResp = futuresClients[idx]->getSubscribingOrderbooks();
        std::string tickerResp = futuresClients[idx]->getSubscribingTickers();
        std::string marketInfoResp = futuresClients[idx]->getSubscribingMarketInfo();
        parseJson(orderbookRespDoc, orderbookResp);
        parseJson(tickerRespDoc, tickerResp);
        parseJson(marketInfoRespDoc, marketInfoResp);

        if( !orderbookRespDoc["success"].GetBool() ||
            !tickerRespDoc["success"].GetBool() ||
            !marketInfoRespDoc["success"].GetBool()){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing success \n" + orderbookResp + "\n" + tickerResp + "\n" + marketInfoResp);
        }
        else if(orderbookRespDoc["data"]["orderbooks"].Size() != futuresGroupA[idx].size() ||
                tickerRespDoc["data"]["tickers"].Size() != futuresGroupD[idx].size() ||
                marketInfoRespDoc["data"]["marketInfo"].Size() < futuresGroupA[idx].size()){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing size \n" + orderbookResp + "\n" + tickerResp + "\n" + marketInfoResp);
        }
        for(const auto& orderbook : orderbookRespDoc["data"]["orderbooks"].GetArray()){
            pair<string, string> pair{boost::to_upper_copy(string(orderbook["baseCurrency"].GetString())), boost::to_upper_copy(string(orderbook["quoteCurrency"].GetString()))};
            if(!IN_VECTOR(futuresGroupA[idx], pair)){
                throw(tag + exchangeInfo + " Ws Error : subscribingOrderbooks find \n" + orderbookResp);
            }
        }
        for(const auto& ticker : tickerRespDoc["data"]["tickers"].GetArray()){
            pair<string, string> pair{boost::to_upper_copy(string(ticker["baseCurrency"].GetString())), boost::to_upper_copy(string(ticker["quoteCurrency"].GetString()))};
            if(!IN_VECTOR(futuresGroupD[idx], pair)){
                throw(tag + exchangeInfo + " Ws Error : subscribingTickers find \n" + tickerResp);
            }
        }
        // for(const auto& marketInfo : marketInfoRespDoc["data"]["marketInfo"].GetArray()){
        //     pair<string, string> pair{boost::to_upper_copy(string(marketInfo["baseCurrency"].GetString())), boost::to_upper_copy(string(marketInfo["quoteCurrency"].GetString()))};
        //     if(!IN_VECTOR(futuresGroupA[idx], pair)){
        //         throw(tag + exchangeInfo + " Ws Error : subscribingMarketInfo find \n" + marketInfoResp);
        //     }
        // }

        uint64_t timestampMax = 0;
        std::string maxOrderbook = "";
        /* Orderbook & MarketInfo */
        for(auto symbol:futuresGroupA[idx]){
            Document orderbookDoc, marketInfoDoc;

            std::string orderbook = futuresClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string marketInfo = futuresClients[idx]->fetchMarketInfo(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);
            parseJson(marketInfoDoc, marketInfo);

            if( !orderbookDoc["success"].GetBool() ||
                !marketInfoDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook + "\n" + marketInfo);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() != 0 ||
                    marketInfoDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook + "\n" + marketInfo);
            }
            else if(string("websocket").compare(orderbookDoc["data"]["fetchType"].GetString()) != 0 ||
                    string("websocket").compare(marketInfoDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + orderbook + "\n" + marketInfo);
            }
            else if(orderbookDoc["data"]["timestamp"].GetUint64() < getCurrentMsEpoch()-1800000){
                throw(tag + exchangeInfo + " Ws Error : fetchOrderbook timestamp \n" + orderbook);
            }

            if(timestampMax < orderbookDoc["data"]["timestamp"].GetUint64()){
                timestampMax = orderbookDoc["data"]["timestamp"].GetUint64();
                maxOrderbook = orderbook;
            }
        }
        if(timestampMax < getCurrentMsEpoch()-60000){
            throw(tag + exchangeInfo + " Ws Error : fetchOrderbook timestamp Max \n" + maxOrderbook);
        }

        /* Ticker */
        for(auto symbol:futuresGroupD[idx]){
            Document tickerDoc;

            std::string ticker = futuresClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(tickerDoc, ticker);

            if( !tickerDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + ticker);
            }
            else if(tickerDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + ticker);
            }
            else if(string("websocket").compare(tickerDoc["data"]["fetchType"].GetString()) != 0 ){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + ticker);
            }
            else if(tickerDoc["data"]["openTime"].GetUint64() < getCurrentMsEpoch()-170000000){
                throw(tag + exchangeInfo + " Ws Error : fetchTicker openTime \n" + ticker);
            }
        }
    }
}

void restTest(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        for(auto symbol:spotGroupB[idx]){
            Document orderbookDoc, tickerDoc;

            std::string orderbook = spotClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string ticker = spotClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);
            parseJson(tickerDoc, ticker);

            if( !orderbookDoc["success"].GetBool() ||
                !tickerDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook + "\n" + ticker);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() < 1 ||
                    tickerDoc["requestedApiCount"].GetUint() < 1){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook + "\n" + ticker);
            }
            else if(string("rest").compare(orderbookDoc["data"]["fetchType"].GetString()) != 0 ||
                    string("rest").compare(tickerDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + orderbook + "\n" + ticker);
            }
            sleep(1);
        }
    }

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        for(auto symbol:futuresGroupB[idx]){
            Document orderbookDoc, tickerDoc, marketInfoDoc;

            std::string orderbook = futuresClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string ticker = futuresClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string marketInfo = futuresClients[idx]->fetchMarketInfo(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);
            parseJson(tickerDoc, ticker);
            parseJson(marketInfoDoc, marketInfo);

            if( !orderbookDoc["success"].GetBool() ||
                !tickerDoc["success"].GetBool() ||
                !marketInfoDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() < 1 ||
                    tickerDoc["requestedApiCount"].GetUint() < 1 ||
                    marketInfoDoc["requestedApiCount"].GetUint() < 1){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            else if(string("rest").compare(orderbookDoc["data"]["fetchType"].GetString()) != 0 ||
                    string("rest").compare(tickerDoc["data"]["fetchType"].GetString()) != 0 ||
                    string("rest").compare(marketInfoDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch fetchType \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            sleep(1);
        }
    }
}

void failTest(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        for(auto symbol:spotGroupC[idx]){
            Document orderbookDoc, tickerDoc;

            std::string orderbook = spotClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string ticker = spotClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);
            parseJson(tickerDoc, ticker);

            if( orderbookDoc["success"].GetBool() ||
                tickerDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook + "\n" + ticker);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() < 1 ||
                    tickerDoc["requestedApiCount"].GetUint() < 1){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook + "\n" + ticker);
            }
            else if(string("EXCHANGE_REJECT").compare(orderbookDoc["data"]["errorType"].GetString()) != 0 ||
                    string("EXCHANGE_REJECT").compare(tickerDoc["data"]["errorType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch errorType \n" + orderbook + "\n" + ticker);
            }
            sleep(1);
        }
    }

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        for(auto symbol:futuresGroupC[idx]){
            Document orderbookDoc, tickerDoc, marketInfoDoc;

            std::string orderbook = futuresClients[idx]->fetchOrderbook(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string ticker = futuresClients[idx]->fetchTicker(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");
            std::string marketInfo = futuresClients[idx]->fetchMarketInfo(R"({"baseCurrency":")" + symbol.first + R"(","quoteCurrency":")" + symbol.second + R"("})");

            parseJson(orderbookDoc, orderbook);
            parseJson(tickerDoc, ticker);
            parseJson(marketInfoDoc, marketInfo);

            if( orderbookDoc["success"].GetBool() ||
                tickerDoc["success"].GetBool() ||
                marketInfoDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : fetch success \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            else if(orderbookDoc["requestedApiCount"].GetUint() < 1 ||
                    tickerDoc["requestedApiCount"].GetUint() < 1 ||
                    marketInfoDoc["requestedApiCount"].GetUint() < 1){
                throw(tag + exchangeInfo + " Ws Error : fetch count \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            else if(string("EXCHANGE_REJECT").compare(orderbookDoc["data"]["errorType"].GetString()) != 0 ||
                    string("EXCHANGE_REJECT").compare(tickerDoc["data"]["errorType"].GetString()) != 0 ||
                    string("EXCHANGE_REJECT").compare(marketInfoDoc["data"]["errorType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetch errorType \n" + orderbook + "\n" + ticker + "\n" + marketInfo);
            }
            sleep(1);
        }
    }
}

void balanceTest(string tag){
    
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        std::string isSubscribingBalance = spotClients[idx]->isSubscribingBalance();
        std::string fetchBalance = spotClients[idx]->fetchBalance();

        Document isSubscribingBalanceDoc, fetchBalanceDoc;
        parseJson(isSubscribingBalanceDoc, isSubscribingBalance);
        parseJson(fetchBalanceDoc, fetchBalance);

        Document hasCheckDoc;
        parseJson(hasCheckDoc, spotClients[idx]->has(R"({"api":"subscribeBalance"})"));
        if(!hasCheckDoc.HasMember("data")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check failed : " + jsonToString(hasCheckDoc));
            sendTgMsg("Has Check Error");
        }
        else if(!hasCheckDoc["data"].HasMember("subscribeBalance")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check2 failed : " + jsonToString(hasCheckDoc));
            LOGGER.critical(spotClients[idx]->has());
            sendTgMsg("Has Check2 Error");
        }

        if(hasCheckDoc["data"]["subscribeBalance"].GetBool()){
            if( !isSubscribingBalanceDoc["success"].GetBool() ||
                !fetchBalanceDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : balance success \n" + isSubscribingBalance + "\n" + fetchBalance);
            }
            else if(isSubscribingBalanceDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : isSubscribingBalance requestedApiCount \n" + isSubscribingBalance);
            }
            else if(!isSubscribingBalanceDoc["data"]["isSubscribing"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : isSubscribingBalance isSubscribing \n" + isSubscribingBalance);
            }
            else if(fetchBalanceDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : fetchBalance requestedApiCount \n" + fetchBalance);
            }
            else if(string("websocket").compare(fetchBalanceDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetchBalance fetchType \n" + fetchBalance);
            }
        }
        else{
            if( !isSubscribingBalanceDoc["success"].GetBool() ||
                !fetchBalanceDoc["success"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : balance success \n" + isSubscribingBalance + "\n" + fetchBalance);
            }
            else if(isSubscribingBalanceDoc["requestedApiCount"].GetUint() != 0){
                throw(tag + exchangeInfo + " Ws Error : isSubscribingBalance requestedApiCount \n" + isSubscribingBalance);
            }
            else if(isSubscribingBalanceDoc["data"]["isSubscribing"].GetBool()){
                throw(tag + exchangeInfo + " Ws Error : isSubscribingBalance isSubscribing \n" + isSubscribingBalance);
            }
            else if(fetchBalanceDoc["requestedApiCount"].GetUint() < 1){
                throw(tag + exchangeInfo + " Ws Error : fetchBalance requestedApiCount \n" + fetchBalance);
            }
            else if(string("rest").compare(fetchBalanceDoc["data"]["fetchType"].GetString()) != 0){
                throw(tag + exchangeInfo + " Ws Error : fetchBalance fetchType \n" + fetchBalance);
            }
        }
    }
}

void subscribe(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        vector<pair<string,string>> groupAC;
        groupAC.insert(groupAC.end(), spotGroupA[idx].begin(), spotGroupA[idx].end());
        groupAC.insert(groupAC.end(), spotGroupC[idx].begin(), spotGroupC[idx].end());
        std::string request = pairToRequest(groupAC);

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc;
            std::string orderbookResp = spotClients[idx]->subscribeOrderbook(request);
            std::string tickerResp = spotClients[idx]->subscribeTicker(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["subscribed"].Size() == spotGroupA[idx].size() && 
                    orderbookRespDoc["data"]["subscribeFailed"].Size() == spotGroupC[idx].size() &&
                    tickerRespDoc["data"]["subscribed"].Size() > spotGroupA[idx].size()/2){
                    for(const auto& symbol : tickerRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        spotGroupD[idx].push_back(subscribedData);
                    }
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(orderbookResp + "\n\n" + tickerResp);
                    }
                    break;
                }
                else if(orderbookRespDoc["data"]["subscribed"].Size() > spotGroupA[idx].size() - 2){
                    spotGroupA[idx].clear();
                    for(const auto& symbol : orderbookRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        spotGroupA[idx].push_back(subscribedData);
                    }

                    vector<pair<string,string>> groupAC_new;
                    groupAC_new.insert(groupAC_new.end(), spotGroupA[idx].begin(), spotGroupA[idx].end());
                    groupAC_new.insert(groupAC_new.end(), spotGroupC[idx].begin(), spotGroupC[idx].end());
                    request = pairToRequest(groupAC_new);
                }
            }

            LOGGER.critical(tag + exchangeInfo + " subscribe failed at trial " + to_string(retry));
            LOGGER.critical(request);
            LOGGER.critical(orderbookResp + "\n\n" + tickerResp);

            if(!(retry < 5)){
                throw(tag + exchangeInfo + " subscribe not successful");
            }
            sleep(1);
        }

        Document hasCheckDoc;
        parseJson(hasCheckDoc, spotClients[idx]->has(R"({"api":"subscribeBalance"})"));
        if(!hasCheckDoc.HasMember("data")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check failed : " + jsonToString(hasCheckDoc));
            sendTgMsg("Has Check Error");
        }
        else if(!hasCheckDoc["data"].HasMember("subscribeBalance")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check2 failed : " + jsonToString(hasCheckDoc));
            LOGGER.critical(spotClients[idx]->has());
            sendTgMsg("Has Check2 Error");
        }

        if(hasCheckDoc["data"]["subscribeBalance"].GetBool()){
            for(int retry = 0; ; retry++){
                Document respDoc;
                std::string resp = spotClients[idx]->subscribeBalance("{}");
                parseJson(respDoc, resp);

                if(respDoc["success"].GetBool()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(resp);
                    }
                    break;
                }

                LOGGER.critical(tag + exchangeInfo + " subscribe balance failed at trial " + to_string(retry));
                LOGGER.critical(resp);

                if(!(retry < 5)){
                    throw(tag + exchangeInfo + " subscribe balance not successful");
                }

                sleep(1);
            }
        }
    }

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        vector<pair<string,string>> groupAC;
        groupAC.insert(groupAC.end(), futuresGroupA[idx].begin(), futuresGroupA[idx].end());
        groupAC.insert(groupAC.end(), futuresGroupC[idx].begin(), futuresGroupC[idx].end());
        std::string request = pairToRequest(groupAC);

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc, marketInfoRespDoc;
            std::string orderbookResp = futuresClients[idx]->subscribeOrderbook(request);
            std::string tickerResp = futuresClients[idx]->subscribeTicker(request);
            std::string marketInfoResp = futuresClients[idx]->subscribeMarketInfo(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);
            parseJson(marketInfoRespDoc, marketInfoResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool() && marketInfoRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["subscribed"].Size() == futuresGroupA[idx].size() && 
                    orderbookRespDoc["data"]["subscribeFailed"].Size() == futuresGroupC[idx].size() &&
                    marketInfoRespDoc["data"]["subscribed"].Size() == futuresGroupA[idx].size() && 
                    marketInfoRespDoc["data"]["subscribeFailed"].Size() == futuresGroupC[idx].size() &&
                    tickerRespDoc["data"]["subscribed"].Size() > futuresGroupA[idx].size()/2){
                    for(const auto& symbol : tickerRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        futuresGroupD[idx].push_back(subscribedData);
                    }
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(orderbookResp + "\n\n" + tickerResp + "\n\n" + marketInfoResp);
                    }
                    break;
                }
                else if(orderbookRespDoc["data"]["subscribed"].Size() > futuresGroupA[idx].size() - 2){
                    futuresGroupA[idx].clear();
                    for(const auto& symbol : orderbookRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        futuresGroupA[idx].push_back(subscribedData);
                    }

                    vector<pair<string,string>> groupAC_new;
                    groupAC_new.insert(groupAC_new.end(), futuresGroupA[idx].begin(), futuresGroupA[idx].end());
                    groupAC_new.insert(groupAC_new.end(), futuresGroupC[idx].begin(), futuresGroupC[idx].end());
                    request = pairToRequest(groupAC_new);
                }
            }

            LOGGER.critical(tag + exchangeInfo + " subscribe failed at trial " + to_string(retry));
            LOGGER.critical(request);
            LOGGER.critical(orderbookResp + "\n\n" + tickerResp + "\n\n" + marketInfoResp);

            if(!(retry < 5)){
                throw(tag + exchangeInfo + " subscribe not successful");
            }
            sleep(1);
        }

        Document hasCheckDoc;
        parseJson(hasCheckDoc, futuresClients[idx]->has(R"({"api":"subscribeBalance"})"));
        if(!hasCheckDoc.HasMember("data")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check failed : " + jsonToString(hasCheckDoc));
            sendTgMsg("Has Check Error");
        }
        else if(!hasCheckDoc["data"].HasMember("subscribeBalance")){
            LOGGER.critical(tag + exchangeInfo + " subscribe balance has Check2 failed : " + jsonToString(hasCheckDoc));
            LOGGER.critical(futuresClients[idx]->has());
            sendTgMsg("Has Check2 Error");
        }

        if(hasCheckDoc["data"]["subscribeBalance"].GetBool()){
            for(int retry = 0; ; retry++){
                Document respDoc;
                std::string resp = futuresClients[idx]->subscribeBalance("{}");
                parseJson(respDoc, resp);

                if(respDoc["success"].GetBool()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(resp);
                    }
                    break;
                }

                LOGGER.critical(tag + exchangeInfo + " subscribe balance failed at trial " + to_string(retry));
                LOGGER.critical(resp);

                if(!(retry < 5)){
                    throw(tag + exchangeInfo + " subscribe balance not successful");
                }

                sleep(1);
            }
        }
    }
}

void generateClients(){
    Document getInfoDoc;
    OneXAPI::Internal::Util::parseJson(getInfoDoc, OneXAPI::getInfo());
    
    spotClients.push_back(new OneXAPI::Upbit::Spot(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})"));
    spotClients.push_back(new OneXAPI::Binance::Spot(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})"));
    futuresClients.push_back(new OneXAPI::Binance::Futures(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})"));

    uint32_t spotCnt = 0, futuresCnt = 0;
    for(auto& data : getInfoDoc["data"]["supportedExchanges"].GetArray()){
        string instrument = data["instrument"].GetString();
        
        if(instrument.compare("Spot") == 0){
            spotCnt++;
        }
        else if(instrument.compare("Futures") == 0){
            futuresCnt++;
        }
        else{
            throw("not defined instrument : " + instrument);
        }
    }
    if(spotCnt != spotClients.size()){
        LOGGER.critical("Spot is not fully tested. supported : " + to_string(spotCnt) + "   tested : " + to_string(spotClients.size()));
    }
    if(futuresCnt != futuresClients.size()){
        LOGGER.critical("Futures is not fully tested. supported : " + to_string(futuresCnt) + "   tested : " + to_string(futuresClients.size()));
    }
}

void createGroups(){
    uint32_t groupACnt = 30;
    uint32_t groupBCnt = 2;

    for(auto client : spotClients){
        vector<pair<string, string>> groupA = {};
        vector<pair<string, string>> groupB = {};
        vector<pair<string, string>> groupC = {{"qwfW","usDt"},{"btC","fQho"}};

        Document getConfigResp;
        parseJson(getConfigResp, client->getConfig());
        string exchangeName = string(getConfigResp["data"]["exchange"].GetString());

        Document fetchMarketsDoc;
        if(exchangeName.compare("Upbit") == 0){
            OneXAPI::Internal::Util::parseJson(fetchMarketsDoc, client->fetchMarkets(R"({"quoteCurrency":"KRW"})"));
        }
        else{
            OneXAPI::Internal::Util::parseJson(fetchMarketsDoc, client->fetchMarkets());
        }

        uint32_t marketSize = fetchMarketsDoc["data"]["markets"].Size();
        if(marketSize < groupACnt + groupBCnt){
            throw("not enough markets : " + to_string(fetchMarketsDoc["data"]["markets"].Size()));
        }

        for(uint32_t i = 0; i < groupACnt + groupBCnt; i++){
            string baseCurrency = fetchMarketsDoc["data"]["markets"][i*(marketSize/(groupACnt + groupBCnt))]["baseCurrency"].GetString();
            string quoteCurrency = fetchMarketsDoc["data"]["markets"][i*(marketSize/(groupACnt + groupBCnt))]["quoteCurrency"].GetString();
            
            pair<string, string> symbol(baseCurrency, quoteCurrency);
            if(i < groupACnt){
                groupA.push_back(symbol);
            }
            else{
                groupB.push_back(symbol);
            }
        }

        spotGroupA.push_back(groupA);
        spotGroupB.push_back(groupB);
        spotGroupC.push_back(groupC);
        spotGroupD.push_back({});
    }
    for(auto client : futuresClients){
        vector<pair<string, string>> groupA = {};
        vector<pair<string, string>> groupB = {};
        vector<pair<string, string>> groupC = {{"qwfW","usDt"},{"btC","fQho"}};

        Document fetchMarketsDoc;
        OneXAPI::Internal::Util::parseJson(fetchMarketsDoc, client->fetchMarkets());

        uint32_t marketSize = fetchMarketsDoc["data"]["markets"].Size();
        if(marketSize < groupACnt + groupBCnt){
            throw("not enough markets : " + to_string(fetchMarketsDoc["data"]["markets"].Size()));
        }

        for(uint32_t i = 0; i < groupACnt + groupBCnt; i++){
            string baseCurrency = fetchMarketsDoc["data"]["markets"][i*(marketSize/(groupACnt + groupBCnt))]["baseCurrency"].GetString();
            string quoteCurrency = fetchMarketsDoc["data"]["markets"][i*(marketSize/(groupACnt + groupBCnt))]["quoteCurrency"].GetString();
            
            pair<string, string> symbol(baseCurrency, quoteCurrency);
            if(i < groupACnt){
                groupA.push_back(symbol);
            }
            else{
                groupB.push_back(symbol);
            }
        }
        
        futuresGroupA.push_back(groupA);
        futuresGroupB.push_back(groupB);
        futuresGroupC.push_back(groupC);
        futuresGroupD.push_back({});
    }
}

int main(){
    WS_LOGGER.setLevel("error");
    WS_LOGGER.setMethod("both");
    LOGGER.setLevel("error");
    LOGGER.setMethod("both");

    try{
        generateClients();
        createGroups();

        subscribe("First Subscribe ");

        uint64_t loopCnt = 0;
        while(true){
            websocketTest("Websocket Test ");
            restTest("Rest Test ");
            failTest("Fail Test ");
            balanceTest("Loop Balance ");

            if(loopCnt > 10){
                LOGGER.critical("Program is Running!");
                loopCnt = 0;
            }
            else{
                loopCnt++;
            }

            LOGGER.critical("Loop : " + to_string(loopCnt));
            sleep(60);
        }
    }
    catch(std::exception& e){
        LOGGER.critical(e.what());
        sendTgMsg(e.what());
        LOGGER.critical("Websocket BackTesting Finished");
        sendTgMsg("Websocket BackTesting Finished");
    }
    catch(std::string& e){
        LOGGER.critical(e);
        sendTgMsg(e);
        LOGGER.critical("Websocket BackTesting Finished");
        sendTgMsg("Websocket BackTesting Finished");
    }
    catch(...){
        LOGGER.critical("Unexpected Error");
        sendTgMsg("Unexpected Error");
        LOGGER.critical("Websocket BackTesting Finished");
        sendTgMsg("Websocket BackTesting Finished");
    }
}
