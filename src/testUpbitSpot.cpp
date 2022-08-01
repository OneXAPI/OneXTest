#include "../include/testUpbitSpot.hpp"
#include <iostream>

#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

bool TC_UpbitSpot_Object_1(testDataType& testData){
    try{

        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot";
        testData.expectedResult = "No Error";

        OneXAPI::Upbit::Spot stackClient;
        OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot();

        testData.actualResult = "No Error";

        delete heapClient;
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

bool TC_UpbitSpot_Object_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot";
        testData.expectedResult = "No Error";

        OneXAPI::Upbit::Spot stackClient("");
        OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("");

        testData.actualResult = "No Error";

        delete heapClient;
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

bool TC_UpbitSpot_Object_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot";
        testData.expectedResult = "No Error";

        OneXAPI::Upbit::Spot stackClient("{}");
        OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("{}");

        testData.actualResult = "No Error";

        delete heapClient;
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

bool TC_UpbitSpot_Object_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot";
        testData.expectedResult = "No Error";

        OneXAPI::Upbit::Spot stackClient("fnq543wb");
        OneXAPI::Upbit::Spot* heapClient = new OneXAPI::Upbit::Spot("fnq543wb");

        testData.actualResult = "No Error";

        delete heapClient;
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

bool TC_UpbitSpot_Object_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_Object_6(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_Object_7(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

static const std::string getConfigExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"exchange":"Upbit","instrument":"Spot","accessKey":"","secretKey":"","restEndpoint":"https://api.upbit.com/v1","publicWebsocketEndpoint":"wss://api.upbit.com/websocket/v1","privateWebsocketEndpoint":"","restRequestTimeout":5000,"websocketConnectTimeout":5000,"websocketIdleTimeout":5000}})";

bool TC_UpbitSpot_getConfig_1(testDataType& testData){
    try{

        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
        testData.expectedResult = getConfigExpectedResult;

        OneXAPI::Upbit::Spot client;

        std::string response = client.getConfig();

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getConfig_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
        testData.expectedResult = getConfigExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.getConfig(input);

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getConfig_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
        testData.expectedResult = getConfigExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.getConfig(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getConfig_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getConfig";
        testData.expectedResult = getConfigExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "trashData123@@!%";
        std::string response = client.getConfig(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

static const std::string getEndpointCandidatesExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"restEndpoints":["https://api.upbit.com/v1"],"publicWebsocketEndpoints":["wss://api.upbit.com/websocket/v1"],"privateWebsocketEndpoints":[]}})";

bool TC_UpbitSpot_getEndpointCandidates_1(testDataType& testData){
    try{

        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
        testData.expectedResult = getEndpointCandidatesExpectedResult;

        OneXAPI::Upbit::Spot client;

        std::string response = client.getEndpointCandidates();

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getEndpointCandidates_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
        testData.expectedResult = getEndpointCandidatesExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.getEndpointCandidates(input);

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getEndpointCandidates_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
        testData.expectedResult = getEndpointCandidatesExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.getEndpointCandidates(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getEndpointCandidates_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getEndpointCandidates";
        testData.expectedResult = getEndpointCandidatesExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "uNPaRsib1eM5g";
        std::string response = client.getEndpointCandidates(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

std::map<std::string, bool> hasExpectedResult = {
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
    {"fetchTradingFee", false},
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

bool TC_UpbitSpot_has_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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

        std::string response = client.has();

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_has_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
        std::string input = "";
        std::string response = client.has(input);

        testData.actualResult = response;
        
        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_has_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_has_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().has";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

        OneXAPI::Upbit::Spot client;
        std::string input = "el12nlgv@!";
        std::string response = client.has(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_has_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().has";
        testData.expectedResult.clear();

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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_has_6(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().has";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"SPOT does not have an API - notExistApi"}})";

        OneXAPI::Upbit::Spot client;
        std::string input = R"({"api":"notExistApi"})";
        std::string response = client.has(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

static const std::string subscribeBalanceExpectedResult = R"({"success":false,"data":{"errorType":"NOT_SUPPORTED_API","errorMsg":""}})";

bool TC_UpbitSpot_subscribeBalance_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = subscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.subscribeBalance();

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_subscribeBalance_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = subscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.subscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_subscribeBalance_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = subscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.subscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_subscribeBalance_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = subscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.subscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

static const std::string unsubscribeBalanceExpectedResult = R"({"success":false,"data":{"errorType":"NOT_SUPPORTED_API","errorMsg":""}})";

bool TC_UpbitSpot_unsubscribeBalance_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = unsubscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.unsubscribeBalance();

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_unsubscribeBalance_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = unsubscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.unsubscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_unsubscribeBalance_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = unsubscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.unsubscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_unsubscribeBalance_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = unsubscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.unsubscribeBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

static const std::string isSubscribingBalanceExpectedResult = R"({"success":true,"data":{"isSubscribing":false}})";

bool TC_UpbitSpot_isSubscribingBalance_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = isSubscribingBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.isSubscribingBalance();

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_isSubscribingBalance_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = isSubscribingBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.isSubscribingBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_isSubscribingBalance_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = isSubscribingBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.isSubscribingBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_isSubscribingBalance_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = isSubscribingBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.isSubscribingBalance(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

static const std::string getSubscribingTickersExpectedResult = R"({"success":true,"data":{"tickers":[]}})";

bool TC_UpbitSpot_getSubscribingTickers_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
        testData.expectedResult = getSubscribingTickersExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.getSubscribingTickers();

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getSubscribingTickers_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
        testData.expectedResult = getSubscribingTickersExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.getSubscribingTickers(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getSubscribingTickers_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
        testData.expectedResult = getSubscribingTickersExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.getSubscribingTickers(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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

bool TC_UpbitSpot_getSubscribingTickers_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingTickers";
        testData.expectedResult = getSubscribingTickersExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.getSubscribingTickers(input);

        testData.actualResult = response;

        if(response.compare(testData.expectedResult) == 0){
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