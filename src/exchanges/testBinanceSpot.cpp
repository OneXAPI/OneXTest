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

static const std::string getConfigExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"exchange":"Binance","instrument":"Spot","accessKey":"","secretKey":"","restEndpoint":"https://api.binance.com","publicWebsocketEndpoint":"wss://stream.binance.com:9443/stream","privateWebsocketEndpoint":"wss://stream.binance.com:9443/ws","restRequestTimeout":5000,"websocketConnectTimeout":5000,"websocketIdleTimeout":5000}})";

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "trashData123@@!%";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_setConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

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
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE_TYPE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;
    std::string input, response;

    input = R"({"accessKey":1.1354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"secretKey":11354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"restEndpoint":null})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"publicWebsocketEndpoint":true})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"privateWebsocketEndpoint":{}})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"restRequestTimeout":1.1354})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"websocketConnectTimeout":"ffaew"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }
    input = R"({"websocketIdleTimeout":false})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_setConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client;
    std::string input, response;

    input = R"({"restEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }
    input = R"({"publicWebsocketEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }
    input = R"({"privateWebsocketEndpoint":"wrongEndpoint"})";
    response = client.setConfig(input);
    testData.actualResult.append(response + "\n");
    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_setConfig_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().setConfig";
    testData.expectedResult = R"("{"success":true,"requestedApiCount":0,"data":{"requestedKey":"requestedValue"}}"
check using getConfig() also)";
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
        if(!successResponseChecker(response)){
            return false;
        }
        else if(respDoc["requestedApiCount"].GetUint() != 0){
            return false;
        }
        else if(!respDoc["data"].HasMember(testItem.first)){
            return false;
        }
        else if(!memberCountChecker(respDoc["data"], 1)){
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
        if(!successResponseChecker(response)){
            return false;
        }
        else if(respDoc["requestedApiCount"].GetUint() != 0){
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

static const std::string getEndpointCandidatesExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"restEndpoints":["https://api.binance.com","https://api1.binance.com","https://api2.binance.com","https://api3.binance.com","https://testnet.binance.vision/api"],"publicWebsocketEndpoints":["wss://stream.binance.com:9443/stream","wss://testnet.binance.vision/stream"],"privateWebsocketEndpoints":["wss://stream.binance.com:9443/ws","wss://testnet.binance.vision/ws"]}})";

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "uNPaRsib1eM5g";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

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
    {"fetchOrderInfo", true},
    {"fetchOpenOrders", true},
    {"fetchTradingFee", true},
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
    rapidjson::Document expectedResult;
    expectedResult.SetObject();
    expectedResult.AddMember("success", true, expectedResult.GetAllocator());
    expectedResult.AddMember("requestedApiCount", 0, expectedResult.GetAllocator());
    expectedResult.AddMember("data", rapidjson::Value(rapidjson::kObjectType), expectedResult.GetAllocator());
    for(auto api : hasExpectedResult){
        rapidjson::Value apiName(api.first, expectedResult.GetAllocator());
        expectedResult["data"].AddMember(apiName, api.second, expectedResult.GetAllocator());
    }
    testData.expectedResult = OneXAPI::Internal::Util::jsonToString(expectedResult);

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.has(input);
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    testData.actualResult = response;
    if(!successResponseChecker(response)){
        return false;
    }
    else if(response.compare(testData.expectedResult) != 0 || !memberCountChecker(respDoc["data"], 38)){
        return false;
    }
    testData.expectedResult += R"(\n member count of response["data"] = 38)";
    return true;

    TC_END
}

bool TC_BinanceSpot_has_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    rapidjson::Document expectedResult;
    expectedResult.SetObject();
    expectedResult.AddMember("success", true, expectedResult.GetAllocator());
    expectedResult.AddMember("requestedApiCount", 0, expectedResult.GetAllocator());
    expectedResult.AddMember("data", rapidjson::Value(rapidjson::kObjectType), expectedResult.GetAllocator());
    for(auto api : hasExpectedResult){
        rapidjson::Value apiName(api.first, expectedResult.GetAllocator());
        expectedResult["data"].AddMember(apiName, api.second, expectedResult.GetAllocator());
    }
    testData.expectedResult = OneXAPI::Internal::Util::jsonToString(expectedResult);

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.has(input);
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    testData.actualResult = response;
    if(!successResponseChecker(response)){
        return false;
    }
    else if(response.compare(testData.expectedResult) != 0 || !memberCountChecker(respDoc["data"], 38)){
        return false;
    }
    testData.expectedResult += R"(\n member count of response["data"] = 38)";
    return true;

    TC_END
}

bool TC_BinanceSpot_has_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().has";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "el12nlgv@!";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
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
        testData.expectedResult += R"({"success":true,"requestedApiCount":0,"data":{")" + api.first + R"(":)" + (api.second?"true":"false") + R"(}})" + "\n";
        std::string input = R"({"api":")" + api.first + R"("})";
        std::string response = client.has(input);

        testData.actualResult += response + "\n";
        rapidjson::Document respDoc;
        OneXAPI::Internal::Util::parseJson(respDoc, response);

        if(!successResponseChecker(response)){
            return false;
        }
        else if(!memberCountChecker(respDoc["data"], 1)){
            return false;
        }
    }

    if((testData.actualResult).compare(testData.expectedResult) == 0){
        testData.expectedResult += R"(\n member count of response["data"] = 1)";
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

    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }
    return true;

    TC_END
}

static const std::string getWithdrawRoundingRuleExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"roundingRule":"round"}})";

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"roundingRule":"wrongData"})";
    std::string response = client.setWithdrawRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
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
        testData.expectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"roundingRule":")" + testItem + R"("}})" + "\n");
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
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

        if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    std::string findValue2 = R"(METHOD: POST, URL: https://api.binance.com/sapi/v1/capital/withdraw/apply?coin=ADA&network=ADA&address=wrongAddress&addressTag=wrongTag&amount=135.923436)";
    testData.expectedResult = findValue1 + "\nand\n" + findValue2;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"aDA","chain":"AdA","address":"wrongAddress","tag":"wrongTag","amount":135.1234358,"feeInAmount":false})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["currencies"][currency]["chains"] : array
response["data"]["currencies"][currency]["chains"]["chain"] : string
response["data"]["currencies"][currency]["chains"]["isDefault"] : bool

member count of response["data"] = 1
member count of response["data"]["currencies"] is greater than 10
member count of response["data"]["currencies"][currency] = 1
size of response["data"]["currencies"][currency]["chains"] must not be 1
member count of response["data"]["currencies"][currency]["chains"][] = 2)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchAllCurrencies();
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!(respDoc["data"]["currencies"].MemberCount() > 10)){
        return false;
    }

    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        else if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        else if(currencyPtr->value["chains"].Size() == 1){
            return false;
        }
        else if(!memberCountChecker(currencyPtr->value, 1)){
            return false;
        }

        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!memberCountChecker(chain, 2)){
                return false;
            }
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["currencies"][currency]["chains"] : array
response["data"]["currencies"][currency]["chains"]["chain"] : string
response["data"]["currencies"][currency]["chains"]["isDefault"] : bool

