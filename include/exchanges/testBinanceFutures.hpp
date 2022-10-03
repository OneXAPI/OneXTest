#pragma once

#include "OneXAPI.hpp"
#include "../testDataTypes.hpp"
#include "../testKeys.hpp"

extern bool TC_BinanceFutures_Object_1(testDataType& testData);
extern bool TC_BinanceFutures_Object_2(testDataType& testData);
extern bool TC_BinanceFutures_Object_3(testDataType& testData);
extern bool TC_BinanceFutures_Object_4(testDataType& testData);
extern bool TC_BinanceFutures_Object_5(testDataType& testData);
extern bool TC_BinanceFutures_Object_6(testDataType& testData);
extern bool TC_BinanceFutures_Object_7(testDataType& testData);

extern bool TC_BinanceFutures_getConfig_1(testDataType& testData);
extern bool TC_BinanceFutures_getConfig_2(testDataType& testData);
extern bool TC_BinanceFutures_getConfig_3(testDataType& testData);
extern bool TC_BinanceFutures_getConfig_4(testDataType& testData);

extern bool TC_BinanceFutures_setConfig_1(testDataType& testData);
extern bool TC_BinanceFutures_setConfig_2(testDataType& testData);
extern bool TC_BinanceFutures_setConfig_3(testDataType& testData);
extern bool TC_BinanceFutures_setConfig_4(testDataType& testData);
extern bool TC_BinanceFutures_setConfig_5(testDataType& testData);

extern bool TC_BinanceFutures_getEndpointCandidates_1(testDataType& testData);
extern bool TC_BinanceFutures_getEndpointCandidates_2(testDataType& testData);
extern bool TC_BinanceFutures_getEndpointCandidates_3(testDataType& testData);
extern bool TC_BinanceFutures_getEndpointCandidates_4(testDataType& testData);

extern bool TC_BinanceFutures_has_1(testDataType& testData);
extern bool TC_BinanceFutures_has_2(testDataType& testData);
extern bool TC_BinanceFutures_has_3(testDataType& testData);
extern bool TC_BinanceFutures_has_4(testDataType& testData);
extern bool TC_BinanceFutures_has_5(testDataType& testData);

extern bool TC_BinanceFutures_fetchBalance_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchBalance_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchBalance_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchBalance_4(testDataType& testData);

extern bool TC_BinanceFutures_fetchPositions_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchPositions_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchPositions_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchPositions_4(testDataType& testData);
extern bool TC_BinanceFutures_fetchPositions_5(testDataType& testData);
extern bool TC_BinanceFutures_fetchPositions_6(testDataType& testData);

extern bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchFundingFeeIncomeHistory_3(testDataType& testData);

extern bool TC_BinanceFutures_subscribeBalance_1(testDataType& testData);
extern bool TC_BinanceFutures_subscribeBalance_2(testDataType& testData);
extern bool TC_BinanceFutures_subscribeBalance_3(testDataType& testData);
extern bool TC_BinanceFutures_subscribeBalance_4(testDataType& testData);

