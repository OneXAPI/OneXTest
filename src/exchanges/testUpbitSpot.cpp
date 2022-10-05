#include "../../include/exchanges/testUpbitSpot.hpp"
#include "../../include/testDefine.hpp"
#include "../../include/testTool.hpp"
#include <iostream>

bool TC_UpbitSpot_Object_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Upbit::Spot stackClient;
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot();

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_UpbitSpot_Object_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Upbit::Spot stackClient("");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;
    
    TC_END
}

bool TC_UpbitSpot_Object_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Upbit::Spot stackClient("{}");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("{}");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_UpbitSpot_Object_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = "No Error";

    OneXAPI::Upbit::Spot stackClient("fnq543wb");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("fnq543wb");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_UpbitSpot_Object_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "")";

    OneXAPI::Upbit::Spot stackClient(R"({"accessKey":"Test Access Key"})");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot(R"({"accessKey":"Test Access Key"})");

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

bool TC_UpbitSpot_Object_6(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = R"(accessKey : "", secretKey : "Test Secret Key")";

    OneXAPI::Upbit::Spot stackClient(R"({"secretKey":"Test Secret Key"})");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot(R"({"secretKey":"Test Secret Key"})");

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

bool TC_UpbitSpot_Object_7(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "Test Secret Key")";

    OneXAPI::Upbit::Spot stackClient(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");
    OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");

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

static const std::string getConfigExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"exchange":"Upbit","instrument":"Spot","accessKey":"","secretKey":"","restEndpoint":"https://api.upbit.com/v1","publicWebsocketEndpoint":"wss://api.upbit.com/websocket/v1","privateWebsocketEndpoint":"","restRequestTimeout":5000,"websocketConnectTimeout":5000,"websocketIdleTimeout":5000}})";

bool TC_UpbitSpot_getConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Upbit::Spot client;

    std::string response = client.getConfig();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getConfig(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "trashData123@@!%";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_setConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Upbit::Spot client;

    std::string response = client.setConfig("");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_setConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0}})";

    OneXAPI::Upbit::Spot client;

    std::string response = client.setConfig("{}");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_setConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE_TYPE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client;
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

bool TC_UpbitSpot_setConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client;
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

bool TC_UpbitSpot_setConfig_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"requestedKey":"requestedValue"}})";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client;
    std::string input, response;

    std::vector<std::pair<std::string,std::string>> testList = {
        {"accessKey",R"("test access key")"},
        {"secretKey",R"("test secret key")"},
        {"restEndpoint",R"("https://api.upbit.com/v1")"},
        {"publicWebsocketEndpoint",R"("wss://api.upbit.com/websocket/v1")"},
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

static const std::string getEndpointCandidatesExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"restEndpoints":["https://api.upbit.com/v1"],"publicWebsocketEndpoints":["wss://api.upbit.com/websocket/v1"],"privateWebsocketEndpoints":[]}})";

bool TC_UpbitSpot_getEndpointCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;

    std::string response = client.getEndpointCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getEndpointCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getEndpointCandidates_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getEndpointCandidates_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;
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
    {"subscribeBalance", false},
    {"unsubscribeBalance", false},
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

bool TC_UpbitSpot_has_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_has_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().has";
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

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_has_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "el12nlgv@!";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_has_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().has";
    testData.expectedResult.clear();
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_has_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().has";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
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