member count of response["data"] = 1
member count of response["data"]["currencies"] is greater than 10
member count of response["data"]["currencies"][currency] = 1
size of response["data"]["currencies"][currency]["chains"] must not be 1
member count of response["data"]["currencies"][currency]["chains"][] = 2)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchAllCurrencies("");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!(respDoc["data"]["currencies"].MemberCount() > 10)){
        return false;
    }

    for(auto currencyPtr = respDoc["data"]["currencies"].MemberBegin(); currencyPtr != respDoc["data"]["currencies"].MemberEnd(); currencyPtr++){
        if(!currencyPtr->name.IsString()){
            return false;
        }
        else if(!currencyPtr->value["chains"].IsArray()){
            return false;
        }
        else if(currencyPtr->value["chains"].Size() == 1){
            return false;
        }
        else if(!memberCountChecker(currencyPtr->value, 1)){
            return false;
        }
        
        for(const auto& chain : currencyPtr->value["chains"].GetArray()){
            if(!memberCountChecker(chain, 2)){
                return false;
            }
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["free"]:string
response["data"]["balance"][currency]["locked"]:string

member count of response["data"] = 2
member count of response["data"]["balance"][currency] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchBalance(R"({"currencies":[]})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
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
        else if(!memberCountChecker(balancePtr->value, 2)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["free"]:string
response["data"]["balance"][currency]["locked"]:string

member count of response["data"] = 2
member count of response["data"]["balance"] is 3
member count of response["data"]["balance"][currency] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchBalance(R"({"currencies":["bTc","xRP","eTh"],"zeroBalance":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"]["balance"], 3)){
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
        else if(!memberCountChecker(balancePtr->value, 2)){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchBalance_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:0
response["data"]["fetchType"]:"websocket"
response["data"]["balance"][currency]["free"]:string
response["data"]["balance"][currency]["locked"]:string

member count of response["data"] = 2
member count of response["data"]["balance"] is 3
member count of response["data"]["balance"][currency] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.fetchBalance(R"({"currencies":["bTc","xRP","eTh"],"zeroBalance":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(std::string("websocket").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"]["balance"], 3)){
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
        else if(!memberCountChecker(balancePtr->value, 2)){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_fetchBalance_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["free"]:string
response["data"]["balance"][currency]["locked"]:string

member count of response["data"] = 2
member count of response["data"]["balance"][currency] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.fetchBalance(R"({"currencies":["bTc","xRP","eTh"],"zeroBalance":false, "forceRestApi":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("rest").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
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
        else if(!memberCountChecker(balancePtr->value, 2)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["currencies"][currency]["chains"] is array
response["data"]["currencies"][currency]["chains"][]["chain"] is string
response["data"]["currencies"][currency]["chains"][]["withdrawEnable"] is bool
response["data"]["currencies"][currency]["chains"][]["depositEnable"] is bool

member count of response["data"] = 1
member count of response["data"]["currencies"][currency] = 1
size of response["data"]["currencies"][currency]["chains"] must be greater or equal than 1
if size of response["data"]["currencies"][currency]["chains"] is 1, size of response["data"]["currencies"][currency]["chains"][0]["chain"] must be empty string
member count of response["data"]["currencies"][currency]["chains"][] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchWalletStatus(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(memberCountChecker(respDoc["data"]["currencies"], 0)){
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
        else if(!memberCountChecker(currencyPtr->value, 1)){
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
            else if(!memberCountChecker(chain, 3)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["currencies"][currency]["chains"] is array
response["data"]["currencies"][currency]["chains"][]["chain"] is string
response["data"]["currencies"][currency]["chains"][]["withdrawEnable"] is bool
response["data"]["currencies"][currency]["chains"][]["depositEnable"] is bool

member count of response["data"] = 1
member count of response["data"]["currencies"] is 1
member count of response["data"]["currencies"][currency] = 1
size of response["data"]["currencies"][currency]["chains"] must be greater or equal than 1
if size of response["data"]["currencies"][currency]["chains"] is 1, size of response["data"]["currencies"][currency]["chains"][0]["chain"] must be empty string
member count of response["data"]["currencies"][currency]["chains"][] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchWalletStatus(R"({"currency":"bTC"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"]["currencies"], 1)){
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
        else if(!memberCountChecker(currencyPtr->value, 1)){
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
            else if(!memberCountChecker(chain, 3)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["withdrawals"]["currency"] is string
response["data"]["withdrawals"]["amount"] is string
response["data"]["withdrawals"]["fee"] is string
response["data"]["withdrawals"]["orderId"] is string
response["data"]["withdrawals"]["txid"] is string
response["data"]["withdrawals"]["status"] is string
response["data"]["withdrawals"]["created"] is uint64

member count of response["data"] = 1
member count of response["data"]["withdrawals"] = 7)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchWithdrawHistory(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
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
        if(!memberCountChecker(withdrawal, 7)){
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
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["deposits"]["currency"] is string
response["data"]["deposits"]["amount"] is string
response["data"]["deposits"]["fee"] is string
response["data"]["deposits"]["orderId"] is string
response["data"]["deposits"]["txid"] is string
response["data"]["deposits"]["status"] is string
response["data"]["deposits"]["created"] is uint64

member count of response["data"] = 1
member count of response["data"]["deposits"] = 7)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositHistory(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& deposit : respDoc["data"]["deposits"].GetArray()){
        if(!deposit["currency"].IsString()){
            return false;
        }
        if(!deposit["amount"].IsString()){
            return false;
        }
        if(!deposit["fee"].IsString()){
            return false;
        }
        if(!deposit["orderId"].IsString()){
            return false;
        }
        if(!deposit["txid"].IsString()){
            return false;
        }
        if(!deposit["status"].IsString()){
            return false;
        }
        if(!deposit["created"].IsUint64()){
            return false;
        }
        if(!memberCountChecker(deposit, 7)){
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
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.fetchDepositAddress("{}");

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_fetchDepositAddress_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchDepositAddress";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["addresses"]["BTC"] is array
response["data"]["addresses"]["BTC"][0]["chain"] : "BSC"
response["data"]["addresses"]["BTC"][0]["address"] is string
response["data"]["addresses"]["BTC"][0]["tag"] is string

member count of response["data"] = 1
member count of response["data"]["addresses"] = 1
size of response["data"]["addresses"][currency] is 1
member count of response["data"]["addresses"][currency] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositAddress(R"({"currency":"Btc","chain":"BsC"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"]["addresses"], 1)){
        return false;
    }
    else if(!respDoc["data"]["addresses"]["BTC"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["addresses"]["BTC"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"]["addresses"]["BTC"][0], 3)){
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.isDepositCompleted("{}");

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    testData.expectedResult = findValue + R"(  and {"success":true,"requestedApiCount":1,"data":{"isDepositCompleted":false}})";            
    testData.actualResult.clear();
    std::string input = R"({"txid":"testTxid"})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.isDepositCompleted(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string log = getLog(testStartTime);
    LOAD_LOGGER_SETTINGS
    testData.actualResult = log + "  " + response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(respDoc["data"]["isDepositCompleted"].GetBool()){
        return false;
    }

    if(log.find(findValue) != std::string::npos){
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
    testData.expectedResult = findValue + R"(  and {"success":true,"requestedApiCount":1,"data":{"isDepositCompleted":false}})";            
    testData.actualResult.clear();
    std::string input = R"({"currency":"sOl","amount":35.213843,"since":1656044045154})";
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.isDepositCompleted(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string log = getLog(testStartTime);
    LOAD_LOGGER_SETTINGS
    testData.actualResult = log + "  " + response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(respDoc["data"]["isDepositCompleted"].GetBool()){
        return false;
    }

    if(log.find(findValue) != std::string::npos){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_subscribeBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_subscribeBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_subscribeBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeBalance";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;
    TC_END
}

bool TC_BinanceSpot_unsubscribeBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.unsubscribeBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_unsubscribeBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.unsubscribeBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_unsubscribeBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.unsubscribeBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_unsubscribeBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeBalance";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.unsubscribeBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_isSubscribingBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":false}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.isSubscribingBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_isSubscribingBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":false}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    std::string response = client.isSubscribingBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_isSubscribingBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":true}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.isSubscribingBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceSpot_isSubscribingBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().isSubscribingBalance";
    testData.expectedResult = R"({{"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.isSubscribingBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

static const std::string getOrderRoundingRuleExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})";

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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"limitBuyBaseAmount":"wrongData"})";
    std::string response = client.setOrderRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
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
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"ceil","limitBuyBaseAmount":"ceil","limitSellPrice":"ceil","limitSellBaseAmount":"ceil","marketBuyQuoteAmount":"ceil","marketSellBaseAmount":"ceil"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"floor","limitBuyBaseAmount":"floor","limitSellPrice":"floor","limitSellBaseAmount":"floor","marketBuyQuoteAmount":"floor","marketSellBaseAmount":"floor"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})").append("\n");
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
            testData.expectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{")" + testKey + R"(":")" + testValue + R"("}})" + "\n");
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderLimitBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderLimitSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    std::string findValue = R"(METHOD: POST, URL: https://api.binance.com/api/v3/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=FOK&quantity=35.13569&price=24387.72&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158,"clientOrderId":"testId","amplifier":0.96348,"type":"fok"})";
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderMarketBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderMarketSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.orderCancel("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_orderCancel_2(testDataType& testData){
    TC_BEGIN    

    testData.testSubject = "OneXAPI::Binance::Spot().orderCancel";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.orderCancel(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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

bool TC_BinanceSpot_fetchOrderInfo_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderInfo("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderInfo_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.fetchOrderInfo(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:2
response["data"]["baseCurrency"] is string
response["data"]["quoteCurrency"] is string
response["data"]["symbol"] is string
response["data"]["orderId"] = orderId
response["data"]["orderId"] is string
response["data"]["side"] = buy or sell
response["data"]["originalAmount"] is string
response["data"]["filledAmount"] is string
response["data"]["remainingAmount"] is string
response["data"]["originalPrice"] is string
response["data"]["avgFillPrice"] is string
response["data"]["created"] is uint64
response["data"]["feeCurrency"] is string
response["data"]["feeAmount"] is string
response["data"]["status"] is string
response["data"]["fills"] is an empty array

member count of response["data"] = 16)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    if(!successResponseChecker(response)){
        result = false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 2){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 16)){
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["openOrders"][]["baseCurrency"] is string
response["data"]["openOrders"][]["quoteCurrency"] is string
response["data"]["openOrders"][]["symbol"] is string
response["data"]["openOrders"][]["orderId"] is string
response["data"]["openOrders"][]["side"] is string
response["data"]["openOrders"][]["originalAmount"] is string
response["data"]["openOrders"][]["filledAmount"] is string
response["data"]["openOrders"][]["remainingAmount"] is string
response["data"]["openOrders"][]["originalPrice"] is string
response["data"]["openOrders"][]["created"] is uint64
response["data"]["openOrders"][]["lockedCurrency"] is string
response["data"]["openOrders"][]["lockedAmount"] is string

member count of response["data"] = 1
size of response["data"]["openOrders"] is greater than 0
member count of response["data"]["openOrders"][] = 12)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    if(!successResponseChecker(response)){
        result = false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        result = false;
    }
    else if(!(respDoc["data"]["openOrders"].Size() > 0)){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if(!memberCountChecker(openorder, 12)){
            result = false;
        }
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["openOrders"][]["baseCurrency"] is string
response["data"]["openOrders"][]["quoteCurrency"] is string
response["data"]["openOrders"][]["symbol"] is string
response["data"]["openOrders"][]["orderId"] is string
response["data"]["openOrders"][]["side"] is string
response["data"]["openOrders"][]["originalAmount"] is string
response["data"]["openOrders"][]["filledAmount"] is string
response["data"]["openOrders"][]["remainingAmount"] is string
response["data"]["openOrders"][]["originalPrice"] is string
response["data"]["openOrders"][]["created"] is uint64
response["data"]["openOrders"][]["lockedCurrency"] is string
response["data"]["openOrders"][]["lockedAmount"] is string

member count of response["data"] = 1
size of response["data"]["openOrders"] is greater than 0
member count of response["data"]["openOrders"][] = 12)";
    testData.actualResult.clear();

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

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
    if(!successResponseChecker(response)){
        result = false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        result = false;
    }
    else if(!(respDoc["data"]["openOrders"].Size() > 0)){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if(!memberCountChecker(openorder, 12)){
            result = false;
        }
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

bool TC_BinanceSpot_fetchTradingFee_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTradingFee";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fees"] is array
response["data"]["fees"][]["baseCurrency"] is string
response["data"]["fees"][]["quoteCurrency"] is string
response["data"]["fees"][]["symbol"] is string
response["data"]["fees"][]["makerFee"] is string
response["data"]["fees"][]["takerFee"] is string

member count of response["data"] = 1
size of response["data"]["fees"] is greater than 0
member count of response["data"]["fees"][] = 5)";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchTradingFee("{}");
        
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(!respDoc["data"]["fees"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["fees"].Size() > 0)){
        return false;
    }

    for(const auto& fee : respDoc["data"]["fees"].GetArray()){
        if(!fee["baseCurrency"].IsString()){
            return false;
        }
        else if(!fee["quoteCurrency"].IsString()){
            return false;
        }
        else if(!fee["symbol"].IsString()){
            return false;
        }
        else if(!fee["makerFee"].IsString()){
            return false;
        }
        else if(!fee["takerFee"].IsString()){
            return false;
        }
        else if(!memberCountChecker(fee, 5)){
            return false;
        }
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTradingFee_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTradingFee";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fees"] is array
response["data"]["fees"][]["baseCurrency"] = "BTC"
response["data"]["fees"][]["quoteCurrency"] = "USDT"
response["data"]["fees"][]["symbol"] = "BTCUSDT"
response["data"]["fees"][]["makerFee"] is string
response["data"]["fees"][]["takerFee"] is string

member count of response["data"] = 1
size of response["data"]["fees"] is 1
member count of response["data"]["fees"][] = 5)";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT"})";
    std::string response = client.fetchTradingFee(input);
        
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(!respDoc["data"]["fees"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["fees"].Size() != 1){
        return false;
    }

    for(const auto& fee : respDoc["data"]["fees"].GetArray()){
        if(!fee["baseCurrency"].IsString()){
            return false;
        }
        else if(!fee["quoteCurrency"].IsString()){
            return false;
        }
        else if(!fee["symbol"].IsString()){
            return false;
        }
        else if(!fee["makerFee"].IsString()){
            return false;
        }
        else if(!fee["takerFee"].IsString()){
            return false;
        }
        else if(!memberCountChecker(fee, 5)){
            return false;
        }
    }
    return true;

    TC_END
}

static const std::string getCandleIntervalCandidatesExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"intervals":["12hour","15min","1day","1hour","1min","1month","1week","2hour","30min","3day","3min","4hour","5min","6hour","8hour"]}})";

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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["markets"][]["baseCurrency"]:string
response["data"]["markets"][]["quoteCurrency"]:string
response["data"]["markets"][]["symbol"]:string

