#include "../include/testUpbitSpot.hpp"
#include <iostream>

#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

bool TC_UpbitSpot_1_1(testDataType& testData){
    try{

        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
        testData.expectedResult = "No Error";

        OneXAPI::Upbit::Spot stackClient();
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

bool TC_UpbitSpot_1_2(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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

bool TC_UpbitSpot_1_3(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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

bool TC_UpbitSpot_1_4(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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

bool TC_UpbitSpot_1_5(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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

bool TC_UpbitSpot_1_6(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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

bool TC_UpbitSpot_1_7(testDataType& testData){
    try{
        testData.testCaseId = __func__;
        testData.testSubject = "OneXAPI::Upbit::Spot()";
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