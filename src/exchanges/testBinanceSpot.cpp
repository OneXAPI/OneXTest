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

static const std::string getConfigExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"exchange":"Binance","instrument":"Spot","accessKey":"","secretKey":"","restEndpoint":"https://api.binance.com","publicWebsocketEndpoint":"wss://stream.binance.com:9443/stream","privateWebsocketEndpoint":"wss://stream.binance.com:9443/ws","restRequestTimeout":5000,"websocketConnectTimeout":5000,"websocketIdleTimeout":5000}})";

bool TC_BinanceSpot_getConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Spot client;

    std::string response = client.getConfig();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getConfig(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "trashData123@@!%";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_setConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Binance::Spot client;

    std::string response = client.setConfig("");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_setConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0}})";

    OneXAPI::Binance::Spot client;

    std::string response = client.setConfig("{}");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_setConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE_TYPE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;
    std::string input, response;

    input = R"({"accessKey":1.1354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"secretKey":11354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"restEndpoint":null})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"publicWebsocketEndpoint":true})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"privateWebsocketEndpoint":{}})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"restRequestTimeout":1.1354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"websocketConnectTimeout":"ffaew"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }
    input = R"({"websocketIdleTimeout":false})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE")){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_setConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;
    std::string input, response;

    input = R"({"restEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    input = R"({"publicWebsocketEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    input = R"({"privateWebsocketEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_setConfig_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"requestedKey":"requestedValue"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;
    std::string input, response;

    std::vector<std::pair<std::string,std::string>> testList = {
        {"accessKey",R"("test access key")"},
        {"secretKey",R"("test secret key")"},
        {"restEndpoint",R"("https://api3.binance.com")"},
        {"publicWebsocketEndpoint",R"("wss://testnet.binance.vision/stream")"},
        {"privateWebsocketEndpoint",R"("wss://testnet.binance.vision/ws")"},
        {"restRequestTimeout","1378331"},
        {"websocketConnectTimeout","3787123"},
        {"websocketIdleTimeout","8941313531215"}
    };
    for(const auto& testItem : testList){
        input = R"({")" + testItem.first + R"(":)" + testItem.second + R"(})";
        response = client.setConfig(input);
        testData.actualResult.append(response + "\n");

        rapidjson::Document respDoc;
        OneXAPI::Internal::Util::parseJson(respDoc, response);
        if(!respDoc["success"].GetBool()){
            return false;
        }
        else if(!respDoc["data"].HasMember(testItem.first)){
            return false;
        }
        else if(respDoc["data"][testItem.first].IsString()){
            std::string answer = boost::replace_all_copy(testItem.second, "\"", "");
            if(answer.compare(respDoc["data"][testItem.first].GetString()) != 0){
                return false;
            }
        }
        else if(respDoc["data"][testItem.first].IsUint64()){
            if(testItem.second.compare(std::to_string(respDoc["data"][testItem.first].GetUint64())) != 0){
                return false;
            }                
        }
        else{
            return false;
        }
    }

    response = client.getConfig();
    testData.actualResult.append("getConfig result : \n" + response);
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    for(const auto& testItem : testList){
        if(!respDoc["success"].GetBool()){
            return false;
        }
        else if(!respDoc["data"].HasMember(testItem.first)){
            return false;
        }
        else if(respDoc["data"][testItem.first].IsString()){
            std::string answer = boost::replace_all_copy(testItem.second, "\"", "");
            if(answer.compare(respDoc["data"][testItem.first].GetString()) != 0){
                return false;
            }
        }
        else if(respDoc["data"][testItem.first].IsUint64()){
            if(testItem.second.compare(std::to_string(respDoc["data"][testItem.first].GetUint64())) != 0){
                return false;
            }                
        }
        else{
            return false;
        }
    }

    return true;

    TC_END
}

static const std::string getEndpointCandidatesExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"restEndpoints":["https://api.binance.com","https://api1.binance.com","https://api2.binance.com","https://api3.binance.com","https://testnet.binance.vision/api"],"publicWebsocketEndpoints":["wss://stream.binance.com:9443/stream","wss://testnet.binance.vision/stream"],"privateWebsocketEndpoints":["wss://stream.binance.com:9443/ws","wss://testnet.binance.vision/ws"]}})";

