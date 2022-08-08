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
    result = TC_OneXAPI_getLoggerConfig_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getLoggerConfig_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getLoggerConfig_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_getLoggerConfig_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_OneXAPI_setLoggerConfig_6(td);
    result?(pass++):(fail++);
    printResult(td, result);

    LOGGER.setMethod("file");
    WS_LOGGER.setLevel("info");
	WS_LOGGER.setMethod("file");
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
    result = TC_UpbitSpot_setConfig_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setConfig_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setConfig_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setConfig_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setConfig_5(td);
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
    result = TC_UpbitSpot_getWithdrawRoundingRule_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getWithdrawRoundingRule_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setWithdrawRoundingRule_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setWithdrawRoundingRule_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_withdraw_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_withdraw_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_withdraw_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchAllCurrencies_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchAllCurrencies_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchBalance_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchBalance_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchWalletStatus_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchWalletStatus_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchWithdrawHistory_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchWithdrawHistory_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchDepositHistory_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchDepositHistory_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchDepositAddress_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_fetchDepositAddress_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isDepositCompleted_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isDepositCompleted_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_isDepositCompleted_3(td);
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
    result = TC_UpbitSpot_getOrderRoundingRule_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getOrderRoundingRule_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setOrderRoundingRule_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_setOrderRoundingRule_2(td);
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
    result = TC_UpbitSpot_getSubscribingTickers_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingOrderbooks_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingOrderbooks_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingOrderbooks_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingOrderbooks_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_getSubscribingOrderbooks_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeTicker_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeTicker_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeTicker_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_subscribeTicker_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeTicker_1(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeTicker_2(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeTicker_3(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeTicker_4(td);
    result?(pass++):(fail++);
    printResult(td, result);
    result = TC_UpbitSpot_unsubscribeTicker_5(td);
    result?(pass++):(fail++);
    printResult(td, result);
    
    std::cout << "Executed : " << pass+fail << "   Pass : " << pass << "   Fail : " << fail << std::endl;
    WS_LOGGER.info("regression end");
}