bool TC_UpbitSpot_getWithdrawRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getWithdrawRoundingRule";
    testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.getWithdrawRoundingRule();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getWithdrawRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getWithdrawRoundingRule";
    testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = R"({})";
    std::string response = client.getWithdrawRoundingRule(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_setWithdrawRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setWithdrawRoundingRule";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"roundingRule":"wrongData"})";
    std::string response = client.setWithdrawRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_setWithdrawRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setWithdrawRoundingRule";
    testData.expectedResult.clear();
    testData.actualResult.clear();
    std::string getCheckStr = "";
    OneXAPI::Upbit::Spot client;
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

bool TC_UpbitSpot_withdraw_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().withdraw";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    std::vector<std::string> testList = {
        R"({"currency":"bTc","address":"0x1345"})",
        R"({"currency":"bTc","amount":1.535478})",
        R"({"address":"fwlnvlwnlkfsd","amount":13384.13541345})"
    };
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_withdraw_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().withdraw";
    std::string findValue1 = R"(METHOD: GET, URL: https://api.upbit.com/v1/withdraws/chance?currency=ADA)";
    std::string findValue2 = R"(METHOD: POST, URL: https://api.upbit.com/v1/withdraws/coin?currency=ADA&amount=134.623436&address=wrongAddress&transaction_type=default, BODYDATA:)";
    testData.expectedResult = findValue1 + "\nand\n" + findValue2;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"aDA","address":"wrongAddress","amount":135.1234358})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_withdraw_3(testDataType& testData){
    TC_BEGIN
    
    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().withdraw";
    std::string findValue1 = R"(METHOD: GET, URL: https://api.upbit.com/v1/withdraws/chance?currency=ADA)";
    std::string findValue2 = R"(METHOD: POST, URL: https://api.upbit.com/v1/withdraws/coin?currency=ADA&amount=135.123436&address=wrongAddress&secondary_address=wrongTag&transaction_type=internal, BODYDATA:)";
    testData.expectedResult = findValue1 + "\nand\n" + findValue2;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"aDA","address":"wrongAddress","tag":"wrongTag","amount":135.1234358,"feeInAmount":false,"internal":true})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_fetchAllCurrencies_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchAllCurrencies";
    testData.expectedResult = R"(response["success"]:true, response["data"]["requestedApiCount"]:1, response["data"]["currencies"][currency]["chains"]:empty array)";

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
        if(currencyPtr->value["chains"].Size() != 0){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchAllCurrencies_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchAllCurrencies";
    testData.expectedResult = R"(response["success"]:true, response["data"]["requestedApiCount"]:1, response["data"]["currencies"][currency]["chains"]:empty array)";

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
        if(currencyPtr->value["chains"].Size() != 0){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchBalance_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["fetchType"]:"rest"
        response["data"]["balance"][currency]["free"]:string response["data"]["balance"][currency]["locked"]:string)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_fetchBalance_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchBalance";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:2 response["data"]["fetchType"]:"rest" 
        response["data"]["balance"][currency]["free"]:string response["data"]["balance"][currency]["locked"]:string 
        and member count of response["data"]["balance"] is 3)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string response = client.fetchBalance(R"({"currencies":["bTc","xRP","eTh"],"zeroBalance":true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 2){
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

bool TC_UpbitSpot_fetchWalletStatus_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchWalletStatus";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"]
        response["data"]["currencies"][currency]["chains"]["chain"] = "" response["data"]["currencies"][currency]["chains"]["withdrawEnable"] is bool
        response["data"]["currencies"][currency]["chains"]["depositEnable"] is bool
        and size of response["data"]["currencies"][currency]["chains"] must be 1)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
        else if(currencyPtr->value["chains"].Size() != 1){
            return false;
        }
        else if(std::string("").compare(currencyPtr->value["chains"][0]["chain"].GetString()) != 0){
            return false;
        }
        else if(!currencyPtr->value["chains"][0]["withdrawEnable"].IsBool()){
            return false;
        }
        else if(!currencyPtr->value["chains"][0]["depositEnable"].IsBool()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_UpbitSpot_fetchWalletStatus_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchWalletStatus";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["currencies"][currency]["chains"]
        response["data"]["currencies"][currency]["chains"]["chain"] = "" response["data"]["currencies"][currency]["chains"]["withdrawEnable"] is bool
        response["data"]["currencies"][currency]["chains"]["depositEnable"] is bool
        size of response["data"]["currencies"] is 1
        and size of response["data"]["currencies"][currency]["chains"] must be 1)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
        else if(currencyPtr->value["chains"].Size() != 1){
            return false;
        }
        else if(std::string("").compare(currencyPtr->value["chains"][0]["chain"].GetString()) != 0){
            return false;
        }
        else if(!currencyPtr->value["chains"][0]["withdrawEnable"].IsBool()){
            return false;
        }
        else if(!currencyPtr->value["chains"][0]["depositEnable"].IsBool()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_UpbitSpot_fetchWithdrawHistory_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchWithdrawHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["withdrawals"]["currency"] is string
        response["data"]["withdrawals"]["amount"] is string response["data"]["withdrawals"]["fee"] is string response["data"]["withdrawals"]["orderId"] is string
        response["data"]["withdrawals"]["txid"] is string response["data"]["withdrawals"]["status"] is string response["data"]["withdrawals"]["created"] is uint64)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
    else if(respDoc["data"]["withdrawals"].Size() == 0){
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

bool TC_UpbitSpot_fetchWithdrawHistory_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchWithdrawHistory";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/withdraws?currency=MATIC&uuids=testOrderId&txids=testTxId)";
    testData.expectedResult = findValue;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"mATic","orderId":"testOrderId","txid":"testTxId","startTime":132123534,"endTime":1125615123})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_fetchDepositHistory_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchDepositHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["deposits"]["currency"] is string
        response["data"]["deposits"]["amount"] is string response["data"]["deposits"]["fee"] is string response["data"]["deposits"]["orderId"] is string
        response["data"]["deposits"]["txid"] is string response["data"]["deposits"]["status"] is string response["data"]["deposits"]["created"] is uint64)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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
    else if(respDoc["data"]["deposits"].Size() == 0){
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

bool TC_UpbitSpot_fetchDepositHistory_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchDepositHistory";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/deposits?currency=MATIC&uuids=testOrderId&txids=testTxId)";
    testData.expectedResult = findValue;            
    testData.actualResult.clear();
    std::string input = R"({"currency":"mATic","orderId":"testOrderId","txid":"testTxId","startTime":132123534,"endTime":1125615123})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_fetchDepositAddress_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchDepositAddress";
    testData.expectedResult = R"(rresponse["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["addresses"][currency] is array
        response["data"]["addresses"][currency][0]["chain"] : "" response["data"]["addresses"][currency][0]["address"] is string
        response["data"]["addresses"][currency][0]["tag"] is string
        size of response["data"]["addresses"][currency] is greater than 0)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositAddress(R"({})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 1){
        return false;
    }
    else if(respDoc["data"]["addresses"].MemberCount() == 0){
        return false;
    }
    for(auto addressPtr = respDoc["data"]["addresses"].MemberBegin(); addressPtr != respDoc["data"]["addresses"].MemberEnd(); addressPtr++){
        if(!addressPtr->name.IsString()){
            return false;
        }
        else if(!addressPtr->value.IsArray()){
            return false;
        }
        else if(addressPtr->value.Size() != 1){
            return false;
        }
        else if(std::string("").compare(addressPtr->value[0]["chain"].GetString()) != 0){
            return false;
        }
        else if(!addressPtr->value[0]["address"].IsString()){
            return false;
        }
        else if(!addressPtr->value[0]["tag"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_UpbitSpot_fetchDepositAddress_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchDepositAddress";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["addresses"]["BTC"] is array
        response["data"]["addresses"]["BTC"][0]["chain"] : "" response["data"]["addresses"]["BTC"][0]["address"] is string response["data"]["addresses"]["BTC"][0]["tag"] is string
        member count of response["data"]["addresses"] must be 1
        size of response["data"]["addresses"][currency] is 1)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string response = client.fetchDepositAddress(R"({"currency":"Btc"})");
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
    else if(std::string("").compare(respDoc["data"]["addresses"]["BTC"][0]["chain"].GetString()) != 0){
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

bool TC_UpbitSpot_isDepositCompleted_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().isDepositCompleted";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string response = client.isDepositCompleted("{}");

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_isDepositCompleted_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().isDepositCompleted";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/deposits?txids=testTxid)";
    testData.expectedResult = findValue + R"(  and {"success":true,"data":{"requestedApiCount":1,"isDepositCompleted":false})";            
    testData.actualResult.clear();
    std::string input = R"({"txid":"testTxid"})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_isDepositCompleted_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().isDepositCompleted";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/deposits?currency=SOL)";
    testData.expectedResult = findValue + R"(  and {"success":true,"data":{"requestedApiCount":1,"isDepositCompleted":false})";            
    testData.actualResult.clear();
    std::string input = R"({"currency":"sOl","amount":35.213843,"since":1656044045154})";
    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

static const std::string subscribeBalanceExpectedResult = R"({"success":false,"data":{"errorType":"NOT_SUPPORTED_API","errorMsg":"~~~"}})";

bool TC_UpbitSpot_subscribeBalance_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = subscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.subscribeBalance();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeBalance_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = subscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.subscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeBalance_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = subscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeBalance_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = subscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

static const std::string unsubscribeBalanceExpectedResult = R"({"success":false,"data":{"errorType":"NOT_SUPPORTED_API","errorMsg":""}})";

bool TC_UpbitSpot_unsubscribeBalance_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = unsubscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.unsubscribeBalance();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeBalance_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = unsubscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.unsubscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeBalance_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = unsubscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.unsubscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeBalance_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = unsubscribeBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeBalance(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
        return true;
    }

    TC_END
}

static const std::string isSubscribingBalanceExpectedResult = R"({"success":true,"data":{"isSubscribing":false}})";

bool TC_UpbitSpot_isSubscribingBalance_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = isSubscribingBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.isSubscribingBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_isSubscribingBalance_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = isSubscribingBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.isSubscribingBalance(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_isSubscribingBalance_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = isSubscribingBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.isSubscribingBalance(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_isSubscribingBalance_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
    testData.expectedResult = isSubscribingBalanceExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.isSubscribingBalance(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static const std::string getOrderRoundingRuleExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})";

bool TC_UpbitSpot_getOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.getOrderRoundingRule();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getOrderRoundingRule(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_setOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setOrderRoundingRule";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"limitBuyBaseAmount":"wrongData"})";
    std::string response = client.setOrderRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_setOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().setOrderRoundingRule";
    testData.expectedResult.clear();
    testData.actualResult.clear();
    std::string getCheckStr = "";
    std::string getExpectedResult = "";
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"ceil","limitBuyBaseAmount":"ceil","limitSellPrice":"ceil","limitSellBaseAmount":"ceil","marketBuyQuoteAmount":"ceil","marketSellBaseAmount":"ceil"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"floor","limitBuyBaseAmount":"floor","limitSellPrice":"floor","limitSellBaseAmount":"floor","marketBuyQuoteAmount":"floor","marketSellBaseAmount":"floor"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"data":{"requestedApiCount":0,"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyQuoteAmount":"round","marketSellBaseAmount":"round"}})").append("\n");
    OneXAPI::Upbit::Spot client;
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

bool TC_UpbitSpot_orderLimitBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitBuy";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.orderLimitBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_orderLimitBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=bid&volume=35.13568934&price=13502000&ord_type=limit)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","price":13501545.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderLimitBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=bid&volume=35.13568934&price=13969000&ord_type=limit&identifier=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","price":13501545.1234358,"baseAmount":35.135689342158,"clientOrderId":"testId","amplifier":1.0346})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderLimitSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitSell";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.orderLimitSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_orderLimitSell_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=ask&volume=35.13568934&price=13502000&ord_type=limit)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","price":13501545.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderLimitSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=ask&volume=35.13568934&price=13008000&ord_type=limit&identifier=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","price":13501545.1234358,"baseAmount":35.135689342158,"clientOrderId":"testId","amplifier":0.96348})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderMarketBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketBuy";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.orderMarketBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_orderMarketBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=bid&price=38951381&ord_type=price)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","quoteAmount":38951381.391351334})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderMarketBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=bid&price=38951381&ord_type=price&identifier=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","quoteAmount":38951381.391351334,"clientOrderId":"testId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderMarketSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketSell";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.orderMarketSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_orderMarketSell_2(testDataType& testData){TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=ask&volume=83.13384948&ord_type=market)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","baseAmount":83.1338494835})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderMarketSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://api.upbit.com/v1/orders?market=KRW-BTC&side=ask&volume=83.13384948&ord_type=market&identifier=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw","baseAmount":83.1338494835,"clientOrderId":"testId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderCancel_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().orderCancel";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.orderCancel("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_orderCancel_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://api.upbit.com/v1/order?uuid=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"orderId":"testOrderId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_orderCancel_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://api.upbit.com/v1/order?identifier=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"clientOrderId":"testClientOrderId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_fetchOrderInfo_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchOrderInfo("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchOrderInfo_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/order?uuid=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"orderId":"testOrderId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_fetchOrderInfo_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://api.upbit.com/v1/order?identifier=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"clientOrderId":"testClientOrderId"})";
    OneXAPI::Upbit::Spot client;

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