bool TC_BinanceSpot_getEndpointCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;

    std::string response = client.getEndpointCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getEndpointCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getEndpointCandidates_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getEndpointCandidates_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "uNPaRsib1eM5g";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static std::map<std::string, bool> hasExpectedResult = {
    /* General */
    {"getConfig", true},
    {"setConfig", true},
    {"getEndpointCandidates", true},
    {"has", true},
    /* Wallet */
    {"getWithdrawRoundingRule", true},
    {"setWithdrawRoundingRule", true},
    {"withdraw", true},
    {"fetchAllCurrencies", true},
    {"fetchBalance", true},
    {"fetchWalletStatus", true},
    {"fetchWithdrawHistory", true},
    {"fetchDepositHistory", true},
    {"fetchDepositAddress", true},
    {"isDepositCompleted", true},
    {"subscribeBalance", true},
    {"unsubscribeBalance", true},
    {"isSubscribingBalance", true},
    /* Trade */
    {"getOrderRoundingRule", true},
    {"setOrderRoundingRule", true},
    {"orderLimitBuy", true},
    {"orderLimitSell", true},
    {"orderMarketBuy", true},
    {"orderMarketSell", true},
    {"orderCancel", true},
    {"fetchTradingFee", true},
    {"fetchOrderInfo", true},
    {"fetchOpenOrders", true},
    /* Markets */
    {"getCandleIntervalCandidates", true},
    {"fetchMarkets", true},
    {"fetchTicker", true},
    {"fetchOrderbook", true},
    {"fetchCandleHistory", true},
    {"getSubscribingTickers", true},
    {"getSubscribingOrderbooks", true},
    {"subscribeTicker", true},
    {"unsubscribeTicker", true},
    {"subscribeOrderbook", true},
    {"unsubscribeOrderbook", true},
    {"unsubscribeTicker", true},
};

bool TC_BinanceSpot_has_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_has_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    rapidjson::Document expectedResult;
    expectedResult.SetObject();
    expectedResult.AddMember("success", true, expectedResult.GetAllocator());
    expectedResult.AddMember("data", rapidjson::Value(rapidjson::kObjectType), expectedResult.GetAllocator());
    expectedResult["data"].AddMember("requestedApiCount", 0, expectedResult.GetAllocator());
    for(auto api : hasExpectedResult){
        rapidjson::Value apiName(api.first, expectedResult.GetAllocator());
        expectedResult["data"].AddMember(apiName, api.second, expectedResult.GetAllocator());
    }
    testData.expectedResult = OneXAPI::Internal::Util::jsonToString(expectedResult);

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_has_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Binance::Spot client;
    std::string input = "el12nlgv@!";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_has_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    testData.expectedResult.clear();
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;

    for(auto api : hasExpectedResult){
        testData.expectedResult += R"({"success":true,"data":{"requestedApiCount":0,")" + api.first + R"(":)" + (api.second?"true":"false") + R"(}})" + "\n";
        std::string input = R"({"api":")" + api.first + R"("})";
        std::string response = client.has(input);

        testData.actualResult += response + "\n";
    }

    if((testData.actualResult).compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_has_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"api":"notExistApi"})";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    return true;

    TC_END
}

static const std::string getWithdrawRoundingRuleExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"roundingRule":"round"}})";

