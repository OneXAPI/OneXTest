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
        else if(orderbookRespDoc["data"]["orderbooks"].Size() < 1 ||
                tickerRespDoc["data"]["tickers"].Size() < 1){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing size \n" + orderbookResp + "\n" + tickerResp);
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
        else if(orderbookRespDoc["data"]["orderbooks"].Size() < 1 ||
                tickerRespDoc["data"]["tickers"].Size() < 1 ||
                marketInfoRespDoc["data"]["marketInfo"].Size() < 1){
            throw(tag + exchangeInfo + " Ws Error : getSubscribing size \n" + orderbookResp + "\n" + tickerResp + "\n" + marketInfoResp);
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

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        std::string isSubscribingBalance = futuresClients[idx]->isSubscribingBalance();
        std::string fetchBalance = futuresClients[idx]->fetchBalance();

        Document isSubscribingBalanceDoc, fetchBalanceDoc;
        parseJson(isSubscribingBalanceDoc, isSubscribingBalance);
        parseJson(fetchBalanceDoc, fetchBalance);

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

void subscribe(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        vector<pair<string,string>> groupABC;
        groupABC.insert(groupABC.end(), spotGroupA[idx].begin(), spotGroupA[idx].end());
        groupABC.insert(groupABC.end(), spotGroupB[idx].begin(), spotGroupB[idx].end());
        groupABC.insert(groupABC.end(), spotGroupC[idx].begin(), spotGroupC[idx].end());
        std::string request = pairToRequest(groupABC);

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc;
            std::string orderbookResp = spotClients[idx]->subscribeOrderbook(request);
            std::string tickerResp = spotClients[idx]->subscribeTicker(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["subscribed"].Size() == spotGroupA[idx].size() + spotGroupB[idx].size() && 
                    orderbookRespDoc["data"]["subscribeFailed"].Size() == spotGroupC[idx].size() &&
                    tickerRespDoc["data"]["subscribed"].Size() > (spotGroupA[idx].size() + spotGroupB[idx].size())/2){
                    spotGroupD[idx].clear();
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
                else if(orderbookRespDoc["data"]["subscribed"].Size() > (spotGroupA[idx].size() + spotGroupB[idx].size()) - 2){
                    spotGroupA[idx].clear();
                    for(const auto& symbol : orderbookRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        spotGroupA[idx].push_back(subscribedData);
                    }

                    vector<pair<string,string>> groupABC_new;
                    groupABC_new.insert(groupABC_new.end(), spotGroupA[idx].begin(), spotGroupA[idx].end());
                    groupABC_new.insert(groupABC_new.end(), spotGroupB[idx].begin(), spotGroupB[idx].end());
                    groupABC_new.insert(groupABC_new.end(), spotGroupC[idx].begin(), spotGroupC[idx].end());
                    request = pairToRequest(groupABC_new);
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

        vector<pair<string,string>> groupABC;
        groupABC.insert(groupABC.end(), futuresGroupA[idx].begin(), futuresGroupA[idx].end());
        groupABC.insert(groupABC.end(), futuresGroupB[idx].begin(), futuresGroupB[idx].end());
        groupABC.insert(groupABC.end(), futuresGroupC[idx].begin(), futuresGroupC[idx].end());
        std::string request = pairToRequest(groupABC);

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc, marketInfoRespDoc;
            std::string orderbookResp = futuresClients[idx]->subscribeOrderbook(request);
            std::string tickerResp = futuresClients[idx]->subscribeTicker(request);
            std::string marketInfoResp = futuresClients[idx]->subscribeMarketInfo(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);
            parseJson(marketInfoRespDoc, marketInfoResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool() && marketInfoRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["subscribed"].Size() == (futuresGroupA[idx].size() + futuresGroupB[idx].size()) && 
                    orderbookRespDoc["data"]["subscribeFailed"].Size() == futuresGroupC[idx].size() &&
                    marketInfoRespDoc["data"]["subscribed"].Size() == (futuresGroupA[idx].size() + futuresGroupB[idx].size()) && 
                    marketInfoRespDoc["data"]["subscribeFailed"].Size() == futuresGroupC[idx].size() &&
                    tickerRespDoc["data"]["subscribed"].Size() > (futuresGroupA[idx].size() + futuresGroupB[idx].size())/2){
                    futuresGroupD[idx].clear();
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
                else if(orderbookRespDoc["data"]["subscribed"].Size() > (futuresGroupA[idx].size() + futuresGroupB[idx].size()) - 2){
                    futuresGroupA[idx].clear();
                    for(const auto& symbol : orderbookRespDoc["data"]["subscribed"].GetArray()){
                        pair<string, string> subscribedData(symbol["baseCurrency"].GetString(),symbol["quoteCurrency"].GetString());
                        futuresGroupA[idx].push_back(subscribedData);
                    }

                    vector<pair<string,string>> groupABC_new;
                    groupABC_new.insert(groupABC_new.end(), futuresGroupA[idx].begin(), futuresGroupA[idx].end());
                    groupABC_new.insert(groupABC_new.end(), futuresGroupB[idx].begin(), futuresGroupB[idx].end());
                    groupABC_new.insert(groupABC_new.end(), futuresGroupC[idx].begin(), futuresGroupC[idx].end());
                    request = pairToRequest(groupABC_new);
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

void unsubscribe(string tag){
    for(uint32_t idx = 0; idx < spotClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, spotClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        std::string request = pairToRequest(spotGroupB[idx]);

        for(auto symbol : spotGroupB[idx]){
            spotGroupA[idx].erase(remove(spotGroupA[idx].begin(), spotGroupA[idx].end(), symbol), spotGroupA[idx].end());
            spotGroupD[idx].erase(remove(spotGroupD[idx].begin(), spotGroupD[idx].end(), symbol), spotGroupD[idx].end());
        }

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc;
            std::string orderbookResp = spotClients[idx]->unsubscribeOrderbook(request);
            std::string tickerResp = spotClients[idx]->unsubscribeTicker(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["unsubscribed"].Size() + orderbookRespDoc["data"]["unsubscribeFailed"].Size() == spotGroupB[idx].size() &&
                    tickerRespDoc["data"]["unsubscribed"].Size() + tickerRespDoc["data"]["unsubscribeFailed"].Size() == spotGroupB[idx].size()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(orderbookResp + "\n\n" + tickerResp);
                    }
                    break;
                }
            }

            LOGGER.critical(tag + exchangeInfo + " unsubscribe failed at trial " + to_string(retry));
            LOGGER.critical(request);
            LOGGER.critical(orderbookResp + "\n\n" + tickerResp);

            if(!(retry < 5)){
                throw(tag + exchangeInfo + " unsubscribe not successful");
            }
            sleep(1);
        }

        Document hasCheckDoc;
        parseJson(hasCheckDoc, spotClients[idx]->has(R"({"api":"unsubscribeBalance"})"));
        if(!hasCheckDoc.HasMember("data")){
            LOGGER.critical(tag + exchangeInfo + " unsubscribe balance has Check failed : " + jsonToString(hasCheckDoc));
            sendTgMsg("Has Check Error");
        }
        else if(!hasCheckDoc["data"].HasMember("unsubscribeBalance")){
            LOGGER.critical(tag + exchangeInfo + " unsubscribe balance has Check2 failed : " + jsonToString(hasCheckDoc));
            LOGGER.critical(spotClients[idx]->has());
            sendTgMsg("Has Check2 Error");
        }

        if(hasCheckDoc["data"]["unsubscribeBalance"].GetBool()){
            for(int retry = 0; ; retry++){
                Document respDoc;
                std::string resp = spotClients[idx]->unsubscribeBalance("{}");
                parseJson(respDoc, resp);

                if(respDoc["success"].GetBool()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(resp);
                    }
                    break;
                }

                LOGGER.critical(tag + exchangeInfo + " unsubscribe balance failed at trial " + to_string(retry));
                LOGGER.critical(resp);

                if(!(retry < 5)){
                    throw(tag + exchangeInfo + " unsubscribe balance not successful");
                }

                sleep(1);
            }
        }
    }

    for(uint32_t idx = 0; idx < futuresClients.size(); idx++){
        Document getConfigResp;
        parseJson(getConfigResp, futuresClients[idx]->getConfig());
        string exchangeInfo = string(getConfigResp["data"]["exchange"].GetString()) + string(getConfigResp["data"]["instrument"].GetString());

        std::string request = pairToRequest(futuresGroupB[idx]);

        for(auto symbol : futuresGroupB[idx]){
            futuresGroupA[idx].erase(remove(futuresGroupA[idx].begin(), futuresGroupA[idx].end(), symbol), futuresGroupA[idx].end());
            futuresGroupD[idx].erase(remove(futuresGroupD[idx].begin(), futuresGroupD[idx].end(), symbol), futuresGroupD[idx].end());
        }

        for(int retry = 0; ; retry++){
            Document orderbookRespDoc, tickerRespDoc, marketInfoRespDoc;
            std::string orderbookResp = futuresClients[idx]->unsubscribeOrderbook(request);
            std::string tickerResp = futuresClients[idx]->unsubscribeTicker(request);
            std::string marketInfoResp = futuresClients[idx]->unsubscribeMarketInfo(request);
            parseJson(orderbookRespDoc, orderbookResp);
            parseJson(tickerRespDoc, tickerResp);
            parseJson(marketInfoRespDoc, marketInfoResp);

            if(orderbookRespDoc["success"].GetBool() && tickerRespDoc["success"].GetBool() && marketInfoRespDoc["success"].GetBool()){
                if( orderbookRespDoc["data"]["unsubscribed"].Size() + orderbookRespDoc["data"]["unsubscribeFailed"].Size() == futuresGroupB[idx].size() &&
                    tickerRespDoc["data"]["unsubscribed"].Size() + tickerRespDoc["data"]["unsubscribeFailed"].Size() == futuresGroupB[idx].size() &&
                    marketInfoRespDoc["data"]["unsubscribed"].Size() + marketInfoRespDoc["data"]["unsubscribeFailed"].Size() == futuresGroupB[idx].size()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(orderbookResp + "\n\n" + tickerResp + "\n\n" + marketInfoResp);
                    }
                    break;
                }
            }

            LOGGER.critical(tag + exchangeInfo + " unsubscribe failed at trial " + to_string(retry));
            LOGGER.critical(request);
            LOGGER.critical(orderbookResp + "\n\n" + tickerResp + "\n\n" + marketInfoResp);

            if(!(retry < 5)){
                throw(tag + exchangeInfo + " unsubscribe not successful");
            }
            sleep(1);
        }

        Document hasCheckDoc;
        parseJson(hasCheckDoc, futuresClients[idx]->has(R"({"api":"unsubscribeBalance"})"));
        if(!hasCheckDoc.HasMember("data")){
            LOGGER.critical(tag + exchangeInfo + " unsubscribe balance has Check failed : " + jsonToString(hasCheckDoc));
            sendTgMsg("Has Check Error");
        }
        else if(!hasCheckDoc["data"].HasMember("unsubscribeBalance")){
            LOGGER.critical(tag + exchangeInfo + " unsubscribe balance has Check2 failed : " + jsonToString(hasCheckDoc));
            LOGGER.critical(futuresClients[idx]->has());
            sendTgMsg("Has Check2 Error");
        }

        if(hasCheckDoc["data"]["unsubscribeBalance"].GetBool()){
            for(int retry = 0; ; retry++){
                Document respDoc;
                std::string resp = futuresClients[idx]->unsubscribeBalance("{}");
                parseJson(respDoc, resp);

                if(respDoc["success"].GetBool()){
                    if(retry > 0){
                        LOGGER.critical("Success Log : ");
                        LOGGER.critical(resp);
                    }
                    break;
                }

                LOGGER.critical(tag + exchangeInfo + " unsubscribe balance failed at trial " + to_string(retry));
                LOGGER.critical(resp);

                if(!(retry < 5)){
                    throw(tag + exchangeInfo + " unsubscribe balance not successful");
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

void deleteClients(){
    while(spotClients.size() > 0){
        auto client = spotClients.back();

        Document getConfigResp;
        parseJson(getConfigResp, client->getConfig());
        string exchangeName = string(getConfigResp["data"]["exchange"].GetString());

        if(exchangeName.compare("Upbit") == 0){
            delete(dynamic_cast<OneXAPI::Upbit::Spot*>(client));
        }
        else if(exchangeName.compare("Binance") == 0){
            delete(dynamic_cast<OneXAPI::Binance::Spot*>(client));
        }
        else{
            throw("Cannot find exchange spot name : " + exchangeName);
        }        
        client = nullptr;
        spotClients.pop_back();
    }
    while(futuresClients.size() > 0){
        auto client = futuresClients.back();

        Document getConfigResp;
        parseJson(getConfigResp, client->getConfig());
        string exchangeName = string(getConfigResp["data"]["exchange"].GetString());

        if(exchangeName.compare("Binance") == 0){
            delete(dynamic_cast<OneXAPI::Binance::Futures*>(client));
        }
        else{
            throw("Cannot find exchange futures name : " + exchangeName);
        }
        client = nullptr;
        futuresClients.pop_back();
    }
}

void createGroups(){
    uint32_t groupACnt = 30;
    uint32_t groupBCnt = 10;

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
        deleteClients();

        uint64_t loopCnt = 0;
        while(true){
            generateClients();
            subscribe("Subscribe First : ");
            subscribe("Subscribe Second : ");
            unsubscribe("Unsubscribe First : ");
            unsubscribe("Unsubscribe Second : ");

            websocketTest("Websocket Test ");
            restTest("Rest Test ");
            failTest("Fail Test ");
            balanceTest("Loop Balance ");
            deleteClients();

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
        LOGGER.critical("Websocket Short  BackTesting Finished");
        sendTgMsg("Websocket Short BackTesting Finished");
    }
    catch(std::string& e){
        LOGGER.critical(e);
        sendTgMsg(e);
        LOGGER.critical("Websocket Short BackTesting Finished");
        sendTgMsg("Websocket Short BackTesting Finished");
    }
    catch(...){
        LOGGER.critical("Unexpected Error");
        sendTgMsg("Unexpected Error");
        LOGGER.critical("Websocket Short BackTesting Finished");
        sendTgMsg("Websocket Short BackTesting Finished");
    }
}
