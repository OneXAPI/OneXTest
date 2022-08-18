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

    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositAddress";
    // testData.expectedResult = R"(response["success"]:true response["data"]["addresses"]:1 response["data"]["addresses"]["BTC"]["address"] is string
    //     response["data"]["addresses"]["BTC"]["tag"] is string       member count of response["data"]["addresses"] must be 1)";
    // testData.actualResult.clear();

    // OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SECRET_KEY + R"("})");

    // std::string response = client.fetchDepositAddress(R"({"currency":"Btc"})");
    // testData.actualResult = response;
    // rapidjson::Document respDoc;
    // OneXAPI::Internal::Util::parseJson(respDoc, response);

    // if(!respDoc["success"].GetBool()){
    //     return false;
    // }
    // else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
    //     return false;
    // }
    // else if(respDoc["data"]["addresses"].MemberCount() != 1){
    //     return false;
    // }
    // if(!respDoc["data"]["addresses"]["BTC"]["address"].IsString()){
    //     return false;
    // }
    // if(!respDoc["data"]["addresses"]["BTC"]["tag"].IsString()){
    //     return false;
    // }

    // return true;

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