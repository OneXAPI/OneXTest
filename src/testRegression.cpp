#include "../include/testRegression.hpp"

static void printResult(testDataType& td, bool testResult){
    std::cout << "[" << td.testCaseId << "] [" << td.testSubject << "] - ";
    if(testResult){
        std::cout << "Pass" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
    std::cout << "Expected Result : " << td.expectedResult << std::endl;
    std::cout << "Actual Result : " << td.actualResult << std::endl << std::endl;
}

void regression(){
    uint64_t pass = 0;
    uint64_t fail = 0;
    bool result;
    testDataType td;

    /* OneXAPI */
    result = TC_OneXAPI_getInfo_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getInfo_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getInfo_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getInfo_4(td);
    result?(pass++):(fail++);
    printResult(td, result);

    /* UpbitSpot */
    result = TC_UpbitSpot_Object_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_6(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_Object_7(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getConfig_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getConfig_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getConfig_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getConfig_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getEndpointCandidates_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getEndpointCandidates_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getEndpointCandidates_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getEndpointCandidates_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_has_6(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeBalance_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeBalance_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeBalance_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeBalance_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeBalance_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeBalance_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeBalance_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeBalance_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isSubscribingBalance_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isSubscribingBalance_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isSubscribingBalance_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isSubscribingBalance_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingTickers_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingTickers_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingTickers_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingTickers_4(td);
    result?(pass++):(fail++);
    printResult(td, result);

    std::cout << "Executed : " << pass+fail << "   Pass : " << pass << "   Fail : " << fail << std::endl;
}