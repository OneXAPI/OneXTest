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