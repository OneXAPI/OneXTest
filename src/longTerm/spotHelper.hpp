#include "OneXAPI.hpp"
#include "tgbot/tgbot.h"

std::string (*safeSymbolFunc)(const std::string&, const std::string&);

enum subscribeType{
    TICKER,
    ORDERBOOK
};

struct symbolDetail{
    std::string baseCurrency;
    std::string quoteCurrency;
    std::string symbol;
};

struct Ticker{
    std::string baseCurrency;
    std::string quoteCurrency;
    std::string symbol;
    std::string fetchType;
    uint64_t openTime;
    std::string openPrice;
    std::string closePrice;
    std::string lowPrice;
    std::string highPrice;
    std::string baseVolume;
    std::string quoteVolume;
};

std::string upbitSpotSafeSymbol(const std::string& base, const std::string& quote){
    return boost::to_upper_copy(quote + "-" + base);
}

std::string binanceSpotSafeSymbol(const std::string& base, const std::string& quote){
    return boost::to_upper_copy(base + quote);
}

std::string makeRequest(const std::vector<std::pair<std::string, std::string>>& Currencys){
    rapidjson::Document doc;

    doc.SetObject();
    doc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), doc.GetAllocator());

    for(const auto& Currency : Currencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", Currency.first, doc.GetAllocator());
        objectValue.AddMember("quoteCurrency", Currency.second, doc.GetAllocator());
        doc["market"].PushBack(objectValue, doc.GetAllocator());
    }

    return OneXAPI::Internal::Util::jsonToString(doc);
}

void error(const std::string& msg)
{
    try
    {
        LOGGER.critical(msg);
    }
    catch(const std::exception& e)
    {
        std::cerr << "[error() exception] "  << e.what() << '\n';
    }
}

class spotHelper{
private:
    OneXAPI::Internal::Exchange::SpotBase& client;
    std::vector<symbolDetail> markets;

