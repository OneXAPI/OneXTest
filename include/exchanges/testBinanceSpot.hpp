#pragma once

#include "OneXAPI.hpp"
#include "../testDataTypes.hpp"
#include "../testKeys.hpp"

extern bool TC_BinanceSpot_Object_1(testDataType& testData);
extern bool TC_BinanceSpot_Object_2(testDataType& testData);
extern bool TC_BinanceSpot_Object_3(testDataType& testData);
extern bool TC_BinanceSpot_Object_4(testDataType& testData);
extern bool TC_BinanceSpot_Object_5(testDataType& testData);
extern bool TC_BinanceSpot_Object_6(testDataType& testData);
extern bool TC_BinanceSpot_Object_7(testDataType& testData);

extern bool TC_BinanceSpot_getConfig_1(testDataType& testData);
extern bool TC_BinanceSpot_getConfig_2(testDataType& testData);
extern bool TC_BinanceSpot_getConfig_3(testDataType& testData);
extern bool TC_BinanceSpot_getConfig_4(testDataType& testData);

extern bool TC_BinanceSpot_setConfig_1(testDataType& testData);
extern bool TC_BinanceSpot_setConfig_2(testDataType& testData);
extern bool TC_BinanceSpot_setConfig_3(testDataType& testData);
extern bool TC_BinanceSpot_setConfig_4(testDataType& testData);
extern bool TC_BinanceSpot_setConfig_5(testDataType& testData);

extern bool TC_BinanceSpot_getEndpointCandidates_1(testDataType& testData);
extern bool TC_BinanceSpot_getEndpointCandidates_2(testDataType& testData);
extern bool TC_BinanceSpot_getEndpointCandidates_3(testDataType& testData);
extern bool TC_BinanceSpot_getEndpointCandidates_4(testDataType& testData);

extern bool TC_BinanceSpot_has_1(testDataType& testData);
extern bool TC_BinanceSpot_has_2(testDataType& testData);
extern bool TC_BinanceSpot_has_3(testDataType& testData);
extern bool TC_BinanceSpot_has_4(testDataType& testData);
extern bool TC_BinanceSpot_has_5(testDataType& testData);

extern bool TC_BinanceSpot_getWithdrawRoundingRule_1(testDataType& testData);
extern bool TC_BinanceSpot_getWithdrawRoundingRule_2(testDataType& testData);

extern bool TC_BinanceSpot_setWithdrawRoundingRule_1(testDataType& testData);
extern bool TC_BinanceSpot_setWithdrawRoundingRule_2(testDataType& testData);

extern bool TC_BinanceSpot_withdraw_1(testDataType& testData);
extern bool TC_BinanceSpot_withdraw_2(testDataType& testData);
extern bool TC_BinanceSpot_withdraw_3(testDataType& testData);

extern bool TC_BinanceSpot_fetchAllCurrencies_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchAllCurrencies_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchBalance_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchBalance_2(testDataType& testData);
extern bool TC_BinanceSpot_fetchBalance_3(testDataType& testData);
extern bool TC_BinanceSpot_fetchBalance_4(testDataType& testData);

extern bool TC_BinanceSpot_fetchWalletStatus_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchWalletStatus_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchWithdrawHistory_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchWithdrawHistory_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchDepositHistory_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchDepositHistory_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchDepositAddress_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchDepositAddress_2(testDataType& testData);

extern bool TC_BinanceSpot_isDepositCompleted_1(testDataType& testData);
extern bool TC_BinanceSpot_isDepositCompleted_2(testDataType& testData);
extern bool TC_BinanceSpot_isDepositCompleted_3(testDataType& testData);

extern bool TC_BinanceSpot_getOrderRoundingRule_1(testDataType& testData);
extern bool TC_BinanceSpot_getOrderRoundingRule_2(testDataType& testData);

extern bool TC_BinanceSpot_setOrderRoundingRule_1(testDataType& testData);
extern bool TC_BinanceSpot_setOrderRoundingRule_2(testDataType& testData);

