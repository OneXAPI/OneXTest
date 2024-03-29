
#include "OneXAPI.hpp"

extern bool errorResponseChecker(std::string response, std::string errorType, uint32_t apiCnt);
extern bool successResponseChecker(std::string response);
extern std::string getLog(uint64_t since);
extern bool memberCountChecker(const rapidjson::Value& json, uint64_t count);