    void fetchTickers(std::vector<Ticker>& tickers,  std::string quoteCurrency = ""){
        rapidjson::Document resDoc;
        
        for(const auto& market : this->markets){

            if(!quoteCurrency.empty()){
                if(quoteCurrency.compare(market.quoteCurrency) != 0){
                    continue;
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(200));

            std::string request = "{\"baseCurrency\":\"" + market.baseCurrency + "\",\"quoteCurrency\":\"" + market.quoteCurrency + "\"}";
            OneXAPI::Internal::Util::parseJson(resDoc, this->client.fetchTicker(request));

            if(resDoc["success"].GetBool()){
                Ticker ticker;
                ticker.baseCurrency = resDoc["data"]["baseCurrency"].GetString();
                ticker.quoteCurrency = resDoc["data"]["quoteCurrency"].GetString();
                ticker.symbol = resDoc["data"]["symbol"].GetString();
                ticker.fetchType = resDoc["data"]["fetchType"].GetString();
                ticker.openTime = resDoc["data"]["openTime"].GetUint64();
                ticker.openPrice = resDoc["data"]["openPrice"].GetString();
                ticker.closePrice = resDoc["data"]["closePrice"].GetString();
                ticker.lowPrice = resDoc["data"]["lowPrice"].GetString();
                ticker.highPrice = resDoc["data"]["highPrice"].GetString();
                ticker.baseVolume = resDoc["data"]["baseVolume"].GetString();
                ticker.quoteVolume = resDoc["data"]["quoteVolume"].GetString();
                tickers.emplace_back(ticker);
            }
        }
    }

public:
    spotHelper(OneXAPI::Internal::Exchange::SpotBase& client)
        : client(client) {};
    
    std::vector<symbolDetail> fetchMarkets(){
        rapidjson::Document resDoc;

        OneXAPI::Internal::Util::parseJson(resDoc, this->client.fetchMarkets());

        this->markets.clear();

        if(resDoc["success"].GetBool()){
            for(const auto& market : resDoc["data"]["markets"].GetArray()){
                symbolDetail marketInfo;

                marketInfo.baseCurrency = market["baseCurrency"].GetString();
                marketInfo.quoteCurrency = market["quoteCurrency"].GetString();
                marketInfo.symbol = market["symbol"].GetString();
                this->markets.emplace_back(marketInfo);
            }
        }

        return this->markets;
    }

    std::vector<Ticker> getMarketTickers(std::string quoteCurrency = ""){
        std::vector<Ticker> tickers;

        if(this->markets.size() == 0){
            this->fetchMarkets();
        }

        this->fetchTickers(tickers, quoteCurrency);
        return tickers;
    }

    void subscriber(const subscribeType& type, std::vector<std::pair<std::string, std::string>>& exchangePairs,
        const std::vector<std::pair<std::string, std::string>>& Currencys, const std::string& head){

        std::string request = makeRequest(Currencys);
        std::string subscribeResponse;

        if(type == subscribeType::TICKER){
            subscribeResponse = client.subscribeTicker(request);
        }
        else if(type == subscribeType::ORDERBOOK){
            subscribeResponse = client.subscribeOrderbook(request);
        }

        LOGGER.critical(head + "subscribe\n" + request + "\n" + subscribeResponse);

        rapidjson::Document respSubDoc;
        OneXAPI::Internal::Util::parseJson(respSubDoc, subscribeResponse);

        std::vector<std::string> subscribedSymbols, failedSymbols;

        for(const auto& object : respSubDoc["data"]["subscribed"].GetArray()){
            subscribedSymbols.emplace_back(object["symbol"].GetString());
        }

        for(const auto& object : respSubDoc["data"]["subscribeFailed"].GetArray()){
            failedSymbols.emplace_back(object["symbol"].GetString());
        }

        std::string funcType, getSubscribingResponse;
        if(type == subscribeType::TICKER){
            getSubscribingResponse = client.getSubscribingTickers();
            funcType = "tickers";
        }
        else if(type == subscribeType::ORDERBOOK){
            getSubscribingResponse = client.getSubscribingOrderbooks();
            funcType = "orderbooks";
        }

        OneXAPI::Internal::Util::parseJson(respSubDoc, getSubscribingResponse);

        for(const auto& symbol : subscribedSymbols){
            bool isFound = false;
            
            for(const auto& object : respSubDoc["data"][funcType].GetArray()){
                if(!IN_VECTOR(exchangePairs, (std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString())))){
                    exchangePairs.emplace_back(std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString()));
                }

                if(symbol.compare(object["symbol"].GetString()) == 0){
                    isFound = true;
                }
            }

            if(!isFound){
                error(head + " subscribed symbol not found [" + symbol + "]\n" + getSubscribingResponse);
            }
        }
        
        for(const auto& symbol : failedSymbols){
            bool isFound = false;
            
            for(const auto& object : respSubDoc["data"][funcType].GetArray()){
                if(IN_VECTOR(exchangePairs, (std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString())))){
                    exchangePairs.erase(
                        std::remove(exchangePairs.begin(), exchangePairs.end(), 
                            std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString())), 
                        exchangePairs.end()
                    );
                }