bool TC_UpbitSpot_fetchOrderInfo_4(testDataType& testData){
    TC_BEGIN
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderInfo";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["baseCurrency"] is string response["data"]["quoteCurrency"] is string
        response["data"]["symbol"] is string response["data"]["orderId"] = orderId response["data"]["clientOrderId"] is string response["data"]["side"] = "buy" or "sell" 
        response["data"]["originalAmount"] is string response["data"]["filledAmount"] is string response["data"]["remainingAmount"] is string response["data"]["originalPrice"] is string 
        response["data"]["avgFillPrice"] is string response["data"]["created"] is uint64 response["data"]["feeCurrency"] is string
        response["data"]["feeAmount"] is string response["data"]["status"] is string response["data"]["fills"] is an empty array)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"kRw"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"kRw","price":)" + bid + R"(,"baseAmount":30.00,"amplifier":0.96})");
    rapidjson::Document orderLimitBuyDoc;
    OneXAPI::Internal::Util::parseJson(orderLimitBuyDoc, orderLimitBuy);
    if(!orderLimitBuyDoc["success"].GetBool()){
        return false;
    }
    std::string orderId = orderLimitBuyDoc["data"]["orderId"].GetString();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string input = R"({"orderId":")" + orderId + R"("})";
    std::string response = client.fetchOrderInfo(input);
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

bool TC_UpbitSpot_fetchOpenOrders_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["openOrders"][]["baseCurrency"] is string
        response["data"]["openOrders"][]["quoteCurrency"] is string response["data"]["openOrders"][]["symbol"] is string response["data"]["openOrders"][]["orderId"] is string
        response["data"]["openOrders"][]["side"] is string response["data"]["openOrders"][]["originalAmount"] is string response["data"]["openOrders"][]["filledAmount"] is string
        response["data"]["openOrders"][]["remainingAmount"] is string response["data"]["openOrders"][]["originalPrice"] is string response["data"]["openOrders"][]["status"] is uint64
        response["data"]["openOrders"][]["lockedCurrency"] is string response["data"]["openOrders"][]["lockedAmount"] is string)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"kRw"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"kRw","price":)" + bid + R"(,"baseAmount":30.00,"amplifier":0.96})");
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

    std::string input = R"({"orderId":")" + orderId + R"("})";
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

bool TC_UpbitSpot_fetchOpenOrders_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["openOrders"][]["baseCurrency"] is string
        response["data"]["openOrders"][]["quoteCurrency"] is string response["data"]["openOrders"][]["symbol"] is string response["data"]["openOrders"][]["orderId"] is string
        response["data"]["openOrders"][]["side"] is string response["data"]["openOrders"][]["originalAmount"] is string response["data"]["openOrders"][]["filledAmount"] is string
        response["data"]["openOrders"][]["remainingAmount"] is string response["data"]["openOrders"][]["originalPrice"] is string response["data"]["openOrders"][]["lockedCurrency"] is string
        response["data"]["openOrders"][]["lockedAmount"] is string response["data"]["openOrders"][]["status"] is string)";
    testData.actualResult.clear();

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string orderbook = client.fetchOrderbook(R"({"baseCurrency":"XRP","quoteCurrency":"kRw"})");
    rapidjson::Document orderbookDoc;
    OneXAPI::Internal::Util::parseJson(orderbookDoc, orderbook);
    if(!orderbookDoc["success"].GetBool()){
        return false;
    }
    std::string bid = orderbookDoc["data"]["bids"][0]["price"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string orderLimitBuy = client.orderLimitBuy(R"({"baseCurrency":"XRP","quoteCurrency":"kRw","price":)" + bid + R"(,"baseAmount":30.00,"amplifier":0.96})");
    rapidjson::Document orderLimitBuyDoc;
    OneXAPI::Internal::Util::parseJson(orderLimitBuyDoc, orderLimitBuy);
    if(!orderLimitBuyDoc["success"].GetBool()){
        return false;
    }
    std::string orderId = orderLimitBuyDoc["data"]["orderId"].GetString();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchOpenOrders(R"({"baseCurrency":"xRP","quoteCurrency":"KRw","side":"buy"})");
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

    std::string input = R"({"orderId":")" + orderId + R"("})";
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

bool TC_UpbitSpot_fetchTradingFee_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTradingFee";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchTradingFee(R"({"baseCurrency":"bTC"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchTradingFee_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTradingFee";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":1,"fees":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC","makerFee":"0.0005","takerFee":"0.0005"}]}})";

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"KRw"})";
    std::string response = client.fetchTradingFee(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static const std::string getCandleIntervalCandidatesExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"intervals":["10min","15min","1day","1hour","1min","1month","1week","30min","3min","4hour","5min"]}})";

