#include "../../include/exchanges/testBinanceFutures.hpp"
#include "../../include/testDefine.hpp"
#include "../../include/testTool.hpp"
#include <iostream>

bool TC_BinanceFutures_Object_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Futures stackClient;
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures();

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceFutures_Object_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Futures stackClient("");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures("");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;
    
    TC_END
}

bool TC_BinanceFutures_Object_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Futures stackClient("{}");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures("{}");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceFutures_Object_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = "No Error";

    OneXAPI::Binance::Futures stackClient("fnq543wb");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures("fnq543wb");

    testData.actualResult = "No Error";

    delete heapClient;
    return true;

    TC_END
}

bool TC_BinanceFutures_Object_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "")";

    OneXAPI::Binance::Futures stackClient(R"({"accessKey":"Test Access Key"})");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures(R"({"accessKey":"Test Access Key"})");

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

bool TC_BinanceFutures_Object_6(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = R"(accessKey : "", secretKey : "Test Secret Key")";

    OneXAPI::Binance::Futures stackClient(R"({"secretKey":"Test Secret Key"})");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures(R"({"secretKey":"Test Secret Key"})");

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

bool TC_BinanceFutures_Object_7(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures";
    testData.expectedResult = R"(accessKey : "Test Access Key", secretKey : "Test Secret Key")";

    OneXAPI::Binance::Futures stackClient(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");
    OneXAPI::Binance::Futures* heapClient = new OneXAPI::Binance::Futures(R"({"accessKey":"Test Access Key", "secretKey":"Test Secret Key"})");

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

static const std::string getConfigExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"exchange":"Binance","instrument":"Futures","accessKey":"","secretKey":"","restEndpoint":"https://fapi.binance.com","publicWebsocketEndpoint":"wss://fstream.binance.com/ws","privateWebsocketEndpoint":"wss://fstream.binance.com/ws","restRequestTimeout":5000,"websocketConnectTimeout":5000,"websocketIdleTimeout":5000}})";

bool TC_BinanceFutures_getConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Futures client;

    std::string response = client.getConfig();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getConfig(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getConfig";
    testData.expectedResult = getConfigExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getConfig";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Binance::Futures client;
    std::string input = "trashData123@@!%";
    std::string response = client.getConfig(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_setConfig_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setConfig";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

    OneXAPI::Binance::Futures client;

    std::string response = client.setConfig("");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_setConfig_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setConfig";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

    OneXAPI::Binance::Futures client;

    std::string response = client.setConfig("{}");

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_setConfig_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setConfig";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE_TYPE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client;
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

bool TC_BinanceFutures_setConfig_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setConfig";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client;
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

bool TC_BinanceFutures_setConfig_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setConfig";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"requestedKey":"requestedValue"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client;
    std::string input, response;

    std::vector<std::pair<std::string,std::string>> testList = {
        {"accessKey",R"("test access key")"},
        {"secretKey",R"("test secret key")"},
        {"restEndpoint",R"("https://testnet.binancefuture.com")"},
        {"publicWebsocketEndpoint",R"("wss://fstream-auth.binance.com/ws")"},
        {"privateWebsocketEndpoint",R"("wss://fstream-auth.binance.com/ws")"},
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

static const std::string getEndpointCandidatesExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"restEndpoints":["https://fapi.binance.com","https://testnet.binancefuture.com"],"publicWebsocketEndpoints":["wss://fstream.binance.com/ws","wss://fstream-auth.binance.com/ws","wss://stream.binancefuture.com/ws"],"privateWebsocketEndpoints":["wss://fstream.binance.com/ws","wss://fstream-auth.binance.com/ws","wss://stream.binancefuture.com/ws"]}})";

bool TC_BinanceFutures_getEndpointCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Futures client;

    std::string response = client.getEndpointCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getEndpointCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getEndpointCandidates_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getEndpointCandidates";
    testData.expectedResult = getEndpointCandidatesExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.getEndpointCandidates(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getEndpointCandidates_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getEndpointCandidates";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":""}})";

    OneXAPI::Binance::Futures client;
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
    {"fetchBalance", true},
    {"fetchPositions", true},
    {"fetchFundingFeeIncomeHistory", true},
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
    {"fetchLeverage", true},
    {"changeLeverage", true},
    {"fetchMarginType", true},
    {"changeMarginType", true},
    /* Markets */
    {"getCandleIntervalCandidates", true},
    {"fetchMarkets", true},
    {"fetchMarketInfo", true},
    {"fetchTicker", true},
    {"fetchOrderbook", true},
    {"fetchCandleHistory", true},
    {"getSubscribingMarketInfo", true},
    {"getSubscribingTickers", true},
    {"getSubscribingOrderbooks", true},
    {"subscribeMarketInfo", true},
    {"unsubscribeMarketInfo", true},
    {"subscribeTicker", true},
    {"unsubscribeTicker", true},
    {"subscribeOrderbook", true},
    {"unsubscribeOrderbook", true}
};

bool TC_BinanceFutures_has_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().has";
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

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.has(input);
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    testData.actualResult = response;
    if(!successResponseChecker(response)){
        return false;
    }
    else if(response.compare(testData.expectedResult) != 0 || !memberCountChecker(respDoc["data"], 39)){
        return false;
    }
    testData.expectedResult += R"(\n member count of response["data"] = 39)";
    return true;

    TC_END
}

bool TC_BinanceFutures_has_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().has";
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

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.has(input);
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    testData.actualResult = response;
    if(!successResponseChecker(response)){
        return false;
    }
    else if(response.compare(testData.expectedResult) != 0 || !memberCountChecker(respDoc["data"], 39)){
        return false;
    }
    testData.expectedResult += R"(\n member count of response["data"] = 39)";
    return true;

    TC_END
}

