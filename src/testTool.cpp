#include "../include/testTool.hpp"
#include <fstream>

bool errorResponseChecker(std::string response, std::string errorType){
    rapidjson::Document respDoc;
    OneXAPI::Internal::Util::parseJson(respDoc, response);
    if(!respDoc["success"].GetBool()){
        if(errorType.compare(respDoc["data"]["errorType"].GetString()) == 0)
            return true;
    }
    return false;
}

std::string getLog(uint64_t since){
    std::stringstream timeBuffer;
    time_t rawtime = (const time_t)since;
    struct tm * timeinfo;

    timeinfo = gmtime(&rawtime);
    timeBuffer << std::put_time(timeinfo, "%Y-%m-%d");

    std::ifstream input_file("OneXAPI_Logs/OneXAPI_" + timeBuffer.str() + ".log");
    if (!input_file.is_open()) {
        std::cout << "Cannot fine the log file - '" << "../OneXAPI_Logs/OneXAPI_" + timeBuffer.str() + ".log" << "'" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::string result = "";
    bool found = false;
    while (std::getline(input_file, line)) {
        if(!found && (line.find("[") != std::string::npos && line.find("[") == 0)){
            std::vector<std::string> lineSplit;
            boost::split(lineSplit, line, boost::is_any_of("]"));

            boost::replace_all(lineSplit.front(), "[", "");

            std::wstring wStr;
            wStr.assign(lineSplit.front().begin(), lineSplit.front().end());

            const std::wstring dateTimeFormat{L"%Y-%m-%d %H:%M:%S"};

            std::wistringstream ss{wStr};
            tm dt;
            ss >> std::get_time(&dt, dateTimeFormat.c_str());

            if(uint64_t(mktime(&dt)) < since){
                continue;
            }
            found = true;
        }
        if(found){
            result.append(line + "\n");
        }
    }
    input_file.close();

    return result;
}

bool memberCountChecker(const rapidjson::Value& json, uint64_t count){
    if(json.MemberCount() == count){
        return true;
    }

    return false;
}