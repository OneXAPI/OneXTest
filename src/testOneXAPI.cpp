#include "../include/testOneXAPI.hpp"
#include "../include/testTool.hpp"

#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

static const std::string getInfoExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"supportedExchanges":[{"exchange":"Binance","instrument":"Spot"},{"exchange":"Binance","instrument":"Futures"},{"exchange":"Upbit","instrument":"Spot"}],"onexapiVersion":"0.0.0"}})";

bool TC_OneXAPI_getInfo_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getInfo";
        testData.expectedResult = getInfoExpectedResult;

        std::string response = OneXAPI::getInfo();

        testData.actualResult = response;

        if(response.compare(getInfoExpectedResult) == 0){
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

bool TC_OneXAPI_getInfo_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getInfo";
        testData.expectedResult = getInfoExpectedResult;

        std::string input = "";
        std::string response = OneXAPI::getInfo(input);

        testData.actualResult = response;
        
        if(response.compare(getInfoExpectedResult) == 0){
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

bool TC_OneXAPI_getInfo_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getInfo";
        testData.expectedResult = getInfoExpectedResult;

        std::string input = "{}";

        std::string response = OneXAPI::getInfo(input);

        testData.actualResult = response;

        if(response.compare(getInfoExpectedResult) == 0){
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

bool TC_OneXAPI_getInfo_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getInfo";
        testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":~~}})";

        std::string input = "2gasdv";

        std::string response = OneXAPI::getInfo(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
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

static const std::string getLoggerConfigExpectedResult = R"({"success":true,"requestedApiCount":0,"data":{"main":{"outputMethod":"terminal","logLevel":"off"},"websocket":{"outputMethod":"terminal","logLevel":"off"}}})";

bool TC_OneXAPI_getLoggerConfig_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getLoggerConfig";
        testData.expectedResult = getLoggerConfigExpectedResult;

        std::string response = OneXAPI::getLoggerConfig();

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

bool TC_OneXAPI_getLoggerConfig_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getLoggerConfig";
        testData.expectedResult = getLoggerConfigExpectedResult;

        std::string input = "";
        std::string response = OneXAPI::getLoggerConfig(input);

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

bool TC_OneXAPI_getLoggerConfig_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getLoggerConfig";
        testData.expectedResult = getLoggerConfigExpectedResult;

        std::string input = "{}";
        std::string response = OneXAPI::getLoggerConfig(input);

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

bool TC_OneXAPI_getLoggerConfig_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getLoggerConfig";
        testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":~~}})";

        std::string input = "2gasdv@";
        std::string response = OneXAPI::getLoggerConfig(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
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

bool TC_OneXAPI_setLoggerConfig_1(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

        std::string input = "";
        std::string response = OneXAPI::setLoggerConfig(input);

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

bool TC_OneXAPI_setLoggerConfig_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{}})";

        std::string input = "{}";
        std::string response = OneXAPI::setLoggerConfig(input);

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

bool TC_OneXAPI_setLoggerConfig_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"JSON_PARSING_ERROR","errorMsg":~~}})";

        std::string input = "2gasdv@";
        std::string response = OneXAPI::setLoggerConfig(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "JSON_PARSING_ERROR", 0)){
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

bool TC_OneXAPI_setLoggerConfig_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE_TYPE","errorMsg":~~}})";

        std::string input = R"({"main":["1","2"],"websocket":{"logLevel": "test","outputMethod": 22}})";
        std::string response = OneXAPI::setLoggerConfig(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "WRONG_VALUE_TYPE", 0)){
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

bool TC_OneXAPI_setLoggerConfig_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":false,"requestedApiCount":0,"data":{"errorType":"WRONG_VALUE","errorMsg":~~}})";

        std::string input = R"({"main":{"outputMethod": "file", "logLevel": "test"},"websocket":{"outputMethod": "terminal", "logLevel": "test"}})";
        std::string response = OneXAPI::setLoggerConfig(input);

        testData.actualResult = response;

        if(!errorResponseChecker(response, "WRONG_VALUE", 0)){
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

bool TC_OneXAPI_setLoggerConfig_6(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::setLoggerConfig";
        testData.expectedResult = R"({"success":true,"requestedApiCount":0,"data":{"main":{"outputMethod":"file","logLevel":"info"},"websocket":{"outputMethod":"terminal","logLevel":"error"}}})";

        std::string input = R"({"main":{"outputMethod": "file", "logLevel": "info"},"websocket":{"outputMethod": "terminal", "logLevel": "error"}})";
        std::string response = OneXAPI::setLoggerConfig(input);

        testData.actualResult = response;

        LOGGER.setMethod("terminal");
        LOGGER.setLevel("off");
        WS_LOGGER.setMethod("terminal");
        WS_LOGGER.setLevel("off");

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