bool TC_BinanceFutures_has_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().has";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "el12nlgv@!";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_has_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().has";
    testData.expectedResult.clear();
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_has_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().has";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"api":"notExistApi"})";
    std::string response = client.has(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchBalance_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["balance"]:string
response["data"]["balance"][currency]["crossWalletBalance"]:string
response["data"]["balance"][currency]["availableBalance"]:string

member count of response["data"] = 2
member count of response["data"]["balance"][currency] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
        else if(!memberCountChecker(balancePtr->value, 3)){
            return false;
        }
        else if(!balancePtr->value["balance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["crossWalletBalance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["availableBalance"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchBalance_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["balance"]:string
response["data"]["balance"][currency]["crossWalletBalance"]:string
response["data"]["balance"][currency]["availableBalance"]:string

member count of response["data"] = 2
member count of response["data"]["balance"] is 3
member count of response["data"]["balance"][currency] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
        else if(!memberCountChecker(balancePtr->value, 3)){
            return false;
        }
        else if(!balancePtr->value["balance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["crossWalletBalance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["availableBalance"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchBalance_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["balance"]:string
response["data"]["balance"][currency]["crossWalletBalance"]:string
response["data"]["balance"][currency]["availableBalance"]:string

member count of response["data"] = 2
member count of response["data"]["balance"] is 3
member count of response["data"]["balance"][currency] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    client.subscribeBalance();
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
        else if(!memberCountChecker(balancePtr->value, 3)){
            return false;
        }
        else if(!balancePtr->value["balance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["crossWalletBalance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["availableBalance"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchBalance_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchBalance";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["balance"][currency]["balance"]:string
response["data"]["balance"][currency]["crossWalletBalance"]:string
response["data"]["balance"][currency]["availableBalance"]:string

member count of response["data"] = 2
member count of response["data"]["balance"][currency] = 3)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
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
        else if(!memberCountChecker(balancePtr->value, 3)){
            return false;
        }
        else if(!balancePtr->value["balance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["crossWalletBalance"].IsString()){
            return false;
        }
        else if(!balancePtr->value["availableBalance"].IsString()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchPositions_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["positions"] is array
response["data"]["positions"][]["baseCurrency"] is string
response["data"]["positions"][]["quoteCurrency"] is string
response["data"]["positions"][]["expiration"] is string
response["data"]["positions"][]["symbol"] is string
response["data"]["positions"][]["unrealizedProfit"] is string
response["data"]["positions"][]["entryPrice"] is string
response["data"]["positions"][]["positionAmt"] is string and not 0
response["data"]["positions"][]["leverage"] is uint
response["data"]["positions"][]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchPositions(R"({})");
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
    else if(!respDoc["data"]["positions"].IsArray()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(!memberCountChecker(position, 9)){
            return false;
        }
        else if(!position["baseCurrency"].IsString()){
            return false;
        }
        else if(!position["quoteCurrency"].IsString()){
            return false;
        }
        else if(!position["expiration"].IsString()){
            return false;
        }
        else if(!position["symbol"].IsString()){
            return false;
        }
        else if(!position["unrealizedProfit"].IsString()){
            return false;
        }
        else if(!position["entryPrice"].IsString()){
            return false;
        }
        else if(!position["positionAmt"].IsString()){
            return false;
        }
        else if(std::stod(position["positionAmt"].GetString()) == 0){
            return false;
        }
        else if(!position["leverage"].IsUint64()){
            return false;
        }
        else if(std::string("cross").compare(position["marginType"].GetString()) != 0 && std::string("isolated").compare(position["marginType"].GetString()) != 0){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchPositions_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["positions"] is array and size is greater than 0
response["data"]["positions"]["baseCurrency"] is "BTC"
response["data"]["positions"]["quoteCurrency"] is string
response["data"]["positions"]["expiration"] is string
response["data"]["positions"]["symbol"] is string
response["data"]["positions"]["unrealizedProfit"] is string
response["data"]["positions"]["entryPrice"] is string
response["data"]["positions"]["positionAmt"] is string
response["data"]["positions"]["leverage"] is uint
response["data"]["positions"]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchPositions(R"({"baseCurrency":"bTC","zeroAmount":true})");
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
    else if(!respDoc["data"]["positions"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["positions"].Size() > 0)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(!memberCountChecker(position, 9)){
            return false;
        }
        else if(std::string("BTC").compare(position["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(!position["quoteCurrency"].IsString()){
            return false;
        }
        else if(!position["expiration"].IsString()){
            return false;
        }
        else if(!position["symbol"].IsString()){
            return false;
        }
        else if(!position["unrealizedProfit"].IsString()){
            return false;
        }
        else if(!position["entryPrice"].IsString()){
            return false;
        }
        else if(!position["positionAmt"].IsString()){
            return false;
        }
        else if(!position["leverage"].IsUint64()){
            return false;
        }
        else if(std::string("cross").compare(position["marginType"].GetString()) != 0 && std::string("isolated").compare(position["marginType"].GetString()) != 0){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchPositions_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["positions"] is array and size is 1
response["data"]["positions"]["baseCurrency"] is "ETH"
response["data"]["positions"]["quoteCurrency"] is "USDT"
response["data"]["positions"]["expiration"] is 'PERP"
response["data"]["positions"]["symbol"] is "ETHUSDT"
response["data"]["positions"]["unrealizedProfit"] is string
response["data"]["positions"]["entryPrice"] is string
response["data"]["positions"]["positionAmt"] is string
response["data"]["positions"]["leverage"] is uint
response["data"]["positions"]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchPositions(R"({"baseCurrency":"etH","quoteCurrency":"usdT","expiration":"PerP","zeroAmount":true})");
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
    else if(!respDoc["data"]["positions"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["positions"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(!memberCountChecker(position, 9)){
            return false;
        }
        else if(std::string("ETH").compare(position["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(position["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(position["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("ETHUSDT").compare(position["symbol"].GetString()) != 0){
            return false;
        }
        else if(!position["unrealizedProfit"].IsString()){
            return false;
        }
        else if(!position["entryPrice"].IsString()){
            return false;
        }
        else if(!position["positionAmt"].IsString()){
            return false;
        }
        else if(!position["leverage"].IsUint64()){
            return false;
        }
        else if(std::string("cross").compare(position["marginType"].GetString()) != 0 && std::string("isolated").compare(position["marginType"].GetString()) != 0){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchPositions_4(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:0
response["data"]["fetchType"]:"websocket"
response["data"]["positions"] is array
response["data"]["positions"]["baseCurrency"] : "ETH"
response["data"]["positions"]["quoteCurrency"] is string
response["data"]["positions"]["expiration"] is string
response["data"]["positions"]["symbol"] is string
response["data"]["positions"]["unrealizedProfit"] is string
response["data"]["positions"]["entryPrice"] is string
response["data"]["positions"]["positionAmt"] is string and not 0
response["data"]["positions"]["leverage"] is uint
response["data"]["positions"]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchPositions(R"({"baseCurrency":"etH"})");
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
    else if(respDoc["data"]["positions"].IsArray() == false){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(std::string("ETH").compare(position["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(position["quoteCurrency"].IsString() == false){
            return false;
        }
        else if(position["expiration"].IsString() == false){
            return false;
        }
        else if(position["symbol"].IsString() == false){
            return false;
        }
        else if(position["unrealizedProfit"].IsString() == false){
            return false;
        }
        else if(position["entryPrice"].IsString() == false){
            return false;
        }

        if(position["positionAmt"].IsString() == true){
            std::string positionAmt = position["positionAmt"].GetString();
            if(std::stod(positionAmt) == 0){
                return false;
            }
        }
        else{
            return false;
        }

        if(position["leverage"].IsUint64() == false){
            return false;
        }
        if(position["marginType"].IsString() == true){
            std::string marginType = position["marginType"].GetString();
            if(!(marginType.compare("isolated") == 0 || marginType.compare("cross") == 0)){
                return false;
            }
        }
        else{
            return false;
        }
        if(!memberCountChecker(position, 9)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchPositions_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:0
response["data"]["fetchType"]:"websocket"
response["data"]["positions"] is array and size is greater than 0
response["data"]["positions"]["baseCurrency"] : "ETH"
response["data"]["positions"]["quoteCurrency"] is string
response["data"]["positions"]["expiration"] is string
response["data"]["positions"]["symbol"] is string
response["data"]["positions"]["unrealizedProfit"] is string
response["data"]["positions"]["entryPrice"] is string
response["data"]["positions"]["positionAmt"] is string
response["data"]["positions"]["leverage"] is uint
response["data"]["positions"]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchPositions(R"({"baseCurrency":"etH","zeroAmount":true})");
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
    else if(respDoc["data"]["positions"].IsArray() == false){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(std::string("ETH").compare(position["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(position["quoteCurrency"].IsString() == false){
            return false;
        }
        if(position["expiration"].IsString() == false){
            return false;
        }
        if(position["symbol"].IsString() == false){
            return false;
        }
        if(position["unrealizedProfit"].IsString() == false){
            return false;
        }
        if(position["entryPrice"].IsString() == false){
            return false;
        }
        if(position["positionAmt"].IsString() == false){
            return false;
        }
        if(position["leverage"].IsUint64() == false){
            return false;
        }
        if(position["marginType"].IsString() == true){
            std::string marginType = position["marginType"].GetString();
            if(!(marginType.compare("isolated") == 0 || marginType.compare("cross") == 0)){
                return false;
            }
        }
        else{
            return false;
        }
        if(!memberCountChecker(position, 9)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchPositions_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchPositions";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fetchType"]:"rest"
response["data"]["positions"] is array and size is greater than 0
response["data"]["positions"]["baseCurrency"] : "ETH"
response["data"]["positions"]["quoteCurrency"] is string
response["data"]["positions"]["expiration"] is string
response["data"]["positions"]["symbol"] is string
response["data"]["positions"]["unrealizedProfit"] is string
response["data"]["positions"]["entryPrice"] is string
response["data"]["positions"]["positionAmt"] is string
response["data"]["positions"]["leverage"] is uint
response["data"]["positions"]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
member count of response["data"]["positions"] is 9)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchPositions(R"({"baseCurrency":"etH","zeroAmount":true, "forceRestApi":true})");
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
    else if(respDoc["data"]["positions"].IsArray() == false){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& position : respDoc["data"]["positions"].GetArray()){
        if(std::string("ETH").compare(position["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(position["quoteCurrency"].IsString() == false){
            return false;
        }
        if(position["expiration"].IsString() == false){
            return false;
        }
        if(position["symbol"].IsString() == false){
            return false;
        }
        if(position["unrealizedProfit"].IsString() == false){
            return false;
        }
        if(position["entryPrice"].IsString() == false){
            return false;
        }
        if(position["positionAmt"].IsString() == false){
            return false;
        }
        if(position["leverage"].IsUint64() == false){
            return false;
        }
        if(position["marginType"].IsString() == true){
            std::string marginType = position["marginType"].GetString();
            if(!(marginType.compare("isolated") == 0 || marginType.compare("cross") == 0)){
                return false;
            }
        }
        else{
            return false;
        }
        if(!memberCountChecker(position, 9)){
            return false;
        }
    }
    
    return true;
    TC_END
}

bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchFundingFeeIncomeHistory";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchFundingFeeIncomeHistory(R"({})");    
    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchFundingFeeIncomeHistory";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["incomes"] is array
response["data"]["incomes"]["baseCurrency"] is string
response["data"]["incomes"]["quoteCurrency"] is string
response["data"]["incomes"]["expiration"] is string
response["data"]["incomes"]["symbol"] is string
response["data"]["incomes"]["income"] is string
response["data"]["incomes"]["incomeCurrency"] is string
response["data"]["incomes"]["timestamp"] is uint and greater than 10000000000

member count of response["data"] = 1
member count of response["data"]["incomes"] is 7)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string oneYearBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch() - ((uint64_t)365*(uint64_t)24*(uint64_t)60*(uint64_t)60*(uint64_t)1000));
    std::string response = client.fetchFundingFeeIncomeHistory(R"({"startTime":)" + oneYearBeforeFromNow + R"(})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!respDoc["data"]["incomes"].IsArray()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& income : respDoc["data"]["incomes"].GetArray()){
        if(!memberCountChecker(income, 7)){
            return false;
        }
        else if(!income["baseCurrency"].IsString()){
            return false;
        }
        else if(!income["quoteCurrency"].IsString()){
            return false;
        }
        else if(!income["expiration"].IsString()){
            return false;
        }
        else if(!income["symbol"].IsString()){
            return false;
        }
        else if(!income["income"].IsString()){
            return false;
        }
        else if(!income["incomeCurrency"].IsString()){
            return false;
        }
        else if(!income["timestamp"].IsUint64() || income["timestamp"].GetUint64() < 10000000000){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().fetchFundingFeeIncomeHistory";
    std::string oneYearBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch() - ((uint64_t)365*(uint64_t)24*(uint64_t)60*(uint64_t)60*(uint64_t)1000));
    std::string now = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch());
    std::string findValue = R"(METHOD: GET, URL: https://fapi.binance.com/fapi/v1/income?incomeType=FUNDING_FEE&startTime=)" + oneYearBeforeFromNow + R"(&endTime=)"+now;
    testData.expectedResult = findValue + "\n" + R"(
response["success"]:true
response["requestedApiCount"]:1
response["data"]["incomes"] is array
response["data"]["incomes"]["baseCurrency"] is "DOGE"
response["data"]["incomes"]["quoteCurrency"] is "USDT"
response["data"]["incomes"]["expiration"] is "PERP"
response["data"]["incomes"]["symbol"] is "DOGEUSDT"
response["data"]["incomes"]["income"] is string
response["data"]["incomes"]["incomeCurrency"] is string
response["data"]["incomes"]["timestamp"] is uint and greater than 10000000000

member count of response["data"] = 1
member count of response["data"]["incomes"] is 7)";            
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"dOGe","quoteCurrency":"uSdT","expiration":"PerP","startTime":)" + oneYearBeforeFromNow + R"(,"endTime":)" + now + R"(})";
    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchFundingFeeIncomeHistory(input);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::string log = getLog(testStartTime);
    testData.actualResult = log + "\n" + response;

    LOAD_LOGGER_SETTINGS

    if(log.find(findValue) == std::string::npos){
        std::cout << "findValue" << std::endl;
    }

    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(!respDoc["data"]["incomes"].IsArray()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& income : respDoc["data"]["incomes"].GetArray()){
        if(!memberCountChecker(income, 7)){
            return false;
        }
        else if(std::string("DOGE").compare(income["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(income["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(income["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("DOGEUSDT").compare(income["symbol"].GetString()) != 0){
            return false;
        }
        else if(!income["income"].IsString()){
            return false;
        }
        else if(!income["incomeCurrency"].IsString()){
            return false;
        }
        else if(!income["timestamp"].IsUint64() || income["timestamp"].GetUint64() < 10000000000){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeBalance";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.subscribeBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;
    TC_END
}

bool TC_BinanceFutures_unsubscribeBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.unsubscribeBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.unsubscribeBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.unsubscribeBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeBalance";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.unsubscribeBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;
    TC_END
}

bool TC_BinanceFutures_isSubscribingBalance_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":false}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.isSubscribingBalance();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_isSubscribingBalance_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":false}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    std::string response = client.isSubscribingBalance("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_isSubscribingBalance_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().isSubscribingBalance";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"isSubscribing":true}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.isSubscribingBalance("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_isSubscribingBalance_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().isSubscribingBalance";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");
    client.subscribeBalance();
    std::string response = client.isSubscribingBalance("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;
    TC_END
}

static const std::string getOrderRoundingRuleExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyBaseAmount":"round","marketSellBaseAmount":"round"}})";

bool TC_BinanceFutures_getOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getOrderRoundingRule();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getOrderRoundingRule";
    testData.expectedResult = getOrderRoundingRuleExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getOrderRoundingRule(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_setOrderRoundingRule_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setOrderRoundingRule";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"limitBuyBaseAmount":"wrongData"})";
    std::string response = client.setOrderRoundingRule(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_setOrderRoundingRule_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().setOrderRoundingRule";
    testData.expectedResult.clear();
    testData.actualResult.clear();
    std::string getCheckStr = "";
    std::string getExpectedResult = "";
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"ceil","limitBuyBaseAmount":"ceil","limitSellPrice":"ceil","limitSellBaseAmount":"ceil","marketBuyBaseAmount":"ceil","marketSellBaseAmount":"ceil"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"floor","limitBuyBaseAmount":"floor","limitSellPrice":"floor","limitSellBaseAmount":"floor","marketBuyBaseAmount":"floor","marketSellBaseAmount":"floor"}})").append("\n");
    getExpectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{"limitBuyPrice":"round","limitBuyBaseAmount":"round","limitSellPrice":"round","limitSellBaseAmount":"round","marketBuyBaseAmount":"round","marketSellBaseAmount":"round"}})").append("\n");
    OneXAPI::Binance::Futures client;
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
        "marketBuyBaseAmount",
        "marketSellBaseAmount"
    };

    for(const auto& testValue : testValueList){
        for(const auto& testKey : testKeyList){
            testData.expectedResult.append(R"({"success":true,"requestedApiCount":0,"data":{")" + testKey + R"(":")" + testValue + R"("}})" + "\n");
            std::string input = R"({")" + testKey + R"(":")" + testValue + R"("})";
            std::string response = client.setOrderRoundingRule(input);
        
            testData.actualResult.append(response + "\n");

            rapidjson::Document respDoc;
            OneXAPI::Internal::Util::parseJson(respDoc, response);
            if(!memberCountChecker(respDoc["data"], 1)){
                return false;
            }
        }
        getCheckStr.append(client.getOrderRoundingRule() + "\n");
    }

    if(testData.actualResult.compare(testData.expectedResult) == 0 && getCheckStr.compare(getExpectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_orderLimitBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitBuy";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.orderLimitBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderLimitBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=BUY&type=LIMIT&timeInForce=GTC&quantity=35.136&reduceOnly=false&price=25312.1)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderLimitBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitBuy";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=BUY&type=LIMIT&timeInForce=FOK&quantity=35.136&reduceOnly=true&price=26187.9&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","expiration":"peRP","price":25312.1234358,"baseAmount":35.135689342158,"reduceOnly":true,"clientOrderId":"testId","amplifier":1.0346,"type":"fok"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderLimitSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitSell";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.orderLimitSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderLimitSell_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=GTC&quantity=35.136&reduceOnly=false&price=25312.1)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","price":25312.1234358,"baseAmount":35.135689342158})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderLimitSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderLimitSell";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=IOC&quantity=35.136&reduceOnly=true&price=24387.7&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"uSDt","expiration":"peRP","price":25312.1234358,"baseAmount":35.135689342158,"reduceOnly":true,"clientOrderId":"testId","amplifier":0.96348,"type":"ioc"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderMarketBuy_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketBuy";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.orderMarketBuy("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderMarketBuy_2(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=BUY&type=MARKET&quantity=35.136&reduceOnly=false)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","baseAmount":35.135689342158})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderMarketBuy_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketBuy";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=BUY&type=MARKET&quantity=35.136&reduceOnly=true&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","expiration":"peRP","baseAmount":35.135689342158,"reduceOnly":true,"clientOrderId":"testId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderMarketSell_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketSell";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.orderMarketSell("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderMarketSell_2(testDataType& testData){TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=SELL&type=MARKET&quantity=83.134&reduceOnly=false)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","baseAmount":83.1338494835})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderMarketSell_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderMarketSell";
    std::string findValue = R"(METHOD: POST, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&side=SELL&type=MARKET&quantity=83.134&reduceOnly=true&newClientOrderId=testId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","expiration":"peRP","baseAmount":83.1338494835,"reduceOnly":true,"clientOrderId":"testId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderCancel_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().orderCancel";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.orderCancel("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderCancel_2(testDataType& testData){
    TC_BEGIN    

    testData.testSubject = "OneXAPI::Binance::Futures().orderCancel";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.orderCancel(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_orderCancel_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT_123456&orderId=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","expiration":"123456","orderId":"testOrderId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_orderCancel_4(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().orderCancel";
    std::string findValue = R"(METHOD: DEL, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&origClientOrderId=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"usdT","clientOrderId":"testClientOrderId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_fetchOrderInfo_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchOrderInfo("{}");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchOrderInfo_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string input = R"({"orderId":"testOrderId"})";
    std::string response = client.fetchOrderInfo(input);
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchOrderInfo_3(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT&orderId=testOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT","orderId":"testOrderId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_fetchOrderInfo_4(testDataType& testData){
    TC_BEGIN

    SAVE_LOGGER_SETTINGS
    LOGGER.setLevel("info");
    LOGGER.setMethod("file");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    uint64_t testStartTime = OneXAPI::Internal::Util::getCurrentMsEpoch()/1000;
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderInfo";
    std::string findValue = R"(METHOD: GET, URL: https://fapi.binance.com/fapi/v1/order?symbol=BTCUSDT_953215&origClientOrderId=testClientOrderId)";
    testData.expectedResult = findValue;
    testData.actualResult.clear();
    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT","expiration":"953215","clientOrderId":"testClientOrderId"})";
    OneXAPI::Binance::Futures client;

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

bool TC_BinanceFutures_fetchOrderInfo_5(testDataType& testData){
    TC_BEGIN
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderInfo";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:2
response["data"]["baseCurrency"] is string
response["data"]["quoteCurrency"] is string
response["data"]["expiration"] is string
response["data"]["symbol"] is string
response["data"]["orderId"] = orderId
response["data"]["clientOrderId"] is string
response["data"]["side"] = buy
response["data"]["positionSide"] = long
response["data"]["reduceOnly"] is bool
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

member count of response["data"] = 19)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
    else if(orderId.compare(respDoc["data"]["orderId"].GetString()) != 0 || std::string("buy").compare(respDoc["data"]["side"].GetString()) != 0 || 
        std::string("long").compare(respDoc["data"]["positionSide"].GetString()) != 0){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 19)){
        result = false;
    }
    else if( !respDoc["data"]["baseCurrency"].IsString() || !respDoc["data"]["quoteCurrency"].IsString() || !respDoc["data"]["expiration"].IsString() || !respDoc["data"]["symbol"].IsString() ||
        !respDoc["data"]["clientOrderId"].IsString() || !respDoc["data"]["reduceOnly"].IsBool() || !respDoc["data"]["originalAmount"].IsString() || !respDoc["data"]["remainingAmount"].IsString() || 
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

bool TC_BinanceFutures_fetchOpenOrders_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["openOrders"][]["baseCurrency"] is string
response["data"]["openOrders"][]["quoteCurrency"] is string
response["data"]["openOrders"][]["expiration"] is string
response["data"]["openOrders"][]["symbol"] is string
response["data"]["openOrders"][]["orderId"] is string
response["data"]["openOrders"][]["side"] is string
response["data"]["openOrders"][]["positionSide"] is string
response["data"]["openOrders"][]["reduceOnly"] is bool
response["data"]["openOrders"][]["originalAmount"] is string
response["data"]["openOrders"][]["filledAmount"] is string
response["data"]["openOrders"][]["remainingAmount"] is string
response["data"]["openOrders"][]["originalPrice"] is string
response["data"]["openOrders"][]["created"] is uint64

member count of response["data"] = 1
size of response["data"]["openOrders"] is greater than 0
member count of response["data"]["openOrders"][] = 13)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
    else if(!(respDoc["data"]["openOrders"].Size() > 0)){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if(!memberCountChecker(openorder, 13)){
            result = false;
        }
        else if( !openorder["baseCurrency"].IsString() || !openorder["quoteCurrency"].IsString() || !openorder["expiration"].IsString() || 
            !openorder["symbol"].IsString() || !openorder["orderId"].IsString() || !openorder["side"].IsString() || 
            !openorder["positionSide"].IsString()|| !openorder["reduceOnly"].IsBool()  || !openorder["originalAmount"].IsString() ||
            !openorder["filledAmount"].IsString() || !openorder["remainingAmount"].IsString() || !openorder["originalPrice"].IsString() ||
            !openorder["created"].IsUint64()){
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

bool TC_BinanceFutures_fetchOpenOrders_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOpenOrders";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["openOrders"][]["baseCurrency"] is string
response["data"]["openOrders"][]["quoteCurrency"] is string
response["data"]["openOrders"][]["expiration"] is string
response["data"]["openOrders"][]["symbol"] is string
response["data"]["openOrders"][]["orderId"] is string
response["data"]["openOrders"][]["side"] is string
response["data"]["openOrders"][]["positionSide"] is string
response["data"]["openOrders"][]["reduceOnly"] is bool
response["data"]["openOrders"][]["originalAmount"] is string
response["data"]["openOrders"][]["filledAmount"] is string
response["data"]["openOrders"][]["remainingAmount"] is string
response["data"]["openOrders"][]["originalPrice"] is string
response["data"]["openOrders"][]["created"] is uint64

member count of response["data"] = 1
size of response["data"]["openOrders"] is 1
member count of response["data"]["openOrders"][] = 13)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
    std::string response = client.fetchOpenOrders(R"({"baseCurrency":"xRP","quoteCurrency":"uSDt","expiration":"PerP","side":"buy"})");
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
    else if(respDoc["data"]["openOrders"].Size() == 0){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        result = false;
    }
    for(const auto& openorder : respDoc["data"]["openOrders"].GetArray()){
        if(!memberCountChecker(openorder, 13)){
            result = false;
        }
        else if( !openorder["baseCurrency"].IsString() || !openorder["quoteCurrency"].IsString() || !openorder["expiration"].IsString() || 
            !openorder["symbol"].IsString() || !openorder["orderId"].IsString() || !openorder["side"].IsString() || 
            !openorder["positionSide"].IsString()|| !openorder["reduceOnly"].IsBool()  || !openorder["originalAmount"].IsString() ||
            !openorder["filledAmount"].IsString() || !openorder["remainingAmount"].IsString() || !openorder["originalPrice"].IsString() ||
            !openorder["created"].IsUint64()){
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

bool TC_BinanceFutures_fetchTradingFee_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchTradingFee";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchTradingFee(R"({"baseCurrency":"bTC"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchTradingFee_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchTradingFee";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"]:1
response["data"]["fees"] is array
response["data"]["fees"][]["baseCurrency"] = "BTC"
response["data"]["fees"][]["quoteCurrency"] = "USDT"
response["data"]["fees"][]["expiration"] = "PERP"
response["data"]["fees"][]["symbol"] = "BTCUSDT"
response["data"]["fees"][]["makerFee"] is string
response["data"]["fees"][]["takerFee"] is string

member count of response["data"] = 1
size of response["data"]["fees"] is 1
member count of response["data"]["fees"][] = 6)";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string input = R"({"baseCurrency":"bTC","quoteCurrency":"UsdT","expiration":"PerP"})";
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
    else if(!respDoc["data"]["fees"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["fees"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& fee : respDoc["data"]["fees"].GetArray()){
        if(!memberCountChecker(fee, 6)){
            return false;
        }
        else if(std::string("BTC").compare(fee["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(fee["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(fee["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("BTCUSDT").compare(fee["symbol"].GetString()) != 0){
            return false;
        }
        else if(!fee["makerFee"].IsString()){
            return false;
        }
        else if(!fee["takerFee"].IsString()){
            return false;
        }
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchLeverage_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchLeverage";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["fetchType"] = "rest"
response["data"]["leverages"] is array
response["data"]["leverages"][]["baseCurrency"] is string
response["data"]["leverages"][]["quoteCurrency"] is string
response["data"]["leverages"][]["expiration"] is string
response["data"]["leverages"][]["symbol"] is string
response["data"]["leverages"][]["leverage"] is uint

member count of response["data"] = 2
size of response["data"]["leverages"] is greater than 10
member count of response["data"]["leverages"][] = 5)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchLeverage(R"({})");
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
    else if(!respDoc["data"]["leverages"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["leverages"].Size() > 10)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& leverage : respDoc["data"]["leverages"].GetArray()){
        if(!memberCountChecker(leverage, 5)){
            return false;
        }
        else if( !leverage["baseCurrency"].IsString() || !leverage["quoteCurrency"].IsString() || !leverage["expiration"].IsString() || 
            !leverage["symbol"].IsString() || !leverage["leverage"].IsUint64()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchLeverage_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchLeverage";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["fetchType"] = "rest"
response["data"]["leverages"] is array
response["data"]["leverages"][]["baseCurrency"] = "BTC"
response["data"]["leverages"][]["quoteCurrency"] = "USDT"
response["data"]["leverages"][]["expiration"] = "PERP"
response["data"]["leverages"][]["symbol"] = "BTCUSDT"
response["data"]["leverages"][]["leverage"] is uint

member count of response["data"] = 2
size of response["data"]["leverages"] is 1
member count of response["data"]["leverages"][] = 5)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchLeverage(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
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
    else if(!respDoc["data"]["leverages"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["leverages"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& leverage : respDoc["data"]["leverages"].GetArray()){
        if(!memberCountChecker(leverage, 5)){
            return false;
        }
        else if(std::string("BTC").compare(leverage["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(leverage["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(leverage["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("BTCUSDT").compare(leverage["symbol"].GetString()) != 0){
            return false;
        }
        else if(!leverage["leverage"].IsUint64()){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchLeverage_3(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchLeverage";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 0
response["data"]["fetchType"] is "websocket"
response["data"]["leverages"] is array
response["data"]["leverages"][]["baseCurrency"] : "ETH"
response["data"]["leverages"][]["quoteCurrency"] is string
response["data"]["leverages"][]["expiration"] is string
response["data"]["leverages"][]["symbol"] is string
response["data"]["leverages"][]["leverage"] is uint64

member count of response["data"]["leverages"][] = 5
member count of response["data"] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchLeverage(R"({"baseCurrency":"eth"})");

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
    else if(respDoc["data"]["leverages"].IsArray() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& leverage : respDoc["data"]["leverages"].GetArray()){
        if(std::string("ETH").compare(leverage["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(leverage["quoteCurrency"].IsString() != true){
            return false;
        }
        if(leverage["expiration"].IsString() != true){
            return false;
        }
        if(leverage["symbol"].IsString() != true){
            return false;
        }
        if(leverage["leverage"].IsUint64() != true){
            return false;
        }

        if(!memberCountChecker(leverage, 5)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchLeverage_4(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchLeverage";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["fetchType"] is "rest"
response["data"]["leverages"] is array
response["data"]["leverages"][]["baseCurrency"] : "ETH"
response["data"]["leverages"][]["quoteCurrency"] is string
response["data"]["leverages"][]["expiration"] is string
response["data"]["leverages"][]["symbol"] is string
response["data"]["leverages"][]["leverage"] is uint64

member count of response["data"]["leverages"][] = 5
member count of response["data"] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchLeverage(R"({"baseCurrency":"eth", "forceRestApi": true})");

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
    else if(respDoc["data"]["leverages"].IsArray() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& leverage : respDoc["data"]["leverages"].GetArray()){
        if(std::string("ETH").compare(leverage["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(leverage["quoteCurrency"].IsString() != true){
            return false;
        }
        if(leverage["expiration"].IsString() != true){
            return false;
        }
        if(leverage["symbol"].IsString() != true){
            return false;
        }
        if(leverage["leverage"].IsUint64() != true){
            return false;
        }

        if(!memberCountChecker(leverage, 5)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_changeLeverage_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().changeLeverage";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.changeLeverage(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_changeLeverage_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().changeLeverage";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["baseCurrency"] is "BTC"
response["data"]["quoteCurrency"] is "USDT"
response["data"]["expiration"] is "PERP"
response["data"]["symbol"] is "BTCUSDT"
response["data"]["leverage"] is 5

member count of response["data"] = 5)";

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string responsePre = client.fetchLeverage(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
    rapidjson::Document respPreDoc;
    OneXAPI::Internal::Util::parseJson(respPreDoc, responsePre);

    if(!respPreDoc["success"].GetBool()){
        return false;
    }
    else if(respPreDoc["data"]["leverages"].Size() != 1){
        return false;
    }
    uint64_t leverage = respPreDoc["data"]["leverages"][0]["leverage"].GetUint64();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::string response = client.changeLeverage(R"({"baseCurrency":"bTC","quoteCurrency":"usDT","expiration":"perP","leverage":5})");
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
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        result = false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        result = false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        result = false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        result = false;
    }
    else if(respDoc["data"]["leverage"].GetUint64() != 5){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 5)){
        result = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string responsePost = client.changeLeverage(R"({"baseCurrency":"bTC","quoteCurrency":"usDT","expiration":"perP","leverage":)" + std::to_string(leverage) + R"(})");
    rapidjson::Document respDocPost;
    OneXAPI::Internal::Util::parseJson(respDocPost, responsePost);
    if(!respDocPost["success"].GetBool()){
        result = false;
    }
    
    return result;

    TC_END
}

bool TC_BinanceFutures_fetchMarginType_1(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarginType";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["fetchType"] = "rest"
response["data"]["marginTypes"] is array
response["data"]["marginTypes"][]["baseCurrency"] is string
response["data"]["marginTypes"][]["quoteCurrency"] is string
response["data"]["marginTypes"][]["expiration"] is string
response["data"]["marginTypes"][]["symbol"] is string
response["data"]["marginTypes"][]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
size of response["data"]["marginTypes"] is greater than 10
member count of response["data"]["marginTypes"][] = 5)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchMarginType(R"({})");
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
    else if(!respDoc["data"]["marginTypes"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["marginTypes"].Size() > 10)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& marginType : respDoc["data"]["marginTypes"].GetArray()){
        if(!memberCountChecker(marginType, 5)){
            return false;
        }
        else if( !marginType["baseCurrency"].IsString() || !marginType["quoteCurrency"].IsString() || !marginType["expiration"].IsString() || 
            !marginType["symbol"].IsString()){
            return false;
        }
        else if(std::string("cross").compare(marginType["marginType"].GetString()) != 0 && std::string("isolated").compare(marginType["marginType"].GetString()) != 0){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarginType_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarginType";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["fetchType"] = "rest"
response["data"]["marginTypes"] is array
response["data"]["marginTypes"][]["baseCurrency"] = "BTC"
response["data"]["marginTypes"][]["quoteCurrency"] = "USDT"
response["data"]["marginTypes"][]["expiration"] = "PERP"
response["data"]["marginTypes"][]["symbol"] = "BTCUSDT"
response["data"]["marginTypes"][]["marginType"] is "cross" or "isolated"

member count of response["data"] = 2
size of response["data"]["marginTypes"] is 1
member count of response["data"]["marginTypes"][] = 5)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.fetchMarginType(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
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
    else if(!respDoc["data"]["marginTypes"].IsArray()){
        return false;
    }
    else if(respDoc["data"]["marginTypes"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    for(const auto& marginType : respDoc["data"]["marginTypes"].GetArray()){
        if(!memberCountChecker(marginType, 5)){
            return false;
        }
        else if(std::string("BTC").compare(marginType["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(marginType["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(marginType["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("BTCUSDT").compare(marginType["symbol"].GetString()) != 0){
            return false;
        }
        else if(std::string("cross").compare(marginType["marginType"].GetString()) != 0 && std::string("isolated").compare(marginType["marginType"].GetString()) != 0){
            return false;
        }
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarginType_3(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarginType";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 0
response["data"]["fetchType"] is "websocket"
response["data"]["marginTypes"] is array
response["data"]["marginTypes"][]["baseCurrency"] : "ETH"
response["data"]["marginTypes"][]["quoteCurrency"] is string
response["data"]["marginTypes"][]["expiration"] is string
response["data"]["marginTypes"][]["symbol"] is string
response["data"]["marginTypes"][]["marginType"] is "cross" or "isolated"

member count of response["data"]["marginTypes"][] = 5
member count of response["data"] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchMarginType(R"({"baseCurrency":"eth"})");

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
    else if(respDoc["data"]["marginTypes"].IsArray() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& marginType : respDoc["data"]["marginTypes"].GetArray()){
        if(std::string("ETH").compare(marginType["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(marginType["quoteCurrency"].IsString() != true){
            return false;
        }
        if(marginType["expiration"].IsString() != true){
            return false;
        }
        if(marginType["symbol"].IsString() != true){
            return false;
        }
        if(marginType["marginType"].IsString()){
            std::string type = marginType["marginType"].GetString();
            if(!(type.compare("isolated") == 0 || type.compare("cross") == 0)){
                return false;
            }
        }
        else{
            return false;
        }

        if(!memberCountChecker(marginType, 5)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchMarginType_4(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarginType";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["fetchType"] is "rest"
response["data"]["marginTypes"] is array
response["data"]["marginTypes"][]["baseCurrency"] : "ETH"
response["data"]["marginTypes"][]["quoteCurrency"] is string
response["data"]["marginTypes"][]["expiration"] is string
response["data"]["marginTypes"][]["symbol"] is string
response["data"]["marginTypes"][]["marginType"] is "cross" or "isolated"

member count of response["data"]["marginTypes"][] = 5
member count of response["data"] = 2)";
    testData.actualResult.clear();

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    client.subscribeBalance();
    std::string response = client.fetchMarginType(R"({"baseCurrency":"eth", "forceRestApi": true})");

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
    else if(respDoc["data"]["marginTypes"].IsArray() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }

    for(const auto& marginType : respDoc["data"]["marginTypes"].GetArray()){
        if(std::string("ETH").compare(marginType["baseCurrency"].GetString()) != 0){
            return false;
        }
        if(marginType["quoteCurrency"].IsString() != true){
            return false;
        }
        if(marginType["expiration"].IsString() != true){
            return false;
        }
        if(marginType["symbol"].IsString() != true){
            return false;
        }
        if(marginType["marginType"].IsString()){
            std::string type = marginType["marginType"].GetString();
            if(!(type.compare("isolated") == 0 || type.compare("cross") == 0)){
                return false;
            }
        }
        else{
            return false;
        }

        if(!memberCountChecker(marginType, 5)){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_changeMarginType_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().changeMarginType";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.changeMarginType(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_changeMarginType_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().changeMarginType";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["baseCurrency"] is "BTC"
response["data"]["quoteCurrency"] is "USDT"
response["data"]["expiration"] is "PERP"
response["data"]["symbol"] is "BTCUSDT"
response["data"]["marginType"] is requested value

member count of response["data"] = 5)";

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string responsePre = client.fetchMarginType(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
    rapidjson::Document respPreDoc;
    OneXAPI::Internal::Util::parseJson(respPreDoc, responsePre);

    if(!respPreDoc["success"].GetBool()){
        return false;
    }
    else if(respPreDoc["data"]["marginTypes"].Size() != 1){
        return false;
    }
    std::string currentType = respPreDoc["data"]["marginTypes"][0]["marginType"].GetString();
    std::string reqType = "cross";
    if(currentType.compare("cross") == 0){
        reqType = "isolated";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string response = client.changeMarginType(R"({"baseCurrency":"bTC","quoteCurrency":"usDT","expiration":"perP","marginType":")" + reqType + R"("})");
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
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        result = false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        result = false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        result = false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        result = false;
    }
    else if(reqType.compare(respDoc["data"]["marginType"].GetString()) != 0){
        result = false;
    }
    else if(!memberCountChecker(respDoc["data"], 5)){
        result = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string responsePost = client.changeMarginType(R"({"baseCurrency":"bTC","quoteCurrency":"usDT","expiration":"perP","marginType":")" + currentType + R"("})");
    rapidjson::Document respDocPost;
    OneXAPI::Internal::Util::parseJson(respDocPost, responsePost);
    if(!respDocPost["success"].GetBool()){
        result = false;
    }
    
    return result;

    TC_END
}

static const std::string getCandleIntervalCandidatesExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"intervals":["12hour","15min","1day","1hour","1min","1month","1week","2hour","30min","3day","3min","4hour","5min","6hour","8hour"]}})";

bool TC_BinanceFutures_getCandleIntervalCandidates_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Binance::Futures client;

    std::string response = client.getCandleIntervalCandidates();

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getCandleIntervalCandidates_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getCandleIntervalCandidates";
    testData.expectedResult = getCandleIntervalCandidatesExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getCandleIntervalCandidates(input);

    testData.actualResult = response;
    
    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_fetchMarkets_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["markets"][]["baseCurrency"] is string
response["data"]["markets"][]["quoteCurrency"] is string
response["data"]["markets"][]["expiration"] is string
response["data"]["markets"][]["symbol"] is string

member count of response["data"] = 1
size of response["data"]["markets"] is greater than 0
member count of response["data"]["markets"][] = 4)";

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

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
    else if(!(respDoc["data"]["markets"].Size() > 0)){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!memberCountChecker(market, 4)){
            return false;
        }
        else if(!market["baseCurrency"].IsString() || !market["quoteCurrency"].IsString() || !market["expiration"].IsString() || !market["symbol"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarkets_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarkets";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["markets"][]["baseCurrency"] is "BTC"
response["data"]["markets"][]["quoteCurrency"] is "USDT"
response["data"]["markets"][]["expiration"] is "PERP"
response["data"]["markets"][]["symbol"] is "BTCUSDT"

member count of response["data"] = 1
size of response["data"]["markets"] is 1
member count of response["data"]["markets"][] = 4)";

    OneXAPI::Binance::Futures client(std::string(R"({"accessKey":")") + BINANCE_FUTURES_ACCESS_KEY + R"(", "secretKey":")" + BINANCE_FUTURES_SECRET_KEY + R"("})");

    std::string response = client.fetchMarkets(R"({"baseCurrency":"bTC","quoteCurrency":"usDT","expiration":"perP"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(respDoc["data"]["markets"].Size() != 1){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 1)){
        return false;
    }
    for(const auto& market : respDoc["data"]["markets"].GetArray()){
        if(!memberCountChecker(market, 4)){
            return false;
        }
        else if(std::string("BTC").compare(market["baseCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("USDT").compare(market["quoteCurrency"].GetString()) != 0){
            return false;
        }
        else if(std::string("PERP").compare(market["expiration"].GetString()) != 0){
            return false;
        }
        else if(std::string("BTCUSDT").compare(market["symbol"].GetString()) != 0){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarketInfo_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchMarketInfo(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarketInfo_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarketInfo";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["fetchType"] = "rest"
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["markPrice"] is string
response["data"]["fundingRate"] is string
response["data"]["nextFundingTime"] is uint

member count of response["data"] = 8)";

    OneXAPI::Binance::Futures client;

    std::string response = client.fetchMarketInfo(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
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
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        return false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    else if(!respDoc["data"]["markPrice"].IsString() || !respDoc["data"]["fundingRate"].IsString() || !respDoc["data"]["nextFundingTime"].IsUint64()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 8)){
        return false;
    }
    
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchMarketInfo_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarketInfo";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 0
response["data"]["fetchType"] is "websocket"
response["data"]["baseCurrency"] : "ETH"
response["data"]["quoteCurrency"] : "USDT"
response["data"]["expiration"] is string
response["data"]["symbol"] is string
response["data"]["markPrice"] is string
response["data"]["fundingRate"] is string
response["data"]["nextFundingTime"] is uint64
member count of response["data"] = 8)";

    OneXAPI::Binance::Futures client;

    client.subscribeMarketInfo(R"({"market":[{"baseCurrency": "eTh", "quoteCurrency": "uSdT"}]})");
    std::string response = client.fetchMarketInfo(R"({"baseCurrency": "eTh", "quoteCurrency": "uSdT"})");
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
    else if(std::string("ETH").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(respDoc["data"]["expiration"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["symbol"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["markPrice"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["fundingRate"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["nextFundingTime"].IsUint64() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 8)){
        return false;
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchMarketInfo_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().fetchMarketInfo";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is 1
response["data"]["fetchType"] is "rest"
response["data"]["baseCurrency"] : "ETH"
response["data"]["quoteCurrency"] is string
response["data"]["expiration"] is string
response["data"]["symbol"] is string
response["data"]["markPrice"] is string
response["data"]["fundingRate"] is string
response["data"]["nextFundingTime"] is uint64
member count of response["data"] = 8)";

    OneXAPI::Binance::Futures client;

    client.subscribeMarketInfo(R"({"market":[{"baseCurrency": "eTh", "quoteCurrency": "uSdT"}]})");
    std::string response = client.fetchMarketInfo(R"({"baseCurrency": "eTh", "quoteCurrency": "uSdT", "forceRestApi": true})");
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
    else if(std::string("ETH").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(respDoc["data"]["quoteCurrency"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["expiration"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["symbol"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["markPrice"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["fundingRate"].IsString() != true){
        return false;
    }
    else if(respDoc["data"]["nextFundingTime"].IsUint64() != true){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 8)){
        return false;
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_fetchTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchTicker(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchTicker_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["openTime"] is uint64
response["data"]["openPrice"] is string
response["data"]["closePrice"] is string
response["data"]["lowPrice"] is string
response["data"]["highPrice"] is string
response["data"]["baseVolume"] is string
response["data"]["quoteVolume"] is string

member count of response["data"] = 12)";

    OneXAPI::Binance::Futures client;

    std::string response = client.fetchTicker(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
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
    else if(!memberCountChecker(respDoc["data"], 12)){
        return false;
    }
    
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchTicker_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 0
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "websocket"
response["data"]["openTime"]:uint64
response["data"]["openPrice"]:string
response["data"]["closePrice"]:string
response["data"]["lowPrice"]:string
response["data"]["highPrice"]:string
response["data"]["baseVolume"]:string
response["data"]["quoteVolume"]:string

member count of response["data"] = 12)";

    OneXAPI::Binance::Futures client;

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
    if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        return false;
    }
    if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    if(std::string("websocket").compare(respDoc["data"]["fetchType"].GetString()) != 0){
        return false;
    }
    if(!respDoc["data"]["openTime"].IsUint64() || !respDoc["data"]["openPrice"].IsString() || !respDoc["data"]["closePrice"].IsString() || !respDoc["data"]["lowPrice"].IsString() ||
        !respDoc["data"]["highPrice"].IsString() || !respDoc["data"]["baseVolume"].IsString() || !respDoc["data"]["quoteVolume"].IsString()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 12)){
        return false;
    }
    
    return true;
    TC_END
}

bool TC_BinanceFutures_fetchTicker_4(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchTicker";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["openTime"]:uint64
response["data"]["openPrice"]:string
response["data"]["closePrice"]:string
response["data"]["lowPrice"]:string
response["data"]["highPrice"]:string
response["data"]["baseVolume"]:string
response["data"]["quoteVolume"]:string

member count of response["data"] = 12)";

    OneXAPI::Binance::Futures client;

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
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
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
    else if(!memberCountChecker(respDoc["data"], 12)){
        return false;
    }
    
    return true;
    TC_END
}

bool TC_BinanceFutures_fetchOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchOrderbook(R"({})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchOrderbook_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "rest"
response["data"]["timestamp"] is uint64
response["data"]["bids"][]["price"] is string
response["data"]["bids"][]["size"] is string
response["data"]["asks"][]["price"] is string
response["data"]["asks"][]["size"] is string

member count of response["data"] = 8
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Futures client;

    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt","expiration":"peRp"})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
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
    else if(!memberCountChecker(respDoc["data"], 8)){
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

bool TC_BinanceFutures_fetchOrderbook_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 0
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["expiration"] = "PERP"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["fetchType"] = "websocket"
response["data"]["timestamp"]:uint64
response["data"]["bids"][]["price"]:string
response["data"]["bids"][]["size"]:string
response["data"]["asks"][]["price"]:string
response["data"]["asks"][]["size"]:string

member count of response["data"] = 8
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Futures client;

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
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
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
    else if(!memberCountChecker(respDoc["data"], 8)){
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

bool TC_BinanceFutures_fetchOrderbook_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().fetchOrderbook";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] = 1
response["data"]["baseCurrency"] = "BTC"
response["data"]["quoteCurrency"] = "USDT"
response["data"]["symbol"] = "BTCUSDT"
response["data"]["expiration"] = "PERP"
response["data"]["fetchType"] = "rest"
response["data"]["timestamp"]:uint64
response["data"]["bids"][]["price"]:string
response["data"]["bids"][]["size"]:string
response["data"]["asks"][]["price"]:string
response["data"]["asks"][]["size"]:string

member count of response["data"] = 8
member count of response["data"]["bids"][] = 2
member count of response["data"]["asks"][] = 2)";

    OneXAPI::Binance::Futures client;

    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"bTc","quoteCurrency":"USdt"}]})");
    std::string response = client.fetchOrderbook(R"({"baseCurrency":"bTc","quoteCurrency":"USdt", "forceRestApi": true})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(respDoc["requestedApiCount"].GetUint() != 1){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
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
    else if(!memberCountChecker(respDoc["data"], 8)){
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

bool TC_BinanceFutures_fetchCandleHistory_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().fetchCandleHistory";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";
    testData.actualResult.clear();
    OneXAPI::Binance::Futures client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT"})");
        
    testData.actualResult = response;

    if(!errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchCandleHistory_2(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is uint64
response["data"]["baseCurrency"] is "BTC"
response["data"]["quoteCurrency"] is "USDT"
response["data"]["expiration"] is "PERP"
response["data"]["symbol"] is "BTCUSDT"
response["data"]["candles"][]["timestamp"] is uint64
response["data"]["candles"][]["openPrice"] is string
response["data"]["candles"][]["closePrice"] is string
response["data"]["candles"][]["highPrice"] is string
response["data"]["candles"][]["lowPrice"] is string
response["data"]["candles"][]["baseVolume"] is string
response["data"]["candles"][]["quoteVolume"] is string

member count of response["data"] = 5
size of response["data"]["candles"] is greater than 100
member count of response["data"]["candles"][] = 7)";

    OneXAPI::Binance::Futures client;

    std::string twoHrBeforeFromNow = std::to_string(OneXAPI::Internal::Util::getCurrentMsEpoch()/1000 - 7200);
    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","interval":"1min","startTime":)" + twoHrBeforeFromNow + R"(})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(!respDoc["requestedApiCount"].IsUint64()){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        return false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    else if(respDoc["data"]["candles"].Size() <= 100){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 5)){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if(!memberCountChecker(candle, 7)){
            return false;
        }
        else if( !candle["timestamp"].IsUint64() || !candle["openPrice"].IsString() || !candle["closePrice"].IsString() || !candle["highPrice"].IsString() ||
            !candle["lowPrice"].IsString() || !candle["baseVolume"].IsString() || !candle["quoteVolume"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

bool TC_BinanceFutures_fetchCandleHistory_3(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    testData.testSubject = "OneXAPI::Binance::Futures().fetchCandleHistory";
    testData.expectedResult = R"(response["success"]:true
response["requestedApiCount"] is uint64
response["data"]["baseCurrency"] is "BTC"
response["data"]["quoteCurrency"] is "USDT"
response["data"]["expiration"] is "PERP"
response["data"]["symbol"] is "BTCUSDT"
response["data"]["candles"][]["timestamp"] is uint64
response["data"]["candles"][]["openPrice"] is string
response["data"]["candles"][]["closePrice"] is string
response["data"]["candles"][]["highPrice"] is string
response["data"]["candles"][]["lowPrice"] is string
response["data"]["candles"][]["baseVolume"] is string
response["data"]["candles"][]["quoteVolume"] is string

member count of response["data"] = 5
size of response["data"]["candles"] is greater than 300
member count of response["data"]["candles"][] = 7)";

    OneXAPI::Binance::Futures client;

    std::string response = client.fetchCandleHistory(R"({"baseCurrency":"bTc","quoteCurrency":"uSdT","expiration":"peRp","interval":"1min","startTime":1656042045,"endTime":1656063182,"fetchInterval":900})");
    testData.actualResult = response;
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);

    if(!successResponseChecker(response)){
        return false;
    }
    else if(!respDoc["requestedApiCount"].IsUint64()){
        return false;
    }
    else if(std::string("BTC").compare(respDoc["data"]["baseCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("USDT").compare(respDoc["data"]["quoteCurrency"].GetString()) != 0){
        return false;
    }
    else if(std::string("PERP").compare(respDoc["data"]["expiration"].GetString()) != 0){
        return false;
    }
    else if(std::string("BTCUSDT").compare(respDoc["data"]["symbol"].GetString()) != 0){
        return false;
    }
    else if(respDoc["data"]["candles"].Size() <= 300){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 5)){
        return false;
    }
    for(const auto& candle : respDoc["data"]["candles"].GetArray()){
        if(!memberCountChecker(candle, 7)){
            return false;
        }
        else if( !candle["timestamp"].IsUint64() || !candle["openPrice"].IsString() || !candle["closePrice"].IsString() || !candle["highPrice"].IsString() ||
            !candle["lowPrice"].IsString() || !candle["baseVolume"].IsString() || !candle["quoteVolume"].IsString()){
            return false;
        }
    }
    
    return true;

    TC_END
}

static const std::string getSubscribingMarketInfoExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[]}})";

bool TC_BinanceFutures_getSubscribingMarketInfo_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingMarketInfo";
    testData.expectedResult = getSubscribingMarketInfoExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingMarketInfo();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_getSubscribingMarketInfo_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingMarketInfo";
    testData.expectedResult = getSubscribingMarketInfoExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingMarketInfo("");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_getSubscribingMarketInfo_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingMarketInfo";
    testData.expectedResult = getSubscribingMarketInfoExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingMarketInfo("{}");

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_getSubscribingMarketInfo_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingMarketInfo("Bqbqb@");

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;
    TC_END
}

bool TC_BinanceFutures_getSubscribingMarketInfo_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeMarketInfo(R"({"market":[{"baseCurrency":"BtC","quoteCurrency":"uSdT"}, {"baseCurrency":"eTh","quoteCurrency":"uSdT"}]})");
    std::string response = client.getSubscribingMarketInfo();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }
    TC_END
}

static const std::string getSubscribingTickersExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"tickers":[]}})";

bool TC_BinanceFutures_getSubscribingTickers_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingTickers_2(testDataType& testData){
    TC_BEGIN
    
    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingTickers_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingTickers";
    testData.expectedResult = getSubscribingTickersExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingTickers_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingTickers";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingTickers(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_getSubscribingTickers_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingTickers";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");
    std::string response = client.getSubscribingTickers();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

static const std::string getSubscribingOrderbooksExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[]}})";

bool TC_BinanceFutures_getSubscribingOrderbooks_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingOrderbooks_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingOrderbooks_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingOrderbooks";
    testData.expectedResult = getSubscribingOrderbooksExpectedResult;

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_getSubscribingOrderbooks_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.getSubscribingOrderbooks(input);

    testData.actualResult = response;

    if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_getSubscribingOrderbooks_5(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().getSubscribingOrderbooks";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");
    std::string response = client.getSubscribingOrderbooks();

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.subscribeMarketInfo();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    
    for(int i = 0; i < 10; i++){
        OneXAPI::Binance::Futures client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeMarketInfo(input);

        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        response = client.getSubscribingMarketInfo();

        testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}]}})");
        testData.actualResult.append("\n").append(response);

        if(testData.actualResult.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}],"subscribeFailed":[]}})");
    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
    response = client.subscribeMarketInfo(input);

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);
    
    client.unsubscribeMarketInfo(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}],"requestTimeout":0})");
    
    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"(orderbook : response["requestedApiCount"] is N
otherwise : response["requestedApiCount"] is 0
N is request market size

size of response["data"]["subscribed"] greater than 25

member count of response["data"] is 2
response["data"]["subscribed"] type is array
response["data"]["subscribeFailed"] type is array

member count of response["data"]["subscribed"][] is 4
member count of response["data"]["subscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},.....................................]}}

Element in subscribed list of result 1 must be in funcName list
Element in subscribeFailed list of result 1 must not be in funcName list

member count of response["data"] is 1
response["data"]["funcName"] type is array
member count of response["data"]["funcName"][] is 4

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeMarketInfo(input);

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
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
        return false;
    }
    else if(!respDoc["data"]["subscribeFailed"].IsArray()){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;

    for(const auto& object : respDoc["data"]["subscribed"].GetArray()){
        if(!memberCountChecker(object, 4)){
            return false;
        }
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : respDoc["data"]["subscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
            return false;
        }
        subscribeFailedList.emplace_back(object["symbol"].GetString());
    }
    
    response = client.getSubscribingMarketInfo();

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
    else if(respDoc["data"]["marketInfo"].Size() != subscribedList.size()){
        return false;
    }

    for(const auto& marketInfo : respDoc["data"]["marketInfo"].GetArray()){
        std::string symbol = marketInfo["symbol"].GetString();
        if(!memberCountChecker(marketInfo, 4)){
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

bool TC_BinanceFutures_subscribeMarketInfo_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeMarketInfo_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[]}})");
    response = client.subscribeMarketInfo(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_1(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.unsubscribeMarketInfo();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_2(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_3(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_4(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }
    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeMarketInfo(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    
    OneXAPI::Binance::Futures client;
    client.subscribeMarketInfo(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}],"reconnect":true})";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_7(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}.........................],"unsubscribeFailed":[]}}

unsubscribe request same as pre-condition subscribe request

member count of response["data"] is 2
response["data"]["unsubscribed"] type is array
response["data"]["unsubscribeFailed"] type is array

member count of response["data"]["unsubscribed"][] is 4
member count of response["data"]["unsubscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[]}}

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
        rapidjson::Value objectValue(rapidjson::kObjectType);

        objectValue.AddMember("baseCurrency", baseCurrency, requestDoc.GetAllocator());
        objectValue.AddMember("quoteCurrency", "USDT", requestDoc.GetAllocator());
        requestDoc["market"].PushBack(objectValue, requestDoc.GetAllocator());
    }

    std::string input = OneXAPI::Internal::Util::jsonToString(requestDoc);
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;

    OneXAPI::Internal::Util::parseJson(respDoc, response);
    if(!successResponseChecker(response)){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
        return false;
    }

    response = client.unsubscribeMarketInfo(input);

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
        if(!memberCountChecker(object, 4)){
            return false;
        }
    }

    for(const auto& object : respDoc["data"]["unsubscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
            return false;
        }
    }

    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    std::string getSubscribingExpectedRes = R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[]}})";

    if(response.compare(getSubscribingExpectedRes) != 0){
        return false;
    }
    return true;
    
    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeMarketInfo(input);

    testData.actualResult = response;

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_unsubscribeMarketInfo_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeMarketInfo";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeMarketInfo(input);

    testData.actualResult = response;
    
    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"marketInfo":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingMarketInfo();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[]}})");
    response = client.unsubscribeMarketInfo(R"({"market":[],"reconnect":true})");
    
    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;
    
    TC_END
}

bool TC_BinanceFutures_subscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.subscribeTicker();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";

    for(int i = 0; i < 10; i++){
        OneXAPI::Binance::Futures client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeTicker(input);

        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        response = client.getSubscribingTickers();

        testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}]}})");
        testData.actualResult.append("\n").append(response);

        if(testData.actualResult.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_subscribeTicker_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}],"subscribeFailed":[]}})");
    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
    response = client.subscribeTicker(input);

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);
    
    client.unsubscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}],"requestTimeout":0})");
    
    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"(orderbook : response["requestedApiCount"] is N
otherwise : response["requestedApiCount"] is 0
N is request market size

size of response["data"]["subscribed"] greater than 25

member count of response["data"] is 2
response["data"]["subscribed"] type is array
response["data"]["subscribeFailed"] type is array

member count of response["data"]["subscribed"][] is 4
member count of response["data"]["subscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},.....................................]}}

Element in subscribed list of result 1 must be in funcName list
Element in subscribeFailed list of result 1 must not be in funcName list

member count of response["data"] is 1
response["data"]["funcName"] type is array
member count of response["data"]["funcName"][] is 4

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
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
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
        return false;
    }
    else if(!respDoc["data"]["subscribeFailed"].IsArray()){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;

    for(const auto& object : respDoc["data"]["subscribed"].GetArray()){
        if(!memberCountChecker(object, 4)){
            return false;
        }
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : respDoc["data"]["subscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
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
        if(!memberCountChecker(ticker, 4)){
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

bool TC_BinanceFutures_subscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeTicker_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
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

bool TC_BinanceFutures_unsubscribeTicker_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.unsubscribeTicker();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    
    OneXAPI::Binance::Futures client;
    client.subscribeTicker(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}],"reconnect":true})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingTickers();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_7(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}.........................],"unsubscribeFailed":[]}}

unsubscribe request same as pre-condition subscribe request

member count of response["data"] is 2
response["data"]["unsubscribed"] type is array
response["data"]["unsubscribeFailed"] type is array

member count of response["data"]["unsubscribed"][] is 4
member count of response["data"]["unsubscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[]}}

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
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
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
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
        if(!memberCountChecker(object, 4)){
            return false;
        }
    }

    for(const auto& object : respDoc["data"]["unsubscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
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

bool TC_BinanceFutures_unsubscribeTicker_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeTicker(input);

    testData.actualResult = response;

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_unsubscribeTicker_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeTicker";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeTicker(input);

    testData.actualResult = response;
    
    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"tickers":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
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

bool TC_BinanceFutures_subscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.subscribeOrderbook();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_5(testDataType& testData){
    TC_BEGIN
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";

    for(int i = 0; i < 10; i++){
        OneXAPI::Binance::Futures client;
        
        std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
        std::string response = client.subscribeOrderbook(input);

        testData.expectedResult = R"({"success":true,"requestedApiCount":1,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"subscribeFailed":[]}})";
        testData.actualResult = response;

        response = client.getSubscribingOrderbooks();

        testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}]}})");
        testData.actualResult.append("\n").append(response);

        if(testData.actualResult.compare(testData.expectedResult) != 0){
            return false;
        }
    }

    return true;
    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"subscribed":[{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}],"subscribeFailed":[]}})");
    input = R"({"market":[{"baseCurrency":"XRP","quoteCurrency":"USDT"}], "reconnect": true})";
    response = client.subscribeOrderbook(input);

    testData.actualResult.append("\n").append(response);

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"},{"baseCurrency":"XRP","quoteCurrency":"USDT","expiration":"PERP","symbol":"XRPUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);
    
    client.unsubscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"BTC"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}],"requestTimeout":0})");
    
    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_7(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"(orderbook : response["requestedApiCount"] is N
otherwise : response["requestedApiCount"] is 0
N is request market size

size of response["data"]["subscribed"] greater than 25

member count of response["data"] is 2
response["data"]["subscribed"] type is array
response["data"]["subscribeFailed"] type is array

member count of response["data"]["subscribed"][] is 4
member count of response["data"]["subscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},.....................................]}}

Element in subscribed list of result 1 must be in funcName list
Element in subscribeFailed list of result 1 must not be in funcName list

member count of response["data"] is 1
response["data"]["funcName"] type is array
member count of response["data"]["funcName"][] is 4

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};
        
    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
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
    else if(respDoc["requestedApiCount"].GetUint() != allCurrencies.size()){
        return false;
    }
    else if(!memberCountChecker(respDoc["data"], 2)){
        return false;
    }
    else if(!respDoc["data"]["subscribed"].IsArray()){
        return false;
    }
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
        return false;
    }
    else if(!respDoc["data"]["subscribeFailed"].IsArray()){
        return false;
    }

    std::vector<std::string> subscribedList, subscribeFailedList;

    for(const auto& object : respDoc["data"]["subscribed"].GetArray()){
        if(!memberCountChecker(object, 4)){
            return false;
        }
        subscribedList.emplace_back(object["symbol"].GetString());
    }

    for(const auto& object : respDoc["data"]["subscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
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
        if(!memberCountChecker(orderbook, 4)){
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

bool TC_BinanceFutures_subscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":1,"data":{"subscribed":[],"subscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    if(response.compare(testData.expectedResult) != 0){
        return false;
    }

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }
    return true;

    TC_END
}

bool TC_BinanceFutures_subscribeOrderbook_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().subscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
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

bool TC_BinanceFutures_unsubscribeOrderbook_1(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string response = client.unsubscribeOrderbook();

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_2(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_3(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"NOT_ENOUGH_PARAM","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "{}";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "NOT_ENOUGH_PARAM", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_4(testDataType& testData){
    TC_BEGIN

    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":false,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":"~~~"}})";

    OneXAPI::Binance::Futures client;
    std::string input = "Bqbqb@";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_5(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_6(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    
    OneXAPI::Binance::Futures client;
    client.subscribeOrderbook(R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})");

    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}],"unsubscribeFailed":[]}})";
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"}],"reconnect":true})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
    response = client.getSubscribingOrderbooks();

    testData.actualResult.append("\n").append(response);

    if(testData.actualResult.compare(testData.expectedResult) == 0){
        return true;
    }

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_7(testDataType& testData){
    TC_BEGIN
    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"}.........................],"unsubscribeFailed":[]}}

unsubscribe request same as pre-condition subscribe request

member count of response["data"] is 2
response["data"]["unsubscribed"] type is array
response["data"]["unsubscribeFailed"] type is array

member count of response["data"]["unsubscribed"][] is 4
member count of response["data"]["unsubscribeFailed"][] is 4

{"success":true,"requestedApiCount":0,"data":{"funcName":[]}}

funcName is getSubscribing Type
getSubscribingTickers -> funcName = tickers
getSubscribingOrderbooks -> funcName = orderbooks
getSubscribingMarketInfo -> funcName = marketInfo)";

    OneXAPI::Binance::Futures client;
    std::vector<std::string> allCurrencies = {"1INCH", "AAVE", "ADA", "ALGO", "ALICE", "ALPHA", "ANKR", "ANT", 
        "APE", "API3", "ARPA", "AR", "ATA", "ATOM", "AUDIO", "AVAX", "AXS", "BAKE", 
        "BAL", "BAND", "BAT", "BCH", "BEL", "BLZ", "BNB", "BNX", "BTCDOM", "BTCST", 
        "BTC", "BTS", "C98", "CELO", "CELR", "CHR", "CHZ", "COMP", "COTI", "CRV", "CTK", 
        "CTSI", "CVC", "CVX", "DAR", "DASH", "DEFI", "DENT", "DGB", "DOGE", "DOT", "DUSK", 
        "DYDX", "EGLD", "ENJ", "ENS", "EOS", "ETC", "ETH", "FIL", "FLM", "FLOW", "FOOTBALL", 
        "FTM", "FTT", "GALA", "GAL", "GMT", "GRT", "GTC", "HBAR", "HNT", "HOT", "ICP", "ICX", 
        "IMX", "INJ", "IOST", "IOTA"};

    rapidjson::Document requestDoc, respDoc;

    requestDoc.SetObject();
    requestDoc.AddMember("market", rapidjson::Value(rapidjson::kArrayType), requestDoc.GetAllocator());

    for(const auto& baseCurrency : allCurrencies){
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
    else if(!(respDoc["data"]["subscribed"].Size() > 25)){
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
        if(!memberCountChecker(object, 4)){
            return false;
        }
    }

    for(const auto& object : respDoc["data"]["unsubscribeFailed"].GetArray()){
        if(!memberCountChecker(object, 4)){
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

bool TC_BinanceFutures_unsubscribeOrderbook_8(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"unsubscribed":[],"unsubscribeFailed":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT","expiration":"PERP","symbol":"HYUNKYUUSDT"}]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"HYUNKYU","quoteCurrency":"USDT"}]})";
    std::string response = client.unsubscribeOrderbook(input);

    testData.actualResult = response;

    if(testData.actualResult.compare(testData.expectedResult) != 0){
        return false;
    }

    return true;

    TC_END
}

bool TC_BinanceFutures_unsubscribeOrderbook_9(testDataType& testData){
    TC_BEGIN

    std::this_thread::sleep_for(std::chrono::seconds(1));
    testData.testSubject = "OneXAPI::Binance::Futures().unsubscribeOrderbook";
    testData.expectedResult = R"({"success":true,"requestedApiCount":2,"data":{"subscribed":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}],"subscribeFailed":[]}})";

    OneXAPI::Binance::Futures client;
    std::string input = R"({"market":[{"baseCurrency":"BTC","quoteCurrency":"USDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT"}]})";
    std::string response = client.subscribeOrderbook(input);

    testData.actualResult = response;
    
    testData.expectedResult.append("\n").append(R"({"success":true,"requestedApiCount":0,"data":{"orderbooks":[{"baseCurrency":"BTC","quoteCurrency":"USDT","expiration":"PERP","symbol":"BTCUSDT"},{"baseCurrency":"ETH","quoteCurrency":"USDT","expiration":"PERP","symbol":"ETHUSDT"}]}})");
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