bool TC_UpbitSpot_getCandleIntervalCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;

    std::string response = client.getCandleIntervalCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getCandleIntervalCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getCandleIntervalCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_fetchMarkets_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["markets"][]["baseCurrency"]:string
        response["data"]["markets"][]["quoteCurrency"]:string response["data"]["markets"][]["symbol"]:string)";

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

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

bool TC_UpbitSpot_fetchMarkets_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["markets"][]["baseCurrency"]:string
        response["data"]["markets"][]["quoteCurrency"]:string response["data"]["markets"][]["symbol"]:string)";

    OneXAPI::Upbit::Spot client(std::string(R"({"accessKey":")") + UPBIT_ACCESS_KEY + R"(", "secretKey":")" + UPBIT_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets(R"({"baseCurrency":"bTC","quoteCurrency":"KrW"})");
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

bool TC_UpbitSpot_fetchTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchTicker(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchTicker_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "rest" response["data"]["openTime"]:uint64 response["data"]["openPrice"]:string
        response["data"]["closePrice"]:string response["data"]["lowPrice"]:string response["data"]["highPrice"]:string response["data"]["baseVolume"]:string
        response["data"]["quoteVolume"]:string)";

    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
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
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "orderbook" response["data"]["openTime"]:uint64 response["data"]["openPrice"]:string
        response["data"]["closePrice"]:string response["data"]["lowPrice"]:string response["data"]["highPrice"]:string response["data"]["baseVolume"]:string
        response["data"]["quoteVolume"]:string)";

    OneXAPI::Upbit::Spot client;

    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})");
    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 0){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchTicker_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchTicker";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "rest" response["data"]["openTime"]:uint64 response["data"]["openPrice"]:string
        response["data"]["closePrice"]:string response["data"]["lowPrice"]:string response["data"]["highPrice"]:string response["data"]["baseVolume"]:string
        response["data"]["quoteVolume"]:string)";

    OneXAPI::Upbit::Spot client;

    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})");
    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"kRw","forceRestApi":true})");
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
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchOrderbook(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchOrderbook_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "rest" response["data"]["timestamp"]:uint64 response["data"]["bids"][]["price"]:string
        response["data"]["bids"][]["size"]:string response["data"]["asks"][]["price"]:string response["data"]["asks"][]["size"]:string)";

    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
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
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "rest" response["data"]["timestamp"]:uint64 response["data"]["bids"][]["price"]:string
        response["data"]["bids"][]["size"]:string response["data"]["asks"][]["price"]:string response["data"]["asks"][]["size"]:string)";

    OneXAPI::Upbit::Spot client;

    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})");
    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!respDoc["success"].GetBool()){
        return false;
    }
    else if(respDoc["data"]["requestedApiCount"].GetUint64() != 0){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchOrderbook_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"] = 1 response["data"]["baseCurrency"] = "BTC" response["data"]["quoteCurrency"] = "KRW"
        response["data"]["symbol"] = "KRW-BTC" response["data"]["fetchType"] = "rest" response["data"]["timestamp"]:uint64 response["data"]["bids"][]["price"]:string
        response["data"]["bids"][]["size"]:string response["data"]["asks"][]["price"]:string response["data"]["asks"][]["size"]:string)";

    OneXAPI::Upbit::Spot client;

    client.subscribeOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"kRw","forceRestApi":true})");
    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
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
    else if(std::string("KRW").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("KRW-BTC").compare(respDoc["data"]["symbol"].GetString()) != 0){
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

bool TC_UpbitSpot_fetchCandleHistory_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().fetchCandleHistory";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"kRw"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return false;
    }
    return true;

    TC_END
}

bool TC_UpbitSpot_fetchCandleHistory_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:uint64 response["data"]["baseCurrency"]:string response["data"]["quoteCurrency"]:string
        response["data"]["symbol"]:string response["data"]["candles"][]["timestamp"]:uint64 response["data"]["candles"][]["openPrice"]:string response["data"]["candles"][]["closePrice"]:string
        response["data"]["candles"][]["highPrice"]:string response["data"]["candles"][]["lowPrice"]:string response["data"]["candles"][]["baseVolume"]:string response["data"]["candles"][]["quoteVolume"]:string)";

    OneXAPI::Upbit::Spot client;

    std::string twoHrBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch()/1000 - 7200);
    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"kRw","interval":"1min","startTime":)" + twoHrBeforeFromNow + R"(})");
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

bool TC_UpbitSpot_fetchCandleHistory_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Upbit::Spot().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:uint64 response["data"]["baseCurrency"]:string response["data"]["quoteCurrency"]:string
        response["data"]["symbol"]:string response["data"]["candles"][]["timestamp"]:uint64 response["data"]["candles"][]["openPrice"]:string response["data"]["candles"][]["closePrice"]:string
        response["data"]["candles"][]["highPrice"]:string response["data"]["candles"][]["lowPrice"]:string response["data"]["candles"][]["baseVolume"]:string response["data"]["candles"][]["quoteVolume"]:string)";

    OneXAPI::Upbit::Spot client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"kRw","interval":"1min","startTime":1656042045,"endTime":1656063182,"fetchInterval":900})");
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

