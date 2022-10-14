#include "OneXAPI.hpp"
#include "spotHelper.hpp"

std::vector<std::pair<std::string, std::string>> volumeFilter(const std::vector<Ticker>& tickers, std::string quoteCurrency, int count){
    std::vector<std::pair<std::string, std::string>> result;
    std::vector<Ticker> selectedTickers;

    for(const auto& ticker : tickers){
        if(ticker.quoteCurrency.compare(quoteCurrency) == 0){
            selectedTickers.emplace_back(ticker);
        }
    }

    std::sort(selectedTickers.begin(), selectedTickers.end(), 
        [](const Ticker& a, const Ticker& b){
            return std::stod(a.quoteVolume) > std::stod(b.quoteVolume);
    });

    selectedTickers.resize(count);

    for(const auto ticker : selectedTickers){
        result.emplace_back(std::pair<std::string, std::string>(ticker.baseCurrency, ticker.quoteCurrency));
    }

    return result;
}

std::vector<std::pair<std::string, std::string>> randomFilter(const std::vector<Ticker>& tickers, std::string quoteCurrency, int count){
    std::vector<std::pair<std::string, std::string>> result;
    std::vector<Ticker> selectedTickers;

    for(const auto& ticker : tickers){
        if(ticker.quoteCurrency.compare(quoteCurrency) == 0){
            selectedTickers.emplace_back(ticker);
        }
    }

    std::random_shuffle(selectedTickers.begin(), selectedTickers.end());

    selectedTickers.resize(count);

    for(const auto ticker : selectedTickers){
        result.emplace_back(std::pair<std::string, std::string>(ticker.baseCurrency, ticker.quoteCurrency));
    }

    return result;
}

int main(){
    std::srand(static_cast<uint64_t>(std::time(0)));
    OneXAPI::setLoggerConfig(R"({"main":{"logLevel":"info","outputMethod":"file"},"websocket":{"logLevel":"info","outputMethod":"file"}})");
    OneXAPI::Upbit::Spot upbitSpotclient;
    OneXAPI::Binance::Spot binanceSpotclient;

    spotHelper upbitSpot(upbitSpotclient);
    spotHelper binanceSpot(binanceSpotclient);

    auto upbitTickers = upbitSpot.getMarketTickers("KRW");
    auto binanceTickers = binanceSpot.getMarketTickers("USDT");

    auto upbitTop20Currency = volumeFilter(upbitTickers, "KRW", 20);
    auto binanceTop20Currency = volumeFilter(binanceTickers, "USDT", 20);

    std::vector<std::pair<std::string, std::string>> upbitTickerLongtermSymbol, binanceTickerLongtermSymbol;
    std::vector<std::pair<std::string, std::string>> upbitOrderbookLongtermSymbol, binanceOrderbookLongtermSymbol;

    upbitSpot.subscriber(subscribeType::TICKER, upbitTickerLongtermSymbol, upbitTop20Currency, "upbitSpot");
    binanceSpot.subscriber(subscribeType::TICKER, binanceTickerLongtermSymbol, binanceTop20Currency, "binanceSpot");

    upbitSpot.subscriber(subscribeType::ORDERBOOK, upbitOrderbookLongtermSymbol, upbitTop20Currency, "upbitSpot");
    binanceSpot.subscriber(subscribeType::ORDERBOOK, binanceOrderbookLongtermSymbol, binanceTop20Currency, "binanceSpot");

    while(true){
        OneXAPI::Upbit::Spot upbitShortSpotclient;
        OneXAPI::Binance::Spot binanceShortSpotclient;

        spotHelper upbitShortSpot(upbitShortSpotclient);
        spotHelper binanceShortSpot(binanceShortSpotclient);

        auto upbitShortTickers = upbitShortSpot.getMarketTickers("KRW");
        auto binanceShortTickers = binanceShortSpot.getMarketTickers("USDT");

        auto upbitRandom30Currency = randomFilter(upbitShortTickers, "KRW", 30);
        auto binanceRandom30Currency = randomFilter(binanceShortTickers, "USDT", 30);

        std::vector<std::pair<std::string, std::string>> upbitTickerShorttermSymbol, binanceTickerShorttermSymbol;
        std::vector<std::pair<std::string, std::string>> upbitOrderbookShorttermSymbol, binanceOrderbookShorttermSymbol;

        upbitShortSpot.subscriber(subscribeType::TICKER, upbitTickerShorttermSymbol, upbitRandom30Currency, "upbitSpot");
        binanceShortSpot.subscriber(subscribeType::TICKER, binanceTickerShorttermSymbol, binanceRandom30Currency, "binanceSpot");

        upbitShortSpot.subscriber(subscribeType::ORDERBOOK, upbitOrderbookShorttermSymbol, upbitRandom30Currency, "upbitSpot");
        binanceShortSpot.subscriber(subscribeType::ORDERBOOK, binanceOrderbookShorttermSymbol, binanceRandom30Currency, "binanceSpot");

        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::vector<std::pair<std::string, std::string>> upbitUnsubscribeSymbols, binanceUnsubscribeSymbols;

        for(int i = 0; i < 5; i++){
            upbitUnsubscribeSymbols.emplace_back(upbitRandom30Currency[std::rand() % upbitRandom30Currency.size()]);
        }

        upbitRandom30Currency = randomFilter(upbitShortTickers, "KRW", 30);
        binanceRandom30Currency = randomFilter(binanceShortTickers, "USDT", 30);

        upbitUnsubscribeSymbols.insert(upbitUnsubscribeSymbols.end(), upbitRandom30Currency.begin(), upbitRandom30Currency.end());
        binanceUnsubscribeSymbols.insert(binanceUnsubscribeSymbols.end(), binanceRandom30Currency.begin(), binanceRandom30Currency.end());

        upbitShortSpot.unsubscriber(subscribeType::TICKER, upbitTickerShorttermSymbol, upbitUnsubscribeSymbols, "upbitSpot");
        binanceShortSpot.unsubscriber(subscribeType::TICKER, binanceTickerShorttermSymbol, binanceUnsubscribeSymbols, "binanceSpot");

        upbitShortSpot.unsubscriber(subscribeType::ORDERBOOK, upbitOrderbookShorttermSymbol, upbitUnsubscribeSymbols, "upbitSpot");
        binanceShortSpot.unsubscriber(subscribeType::ORDERBOOK, binanceOrderbookShorttermSymbol, binanceUnsubscribeSymbols, "binanceSpot");

        std::this_thread::sleep_for(std::chrono::seconds(5));

        for(int i = 0; i < 10; i++){
            upbitSpot.checker(upbitSpotSafeSymbol, upbitTickerLongtermSymbol, upbitOrderbookLongtermSymbol, "upbitSpot", "LONG");
            binanceSpot.checker(binanceSpotSafeSymbol, binanceTickerLongtermSymbol, binanceOrderbookLongtermSymbol, "binanceSpot", "LONG");

            upbitShortSpot.checker(upbitSpotSafeSymbol, upbitTickerShorttermSymbol, upbitOrderbookShorttermSymbol, "upbitSpot", "SHORT");
            binanceShortSpot.checker(binanceSpotSafeSymbol, binanceTickerShorttermSymbol, binanceOrderbookShorttermSymbol, "binanceSpot", "SHORT");
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    return 0;
}