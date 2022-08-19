#include "../include/testRegression.hpp"

static std::vector<std::string> failedTestCases;

static void printResult(testDataType& td, bool testResult){
    std::cout << "[" << td.testCaseId << "] [" << td.testSubject << "] - ";
    if(testResult){
        std::cout << "Pass" << std::endl;
    }
    else{
        failedTestCases.push_back(td.testCaseId);
        std::cout << "Fail" << std::endl;
    }
    std::cout << "Expected Result : " << td.expectedResult << std::endl;
    std::cout << "Actual Result : " << td.actualResult << std::endl << std::endl;
}

static void TC_OneXAPI(testDataType& td, uint64_t& pass, uint64_t& fail, bool& result){
    EXECUTE_UNITTEST(TC_OneXAPI_getInfo_1)
    EXECUTE_UNITTEST(TC_OneXAPI_getInfo_2)
    EXECUTE_UNITTEST(TC_OneXAPI_getInfo_3)
    EXECUTE_UNITTEST(TC_OneXAPI_getInfo_4)
    EXECUTE_UNITTEST(TC_OneXAPI_getLoggerConfig_1)
    EXECUTE_UNITTEST(TC_OneXAPI_getLoggerConfig_2)
    EXECUTE_UNITTEST(TC_OneXAPI_getLoggerConfig_3)
    EXECUTE_UNITTEST(TC_OneXAPI_getLoggerConfig_4)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_1)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_2)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_3)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_4)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_5)
    EXECUTE_UNITTEST(TC_OneXAPI_setLoggerConfig_6)
}

static void TC_UpbitSpot(testDataType& td, uint64_t& pass, uint64_t& fail, bool& result){
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_6)
    EXECUTE_UNITTEST(TC_UpbitSpot_Object_7)
    EXECUTE_UNITTEST(TC_UpbitSpot_getConfig_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getConfig_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_getConfig_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_getConfig_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_setConfig_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_setConfig_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_setConfig_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_setConfig_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_setConfig_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_getEndpointCandidates_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getEndpointCandidates_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_getEndpointCandidates_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_getEndpointCandidates_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_has_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_has_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_has_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_has_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_has_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_getWithdrawRoundingRule_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getWithdrawRoundingRule_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_setWithdrawRoundingRule_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_setWithdrawRoundingRule_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_withdraw_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_withdraw_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_withdraw_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchAllCurrencies_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchAllCurrencies_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchBalance_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchBalance_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchWalletStatus_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchWalletStatus_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchWithdrawHistory_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchWithdrawHistory_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchDepositHistory_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchDepositHistory_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchDepositAddress_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchDepositAddress_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_isDepositCompleted_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_isDepositCompleted_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_isDepositCompleted_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeBalance_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeBalance_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeBalance_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeBalance_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeBalance_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeBalance_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeBalance_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeBalance_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_isSubscribingBalance_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_isSubscribingBalance_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_isSubscribingBalance_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_isSubscribingBalance_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_getOrderRoundingRule_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getOrderRoundingRule_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_setOrderRoundingRule_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_setOrderRoundingRule_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitBuy_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitBuy_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitBuy_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitSell_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitSell_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderLimitSell_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketBuy_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketBuy_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketBuy_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketSell_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketSell_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderMarketSell_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderCancel_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderCancel_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_orderCancel_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTradingFee_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTradingFee_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderInfo_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderInfo_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderInfo_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderInfo_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOpenOrders_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOpenOrders_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_getCandleIntervalCandidates_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getCandleIntervalCandidates_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchMarkets_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchMarkets_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTicker_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTicker_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTicker_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchTicker_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderbook_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderbook_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderbook_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchOrderbook_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchCandleHistory_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchCandleHistory_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_fetchCandleHistory_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingTickers_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingTickers_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingTickers_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingTickers_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingTickers_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingOrderbooks_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingOrderbooks_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingOrderbooks_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingOrderbooks_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_getSubscribingOrderbooks_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeTicker_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeTicker_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeTicker_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeTicker_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeTicker_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeTicker_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeTicker_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeTicker_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeTicker_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeOrderbook_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeOrderbook_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeOrderbook_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_subscribeOrderbook_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeOrderbook_1)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeOrderbook_2)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeOrderbook_3)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeOrderbook_4)
    EXECUTE_UNITTEST(TC_UpbitSpot_unsubscribeOrderbook_5)
    EXECUTE_UNITTEST(TC_UpbitSpot_websocketFullTest)
}

static void TC_BinanceSpot(testDataType& td, uint64_t& pass, uint64_t& fail, bool& result){
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_4)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_5)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_6)
    EXECUTE_UNITTEST(TC_BinanceSpot_Object_7)
    EXECUTE_UNITTEST(TC_BinanceSpot_getConfig_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_getConfig_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_getConfig_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_getConfig_4)
    EXECUTE_UNITTEST(TC_BinanceSpot_setConfig_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_setConfig_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_setConfig_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_setConfig_4)
    EXECUTE_UNITTEST(TC_BinanceSpot_setConfig_5)
    EXECUTE_UNITTEST(TC_BinanceSpot_getEndpointCandidates_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_getEndpointCandidates_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_getEndpointCandidates_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_getEndpointCandidates_4)
    EXECUTE_UNITTEST(TC_BinanceSpot_has_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_has_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_has_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_has_4)
    EXECUTE_UNITTEST(TC_BinanceSpot_has_5)
    EXECUTE_UNITTEST(TC_BinanceSpot_getWithdrawRoundingRule_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_getWithdrawRoundingRule_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_setWithdrawRoundingRule_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_setWithdrawRoundingRule_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_withdraw_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_withdraw_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_withdraw_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchAllCurrencies_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchAllCurrencies_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchBalance_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchBalance_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchWalletStatus_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchWalletStatus_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchWithdrawHistory_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchWithdrawHistory_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchDepositHistory_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchDepositHistory_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchDepositAddress_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_fetchDepositAddress_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_isDepositCompleted_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_isDepositCompleted_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_isDepositCompleted_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_getOrderRoundingRule_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_getOrderRoundingRule_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_setOrderRoundingRule_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_setOrderRoundingRule_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitBuy_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitBuy_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitBuy_3)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitSell_1)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitSell_2)
    EXECUTE_UNITTEST(TC_BinanceSpot_orderLimitSell_3)
}

void regression(){
    uint64_t pass = 0;
    uint64_t fail = 0;
    bool result;
    testDataType td;

    /* OneXAPI */
    TC_OneXAPI(td, pass, fail, result);

    LOGGER.setMethod("file");
    WS_LOGGER.setLevel("info");
	WS_LOGGER.setMethod("file");

    /* UpbitSpot */
    TC_UpbitSpot(td, pass, fail, result);

    /* BinanceSpot */
    TC_BinanceSpot(td, pass, fail, result);

    std::cout << "Executed : " << pass+fail << "   Pass : " << pass << "   Fail : " << fail << std::endl;
    std::cout << std::endl << "Failed Test Cases : " << std::endl;
    for(const auto& tc : failedTestCases){
        std::cout << tc << std::endl;
    }

    WS_LOGGER.info("regression end");
}