bool TC_BinanceSpot_getWithdrawRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getWithdrawRoundingRule";
    testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string response = client.getWithdrawRoundingRule();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getWithdrawRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getWithdrawRoundingRule";
    testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = R"({})";
    std::string response = client.getWithdrawRoundingRule(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_setWithdrawRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setWithdrawRoundingRule";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"roundingRule":"wrongData"})";
    std::string response = client.setWithdrawRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_setWithdrawRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setWithdrawRoundingRule";
    testData.expectedResult.clear();
    testData.actualResult.clear();
    std::string getCheckStr = "";
    OneXAPI::Binance::Spot client;
    std::vector<std::string> testList = {
        "ceil",
        "floor",
        "round"
    };
    for(const auto& testItem : testList){
        testData.expectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"roundingRule":")" + testItem + R"("}})" + "\n");
        std::string input = R"({"roundingRule":")" + testItem + R"("})";
        std::string response = client.setWithdrawRoundingRule(input);
        
        testData.actualResult.append(response + "\n");
        getCheckStr.append(client.getWithdrawRoundingRule() + "\n");
    }
    if(testData.actualResult.compare(testData.expectedResult) == 0 && getCheckStr.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_withdraw_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().withdraw";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    std::vector<std::string> testList = {
        R"({"currency":"bTc","address":"0x1345"})",
        R"({"currency":"bTc","amount":1.535478})",
        R"({"address":"fwlnvlwnlkfsd","amount":13384.13541345})"
    };
    OneXAPI::Binance::Spot client;

    for(const auto& testItem : testList){
        std::string response = client.withdraw(testItem);
        
        testData.actualResult.append(response + "\n");

        if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
            return false;
        }
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_withdraw_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().withdraw";
    std::string findValue1 = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/config/getall)";
    std::string findValue2 = R"(METHOD: POST, URL: https://api.binance.com/sapi/v1/capital/withdraw/apply?coin=ADA&address=wrongAddress&amount=135.123436)";
    testData.expectedResult = findValue1 + "\nand\n" + findValue2;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"aDA","address":"wrongAddress","amount":135.1234358})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    client.withdraw(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue1) != std::string::npos && response.find(findValue2) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_withdraw_3(testDataType& testData){
    TC_BEGIN
    
    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().withdraw";
    std::string findValue1 = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/config/getall)";
    std::string findValue2 = R"(METHOD: POST, URL: https://api.binance.com/sapi/v1/capital/withdraw/apply?coin=ADA&network=ADA&address=wrongAddress&addressTag=wrongTag&amount=136.123436)";
    testData.expectedResult = findValue1 + "\nand\n" + findValue2;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"aDA","chain":"AdA","address":"wrongAddress","tag":"wrongTag","amount":135.1234358,"feeInAmount":false})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    client.withdraw(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue1) != std::string::npos && response.find(findValue2) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchAllCurrencies_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchAllCurrencies";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"] : array&size must not be 1
        response["data"]["currencies"][currency]["chains"]["chain"] : string response["data"]["currencies"][currency]["chains"]["isDefault"] : bool)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchAllCurrencies();
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["currencies"].MemberCount() == 0){
        return false;
    }

    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        if(currencyPtr->value["chains"].Size() == 1){
            return false;
        }
        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!chain["chain"].IsString()){
                return false;
            }
            if(!chain["isDefault"].IsBool()){
                return false;
            }
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchAllCurrencies_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchAllCurrencies";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"] : array&size must not be 1
        response["data"]["currencies"][currency]["chains"]["chain"] : string response["data"]["currencies"][currency]["chains"]["isDefault"] : bool)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchAllCurrencies("");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["currencies"].MemberCount() == 0){
        return false;
    }

    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        if(currencyPtr->value["chains"].Size() == 1){
            return false;
        }
        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!chain["chain"].IsString()){
                return false;
            }
            if(!chain["isDefault"].IsBool()){
                return false;
            }
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchBalance_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["fetchType"]:"rest"
        response["data"]["balance"][currency]["free"]:string response["data"]["balance"][currency]["locked"]:string)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchBalance(R"({"currencies":[]})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    for(auto balancePtr = respDoc["data"]["balance"].MemberBegin(); balancePtr != respDoc["data"]["balance"].MemberEnd(); balancePtr++){
        if(!balancePtr->name.IsString()){
            return false;
        }
        else if(!balancePtr->value["free"].IsString()){
            return false;
        }
        else if(!balancePtr->value["locked"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchBalance_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["fetchType"]:"rest" 
        response["data"]["balance"][currency]["free"]:string response["data"]["balance"][currency]["locked"]:string 
        and member count of response["data"]["balance"] is 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchBalance(R"({"currencies":["bTc","xRP","eTh"],"zeroBalance":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(respDoc["data"]["balance"].MemberCount() != 3){
        return false;
    }

    for(auto balancePtr = respDoc["data"]["balance"].MemberBegin(); balancePtr != respDoc["data"]["balance"].MemberEnd(); balancePtr++){
        if(!balancePtr->name.IsString()){
            return false;
        }
        else if(!balancePtr->value["free"].IsString()){
            return false;
        }
        else if(!balancePtr->value["locked"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchWalletStatus_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchWalletStatus";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"] is array
        response["data"]["currencies"][currency]["chains"][]["chain"] is string response["data"]["currencies"][currency]["chains"][]["withdrawEnable"] is bool
        response["data"]["currencies"][currency]["chains"][]["depositEnable"] is bool
        and size of response["data"]["currencies"][currency]["chains"] must be greater or equal than 1
        if size of response["data"]["currencies"][currency]["chains"] is 1, size of response["data"]["currencies"][currency]["chains"][0]["chain"] must be empty string)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchWalletStatus(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["currencies"].MemberCount() == 0){
        return false;
    }
    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        else if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        if(currencyPtr->value["chains"].Size() < 1){
            return false;
        }
        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!chain["chain"].IsString()){
                return false;
            }
            else if(!chain["withdrawEnable"].IsBool()){
                return false;
            }
            else if(!chain["depositEnable"].IsBool()){
                return false;
            }
        }
        if(currencyPtr->value["chains"].Size() == 1){
            if(std::string("").compare(currencyPtr->value["chains"][0]["chain"].GetString()) != 0){
                return false;
            }
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchWalletStatus_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchWalletStatus";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"] is array
        response["data"]["currencies"][currency]["chains"][]["chain"] is string response["data"]["currencies"][currency]["chains"][]["withdrawEnable"] is bool
        response["data"]["currencies"][currency]["chains"][]["depositEnable"] is bool
        and member count of response["data"]["currencies"] is 1
        and size of response["data"]["currencies"][currency]["chains"] must be greater or equal than 1
        if size of response["data"]["currencies"][currency]["chains"] is 1, size of response["data"]["currencies"][currency]["chains"][0]["chain"] must be empty string)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchWalletStatus(R"({"currency":"bTC"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["currencies"].MemberCount() != 1){
        return false;
    }
    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        else if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        if(currencyPtr->value["chains"].Size() < 1){
            return false;
        }
        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!chain["chain"].IsString()){
                return false;
            }
            else if(!chain["withdrawEnable"].IsBool()){
                return false;
            }
            else if(!chain["depositEnable"].IsBool()){
                return false;
            }
        }
        if(currencyPtr->value["chains"].Size() == 1){
            if(std::string("").compare(currencyPtr->value["chains"][0]["chain"].GetString()) != 0){
                return false;
            }
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchWithdrawHistory_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchWithdrawHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["withdrawals"]["currency"] is string
        response["data"]["withdrawals"]["amount"] is string response["data"]["withdrawals"]["fee"] is string response["data"]["withdrawals"]["orderId"] is string
        response["data"]["withdrawals"]["txid"] is string response["data"]["withdrawals"]["status"] is string response["data"]["withdrawals"]["created"] is uint64)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchWithdrawHistory(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    for(const auto& withdrawal : respDoc["data"]["withdrawals"].GetArray()){
        if(!withdrawal["currency"].IsString()){
            return false;
        }
        if(!withdrawal["amount"].IsString()){
            return false;
        }
        if(!withdrawal["fee"].IsString()){
            return false;
        }
        if(!withdrawal["orderId"].IsString()){
            return false;
        }
        if(!withdrawal["txid"].IsString()){
            return false;
        }
        if(!withdrawal["status"].IsString()){
            return false;
        }
        if(!withdrawal["created"].IsUint64()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchWithdrawHistory_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().fetchWithdrawHistory";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/withdraw/history?coin=MATIC&startTime=132123534&endTime=1125615123)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"currency":"mATic","orderId":"testOrderId","txid":"testTxId","startTime":132123534,"endTime":1125615123})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    client.fetchWithdrawHistory(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchDepositHistory_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["deposits"]["currency"] is string
        response["data"]["deposits"]["amount"] is string response["data"]["deposits"]["fee"] is string response["data"]["deposits"]["orderId"] is string
        response["data"]["deposits"]["txid"] is string response["data"]["deposits"]["status"] is string response["data"]["deposits"]["created"] is uint64)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositHistory(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    for(const auto& withdrawal : respDoc["data"]["deposits"].GetArray()){
        if(!withdrawal["currency"].IsString()){
            return false;
        }
        if(!withdrawal["amount"].IsString()){
            return false;
        }
        if(!withdrawal["fee"].IsString()){
            return false;
        }
        if(!withdrawal["orderId"].IsString()){
            return false;
        }
        if(!withdrawal["txid"].IsString()){
            return false;
        }
        if(!withdrawal["status"].IsString()){
            return false;
        }
        if(!withdrawal["created"].IsUint64()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchDepositHistory_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositHistory";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/deposit/hisrec?coin=MATIC&startTime=132123534&endTime=1125615123)";
    testData.expectedResult = findValue;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"mATic","orderId":"testOrderId","txid":"testTxId","startTime":132123534,"endTime":1125615123})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    client.fetchDepositHistory(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchDepositAddress_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositAddress";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");
    std::string response = client.fetchDepositAddress("{}");

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchDepositAddress_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositAddress";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["addresses"]["BTC"] is array
        response["data"]["addresses"]["BTC"][0]["chain"] : "BSC" response["data"]["addresses"]["BTC"][0]["address"] is string response["data"]["addresses"]["BTC"][0]["tag"] is string
        member count of response["data"]["addresses"] must be 1
        size of response["data"]["addresses"][currency] is 1)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositAddress(R"({"currency":"Btc","chain":"BsC"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["addresses"].MemberCount() != 1){
        return false;
    }
    else if(!respDoc["data"]["addresses"]["BTC"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["addresses"]["BTC"].Size() != 1){
        return false;
    }
    else if(std::string("BSC").compare(respDoc["data"]["addresses"]["BTC"][0]["chain"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["addresses"]["BTC"][0]["address"].IsString()){
        return false;
    }
    else if(!respDoc["data"]["addresses"]["BTC"][0]["tag"].IsString()){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_isDepositCompleted_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().isDepositCompleted";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.isDepositCompleted("{}");

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_isDepositCompleted_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().isDepositCompleted";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/deposit/hisrec)";
    testData.expectedResult = findValue + R"(  and {"success":true,"data":{"requestedApiCount":1,"isDepositCompleted":false})";            
    testData.actualResult.clear();
    std::string input = R"({"txid":"testTxid"})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string restResp = client.isDepositCompleted(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    LOAD_LOGGER_SETTINGS
    testData.actualResult = response + "  " + restResp;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, restResp);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["isDepositCompleted"].GetBool()){
        return false;
    }

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_isDepositCompleted_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().isDepositCompleted";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/sapi/v1/capital/deposit/hisrec?coin=SOL&startTime=1656044045154)";
    testData.expectedResult = findValue + R"(  and {"success":true,"data":{"requestedApiCount":1,"isDepositCompleted":false})";            
    testData.actualResult.clear();
    std::string input = R"({"currency":"sOl","amount":35.213843,"since":1656044045154})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string restResp = client.isDepositCompleted(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    LOAD_LOGGER_SETTINGS
    testData.actualResult = response + "  " + restResp;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, restResp);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["isDepositCompleted"].GetBool()){
        return false;
    }

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

static const std::string getOrderRoundingRuleExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})";