member count of response["data"] = 1
size of response["data"]["markets"] is greater than 10
member count of response["data"]["markets"][] = 3)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets("{}");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(respDoc["data"]["markets"].Size() == 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(!(respDoc["data"]["markets"].Size() > 10)){
        return false;
    }

    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!memberCountChecker(market, 3)){
            return false;
        }
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["markets"][]["baseCurrency"]:string
response["data"]["markets"][]["quoteCurrency"]:string
response["data"]["markets"][]["symbol"]:string

member count of response["data"] = 1
member count of response["data"]["markets"][] = 3
size of response["data"]["markets"] is 1)";

    OneXAPI::Binance::Spot client(std::string(R"({"accessKey":")") + BINANCE_SPOT_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_SPOT_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets(R"({"baseCurrency":"bTC","quoteCurrency":"usDT"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(respDoc["data"]["markets"].Size() != 1){
        return false;
    }

    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!memberCountChecker(market, 3)){
            return false;
        }
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
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchTicker(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTicker_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["openTime"]:uint64
response["data"]["openPrice"]:string
response["data"]["closePrice"]:string
response["data"]["lowPrice"]:string
response["data"]["highPrice"]:string
response["data"]["baseVolume"]:string
response["data"]["quoteVolume"]:string

member count of response["data"] = 11)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 11)){
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

bool TC_BinanceSpot_fetchTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 0
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "websocket"
response["data"]["openTime"]:uint64
response["data"]["openPrice"]:string
response["data"]["closePrice"]:string
response["data"]["lowPrice"]:string
response["data"]["highPrice"]:string
response["data"]["baseVolume"]:string
response["data"]["quoteVolume"]:string

member count of response["data"] = 11)";

    OneXAPI::Binance::Spot client;

    client.subscribeTicker(R"({"market":[{"baseCurrency":"bTc","quoteCurrency":"USdt"}]})");
    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 11)){
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
    else if(std::string("websocket").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["openTime"].IsUint64() || !respDoc["data"]["openPrice"].IsString() || !respDoc["data"]["closePrice"].IsString() || !respDoc["data"]["lowPrice"].IsString() ||
        !respDoc["data"]["highPrice"].IsString() || !respDoc["data"]["baseVolume"].IsString() || !respDoc["data"]["quoteVolume"].IsString()){
        return false;
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchTicker_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["openTime"]:uint64
response["data"]["openPrice"]:string
response["data"]["closePrice"]:string
response["data"]["lowPrice"]:string
response["data"]["highPrice"]:string
response["data"]["baseVolume"]:string
response["data"]["quoteVolume"]:string

member count of response["data"] = 11)";

    OneXAPI::Binance::Spot client;

    client.subscribeTicker(R"({"market":[{"baseCurrency":"bTc","quoteCurrency":"USdt"}]})");
    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","forceRestApi":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 11)){
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
    testData.expectedResult = R"({{"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderbook(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderbook_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["timestamp"]:uint64
response["data"]["bids"][]["price"]:string
response["data"]["bids"][]["size"]:string
response["data"]["asks"][]["price"]:string
response["data"]["asks"][]["size"]:string

member count of response["data"] = 7
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 7)){
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
        if(!memberCountChecker(bid, 2)){
            return false;
        }
        else if(!bid["price"].IsString() || !bid["size"].IsString()){
            return false;
        }
    }
    for(const auto& ask : respDoc["data"]["asks"].GetArray()){
        if(!memberCountChecker(ask, 2)){
            return false;
        }
        else if(!ask["price"].IsString() || !ask["size"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 0
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "websocket"
response["data"]["timestamp"]:uint64
response["data"]["bids"][]["price"]:string
response["data"]["bids"][]["size"]:string
response["data"]["asks"][]["price"]:string
response["data"]["asks"][]["size"]:string

member count of response["data"] = 7
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Spot client;

    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"bTc","quoteCurrency":"USdt"}]})");
    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 7)){
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
    else if(std::string("websocket").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["timestamp"].IsUint64()){
        return false;
    }
    else if(respDoc["data"]["bids"].Size() == 0 || respDoc["data"]["asks"].Size() == 0){
        return false;
    }
    for(const auto& bid : respDoc["data"]["bids"].GetArray()){
        if(!memberCountChecker(bid, 2)){
            return false;
        }
        else if(!bid["price"].IsString() || !bid["size"].IsString()){
            return false;
        }
    }
    for(const auto& ask : respDoc["data"]["asks"].GetArray()){
        if(!memberCountChecker(ask, 2)){
            return false;
        }
        else if(!ask["price"].IsString() || !ask["size"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchOrderbook_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["timestamp"]:uint64
response["data"]["bids"][]["price"]:string
response["data"]["bids"][]["size"]:string
response["data"]["asks"][]["price"]:string
response["data"]["asks"][]["size"]:string

member count of response["data"] = 7
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Spot client;

    client.subscribeOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","forceRestApi":true})");
    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 7)){
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
        if(!memberCountChecker(bid, 2)){
            return false;
        }
        else if(!bid["price"].IsString() || !bid["size"].IsString()){
            return false;
        }
    }
    for(const auto& ask : respDoc["data"]["asks"].GetArray()){
        if(!memberCountChecker(ask, 2)){
            return false;
        }
        else if(!ask["price"].IsString() || !ask["size"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchCandleHistory_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().fetchCandleHistory";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_fetchCandleHistory_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Spot().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:uint64
response["data"]["baseCurrency"]:string
response["data"]["quoteCurrency"]:string
response["data"]["symbol"]:string
response["data"]["candles"][]["timestamp"]:uint64
response["data"]["candles"][]["openPrice"]:string
response["data"]["candles"][]["closePrice"]:string
response["data"]["candles"][]["highPrice"]:string
response["data"]["candles"][]["lowPrice"]:string
response["data"]["candles"][]["baseVolume"]:string
response["data"]["candles"][]["quoteVolume"]:string

member count of response["data"] = 4
member count of response["data"]["candles"][] = 7
size of response["data"]["candles"][] is greater than 50)";

    OneXAPI::Binance::Spot client;

    std::string twoHrBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch()/1000 - 7200);
    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","interval":"1min","startTime":)" + twoHrBeforeFromNow + R"(})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(!respDoc["requestedApiCount"].IsUint()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 4)){
        return false;
    }
    else if(!respDoc["data"]["baseCurrency"].IsString() || 
        !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["symbol"].IsString()){
        return false;
    }
    else if(!(respDoc["data"]["candles"].Size() > 50)){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if(!memberCountChecker(candle, 7)){
            return false;
        }
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
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:uint64
response["data"]["baseCurrency"]:string
response["data"]["quoteCurrency"]:string
response["data"]["symbol"]:string
response["data"]["candles"][]["timestamp"]:uint64
response["data"]["candles"][]["openPrice"]:string
response["data"]["candles"][]["closePrice"]:string
response["data"]["candles"][]["highPrice"]:string
response["data"]["candles"][]["lowPrice"]:string
response["data"]["candles"][]["baseVolume"]:string
response["data"]["candles"][]["quoteVolume"]:string

member count of response["data"] = 4
member count of response["data"]["candles"][] = 7
size of response["data"]["candles"][] is greater than 50)";

    OneXAPI::Binance::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","interval":"1min","startTime":1656042045,"endTime":1656063182,"fetchInterval":900})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(!respDoc["requestedApiCount"].IsUint()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 4)){
        return false;
    }
    else if(!respDoc["data"]["baseCurrency"].IsString() || 
        !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["symbol"].IsString()){
        return false;
    }
    else if(!(respDoc["data"]["candles"].Size() > 50)){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if(!memberCountChecker(candle, 7)){
            return false;
        }
        if( !candle["timestamp"].IsUint64() || !candle["openPrice"].IsString() || !candle["closePrice"].IsString() || !candle["highPrice"].IsString() ||
            !candle["lowPrice"].IsString() || !candle["baseVolume"].IsString() || !candle["quoteVolume"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

static const std::string getSubscribingTickersExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"tickers":[]}})";

