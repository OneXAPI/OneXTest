#include "../include/testTool.hpp"

bool errorResponseChecker(std::string response, std::string errorType){
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    if(!respDoc["success"].GetBool()){
        if(errorType.compare(respDoc["data"]["errorType"].GetString()) == 0)
            return true;
    }
    return false;
}