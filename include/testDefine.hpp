
#define EXCEPTION_MSG               std::string("exception occurred : ") + e.what()
#define UNEXPECTED_EXCEPTION_MSG    "unexpected exception occurred"

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
    std::string loggeMethod = LOGGER.getMethod();

#define LOAD_LOGGER_SETTINGS                                        \
    LOGGER.setLevel(loggerLevel);                                   \
    LOGGER.setMethod(loggeMethod);
    