bool TC_BinanceSpot_getSubscribingTickers_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingTickers_2(testDataType& testData){
    TC_BEGIN
    
    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingTickers_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingTickers_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_getSubscribingTickers_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"ETHBTC"}]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})");
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}],requestTimeout:0})");

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static const std::string getSubscribingOrderbooksExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[]}})";

bool TC_BinanceSpot_getSubscribingOrderbooks_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingOrderbooks_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingOrderbooks_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_getSubscribingOrderbooks_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_getSubscribingOrderbooks_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"ETHBTC"}]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})");
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}],requestTimeout:0})");

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.subscribeTicker();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";

    for(int i = 0; i < 10; i++){
        OneXAPI::Binance::Spot client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeTicker(input);

        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        response = client.getSubscribingTickers();

        testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}]}})");
        testData.actualResult.append("\n").append(response);

        if(testData.actualResult.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceSpot_subscribeTicker_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}],"subscribeFailed":[]}})");
    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
    response = client.subscribeTicker(input);

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);
    
    client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}],"requestTimeout":0})");
    
    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"(if subscribeOrderbook() requestedApiCount is N
else requestedApiCount is 0

size of response["data"]["subscribed"] greater than 50

member count of response["data"] is 2
response["data"]["subscribed"] type is array
response["data"]["subscribeFailed"] type is array

