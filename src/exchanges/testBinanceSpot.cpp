#include "../../include/exchanges/testBinanceSpot.hpp"
#include "../../include/testTool.hpp"
#include <iostream>


#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

bool TC_BinanceSpot_subscribeTicker_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

        OneXAPI::Binance::Spot client;
        std::string input = "";
        std::string response = client.subscribeTicker(input);

        testData.actualResult = response;

        if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
            return true;
        }
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_BinanceSpot_subscribeTicker_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

        OneXAPI::Binance::Spot client;
        std::string input = "{}";
        std::string response = client.subscribeTicker(input);

        testData.actualResult = response;

        if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
            return true;
        }
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_BinanceSpot_subscribeTicker_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

        OneXAPI::Binance::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.subscribeTicker(input);

        testData.actualResult = response;

        if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
            return true;
        }
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_BinanceSpot_subscribeTicker_4(testDataType& testData){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
        testData.expectedResult = R"({"success":true,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

        OneXAPI::Binance::Spot client;
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeTicker(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
        testData.expectedResult = R"({"success":true,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})";
        response = client.getSubscribingTickers();

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
        testData.expectedResult = R"({"success":true,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}],"subscribeFailed":[]}})";
        input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
        response = client.subscribeTicker(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
        testData.expectedResult = R"({"success":true,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}]}})";
        response = client.getSubscribingTickers();

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        return true;
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}