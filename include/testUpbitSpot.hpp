#pragma once

#include "OneXAPI.hpp"
#include "testDataTypes.hpp"
#include "testKeys.hpp"

extern bool TC_UpbitSpot_Object_1(testDataType& testData);
extern bool TC_UpbitSpot_Object_2(testDataType& testData);
extern bool TC_UpbitSpot_Object_3(testDataType& testData);
extern bool TC_UpbitSpot_Object_4(testDataType& testData);
extern bool TC_UpbitSpot_Object_5(testDataType& testData);
extern bool TC_UpbitSpot_Object_6(testDataType& testData);
extern bool TC_UpbitSpot_Object_7(testDataType& testData);

extern bool TC_UpbitSpot_getConfig_1(testDataType& testData);
extern bool TC_UpbitSpot_getConfig_2(testDataType& testData);
extern bool TC_UpbitSpot_getConfig_3(testDataType& testData);
extern bool TC_UpbitSpot_getConfig_4(testDataType& testData);

extern bool TC_UpbitSpot_setConfig_1(testDataType& testData);
extern bool TC_UpbitSpot_setConfig_2(testDataType& testData);
extern bool TC_UpbitSpot_setConfig_3(testDataType& testData);
extern bool TC_UpbitSpot_setConfig_4(testDataType& testData);
extern bool TC_UpbitSpot_setConfig_5(testDataType& testData);

extern bool TC_UpbitSpot_getEndpointCandidates_1(testDataType& testData);
extern bool TC_UpbitSpot_getEndpointCandidates_2(testDataType& testData);
extern bool TC_UpbitSpot_getEndpointCandidates_3(testDataType& testData);
extern bool TC_UpbitSpot_getEndpointCandidates_4(testDataType& testData);

extern bool TC_UpbitSpot_has_1(testDataType& testData);
extern bool TC_UpbitSpot_has_2(testDataType& testData);
extern bool TC_UpbitSpot_has_3(testDataType& testData);
extern bool TC_UpbitSpot_has_4(testDataType& testData);
extern bool TC_UpbitSpot_has_5(testDataType& testData);
extern bool TC_UpbitSpot_has_6(testDataType& testData);

extern bool TC_UpbitSpot_getWithdrawRoundingRule_1(testDataType& testData);
extern bool TC_UpbitSpot_getWithdrawRoundingRule_2(testDataType& testData);

extern bool TC_UpbitSpot_setWithdrawRoundingRule_1(testDataType& testData);
extern bool TC_UpbitSpot_setWithdrawRoundingRule_2(testDataType& testData);

extern bool TC_UpbitSpot_withdraw_1(testDataType& testData);
extern bool TC_UpbitSpot_withdraw_2(testDataType& testData);
extern bool TC_UpbitSpot_withdraw_3(testDataType& testData);

extern bool TC_UpbitSpot_fetchAllCurrencies_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchAllCurrencies_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchBalance_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchBalance_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchWalletStatus_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchWalletStatus_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchWithdrawHistory_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchWithdrawHistory_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchDepositHistory_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchDepositHistory_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchDepositAddress_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchDepositAddress_2(testDataType& testData);

extern bool TC_UpbitSpot_isDepositCompleted_1(testDataType& testData);
extern bool TC_UpbitSpot_isDepositCompleted_2(testDataType& testData);
extern bool TC_UpbitSpot_isDepositCompleted_3(testDataType& testData);

extern bool TC_UpbitSpot_subscribeBalance_1(testDataType& testData);
extern bool TC_UpbitSpot_subscribeBalance_2(testDataType& testData);
extern bool TC_UpbitSpot_subscribeBalance_3(testDataType& testData);
extern bool TC_UpbitSpot_subscribeBalance_4(testDataType& testData);