member count of response["data"]["subscribed"][] is 3
member count of response["data"]["subscribeFailed"][] is 3

N is request market size

{"success":true,"requestedApiCount":0,"data":{"funcName":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},.....................................]}}

Element in subscribed list of result 1 must be in funcName list
Element in subscribeFailed list of result 1 must not be in funcName list

member count of response["data"] is 1
response["data"]["funcName"] type is array
member count of response["data"]["funcName"][] is 3

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks)";

    OneXAPI::Binance::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "YFI", "PAXG", "ETH", "YFII", "MKR", "BIFI", "BNB", "AUTO", "BNX",
    "QNT", "XMR", "BCH", "GNO", "KP3R", "AAVE", "QUICK", "COMP", "EGLD", "ILV",
    "LTC", "ZEC", "DASH", "KSM", "GMX", "FARM", "SOL", "DCR", "ETC", "FTT",
    "ALCX", "BTG", "MLN", "ENS", "WNXM", "AVAX", "NMR", "TRB", "SANTOS", "ZEN",
    "ATOM", "AXS", "MOVR", "LPT", "AR", "BTCST", "WING", "NEO", "LINK", "PSG",
    "REP", "DOT", "UNI", "CVX", "AUCTION", "UNFI", "CITY", "TORN", "ICP", "FIL"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!respDoc["data"]["subscribed"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 50)){
        return false;
    }
    else if(!respDoc["data"]["subscribeFailed"].IsArray()){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : respDoc["data"]["subscribed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : respDoc["data"]["subscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(respDoc["data"]["tickers"].Size() != subscribedList.size()){
        return false;
    }

    for(const auto& ticker : respDoc["data"]["tickers"].GetArray()){
        std::string symbol = ticker["symbol"].GetString();
        if(!memberCountChecker(ticker, 3)){
            return false;
        }

        if(IN_VECTOR(subscribedList, symbol)){
            continue;
        }
        else{
            return false;
        }

        if(IN_VECTOR(subscribeFailedList, symbol)){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    
    TC_END
}

bool TC_BinanceSpot_subscribeTicker_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[]}})");
    response = client.subscribeTicker(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.unsubscribeTicker();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}],"reconnect":true})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_7(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}.........................],"unsubscribeFailed":[]}}

