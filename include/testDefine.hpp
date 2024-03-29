
#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

#define EXECUTE_UNITTEST(testName)                                  \
    result = testName(td);                                          \
    result?(pass++):(fail++);                                       \
    printResult(td, result);                                        \

#define TC_BEGIN        try{testData.testCaseId = __func__;
#define TC_END          }                                           \
    catch(std::exception& e){                                       \
        testData.actualResult = EXCEPTION_MSG;                      \
    }                                                               \
    catch(...){                                                     \
        testData.actualResult = UNEXPECTED_EXCEPTION_MSG;           \
    }                                                               \
    return false;

#define SAVE_LOGGER_SETTINGS                                        \
    std::string loggerLevel = LOGGER.getLevel();                    \
    std::string loggeMethod = LOGGER.getMethod();                   \
    std::string wsLoggerLevel = WS_LOGGER.getLevel();               \
    std::string wsloggeMethod = WS_LOGGER.getMethod();

#define LOAD_LOGGER_SETTINGS                                        \
    LOGGER.setLevel(loggerLevel);                                   \
    LOGGER.setMethod(loggeMethod);                                  \
    WS_LOGGER.setLevel(wsLoggerLevel);                              \
    WS_LOGGER.setMethod(wsloggeMethod);
    