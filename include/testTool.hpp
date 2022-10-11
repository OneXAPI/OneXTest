
#include "OneXAPI.hpp"

extern bool errorResponseChecker(std::string response, std::string errorType, uint32_t apiCnt = 0); // Temporary solution for compile
extern std::string getLog(uint64_t since);
extern bool memberCountChecker(const rapidjson::Value& json, uint64_t count);