unsubscribe request same as pre-condition subscribe request

member count of response["data"] is 2
response["data"]["unsubscribed"] type is array
response["data"]["unsubscribeFailed"] type is array

member count of response["data"]["unsubscribed"][] is 3
member count of response["data"]["unsubscribeFailed"][] is 3

{"success":true,"requestedApiCount":0,"data":{"funcName":[]}}

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks)";

    OneXAPI::Binance::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "YFI", "PAXG", "ETH", "YFII", "MKR", "BIFI", "BNB", "AUTO", "BNX",
        "QNT", "XMR", "BCH", "GNO", "KP3R", "AAVE", "QUICK", "COMP", "EGLD", "ILV",
        "LTC", "ZEC", "DASH", "KSM", "GMX", "FARM", "SOL", "DCR", "ETC", "FTT",
        "ALCX", "BTG", "MLN", "ENS", "WNXM", "AVAX", "NMR", "TRB", "SANTOS", "ZEN",
        "ATOM", "AXS", "MOVR", "LPT", "AR", "BTCST", "WING", "NEO", "LINK", "PSG",
        "REP", "DOT", "UNI", "CVX", "AUCTION", "UNFI", "CITY", "TORN", "ICP", "FIL"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);
    if(!successResponseChecker(response)){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 50)){
        return false;
    }

    response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);
    
    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!respDoc["data"]["unsubscribed"].IsArray()){
        return false;
    }
    else if(!respDoc["data"]["unsubscribeFailed"].IsArray()){
        return false;
    }
    
    for(const auto& object : respDoc["data"]["unsubscribed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
    }

    for(const auto& object : respDoc["data"]["unsubscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
    }

    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    std::string getSubscribingExpectedRes = R"({"success":true,"requestedApiCount":0,"data":{"tickers":[]}})";

    if(response.compare(getSubscribingExpectedRes) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;
    
    TC_END
}

bool TC_BinanceSpot_unsubscribeTicker_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[]}})");
    response = client.unsubscribeTicker(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.subscribeOrderbook();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";

    for(int i = 0; i < 10; i++){
        OneXAPI::Binance::Spot client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeOrderbook(input);

        testData.expectedResult = R"({"success":true,"requestedApiCount":1,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        response = client.getSubscribingOrderbooks();

        testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}]}})");
        testData.actualResult.append("\n").append(response);

        if(testData.actualResult.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}],"subscribeFailed":[]}})");
    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
    response = client.subscribeOrderbook(input);

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","symbol":"XRPUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);
    
    client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}],"requestTimeout":0})");
    
    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"(if subscribeOrderbook() requestedApiCount is N