extern bool TC_UpbitSpot_unsubscribeBalance_1(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeBalance_2(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeBalance_3(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeBalance_4(testDataType& testData);

extern bool TC_UpbitSpot_isSubscribingBalance_1(testDataType& testData);
extern bool TC_UpbitSpot_isSubscribingBalance_2(testDataType& testData);
extern bool TC_UpbitSpot_isSubscribingBalance_3(testDataType& testData);
extern bool TC_UpbitSpot_isSubscribingBalance_4(testDataType& testData);

extern bool TC_UpbitSpot_getOrderRoundingRule_1(testDataType& testData);
extern bool TC_UpbitSpot_getOrderRoundingRule_2(testDataType& testData);

extern bool TC_UpbitSpot_setOrderRoundingRule_1(testDataType& testData);
extern bool TC_UpbitSpot_setOrderRoundingRule_2(testDataType& testData);

extern bool TC_UpbitSpot_orderLimitBuy_1(testDataType& testData);
extern bool TC_UpbitSpot_orderLimitBuy_2(testDataType& testData);
extern bool TC_UpbitSpot_orderLimitBuy_3(testDataType& testData);

extern bool TC_UpbitSpot_orderLimitSell_1(testDataType& testData);
extern bool TC_UpbitSpot_orderLimitSell_2(testDataType& testData);
extern bool TC_UpbitSpot_orderLimitSell_3(testDataType& testData);

extern bool TC_UpbitSpot_orderMarketBuy_1(testDataType& testData);
extern bool TC_UpbitSpot_orderMarketBuy_2(testDataType& testData);
extern bool TC_UpbitSpot_orderMarketBuy_3(testDataType& testData);

extern bool TC_UpbitSpot_orderMarketSell_1(testDataType& testData);
extern bool TC_UpbitSpot_orderMarketSell_2(testDataType& testData);
extern bool TC_UpbitSpot_orderMarketSell_3(testDataType& testData);

extern bool TC_UpbitSpot_orderCancel_1(testDataType& testData);
extern bool TC_UpbitSpot_orderCancel_2(testDataType& testData);
extern bool TC_UpbitSpot_orderCancel_3(testDataType& testData);

extern bool TC_UpbitSpot_fetchTradingFee_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchTradingFee_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchOrderInfo_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchOrderInfo_2(testDataType& testData);
extern bool TC_UpbitSpot_fetchOrderInfo_3(testDataType& testData);

extern bool TC_UpbitSpot_fetchOpenOrders_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchOpenOrders_2(testDataType& testData);

extern bool TC_UpbitSpot_getCandleIntervalCandidates_1(testDataType& testData);
extern bool TC_UpbitSpot_getCandleIntervalCandidates_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchMarkets_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchMarkets_2(testDataType& testData);

extern bool TC_UpbitSpot_fetchTicker_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchTicker_2(testDataType& testData);
extern bool TC_UpbitSpot_fetchTicker_3(testDataType& testData);
extern bool TC_UpbitSpot_fetchTicker_4(testDataType& testData);

extern bool TC_UpbitSpot_fetchOrderbook_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchOrderbook_2(testDataType& testData);
extern bool TC_UpbitSpot_fetchOrderbook_3(testDataType& testData);
extern bool TC_UpbitSpot_fetchOrderbook_4(testDataType& testData);

extern bool TC_UpbitSpot_fetchCandleHistory_1(testDataType& testData);
extern bool TC_UpbitSpot_fetchCandleHistory_2(testDataType& testData);
extern bool TC_UpbitSpot_fetchCandleHistory_3(testDataType& testData);

extern bool TC_UpbitSpot_getSubscribingTickers_1(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingTickers_2(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingTickers_3(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingTickers_4(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingTickers_5(testDataType& testData);

extern bool TC_UpbitSpot_getSubscribingOrderbooks_1(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingOrderbooks_2(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingOrderbooks_3(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingOrderbooks_4(testDataType& testData);
extern bool TC_UpbitSpot_getSubscribingOrderbooks_5(testDataType& testData);

extern bool TC_UpbitSpot_subscribeTicker_1(testDataType& testData);
extern bool TC_UpbitSpot_subscribeTicker_2(testDataType& testData);
extern bool TC_UpbitSpot_subscribeTicker_3(testDataType& testData);
extern bool TC_UpbitSpot_subscribeTicker_4(testDataType& testData);

extern bool TC_UpbitSpot_unsubscribeTicker_1(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeTicker_2(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeTicker_3(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeTicker_4(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeTicker_5(testDataType& testData);

extern bool TC_UpbitSpot_subscribeOrderbook_1(testDataType& testData);
extern bool TC_UpbitSpot_subscribeOrderbook_2(testDataType& testData);
extern bool TC_UpbitSpot_subscribeOrderbook_3(testDataType& testData);
extern bool TC_UpbitSpot_subscribeOrderbook_4(testDataType& testData);

extern bool TC_UpbitSpot_unsubscribeOrderbook_1(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeOrderbook_2(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeOrderbook_3(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeOrderbook_4(testDataType& testData);
extern bool TC_UpbitSpot_unsubscribeOrderbook_5(testDataType& testData);