extern bool TC_BinanceFutures_unsubscribeBalance_1(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeBalance_2(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeBalance_3(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeBalance_4(testDataType& testData);

extern bool TC_BinanceFutures_isSubscribingBalance_1(testDataType& testData);
extern bool TC_BinanceFutures_isSubscribingBalance_2(testDataType& testData);
extern bool TC_BinanceFutures_isSubscribingBalance_3(testDataType& testData);
extern bool TC_BinanceFutures_isSubscribingBalance_4(testDataType& testData);

extern bool TC_BinanceFutures_getOrderRoundingRule_1(testDataType& testData);
extern bool TC_BinanceFutures_getOrderRoundingRule_2(testDataType& testData);

extern bool TC_BinanceFutures_setOrderRoundingRule_1(testDataType& testData);
extern bool TC_BinanceFutures_setOrderRoundingRule_2(testDataType& testData);

extern bool TC_BinanceFutures_orderLimitBuy_1(testDataType& testData);
extern bool TC_BinanceFutures_orderLimitBuy_2(testDataType& testData);
extern bool TC_BinanceFutures_orderLimitBuy_3(testDataType& testData);

extern bool TC_BinanceFutures_orderLimitSell_1(testDataType& testData);
extern bool TC_BinanceFutures_orderLimitSell_2(testDataType& testData);
extern bool TC_BinanceFutures_orderLimitSell_3(testDataType& testData);

extern bool TC_BinanceFutures_orderMarketBuy_1(testDataType& testData);
extern bool TC_BinanceFutures_orderMarketBuy_2(testDataType& testData);
extern bool TC_BinanceFutures_orderMarketBuy_3(testDataType& testData);

extern bool TC_BinanceFutures_orderMarketSell_1(testDataType& testData);
extern bool TC_BinanceFutures_orderMarketSell_2(testDataType& testData);
extern bool TC_BinanceFutures_orderMarketSell_3(testDataType& testData);

extern bool TC_BinanceFutures_orderCancel_1(testDataType& testData);
extern bool TC_BinanceFutures_orderCancel_2(testDataType& testData);
extern bool TC_BinanceFutures_orderCancel_3(testDataType& testData);
extern bool TC_BinanceFutures_orderCancel_4(testDataType& testData);

extern bool TC_BinanceFutures_fetchOrderInfo_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderInfo_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderInfo_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderInfo_4(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderInfo_5(testDataType& testData);

extern bool TC_BinanceFutures_fetchOpenOrders_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchOpenOrders_2(testDataType& testData);

extern bool TC_BinanceFutures_fetchTradingFee_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchTradingFee_2(testDataType& testData);

extern bool TC_BinanceFutures_fetchLeverage_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchLeverage_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchLeverage_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchLeverage_4(testDataType& testData);

extern bool TC_BinanceFutures_changeLeverage_1(testDataType& testData);
extern bool TC_BinanceFutures_changeLeverage_2(testDataType& testData);

extern bool TC_BinanceFutures_fetchMarginType_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarginType_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarginType_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarginType_4(testDataType& testData);

extern bool TC_BinanceFutures_changeMarginType_1(testDataType& testData);
extern bool TC_BinanceFutures_changeMarginType_2(testDataType& testData);

extern bool TC_BinanceFutures_getCandleIntervalCandidates_1(testDataType& testData);
extern bool TC_BinanceFutures_getCandleIntervalCandidates_2(testDataType& testData);

extern bool TC_BinanceFutures_fetchMarkets_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarkets_2(testDataType& testData);

extern bool TC_BinanceFutures_fetchMarketInfo_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarketInfo_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarketInfo_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchMarketInfo_4(testDataType& testData);

extern bool TC_BinanceFutures_fetchTicker_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchTicker_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchTicker_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchTicker_4(testDataType& testData);

extern bool TC_BinanceFutures_fetchOrderbook_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderbook_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderbook_3(testDataType& testData);
extern bool TC_BinanceFutures_fetchOrderbook_4(testDataType& testData);

extern bool TC_BinanceFutures_fetchCandleHistory_1(testDataType& testData);
extern bool TC_BinanceFutures_fetchCandleHistory_2(testDataType& testData);
extern bool TC_BinanceFutures_fetchCandleHistory_3(testDataType& testData);

extern bool TC_BinanceFutures_getSubscribingMarketInfo_1(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingMarketInfo_2(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingMarketInfo_3(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingMarketInfo_4(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingMarketInfo_5(testDataType& testData);

extern bool TC_BinanceFutures_getSubscribingTickers_1(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingTickers_2(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingTickers_3(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingTickers_4(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingTickers_5(testDataType& testData);

extern bool TC_BinanceFutures_getSubscribingOrderbooks_1(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingOrderbooks_2(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingOrderbooks_3(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingOrderbooks_4(testDataType& testData);
extern bool TC_BinanceFutures_getSubscribingOrderbooks_5(testDataType& testData);

extern bool TC_BinanceFutures_subscribeMarketInfo_1(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_2(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_3(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_4(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_5(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_6(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_7(testDataType& testData);
extern bool TC_BinanceFutures_subscribeMarketInfo_8(testDataType& testData);

extern bool TC_BinanceFutures_unsubscribeMarketInfo_1(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_2(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_3(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_4(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_5(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_6(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_7(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeMarketInfo_8(testDataType& testData);

extern bool TC_BinanceFutures_subscribeTicker_1(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_2(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_3(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_4(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_5(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_6(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_7(testDataType& testData);
extern bool TC_BinanceFutures_subscribeTicker_8(testDataType& testData);

extern bool TC_BinanceFutures_unsubscribeTicker_1(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_2(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_3(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_4(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_5(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_6(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_7(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeTicker_8(testDataType& testData);

extern bool TC_BinanceFutures_subscribeOrderbook_1(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_2(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_3(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_4(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_5(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_6(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_7(testDataType& testData);
extern bool TC_BinanceFutures_subscribeOrderbook_8(testDataType& testData);

extern bool TC_BinanceFutures_unsubscribeOrderbook_1(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_2(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_3(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_4(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_5(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_6(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_7(testDataType& testData);
extern bool TC_BinanceFutures_unsubscribeOrderbook_8(testDataType& testData);

extern bool TC_BinanceFutures_websocketFullTest(testDataType& testData);