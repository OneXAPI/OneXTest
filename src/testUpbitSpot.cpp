#include "../include/testUpbitSpot.hpp"
#include "../include/testTool.hpp"
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

bool TC_UpbitSpot_setConfig_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
        testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

        OneXAPI::Upbit::Spot client;

        std::string response = client.setConfig("");

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

bool TC_UpbitSpot_setConfig_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().setConfig";
        testData.expectedResult = R"({"success":true,"data":{"requestedApiCount":0}})";

        OneXAPI::Upbit::Spot client;

        std::string response = client.setConfig("{}");

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

bool TC_UpbitSpot_setConfig_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_setConfig_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_setConfig_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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

        if(!errorResponseChecker(response, "JSON_PARSING_ERROR")){
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

bool TC_UpbitSpot_has_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
        testData.expectedResult = R"({"success":false,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

        OneXAPI::Upbit::Spot client;
        std::string input = R"({"api":"notExistApi"})";
        std::string response = client.has(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "WRONG_VALUE")){
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

static const std::string getWithdrawRoundingRuleExpectedResult = R"({"success":true,"data":{"requestedApiCount":0,"roundingRule":"round"}})";

bool TC_UpbitSpot_getWithdrawRoundingRule_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getWithdrawRoundingRule";
        testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.getWithdrawRoundingRule();

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

bool TC_UpbitSpot_getWithdrawRoundingRule_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getWithdrawRoundingRule";
        testData.expectedResult = getWithdrawRoundingRuleExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = R"({})";
        std::string response = client.getWithdrawRoundingRule(input);

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

bool TC_UpbitSpot_setWithdrawRoundingRule_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_setWithdrawRoundingRule_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_withdraw_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_withdraw_2(testDataType& testData){
    try{
        std::string loggerLevel = LOGGER.getLevel();
        LOGGER.setLevel("info");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
        testData.testCaseId = __func__;
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

        if(response.find(findValue1) != std::string::npos && response.find(findValue2) != std::string::npos){
            return true;
        }

        LOGGER.setLevel(loggerLevel);
        
        return false;
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_withdraw_3(testDataType& testData){
    try{
        std::string loggerLevel = LOGGER.getLevel();
        LOGGER.setLevel("info");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
        testData.testCaseId = __func__;
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

        if(response.find(findValue1) != std::string::npos && response.find(findValue2) != std::string::npos){
            return true;
        }

        LOGGER.setLevel(loggerLevel);
        
        return false;
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_fetchAllCurrencies_1(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
            if(currencyPtr->value["chains"].Size() != 0){
                return false;
            }
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

bool TC_UpbitSpot_fetchAllCurrencies_2(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
            if(currencyPtr->value["chains"].Size() != 0){
                return false;
            }
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

bool TC_UpbitSpot_fetchBalance_1(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_fetchBalance_2(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_fetchWalletStatus_1(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_fetchWalletStatus_2(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
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
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

bool TC_UpbitSpot_fetchWithdrawHistory_1(testDataType& testData){
    try{
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().fetchWithdrawHistory";
        testData.expectedResult = R"(response["success"]:true response["data"]["requestedApiCount"]:1 response["data"]["withdrawals"]["currency"] is string
            response["data"]["withdrawals"]["amount"] is string response["data"]["withdrawals"]["fee"] is string response["data"]["withdrawals"]["orderId"] is string
            response["data"]["withdrawals"]["txid"] is string response["data"]["withdrawals"]["status"] is string response["data"]["withdrawals"]["createdAt"] is uint64
            response["data"]["withdrawals"]["doneAt"] is uint64)";
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
            if(!withdrawal["createdAt"].IsUint64()){
                return false;
            }
            if(!withdrawal["doneAt"].IsUint64()){
                return false;
            }
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

bool TC_UpbitSpot_fetchWithdrawHistory_2(testDataType& testData){
    try{
        std::string loggerLevel = LOGGER.getLevel();
        LOGGER.setLevel("info");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
        testData.testCaseId = __func__;
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

        if(response.find(findValue) != std::string::npos){
            return true;
        }

        LOGGER.setLevel(loggerLevel);
        
        return false;
    }
    catch(std::exception& e){
        testData.actualResult = EXCEPTION_MSG;
    }
    catch(...){
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;
    }
    return false;
}

static const std::string subscribeBalanceExpectedResult = R"({"success":false,"data":{"errorType":"NOT_SUPPORTED_API","errorMsg":"~~~"}})";

bool TC_UpbitSpot_subscribeBalance_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().subscribeBalance";
        testData.expectedResult = subscribeBalanceExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.subscribeBalance();

        testData.actualResult = response;

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

        if(errorResponseChecker(response, "NOT_SUPPORTED_API")){
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

static const std::string getSubscribingOrderbooksExpectedResult = R"({"success":true,"data":{"orderbooks":[]}})";

bool TC_UpbitSpot_getSubscribingOrderbooks_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
        testData.expectedResult = getSubscribingOrderbooksExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string response = client.getSubscribingOrderbooks();

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

bool TC_UpbitSpot_getSubscribingOrderbooks_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
        testData.expectedResult = getSubscribingOrderbooksExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "";
        std::string response = client.getSubscribingOrderbooks(input);

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

bool TC_UpbitSpot_getSubscribingOrderbooks_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
        testData.expectedResult = getSubscribingOrderbooksExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "{}";
        std::string response = client.getSubscribingOrderbooks(input);

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

bool TC_UpbitSpot_getSubscribingOrderbooks_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot().getSubscribingOrderbooks";
        testData.expectedResult = getSubscribingOrderbooksExpectedResult;

        OneXAPI::Upbit::Spot client;
        std::string input = "Bqbqb@";
        std::string response = client.getSubscribingOrderbooks(input);

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