static const std::string getSubscribingTickersExpectedResult = R"({"success":true,"data":{"tickers":[]}})";

bool TC_UpbitSpot_getSubscribingTickers_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingTickers_2(testDataType& testData){
    TC_BEGIN
    
    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingTickers_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingTickers_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingTickers_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})");
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}],requestTimeout:0})");

    testDataType tempData;

    if(!TC_UpbitSpot_getSubscribingTickers_1(tempData)){
        LOGGER.critical(__func__ + std::string(": Websocket is alive"));
    }

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static const std::string getSubscribingOrderbooksExpectedResult = R"({"success":true,"data":{"orderbooks":[]}})";

bool TC_UpbitSpot_getSubscribingOrderbooks_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingOrderbooks_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingOrderbooks_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingOrderbooks_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_getSubscribingOrderbooks_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})");
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}],requestTimeout:0})");

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeTicker_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";

    for(int i = 0; i < 10; i++){
        OneXAPI::Upbit::Spot client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})";
        std::string response = client.subscribeTicker(input);

        testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        response = client.getSubscribingTickers();

        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
        testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}]}})";
        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_subscribeTicker_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";
    input = R"({"market":[{"baseCurrency":"ETH","quoteCurrency":"KRW"}], "reconnect": true})";
    response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"requestTimeout":0})");
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;
    
    client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"requestTimeout":0})");
    
    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_UpbitSpot_subscribeTicker_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    OneXAPI::Upbit::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "ETH", "ETC", "BCH", "OMG", "POWR", "REP", "SNT", "STORJ", "MTL", "TIX", "LTC", "QTUM", "DGD", "XRP", 
    "MYST", "BTG", "WAVES", "SNGLS", "XAUR", "MER", "EDG", "AMP", "MAID", "AGRS", "FUN", "ANT", "MANA", "SRN", "WAXP", "ZRX", "VEE", "STEEM", "SBD", 
    "BCPT", "BAT", "SALT", "BNT", "MCO", "RCN", "CFI", "HMQ", "WINGS", "NMR", "GUP", "SWT", "DNT", "GLM", "CVC", "PAY", "RLC", "ENG", "UKG", "VIB", 
    "ADX", "QRL", "GNO", "PTOY", "ADT", "STRAX", "ADA", "TRX", "1ST", "LRC", "NEO", "XMR", "PIVX", "UP", "STMX", "ICX", "EOS", "DMT", "DASH", "ARK", 
    "ZEC", "ARDR", "IGNIS", "XEM", "KMD", "GRS", "EMC2", "VTC", "LSK", "LUN", "POLY", "XLM", "XVG", "RDD", "EMC", "PRO", "SC", "GTO", "ONT", "ZIL", 
    "BLT", "DCR", "AID", "NGC", "OCN", "LOOM", "CMCT", "NXT", "BKX", "MFT", "IOST", "RFR", "IQ", "CLOAK", "PART", "DOGE", "IOP", "VIA", "NAV", "IOTA", 
    "OST", "BFT", "SYS", "ZEN", "OK", "UPP", "ENJ", "MET", "HYDRO", "CRW", "DTA", "EDR", "BOXX", "GAS", "ONG", "IHT", "MED", "TX", "BLOCK", "RVN", "ION", 
    "BITB", "BSD", "FTC", "RVR", "LBC", "GAME", "ELF", "PMA", "KNC", "PAL", "UNB", "MOC", "PUNDIX", "SPC", "NXS", "SYNX", "KORE", "DYN", "VAL", "DGB", 
    "SIB", "VRC", "MEME", "EXCL", "BAY", "SHIFT", "MONA", "BLK", "XHV", "TUBE", "UBQ", "GO", "EXP", "XZC", "MUE", "NBT", "BURST", "DCT", "SPHR", "SLS", 
    "XEL", "GBYTE", "XDN", "FCT", "BSV", "XNK", "THETA", "NCASH", "JNT", "LBA", "DENT", "DRGN", "QKC", "CPT", "BTM", "BTT", "VITE", "IOTX", "BTU", "SOLVE", 
    "NKN", "CTXC", "QNT", "STRK", "META", "MOBI", "SERV", "ANKR", "COSM", "CRO", "TFUEL", "BTS", "FSN", "MARO", "ORBS", "HST", "AERGO", "PI", "VBK", "ATOM", 
    "TT", "ACN", "CRE", "VDX", "STPT", "MBL", "LAMB", "LUNC", "DAI", "MKR", "BORA", "TSHP", "HBAR", "WIN", "MLK", "PXL", "VET", "CHZ", "VTHO", "XPR", "FX", 
    "OGN", "ITAM", "XTZ", "OBSR", "DKA", "AHT", "RINGX", "GOM2", "LINK", "JST", "KAVA", "RVC", "PCI", "TON", "CTSI", "DOT", "DAD", "CHR", "COMP", "SXP", 
    "HUNT", "ONIT", "CRV", "ALGO", "RSR", "OXT", "PLA", "SAND", "SUN", "SRM", "QTCON", "MVL", "REI", "AQT", "AXS", "FCT2", "SSX", "FIL", "XEC", "UNI", "INJ", 
    "BASIC", "PROM", "CBK", "FOR", "ONX", "MIR", "BFC", "LINA", "HUM", "PICA", "CELO", "STX", "LZM", "DON", "NEAR", "AUCTION", "DAWN", "FLOW", "GRT", "SNX", 
    "XYM", "APENFT", "SGB", "SOL", "MATIC", "NU", "QI", "1INCH", "AAVE", "MASK", "AUDIO", "BOBA", "YGG", "GTC", "OCEAN", "CTC", "LPT", "WEMIX", "AVAX", "IMX", 
    "RNDR", "RLY", "T", "AQUA", "RAD", "AGLD", "API3", "ARPA", "ENS", "GMT", "APE", "LUNA2", "OGV", "RAY", "ETHW", "ETHF"};

    rapidjson::Document requestDoc, responseDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "KRW", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : responseDoc["data"]["subscribed"].GetArray()){
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : responseDoc["data"]["subscribeFailed"].GetArray()){
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingTickers();

    testData.actualResult = response;
    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    for(const auto& ticker : responseDoc["data"]["tickers"].GetArray()){
        std::string symbol = ticker["symbol"].GetString();

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

bool TC_UpbitSpot_subscribeTicker_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW","symbol":"KRW-HYUNKYU"}]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_subscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker_1";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_2";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker_3";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[],"subscribeFailed":[]}})";
    response = client.subscribeTicker(R"({"market":[],"reconnect":true})");
    
    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"unsubscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}])";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"unsubscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}],"reconnect":true})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}])";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_6(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    OneXAPI::Upbit::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "ETH", "ETC", "BCH", "OMG", "POWR", "REP", "SNT", "STORJ", "MTL", "TIX", "LTC", "QTUM", "DGD", "XRP", 
    "MYST", "BTG", "WAVES", "SNGLS", "XAUR", "MER", "EDG", "AMP", "MAID", "AGRS", "FUN", "ANT", "MANA", "SRN", "WAXP", "ZRX", "VEE", "STEEM", "SBD", 
    "BCPT", "BAT", "SALT", "BNT", "MCO", "RCN", "CFI", "HMQ", "WINGS", "NMR", "GUP", "SWT", "DNT", "GLM", "CVC", "PAY", "RLC", "ENG", "UKG", "VIB", 
    "ADX", "QRL", "GNO", "PTOY", "ADT", "STRAX", "ADA", "TRX", "1ST", "LRC", "NEO", "XMR", "PIVX", "UP", "STMX", "ICX", "EOS", "DMT", "DASH", "ARK", 
    "ZEC", "ARDR", "IGNIS", "XEM", "KMD", "GRS", "EMC2", "VTC", "LSK", "LUN", "POLY", "XLM", "XVG", "RDD", "EMC", "PRO", "SC", "GTO", "ONT", "ZIL", 
    "BLT", "DCR", "AID", "NGC", "OCN", "LOOM", "CMCT", "NXT", "BKX", "MFT", "IOST", "RFR", "IQ", "CLOAK", "PART", "DOGE", "IOP", "VIA", "NAV", "IOTA", 
    "OST", "BFT", "SYS", "ZEN", "OK", "UPP", "ENJ", "MET", "HYDRO", "CRW", "DTA", "EDR", "BOXX", "GAS", "ONG", "IHT", "MED", "TX", "BLOCK", "RVN", "ION", 
    "BITB", "BSD", "FTC", "RVR", "LBC", "GAME", "ELF", "PMA", "KNC", "PAL", "UNB", "MOC", "PUNDIX", "SPC", "NXS", "SYNX", "KORE", "DYN", "VAL", "DGB", 
    "SIB", "VRC", "MEME", "EXCL", "BAY", "SHIFT", "MONA", "BLK", "XHV", "TUBE", "UBQ", "GO", "EXP", "XZC", "MUE", "NBT", "BURST", "DCT", "SPHR", "SLS", 
    "XEL", "GBYTE", "XDN", "FCT", "BSV", "XNK", "THETA", "NCASH", "JNT", "LBA", "DENT", "DRGN", "QKC", "CPT", "BTM", "BTT", "VITE", "IOTX", "BTU", "SOLVE", 
    "NKN", "CTXC", "QNT", "STRK", "META", "MOBI", "SERV", "ANKR", "COSM", "CRO", "TFUEL", "BTS", "FSN", "MARO", "ORBS", "HST", "AERGO", "PI", "VBK", "ATOM", 
    "TT", "ACN", "CRE", "VDX", "STPT", "MBL", "LAMB", "LUNC", "DAI", "MKR", "BORA", "TSHP", "HBAR", "WIN", "MLK", "PXL", "VET", "CHZ", "VTHO", "XPR", "FX", 
    "OGN", "ITAM", "XTZ", "OBSR", "DKA", "AHT", "RINGX", "GOM2", "LINK", "JST", "KAVA", "RVC", "PCI", "TON", "CTSI", "DOT", "DAD", "CHR", "COMP", "SXP", 
    "HUNT", "ONIT", "CRV", "ALGO", "RSR", "OXT", "PLA", "SAND", "SUN", "SRM", "QTCON", "MVL", "REI", "AQT", "AXS", "FCT2", "SSX", "FIL", "XEC", "UNI", "INJ", 
    "BASIC", "PROM", "CBK", "FOR", "ONX", "MIR", "BFC", "LINA", "HUM", "PICA", "CELO", "STX", "LZM", "DON", "NEAR", "AUCTION", "DAWN", "FLOW", "GRT", "SNX", 
    "XYM", "APENFT", "SGB", "SOL", "MATIC", "NU", "QI", "1INCH", "AAVE", "MASK", "AUDIO", "BOBA", "YGG", "GTC", "OCEAN", "CTC", "LPT", "WEMIX", "AVAX", "IMX", 
    "RNDR", "RLY", "T", "AQUA", "RAD", "AGLD", "API3", "ARPA", "ENS", "GMT", "APE", "LUNA2", "OGV", "RAY", "ETHW", "ETHF"};

    rapidjson::Document requestDoc, responseDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "KRW", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : responseDoc["data"]["subscribed"].GetArray()){
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : responseDoc["data"]["subscribeFailed"].GetArray()){
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingTickers();

    testData.actualResult = response;
    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    rapidjson::Document unsubscribeRequest;

    unsubscribeRequest.SetObject();
    unsubscribeRequest.AddMember("market", rapidjson::kArrayType, unsubscribeRequest.GetAllocator());

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    for(const auto& ticker : responseDoc["data"]["tickers"].GetArray()){
        std::string baseCurrency = ticker["baseCurrency"].GetString();
        std::string quoteCurrency = ticker["quoteCurrency"].GetString();
        std::string symbol = ticker["symbol"].GetString();

        rapidjson::Value marketObject(rapidjson::kObjectType);

        marketObject.AddMember("baseCurrency", baseCurrency, unsubscribeRequest.GetAllocator());
        marketObject.AddMember("quoteCurrency", quoteCurrency, unsubscribeRequest.GetAllocator());

        unsubscribeRequest["market"].PushBack(marketObject, unsubscribeRequest.GetAllocator());

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

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    client.unsubscribeTicker(OneXAPI::Internal::Util::jsonToString(unsubscribeRequest));

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW","symbol":"KRW-HYUNKYU"}]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker_1";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_2";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker_3";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[],"unsubscribeFailed":[]}})";
    response = client.unsubscribeTicker(R"({"market":[],"reconnect":true})");
    
    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";

    for(int i = 0; i < 10; i++){
        OneXAPI::Upbit::Spot client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})";
        std::string response = client.subscribeOrderbook(input);

        testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }

        response = client.getSubscribingOrderbooks();

        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
        testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}]}})";
        testData.actualResult = response;

        if(response.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"}]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";
    input = R"({"market":[{"baseCurrency":"ETH","quoteCurrency":"KRW"}], "reconnect": true})";
    response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"requestTimeout":0})");
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"BTC","symbol":"BTC-ETH"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;
    
    client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"requestTimeout":0})");
    
    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    OneXAPI::Upbit::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "ETH", "ETC", "BCH", "OMG", "POWR", "REP", "SNT", "STORJ", "MTL", "TIX", "LTC", "QTUM", "DGD", "XRP", 
    "MYST", "BTG", "WAVES", "SNGLS", "XAUR", "MER", "EDG", "AMP", "MAID", "AGRS", "FUN", "ANT", "MANA", "SRN", "WAXP", "ZRX", "VEE", "STEEM", "SBD", 
    "BCPT", "BAT", "SALT", "BNT", "MCO", "RCN", "CFI", "HMQ", "WINGS", "NMR", "GUP", "SWT", "DNT", "GLM", "CVC", "PAY", "RLC", "ENG", "UKG", "VIB", 
    "ADX", "QRL", "GNO", "PTOY", "ADT", "STRAX", "ADA", "TRX", "1ST", "LRC", "NEO", "XMR", "PIVX", "UP", "STMX", "ICX", "EOS", "DMT", "DASH", "ARK", 
    "ZEC", "ARDR", "IGNIS", "XEM", "KMD", "GRS", "EMC2", "VTC", "LSK", "LUN", "POLY", "XLM", "XVG", "RDD", "EMC", "PRO", "SC", "GTO", "ONT", "ZIL", 
    "BLT", "DCR", "AID", "NGC", "OCN", "LOOM", "CMCT", "NXT", "BKX", "MFT", "IOST", "RFR", "IQ", "CLOAK", "PART", "DOGE", "IOP", "VIA", "NAV", "IOTA", 
    "OST", "BFT", "SYS", "ZEN", "OK", "UPP", "ENJ", "MET", "HYDRO", "CRW", "DTA", "EDR", "BOXX", "GAS", "ONG", "IHT", "MED", "TX", "BLOCK", "RVN", "ION", 
    "BITB", "BSD", "FTC", "RVR", "LBC", "GAME", "ELF", "PMA", "KNC", "PAL", "UNB", "MOC", "PUNDIX", "SPC", "NXS", "SYNX", "KORE", "DYN", "VAL", "DGB", 
    "SIB", "VRC", "MEME", "EXCL", "BAY", "SHIFT", "MONA", "BLK", "XHV", "TUBE", "UBQ", "GO", "EXP", "XZC", "MUE", "NBT", "BURST", "DCT", "SPHR", "SLS", 
    "XEL", "GBYTE", "XDN", "FCT", "BSV", "XNK", "THETA", "NCASH", "JNT", "LBA", "DENT", "DRGN", "QKC", "CPT", "BTM", "BTT", "VITE", "IOTX", "BTU", "SOLVE", 
    "NKN", "CTXC", "QNT", "STRK", "META", "MOBI", "SERV", "ANKR", "COSM", "CRO", "TFUEL", "BTS", "FSN", "MARO", "ORBS", "HST", "AERGO", "PI", "VBK", "ATOM", 
    "TT", "ACN", "CRE", "VDX", "STPT", "MBL", "LAMB", "LUNC", "DAI", "MKR", "BORA", "TSHP", "HBAR", "WIN", "MLK", "PXL", "VET", "CHZ", "VTHO", "XPR", "FX", 
    "OGN", "ITAM", "XTZ", "OBSR", "DKA", "AHT", "RINGX", "GOM2", "LINK", "JST", "KAVA", "RVC", "PCI", "TON", "CTSI", "DOT", "DAD", "CHR", "COMP", "SXP", 
    "HUNT", "ONIT", "CRV", "ALGO", "RSR", "OXT", "PLA", "SAND", "SUN", "SRM", "QTCON", "MVL", "REI", "AQT", "AXS", "FCT2", "SSX", "FIL", "XEC", "UNI", "INJ", 
    "BASIC", "PROM", "CBK", "FOR", "ONX", "MIR", "BFC", "LINA", "HUM", "PICA", "CELO", "STX", "LZM", "DON", "NEAR", "AUCTION", "DAWN", "FLOW", "GRT", "SNX", 
    "XYM", "APENFT", "SGB", "SOL", "MATIC", "NU", "QI", "1INCH", "AAVE", "MASK", "AUDIO", "BOBA", "YGG", "GTC", "OCEAN", "CTC", "LPT", "WEMIX", "AVAX", "IMX", 
    "RNDR", "RLY", "T", "AQUA", "RAD", "AGLD", "API3", "ARPA", "ENS", "GMT", "APE", "LUNA2", "OGV", "RAY", "ETHW", "ETHF"};

    rapidjson::Document requestDoc, responseDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "KRW", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : responseDoc["data"]["subscribed"].GetArray()){
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : responseDoc["data"]["subscribeFailed"].GetArray()){
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;
    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    for(const auto& Orderbook : responseDoc["data"]["orderbooks"].GetArray()){
        std::string symbol = Orderbook["symbol"].GetString();

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

bool TC_UpbitSpot_subscribeOrderbook_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW","symbol":"KRW-HYUNKYU"}]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_subscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook_1";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_2";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook_3";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[],"subscribeFailed":[]}})";
    response = client.subscribeOrderbook(R"({"market":[],"reconnect":true})");
    
    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "{}";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Upbit::Spot client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR")){
        return true;
    }

    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"unsubscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}])";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"unsubscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}],"reconnect":true})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}])";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_6(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    OneXAPI::Upbit::Spot client;
    std::vector<std::string> allCurrencys = {"BTC", "ETH", "ETC", "BCH", "OMG", "POWR", "REP", "SNT", "STORJ", "MTL", "TIX", "LTC", "QTUM", "DGD", "XRP", 
    "MYST", "BTG", "WAVES", "SNGLS", "XAUR", "MER", "EDG", "AMP", "MAID", "AGRS", "FUN", "ANT", "MANA", "SRN", "WAXP", "ZRX", "VEE", "STEEM", "SBD", 
    "BCPT", "BAT", "SALT", "BNT", "MCO", "RCN", "CFI", "HMQ", "WINGS", "NMR", "GUP", "SWT", "DNT", "GLM", "CVC", "PAY", "RLC", "ENG", "UKG", "VIB", 
    "ADX", "QRL", "GNO", "PTOY", "ADT", "STRAX", "ADA", "TRX", "1ST", "LRC", "NEO", "XMR", "PIVX", "UP", "STMX", "ICX", "EOS", "DMT", "DASH", "ARK", 
    "ZEC", "ARDR", "IGNIS", "XEM", "KMD", "GRS", "EMC2", "VTC", "LSK", "LUN", "POLY", "XLM", "XVG", "RDD", "EMC", "PRO", "SC", "GTO", "ONT", "ZIL", 
    "BLT", "DCR", "AID", "NGC", "OCN", "LOOM", "CMCT", "NXT", "BKX", "MFT", "IOST", "RFR", "IQ", "CLOAK", "PART", "DOGE", "IOP", "VIA", "NAV", "IOTA", 
    "OST", "BFT", "SYS", "ZEN", "OK", "UPP", "ENJ", "MET", "HYDRO", "CRW", "DTA", "EDR", "BOXX", "GAS", "ONG", "IHT", "MED", "TX", "BLOCK", "RVN", "ION", 
    "BITB", "BSD", "FTC", "RVR", "LBC", "GAME", "ELF", "PMA", "KNC", "PAL", "UNB", "MOC", "PUNDIX", "SPC", "NXS", "SYNX", "KORE", "DYN", "VAL", "DGB", 
    "SIB", "VRC", "MEME", "EXCL", "BAY", "SHIFT", "MONA", "BLK", "XHV", "TUBE", "UBQ", "GO", "EXP", "XZC", "MUE", "NBT", "BURST", "DCT", "SPHR", "SLS", 
    "XEL", "GBYTE", "XDN", "FCT", "BSV", "XNK", "THETA", "NCASH", "JNT", "LBA", "DENT", "DRGN", "QKC", "CPT", "BTM", "BTT", "VITE", "IOTX", "BTU", "SOLVE", 
    "NKN", "CTXC", "QNT", "STRK", "META", "MOBI", "SERV", "ANKR", "COSM", "CRO", "TFUEL", "BTS", "FSN", "MARO", "ORBS", "HST", "AERGO", "PI", "VBK", "ATOM", 
    "TT", "ACN", "CRE", "VDX", "STPT", "MBL", "LAMB", "LUNC", "DAI", "MKR", "BORA", "TSHP", "HBAR", "WIN", "MLK", "PXL", "VET", "CHZ", "VTHO", "XPR", "FX", 
    "OGN", "ITAM", "XTZ", "OBSR", "DKA", "AHT", "RINGX", "GOM2", "LINK", "JST", "KAVA", "RVC", "PCI", "TON", "CTSI", "DOT", "DAD", "CHR", "COMP", "SXP", 
    "HUNT", "ONIT", "CRV", "ALGO", "RSR", "OXT", "PLA", "SAND", "SUN", "SRM", "QTCON", "MVL", "REI", "AQT", "AXS", "FCT2", "SSX", "FIL", "XEC", "UNI", "INJ", 
    "BASIC", "PROM", "CBK", "FOR", "ONX", "MIR", "BFC", "LINA", "HUM", "PICA", "CELO", "STX", "LZM", "DON", "NEAR", "AUCTION", "DAWN", "FLOW", "GRT", "SNX", 
    "XYM", "APENFT", "SGB", "SOL", "MATIC", "NU", "QI", "1INCH", "AAVE", "MASK", "AUDIO", "BOBA", "YGG", "GTC", "OCEAN", "CTC", "LPT", "WEMIX", "AVAX", "IMX", 
    "RNDR", "RLY", "T", "AQUA", "RAD", "AGLD", "API3", "ARPA", "ENS", "GMT", "APE", "LUNA2", "OGV", "RAY", "ETHW", "ETHF"};

    rapidjson::Document requestDoc, responseDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencys){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "KRW", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;
    
    for(const auto& object : responseDoc["data"]["subscribed"].GetArray()){
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : responseDoc["data"]["subscribeFailed"].GetArray()){
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;
    OneXAPI::Internal::Util::parseJson(responseDoc, response);

    rapidjson::Document unsubscribeRequest;

    unsubscribeRequest.SetObject();
    unsubscribeRequest.AddMember("market", rapidjson::kArrayType, unsubscribeRequest.GetAllocator());

    if(responseDoc["success"].GetBool() == false){
        return false;
    }

    for(const auto& Orderbook : responseDoc["data"]["orderbooks"].GetArray()){
        std::string baseCurrency = Orderbook["baseCurrency"].GetString();
        std::string quoteCurrency = Orderbook["quoteCurrency"].GetString();
        std::string symbol = Orderbook["symbol"].GetString();

        rapidjson::Value marketObject(rapidjson::kObjectType);

        marketObject.AddMember("baseCurrency", baseCurrency, unsubscribeRequest.GetAllocator());
        marketObject.AddMember("quoteCurrency", quoteCurrency, unsubscribeRequest.GetAllocator());

        unsubscribeRequest["market"].PushBack(marketObject, unsubscribeRequest.GetAllocator());

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

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,})";

    client.unsubscribeOrderbook(OneXAPI::Internal::Util::jsonToString(unsubscribeRequest));

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[]}})";

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW","symbol":"KRW-HYUNKYU"}]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"KRW"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_unsubscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook_1";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_2";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";
    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook_3";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[],"unsubscribeFailed":[]}})";
    response = client.unsubscribeOrderbook(R"({"market":[],"reconnect":true})");
    
    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    TC_END
}

bool TC_UpbitSpot_websocketFullTest(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeTicker_1";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    OneXAPI::Upbit::Spot client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_2";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook_3";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"reconnect":true})";
    response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_4";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_5";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeTicker_6";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}],"unsubscribeFailed":[]}})";

    input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"KRW"}],"reconnect":true})";
    response = client.unsubscribeTicker(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_7";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_8";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().unsubscribeOrderbook_9";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"unsubscribed":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"unsubscribeFailed":[]}})";

    input = R"({"market":[{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"reconnect":true})";
    response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_10";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_11";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"}]}})";

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().subscribeOrderbook_12";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"KRW","symbol":"KRW-XRP"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}],"subscribeFailed":[]}})";

    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"KRW"},{"baseCurrency":"ETH","quoteCurrency":"KRW"}],"reconnect":true})";
    response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers_13";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"tickers":[{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks_14";
    testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0,"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"KRW","symbol":"KRW-BTC"},{"baseCurrency":"XRP","quoteCurrency":"KRW","symbol":"KRW-XRP"},{"baseCurrency":"ETH","quoteCurrency":"KRW","symbol":"KRW-ETH"}]}})";

    response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}