else requestedApiCount is 0

size of response["data"]["subscribed"] greater than 50

member count of response["data"] is 2
response["data"]["subscribed"] type is array
response["data"]["subscribeFailed"] type is array

member count of response["data"]["subscribed"][] is 3
member count of response["data"]["subscribeFailed"][] is 3

N is request market size

{"success":true,"requestedApiCount":0,"data":{"funcName":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},.....................................]}}

Element in subscribed list of result 1 must be in funcName list
Element in subscribeFailed list of result 1 must not be in funcName list

member count of response["data"] is 1
response["data"]["funcName"] type is array
member count of response["data"]["funcName"][] is 3

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks)";

    OneXAPI::Binance::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "YFI", "PAXG", "ETH", "YFII", "MKR", "BIFI", "BNB", "AUTO", "BNX",
    "QNT", "XMR", "BCH", "GNO", "KP3R", "AAVE", "QUICK", "COMP", "EGLD", "ILV",
    "LTC", "ZEC", "DASH", "KSM", "GMX", "FARM", "SOL", "DCR", "ETC", "FTT",
    "ALCX", "BTG", "MLN", "ENS", "WNXM", "AVAX", "NMR", "TRB", "SANTOS", "ZEN",
    "ATOM", "AXS", "MOVR", "LPT", "AR", "BTCST", "WING", "NEO", "LINK", "PSG",
    "REP", "DOT", "UNI", "CVX", "AUCTION", "UNFI", "CITY", "TORN", "ICP", "FIL"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != allCurrencys.size()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!respDoc["data"]["subscribed"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 50)){
        return false;
    }
    else if(!respDoc["data"]["subscribeFailed"].IsArray()){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : respDoc["data"]["subscribed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : respDoc["data"]["subscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    else if(respDoc["data"]["orderbooks"].Size() != subscribedList.size()){
        return false;
    }

    for(const auto& orderbook : respDoc["data"]["orderbooks"].GetArray()){
        std::string symbol = orderbook["symbol"].GetString();
        if(!memberCountChecker(orderbook, 3)){
            return false;
        }

        if(IN_VECTOR(subscribedList, symbol)){
            continue;
        }
        else{
            return false;
        }

        if(IN_VECTOR(subscribeFailedList, symbol)){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":1,"data":{"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceSpot_subscribeOrderbook_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[]}})");
    response = client.subscribeOrderbook(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string response = client.unsubscribeOrderbook();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "{}";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}],"reconnect":true})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_7(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"}.........................],"unsubscribeFailed":[]}}

unsubscribe request same as pre-condition subscribe request

member count of response["data"] is 2
response["data"]["unsubscribed"] type is array
response["data"]["unsubscribeFailed"] type is array

member count of response["data"]["unsubscribed"][] is 3
member count of response["data"]["unsubscribeFailed"][] is 3

{"success":true,"requestedApiCount":0,"data":{"funcName":[]}}

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks)";

    OneXAPI::Binance::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "YFI", "PAXG", "ETH", "YFII", "MKR", "BIFI", "BNB", "AUTO", "BNX",
        "QNT", "XMR", "BCH", "GNO", "KP3R", "AAVE", "QUICK", "COMP", "EGLD", "ILV",
        "LTC", "ZEC", "DASH", "KSM", "GMX", "FARM", "SOL", "DCR", "ETC", "FTT",
        "ALCX", "BTG", "MLN", "ENS", "WNXM", "AVAX", "NMR", "TRB", "SANTOS", "ZEN",
        "ATOM", "AXS", "MOVR", "LPT", "AR", "BTCST", "WING", "NEO", "LINK", "PSG",
        "REP", "DOT", "UNI", "CVX", "AUCTION", "UNFI", "CITY", "TORN", "ICP", "FIL"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);
    if(!successResponseChecker(response)){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 50)){
        return false;
    }

    response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);
    
    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 0){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!respDoc["data"]["unsubscribed"].IsArray()){
        return false;
    }
    else if(!respDoc["data"]["unsubscribeFailed"].IsArray()){
        return false;
    }
    
    for(const auto& object : respDoc["data"]["unsubscribed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
    }

    for(const auto& object : respDoc["data"]["unsubscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 3)){
            return false;
        }
    }

    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    std::string getSubscribingExpectedRes = R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[]}})";

    if(response.compare(getSubscribingExpectedRes) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceSpot_unsubscribeOrderbook_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[]}})");
    response = client.unsubscribeOrderbook(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}