extern bool TC_BinanceSpot_orderLimitBuy_1(testDataType& testData);
extern bool TC_BinanceSpot_orderLimitBuy_2(testDataType& testData);
extern bool TC_BinanceSpot_orderLimitBuy_3(testDataType& testData);

extern bool TC_BinanceSpot_orderLimitSell_1(testDataType& testData);
extern bool TC_BinanceSpot_orderLimitSell_2(testDataType& testData);
extern bool TC_BinanceSpot_orderLimitSell_3(testDataType& testData);

extern bool TC_BinanceSpot_orderMarketBuy_1(testDataType& testData);
extern bool TC_BinanceSpot_orderMarketBuy_2(testDataType& testData);
extern bool TC_BinanceSpot_orderMarketBuy_3(testDataType& testData);

extern bool TC_BinanceSpot_orderMarketSell_1(testDataType& testData);
extern bool TC_BinanceSpot_orderMarketSell_2(testDataType& testData);
extern bool TC_BinanceSpot_orderMarketSell_3(testDataType& testData);

extern bool TC_BinanceSpot_orderCancel_1(testDataType& testData);
extern bool TC_BinanceSpot_orderCancel_2(testDataType& testData);
extern bool TC_BinanceSpot_orderCancel_3(testDataType& testData);
extern bool TC_BinanceSpot_orderCancel_4(testDataType& testData);

extern bool TC_BinanceSpot_fetchTradingFee_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchTradingFee_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchOrderInfo_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchOrderInfo_2(testDataType& testData);
extern bool TC_BinanceSpot_fetchOrderInfo_3(testDataType& testData);
extern bool TC_BinanceSpot_fetchOrderInfo_4(testDataType& testData);
extern bool TC_BinanceSpot_fetchOrderInfo_5(testDataType& testData);

extern bool TC_BinanceSpot_fetchOpenOrders_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchOpenOrders_2(testDataType& testData);

extern bool TC_BinanceSpot_getCandleIntervalCandidates_1(testDataType& testData);
extern bool TC_BinanceSpot_getCandleIntervalCandidates_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchMarkets_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchMarkets_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchTicker_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchTicker_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchOrderbook_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchOrderbook_2(testDataType& testData);

extern bool TC_BinanceSpot_fetchCandleHistory_1(testDataType& testData);
extern bool TC_BinanceSpot_fetchCandleHistory_2(testDataType& testData);
extern bool TC_BinanceSpot_fetchCandleHistory_3(testDataType& testData);

extern bool TC_BinanceSpot_getSubscribingTickers_1(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingTickers_2(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingTickers_3(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingTickers_4(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingTickers_5(testDataType& testData);

extern bool TC_BinanceSpot_getSubscribingOrderbooks_1(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingOrderbooks_2(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingOrderbooks_3(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingOrderbooks_4(testDataType& testData);
extern bool TC_BinanceSpot_getSubscribingOrderbooks_5(testDataType& testData);

extern bool TC_BinanceSpot_subscribeTicker_1(testDataType& testData);
extern bool TC_BinanceSpot_subscribeTicker_2(testDataType& testData);
extern bool TC_BinanceSpot_subscribeTicker_3(testDataType& testData);
extern bool TC_BinanceSpot_subscribeTicker_4(testDataType& testData);

extern bool TC_BinanceSpot_unsubscribeTicker_1(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeTicker_2(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeTicker_3(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeTicker_4(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeTicker_5(testDataType& testData);

extern bool TC_BinanceSpot_subscribeOrderbook_1(testDataType& testData);
extern bool TC_BinanceSpot_subscribeOrderbook_2(testDataType& testData);
extern bool TC_BinanceSpot_subscribeOrderbook_3(testDataType& testData);
extern bool TC_BinanceSpot_subscribeOrderbook_4(testDataType& testData);

extern bool TC_BinanceSpot_unsubscribeOrderbook_1(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeOrderbook_2(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeOrderbook_3(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeOrderbook_4(testDataType& testData);
extern bool TC_BinanceSpot_unsubscribeOrderbook_5(testDataType& testData);

extern bool TC_BinanceSpot_websocketFullTest(testDataType& testData);