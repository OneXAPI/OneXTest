#include "../include/testOneXAPI.hpp"

#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

static const std::string getInfoExpectedResult = R"({"success":true,"data":{"supportedExchanges":[{"exchange":"Upbit","instrument":"Spot"}],"onexapiVersion":"0.0.0"}})";

bool TC_OneXAPI_1_1(testDataType& testData){
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

bool TC_OneXAPI_1_2(testDataType& testData){
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

bool TC_OneXAPI_1_3(testDataType& testData){
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

bool TC_OneXAPI_1_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::getInfo";
        testData.expectedResult = getInfoExpectedResult;

        std::string input = "2gasdv";

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