bool TC_BinanceSpot_getOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string response = client.getOrderRoundingRule();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getOrderRoundingRule(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_setOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setOrderRoundingRule";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"limitBuyBaseAmount":"wrongData"})";
    std::string response = client.setOrderRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_setOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setOrderRoundingRule";
    testData.expectedResult.clear();
    testData.actualResult.clear();
    std::string getCheckStr = "";
    std::string getExpectedResult = "";
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"ceil","limitBuyBaseAmount":"ceil","limitSellPrice":"ceil","limitSellBaseAmount":"ceil","marketBuyQuoteAmount":"ceil","marketSellBaseAmount":"ceil"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"floor","limitBuyBaseAmount":"floor","limitSellPrice":"floor","limitSellBaseAmount":"floor","marketBuyQuoteAmount":"floor","marketSellBaseAmount":"floor"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})").append("\n");
    OneXAPI::Binance::Spot client;
    std::vector<std::string> testValueList = {
        "ceil",
        "floor",
        "round"
    };
    std::vector<std::string> testKeyList = {
        "limitBuyPrice",
        "limitBuyBaseAmount",
        "limitSellPrice",
        "limitSellBaseAmount",
        "marketBuyQuoteAmount",
        "marketSellBaseAmount"
    };

    for(const auto& testValue : testValueList){
        for(const auto& testKey : testKeyList){
            testData.expectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,")" + testKey + R"(":")" + testValue + R"("}})" + "\n");
            std::string input = R"({")" + testKey + R"(":")" + testValue + R"("})";
            std::string response = client.setOrderRoundingRule(input);
        
            testData.actualResult.append(response + "\n");
        }
        getCheckStr.append(client.getOrderRoundingRule() + "\n");
    }

    if(testData.actualResult.compare(testData.expectedResult) == 0 && getCheckStr.compare(getExpectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderLimitBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitBuy";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderLimitBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderLimitBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=BUY&type=LIMIT&timeInForce=GTC&quantity=35.13569&price=25312.12)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Binance::Spot client;

    client.orderLimitBuy(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderLimitBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=BUY&type=LIMIT&timeInForce=FOK&quantity=35.13569&price=26187.92&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158,"clientOrderId":"testId","amplifier":1.0346,"type":"fok"})";
    OneXAPI::Binance::Spot client;

    client.orderLimitBuy(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderLimitSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitSell";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderLimitSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderLimitSell_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=GTC&quantity=35.13569&price=25312.12)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Binance::Spot client;

    client.orderLimitSell(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }
    
    TC_END
}

bool TC_BinanceSpot_orderLimitSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=IOC&quantity=35.13569&price=24387.72&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158,"clientOrderId":"testId","amplifier":0.96348,"type":"ioc"})";
    OneXAPI::Binance::Spot client;

    client.orderLimitSell(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderMarketBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketBuy";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderMarketBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderMarketBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=BUY&type=MARKET&quoteOrderQty=41381.39)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","quoteAmount":41381.391351334})";
    OneXAPI::Binance::Spot client;

    client.orderMarketBuy(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;
    
    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderMarketBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=BUY&type=MARKET&quoteOrderQty=41381.39&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","quoteAmount":41381.391351334,"clientOrderId":"testId"})";
    OneXAPI::Binance::Spot client;

    client.orderMarketBuy(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;
    
    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderMarketSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketSell";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderMarketSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderMarketSell_2(testDataType& testData){TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=SELL&type=MARKET&quantity=83.13385)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","baseAmount":83.1338494835})";
    OneXAPI::Binance::Spot client;

    client.orderMarketSell(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderMarketSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=SELL&type=MARKET&quantity=83.13385&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","baseAmount":83.1338494835,"clientOrderId":"testId"})";
    OneXAPI::Binance::Spot client;

    client.orderMarketSell(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderCancel_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().orderCancel";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderCancel("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderCancel_2(testDataType& testData){
    TC_BEGIN    

    testData.testSubject = "OneXAPI::Binance::Spot().orderCancel";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.orderCancel(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderCancel_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&orderId=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","orderId":"testOrderId"})";
    OneXAPI::Binance::Spot client;

    client.orderCancel(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_orderCancel_4(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&origClientOrderId=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","clientOrderId":"testClientOrderId"})";
    OneXAPI::Binance::Spot client;

    client.orderCancel(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchTradingFee_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTradingFee";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["fees"] is array
        response["data"]["fees"][]["baseCurrency"] is string response["data"]["fees"][]["quoteCurrency"] is string response["data"]["fees"][]["symbol"] is string
        response["data"]["fees"][]["makerFee"] is string response["data"]["fees"][]["takerFee"] is string
        size of response["data"]["fees"] is not 0)";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchTradingFee("{}");
        
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    bool result = true;
    if(!respDoc["success"].GetBool()){
        result = false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        result = false;
    }
    else if(!respDoc["data"]["fees"].IsArray()){
        result = false;
    }
    else if(respDoc["data"]["fees"].Size() == 0){
        result = false;
    }
    for(const auto& fee : respDoc["data"]["fees"].GetArray()){
        if(!fee["baseCurrency"].IsString()){
            result = false;
        }
        else if(!fee["quoteCurrency"].IsString()){
            result = false;
        }
        else if(!fee["symbol"].IsString()){
            result = false;
        }
        else if(!fee["makerFee"].IsString()){
            result = false;
        }
        else if(!fee["takerFee"].IsString()){
            result = false;
        }
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTradingFee_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTradingFee";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["fees"] is array
        response["data"]["fees"][]["baseCurrency"] = "BTC" response["data"]["fees"][]["quoteCurrency"] = "USDT" response["data"]["fees"][]["symbol"] = "BTCUSDT"
        response["data"]["fees"][]["makerFee"] is string response["data"]["fees"][]["takerFee"] is string
        size of response["data"]["fees"] is 1)";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT"})";
    std::string response = client.fetchTradingFee(input);
        
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    bool result = true;
    if(!respDoc["success"].GetBool()){
        result = false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        result = false;
    }
    else if(!respDoc["data"]["fees"].IsArray()){
        result = false;
    }
    else if(respDoc["data"]["fees"].Size() != 1){
        result = false;
    }
    for(const auto& fee : respDoc["data"]["fees"].GetArray()){
        if(std::string("BTC").compare(fee["baseCurrency"].GetString()) != 0){
            result = false;
        }
        else if(std::string("USDT").compare(fee["quoteCurrency"].GetString()) != 0){
            result = false;
        }
        else if(std::string("BTCUSDT").compare(fee["symbol"].GetString()) != 0){
            result = false;
        }
        else if(!fee["makerFee"].IsString()){
            result = false;
        }
        else if(!fee["takerFee"].IsString()){
            result = false;
        }
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderInfo("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.fetchOrderInfo(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&orderId=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT","orderId":"testOrderId"})";
    OneXAPI::Binance::Spot client;

    client.fetchOrderInfo(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_4(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&origClientOrderId=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT","clientOrderId":"testClientOrderId"})";
    OneXAPI::Binance::Spot client;

    client.fetchOrderInfo(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string response = getLog(testStartTime);
    testData.actualResult = response;

    LOAD_LOGGER_SETTINGS

    if(response.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_5(testDataType& testData){
    TC_BEGIN
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:2 response["data"]["baseCurrency"] is string response["data"]["quoteCurrency"] is string
        response["data"]["symbol"] is string response["data"]["orderId"] = orderId response["data"]["clientOrderId"] is string response["data"]["side"] = "buy" or "sell" 
        response["data"]["originalAmount"] is string response["data"]["filledAmount"] is string response["data"]["remainingAmount"] is string response["data"]["originalPrice"] is string 
        response["data"]["avgFillPrice"] is string response["data"]["created"] is uint64 response["data"]["feeCurrency"] is string
        response["data"]["feeAmount"] is string response["data"]["status"] is string response["data"]["fills"] is an empty array)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"USDT"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"USDT","price":)" + bid + R"(,"baseAmount":50.00,"amplifier":0.96})");
    rapidjson::Document orderLimitBuyDoc;
    OneXAPI::Internal::Util::parseJson(orderLimitBuyDoc, orderLimitBuy);
    if(!orderLimitBuyDoc["success"].GetBool()){
        return false;
    }
    std::string orderId = orderLimitBuyDoc["data"]["orderId"].GetString();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string input = R"({"baseCurrency":"xRp","quoteCurrency":"UsdT","orderId":")" + orderId + R"("})";
    std::string response = client.fetchOrderInfo(input);
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    bool result = true;
    if(!respDoc["success"].GetBool()){
        result = false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 2){
        result = false;
    }
    else if(orderId.compare(respDoc["data"]["orderId"].GetString()) != 0 || std::string("buy").compare(respDoc["data"]["side"].GetString()) != 0){
        result = false;
    }
    else if( !respDoc["data"]["baseCurrency"].IsString() || !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["symbol"].IsString() ||
        !respDoc["data"]["clientOrderId"].IsString() || !respDoc["data"]["originalAmount"].IsString() || !respDoc["data"]["remainingAmount"].IsString() || 
        !respDoc["data"]["originalPrice"].IsString() || !respDoc["data"]["filledAmount"].IsString() || !respDoc["data"]["avgFillPrice"].IsString() || 
        !respDoc["data"]["created"].IsUint64() || !respDoc["data"]["feeCurrency"].IsString() || !respDoc["data"]["feeAmount"].IsString() || 
        !respDoc["data"]["status"].IsString() || !respDoc["data"]["fills"].IsArray()){
        result = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderCancel = client.orderCancel(input);
    rapidjson::Document orderCancelDoc;
    OneXAPI::Internal::Util::parseJson(orderCancelDoc, orderCancel);
    if(!orderCancelDoc["success"].GetBool() || !result){
        return false;
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOpenOrders_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["openOrders"][]["baseCurrency"] is string
        response["data"]["openOrders"][]["quoteCurrency"] is string response["data"]["openOrders"][]["symbol"] is string response["data"]["openOrders"][]["orderId"] is string
        response["data"]["openOrders"][]["side"] is string response["data"]["openOrders"][]["originalAmount"] is string response["data"]["openOrders"][]["filledAmount"] is string
        response["data"]["openOrders"][]["remainingAmount"] is string response["data"]["openOrders"][]["originalPrice"] is string response["data"]["openOrders"][]["status"] is uint64
        response["data"]["openOrders"][]["lockedCurrency"] is string response["data"]["openOrders"][]["lockedAmount"] is string)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"USDT"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"USDT","price":)" + bid + R"(,"baseAmount":50.00,"amplifier":0.96})");
    rapidjson::Document orderLimitBuyDoc;
    OneXAPI::Internal::Util::parseJson(orderLimitBuyDoc, orderLimitBuy);
    if(!orderLimitBuyDoc["success"].GetBool()){
        return false;
    }
    std::string orderId = orderLimitBuyDoc["data"]["orderId"].GetString();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchOpenOrders(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    bool result = true;
    if(!respDoc["success"].GetBool()){
        result = false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        result = false;
    }
    else if(respDoc["data"]["openOrders"].Size() == 0){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if( !openorder["baseCurrency"].IsString() || !openorder["quoteCurrency"].IsString() || !openorder["symbol"].IsString() ||
            !openorder["orderId"].IsString() || !openorder["side"].IsString() || !openorder["originalAmount"].IsString() ||
            !openorder["filledAmount"].IsString() || !openorder["remainingAmount"].IsString() || !openorder["originalPrice"].IsString() ||
            !openorder["created"].IsUint64() || !openorder["lockedCurrency"].IsString() || !openorder["lockedAmount"].IsString()){
            result = false;
        }
    }

    std::string input = R"({"baseCurrency":"xRP","quoteCurrency":"uSDt","orderId":")" + orderId + R"("})";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderCancel = client.orderCancel(input);
    rapidjson::Document orderCancelDoc;
    OneXAPI::Internal::Util::parseJson(orderCancelDoc, orderCancel);
    if(!orderCancelDoc["success"].GetBool() || !result){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOpenOrders_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["openOrders"][]["baseCurrency"] is string
        response["data"]["openOrders"][]["quoteCurrency"] is string response["data"]["openOrders"][]["symbol"] is string response["data"]["openOrders"][]["orderId"] is string
        response["data"]["openOrders"][]["side"] is string response["data"]["openOrders"][]["originalAmount"] is string response["data"]["openOrders"][]["filledAmount"] is string
        response["data"]["openOrders"][]["remainingAmount"] is string response["data"]["openOrders"][]["originalPrice"] is string response["data"]["openOrders"][]["lockedCurrency"] is string
        response["data"]["openOrders"][]["lockedAmount"] is string response["data"]["openOrders"][]["status"] is string)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"USDT"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"USDT","price":)" + bid + R"(,"baseAmount":50.00,"amplifier":0.96})");
    rapidjson::Document orderLimitBuyDoc;
    OneXAPI::Internal::Util::parseJson(orderLimitBuyDoc, orderLimitBuy);
    if(!orderLimitBuyDoc["success"].GetBool()){
        return false;
    }
    std::string orderId = orderLimitBuyDoc["data"]["orderId"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchOpenOrders(R"({"baseCurrency":"xRP","quoteCurrency":"uSDt","side":"buy"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    bool result = true;
    if(!respDoc["success"].GetBool()){
        result = false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        result = false;
    }
    else if(respDoc["data"]["openOrders"].Size() == 0){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if( !openorder["baseCurrency"].IsString() || !openorder["quoteCurrency"].IsString() || !openorder["symbol"].IsString() ||
            !openorder["orderId"].IsString() || !openorder["side"].IsString() || !openorder["originalAmount"].IsString() ||
            !openorder["filledAmount"].IsString() || !openorder["remainingAmount"].IsString() || !openorder["originalPrice"].IsString() ||
            !openorder["created"].IsUint64() || !openorder["lockedCurrency"].IsString() || !openorder["lockedAmount"].IsString()){
            result = false;
        }
    }

    std::string input = R"({"baseCurrency":"xRP","quoteCurrency":"uSDt","orderId":")" + orderId + R"("})";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderCancel = client.orderCancel(input);
    rapidjson::Document orderCancelDoc;
    OneXAPI::Internal::Util::parseJson(orderCancelDoc, orderCancel);
    if(!orderCancelDoc["success"].GetBool() || !result){
        return false;
    }

    return true;

    TC_END
}

static const std::string getCandleIntervalCandidatesExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"intervals":["12hour","15min","1day","1hour","1min","1month","1week","2hour","30min","3day","3min","4hour","5min","6hour","8hour"]}})";

bool TC_BinanceSpot_getCandleIntervalCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;

    std::string response = client.getCandleIntervalCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getCandleIntervalCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getCandleIntervalCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchMarkets_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["markets"][]["baseCurrency"]:string
        response["data"]["markets"][]["quoteCurrency"]:string response["data"]["markets"][]["symbol"]:string)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets("{}");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["markets"].Size() == 0){
        return false;
    }

    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!market["baseCurrency"].IsString() || !market["quoteCurrency"].IsString() || !market["symbol"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchMarkets_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["markets"][]["baseCurrency"]:string
        response["data"]["markets"][]["quoteCurrency"]:string response["data"]["markets"][]["symbol"]:string)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets(R"({"baseCurrency":"bTC","quoteCurrency":"usDT"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["markets"].Size() != 1){
        return false;
    }

    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!market["baseCurrency"].IsString() || !market["quoteCurrency"].IsString() || !market["symbol"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchTicker(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTicker_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "USDT"
        response["data"]["symbol"] = "BTCUSDT" response["data"]["fetchType"] = "rest" response["data"]["openTime"]:uint64 response["data"]["openPrice"]:string
        response["data"]["closePrice"]:string response["data"]["lowPrice"]:string response["data"]["highPrice"]:string response["data"]["baseVolume"]:string
        response["data"]["quoteVolume"]:string)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["openTime"].IsUint64() || !respDoc["data"]["openPrice"].IsString() || !respDoc["data"]["closePrice"].IsString() || !respDoc["data"]["lowPrice"].IsString() ||
        !respDoc["data"]["highPrice"].IsString() || !respDoc["data"]["baseVolume"].IsString() || !respDoc["data"]["quoteVolume"].IsString()){
        return false;
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderbook(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderbook_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "USDT"
        response["data"]["symbol"] = "BTCUSDT" response["data"]["fetchType"] = "rest" response["data"]["timestamp"]:uint64 response["data"]["bids"][]["price"]:string
        response["data"]["bids"][]["size"]:string response["data"]["asks"][]["price"]:string response["data"]["asks"][]["size"]:string)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["timestamp"].IsUint64()){
        return false;
    }
    else if(respDoc["data"]["bids"].Size() == 0 || respDoc["data"]["asks"].Size() == 0){
        return false;
    }
    for(const auto& bid : respDoc["data"]["bids"].GetArray()){
        if(!bid["price"].IsString() || !bid["size"].IsString()){
            return false;
        }
    }
    for(const auto& ask : respDoc["data"]["asks"].GetArray()){
        if(!ask["price"].IsString() || !ask["size"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchCandleHistory_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchCandleHistory";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchCandleHistory_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:uint64 response["data"]["baseCurrency"]:string response["data"]["quoteCurrency"]:string
        response["data"]["symbol"]:string response["data"]["candles"][]["timestamp"]:uint64 response["data"]["candles"][]["openPrice"]:string response["data"]["candles"][]["closePrice"]:string
        response["data"]["candles"][]["highPrice"]:string response["data"]["candles"][]["lowPrice"]:string response["data"]["candles"][]["baseVolume"]:string response["data"]["candles"][]["quoteVolume"]:string)";

    OneXAPI::Binance::Spot client;

    std::string twoHrBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch()/1000 - 7200);
    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","interval":"1min","startTime":)" + twoHrBeforeFromNow + R"(})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(!respDoc["data"]["requestedApiCount"].IsUint64() || !respDoc["data"]["baseCurrency"].IsString() || 
        !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["symbol"].IsString()){
        return false;
    }
    else if(respDoc["data"]["candles"].Size() == 0){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if( !candle["timestamp"].IsUint64() || !candle["openPrice"].IsString() || !candle["closePrice"].IsString() || !candle["highPrice"].IsString() ||
            !candle["lowPrice"].IsString() || !candle["baseVolume"].IsString() || !candle["quoteVolume"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchCandleHistory_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:uint64 response["data"]["baseCurrency"]:string response["data"]["quoteCurrency"]:string
        response["data"]["symbol"]:string response["data"]["candles"][]["timestamp"]:uint64 response["data"]["candles"][]["openPrice"]:string response["data"]["candles"][]["closePrice"]:string
        response["data"]["candles"][]["highPrice"]:string response["data"]["candles"][]["lowPrice"]:string response["data"]["candles"][]["baseVolume"]:string response["data"]["candles"][]["quoteVolume"]:string)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","interval":"1min","startTime":1656042045,"endTime":1656063182,"fetchInterval":900})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(!respDoc["data"]["requestedApiCount"].IsUint64() || !respDoc["data"]["baseCurrency"].IsString() || 
        !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["symbol"].IsString()){
        return false;
    }
    else if(respDoc["data"]["candles"].Size() == 0){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if( !candle["timestamp"].IsUint64() || !candle["openPrice"].IsString() || !candle["closePrice"].IsString() || !candle["highPrice"].IsString() ||
            !candle["lowPrice"].IsString() || !candle["baseVolume"].IsString() || !candle["quoteVolume"].IsString()){
            return false;
        }
    }
    
    return true;

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