                if(symbol.compare(object["symbol"].GetString()) == 0){
                    isFound = true;
                }
            }

            if(isFound){
                error(head + " subscribefailed symbol found [" + symbol + "]\n" + getSubscribingResponse);
            }
        }
    }

    void unsubscriber(const subscribeType& type, std::vector<std::pair<std::string, std::string>>& exchangePairs,
        const std::vector<std::pair<std::string, std::string>>& Currencys, const std::string& head){

        // add missingSymbol
        rapidjson::Document respSubDoc;
        std::vector<std::pair<std::string, std::string>> missingPairs, subscribedPairs;
        std::string funcType, getSubscribingResponse;

        if(type == subscribeType::TICKER){
            getSubscribingResponse = client.getSubscribingTickers();
            funcType = "tickers";
        }
        else if(type == subscribeType::ORDERBOOK){
            getSubscribingResponse = client.getSubscribingOrderbooks();
            funcType = "orderbooks";
        }

        OneXAPI::Internal::Util::parseJson(respSubDoc, getSubscribingResponse);

        for(const auto& object : respSubDoc["data"][funcType].GetArray()){
            std::pair<std::string, std::string> resPair = std::pair<std::string, std::string>(
                object["baseCurrency"].GetString(), object["quoteCurrency"].GetString());
            
            subscribedPairs.emplace_back(resPair);
        }

        for(const auto& Currency : Currencys){ 
            auto resPair = std::pair<std::string, std::string>(boost::to_upper_copy(Currency.first), boost::to_upper_copy(Currency.second));
            if(!IN_VECTOR(subscribedPairs, resPair)){
                missingPairs.emplace_back(resPair);
            }
        }

        // start unsubscribe logic
        std::string request = makeRequest(Currencys);
        std::string unsubscribeResponse;

        if(type == subscribeType::TICKER){
            unsubscribeResponse = client.unsubscribeTicker(request);
        }
        else if(type == subscribeType::ORDERBOOK){
            unsubscribeResponse = client.unsubscribeOrderbook(request);
        }

        LOGGER.critical(head + "unsubscribe\n" + request + "\n" + unsubscribeResponse);

        OneXAPI::Internal::Util::parseJson(respSubDoc, unsubscribeResponse);

        std::vector<std::string> unsubscribedSymbols;
        std::vector<symbolDetail> failedSymbols;

        bool isSuccess = false;

        isSuccess = respSubDoc["success"].GetBool();
        
        if(isSuccess){
            for(const auto& object : respSubDoc["data"]["unsubscribed"].GetArray()){
                unsubscribedSymbols.emplace_back(object["symbol"].GetString());
            }

            for(const auto& object : respSubDoc["data"]["unsubscribeFailed"].GetArray()){
                symbolDetail detail;
                detail.baseCurrency = object["baseCurrency"].GetString();
                detail.quoteCurrency = object["quoteCurrency"].GetString();
                detail.symbol = object["symbol"].GetString();
                failedSymbols.emplace_back(detail);
            }
        }
        else{
            if(type == subscribeType::TICKER){
                getSubscribingResponse = client.getSubscribingTickers();
                funcType = "tickers";
            }
            else if(type == subscribeType::ORDERBOOK){
                getSubscribingResponse = client.getSubscribingOrderbooks();
                funcType = "orderbooks";
            }

            OneXAPI::Internal::Util::parseJson(respSubDoc, getSubscribingResponse);

            for(const auto& object : respSubDoc["data"][funcType].GetArray()){
                std::string baseCurrency = object["baseCurrency"].GetString();
                std::string quoteCurrency = object["quoteCurrency"].GetString();
                std::pair<std::string, std::string> tmpPair = std::pair<std::string, std::string>(baseCurrency, quoteCurrency);

                if(IN_VECTOR(subscribedPairs, tmpPair)){
                    symbolDetail detail;
                    detail.baseCurrency = object["baseCurrency"].GetString();
                    detail.quoteCurrency = object["quoteCurrency"].GetString();
                    detail.symbol = object["symbol"].GetString();
                    failedSymbols.emplace_back(detail);
                }
                else{
                    unsubscribedSymbols.emplace_back(object["symbol"].GetString());
                }
            }
        }

        if(type == subscribeType::TICKER){
            getSubscribingResponse = client.getSubscribingTickers();
            funcType = "tickers";
        }
        else if(type == subscribeType::ORDERBOOK){
            getSubscribingResponse = client.getSubscribingOrderbooks();
            funcType = "orderbooks";
        }

        OneXAPI::Internal::Util::parseJson(respSubDoc, getSubscribingResponse);

        for(const auto& symbol : unsubscribedSymbols){
            bool isFound = false;
            
            for(const auto& object : respSubDoc["data"][funcType].GetArray()){
                if(IN_VECTOR(exchangePairs, (std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString())))){
                    exchangePairs.erase(
                        std::remove(exchangePairs.begin(), exchangePairs.end(), 
                            std::pair<std::string, std::string>(object["baseCurrency"].GetString(), object["quoteCurrency"].GetString())), 
                        exchangePairs.end()
                    );
                }

                if(symbol.compare(object["symbol"].GetString()) == 0){
                    isFound = true;
                }
            }

            if(isFound){
                error(head + " unsubscribed symbol found [" + symbol + "]\n" + getSubscribingResponse);
            }
        }
        
        for(const auto& symbol : failedSymbols){
            bool isFound = false;

            for(const auto& object : respSubDoc["data"][funcType].GetArray()){
                if(symbol.symbol.compare(object["symbol"].GetString()) == 0){
                    isFound = true;
                }
            }

            if(!isFound){
                if(!IN_VECTOR(missingPairs, (std::pair<std::string, std::string>(symbol.baseCurrency, symbol.quoteCurrency)))){
                    error(head + " unsubscribeFailed symbol not found [" + symbol.symbol + "]\n" + getSubscribingResponse);
                }
            }
        }
    }

    void checker(std::string (*safeSymbolFunc)(const std::string&, const std::string&),
        const std::vector<std::pair<std::string, std::string>>& tickerPairs, const std::vector<std::pair<std::string, std::string>>& orderbookPairs, 
        const std::string& head, const std::string& middle){

        std::map<std::string, uint64_t> orderbookTime;

        for(const auto& tickerPair : tickerPairs){
            std::string request = R"({"baseCurrency":")" + tickerPair.first + R"(","quoteCurrency":")" + tickerPair.second + R"("})";
            std::string tickerInfo = client.fetchTicker(request);

            rapidjson::Document tickerDoc;
            OneXAPI::Internal::Util::parseJson(tickerDoc, tickerInfo);

            if(!tickerDoc["success"].GetBool()){
                continue;
            }

            std::string symbol = safeSymbolFunc(tickerPair.first, tickerPair.second);

            std::string tickerFetchType = tickerDoc["data"]["fetchType"].GetString();

            if(tickerFetchType.compare("rest") == 0){
                error(head + " " + middle + " " + symbol + " ticker fetchType is rest");
            }
        }

        for(const auto& orderbookPair : orderbookPairs){
            std::string request = R"({"baseCurrency":")" + orderbookPair.first + R"(","quoteCurrency":")" + orderbookPair.second + R"("})";
            std::string orderbookInfo = client.fetchOrderbook(request);

            rapidjson::Document orderbookDoc;
            OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbookInfo);

            if(!orderbookDoc["success"].GetBool()){
                continue;
            }

            std::string symbol = safeSymbolFunc(orderbookPair.first, orderbookPair.second);

            std::string orderbookFetchType = orderbookDoc["data"]["fetchType"].GetString();

            if(orderbookFetchType.compare("rest") == 0){
                error(head + " " + middle + " " + symbol + " orderbook fetchType is rest");
            }

            if(orderbookDoc["success"].GetBool()){
                orderbookTime[symbol] = orderbookDoc["data"]["timestamp"].GetUint64();
            }
            else{
                error(head + " " + middle + " " + symbol + " fetchOrderbook Fail");
            }
        }

        uint64_t now = OneXAPI::Internal::Util::getCurrentMsEpoch();
        std::string resultMsg = head + " ";

        for(const auto& orderbook : orderbookTime){
            std::string orderbookMsg = orderbook.first + ": " + std::to_string(now - orderbook.second) + ", ";

            uint64_t timeout = 3600000;

            if(head.compare("upbitSpot") == 0 && middle.compare("Short") == 0){
                continue;
            }

            if(head.compare("binanceSpot") == 0){
                timeout = 5000;
            }

            if(now - orderbook.second > timeout && now > orderbook.second){
                error(head + " " +  middle + " " + orderbook.first + " delayed : " + std::to_string(now - orderbook.second) +
                ", now : " + std::to_string(now) + ", recvTime : " + std::to_string(orderbook.second));
            }
            LOGGER.info(orderbookMsg);
        }
    }
};