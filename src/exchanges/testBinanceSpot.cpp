#include "../../include/exchanges/testBinanceSpot.hpp"
#include "../../include/testDefine.hpp"
#include "../../include/testTool.hpp"
#include <iostream>

bool TC_BinanceSpot_Object_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Spot stackClient;
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot();

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceSpot_Object_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Spot stackClient("");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot("");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;
    
    TC_END
}

bool TC_BinanceSpot_Object_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Spot stackClient("{}");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot("{}");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceSpot_Object_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Spot stackClient("fnq543wb");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot("fnq543wb");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceSpot_Object_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "")";

    OneXAPI::Binance::Spot stackClient(R"({"accessKey":"Test Access Key"})");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot(R"({"accessKey":"Test Access Key"})");

    rapidjson::Document respDoc;
    std::string response = stackClient.getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult = "stack : " + response + "\n";
    std::string stackAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string stackSecretKey = respDoc["data"]["secretKey"].GetString();
    
    response = heapClient->getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult += "heap : " + response + "\n";
    std::string heapAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string heapSecretKey = respDoc["data"]["secretKey"].GetString();

    delete heapClient;
    if( stackAccessKey.compare("Test Access Key") == 0 && stackSecretKey.empty() &&
        heapAccessKey.compare("Test Access Key") == 0 && heapSecretKey.empty()){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_Object_6(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = R"(accessKey : "", secretKey : "Test Secret Key")";

    OneXAPI::Binance::Spot stackClient(R"({"secretKey":"Test Secret Key"})");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot(R"({"secretKey":"Test Secret Key"})");

    rapidjson::Document respDoc;
    std::string response = stackClient.getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult = "stack : " + response + "\n";
    std::string stackAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string stackSecretKey = respDoc["data"]["secretKey"].GetString();
    
    response = heapClient->getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult += "heap : " + response + "\n";
    std::string heapAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string heapSecretKey = respDoc["data"]["secretKey"].GetString();

    delete heapClient;
    if( stackAccessKey.empty() && stackSecretKey.compare("Test Secret Key") == 0 &&
        heapAccessKey.empty() && heapSecretKey.compare("Test Secret Key") == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_Object_7(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "Test Secret Key")";

    OneXAPI::Binance::Spot stackClient(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");
    OneXAPI::Binance::Spot* heapClient = new OneXAPI::Binance::Spot(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");

    rapidjson::Document respDoc;
    std::string response = stackClient.getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult = "stack : " + response + "\n";
    std::string stackAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string stackSecretKey = respDoc["data"]["secretKey"].GetString();
    
    response = heapClient->getConfig();
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    testData.actualResult += "heap : " + response + "\n";
    std::string heapAccessKey = respDoc["data"]["accessKey"].GetString();
    std::string heapSecretKey = respDoc["data"]["secretKey"].GetString();

    delete heapClient;
    if( stackAccessKey.compare("Test Access Key") == 0 && stackSecretKey.compare("Test Secret Key") == 0 &&
        heapAccessKey.compare("Test Access Key") == 0 && heapSecretKey.compare("Test Secret Key") == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }
    
    TC_END
}

bool TC_BinanceSpot_subscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
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

    TC_END
}