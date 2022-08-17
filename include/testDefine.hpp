
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
    