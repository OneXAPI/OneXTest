#include "OneXAPI.hpp"
#include "spotHelper.hpp"

std::vector<std::pair<std::string, std::string>> volumeFilter(const std::vector<Ticker>& tickers, 
    std::string quoteCurrency, int count){

    std::vector<std::pair<std::string, std::string>> result;
    std::vector<Ticker> highrankTickers, lowrankTickers;

    for(const auto& ticker : tickers){
        if(ticker.quoteCurrency.compare(quoteCurrency) == 0){
            highrankTickers.emplace_back(ticker);
            lowrankTickers.emplace_back(ticker);
        }
    }

    std::sort(highrankTickers.begin(), highrankTickers.end(), 
        [](const Ticker& a, const Ticker& b){
            return std::stod(a.quoteVolume) > std::stod(b.quoteVolume);
    });

    std::sort(lowrankTickers.begin(), lowrankTickers.end(), 
        [](const Ticker& a, const Ticker& b){
            return std::stod(a.quoteVolume) < std::stod(b.quoteVolume);
    });

    highrankTickers.resize(count);
    lowrankTickers.resize(count);

    for(const auto ticker : highrankTickers){
        result.emplace_back(std::pair<std::string, std::string>(ticker.baseCurrency, ticker.quoteCurrency));
    }

    for(const auto ticker : lowrankTickers){
        result.emplace_back(std::pair<std::string, std::string>(ticker.baseCurrency, ticker.quoteCurrency));
    }

    return result;
}

bool compareSymbols(const std::vector<std::pair<std::string, std::string>>& base, 
    const std::vector<std::pair<std::string, std::string>>& ticker, 
    const std::vector<std::pair<std::string, std::string>>& orderbook){
    
    for(const auto& baseSymbol : base){
        bool isFound = false;

        for(const auto& quoteSymbol : ticker){
            if(baseSymbol == quoteSymbol){
                isFound = true;
                break;
            }
        }

        if(!isFound){
            return false;
        }

        isFound = false;

        for(const auto& quoteSymbol : orderbook){
            if(baseSymbol == quoteSymbol){
                isFound = true;
                break;
            }
        }

        if(!isFound){
            return false;
        }
    }

    return true;
}

int main(){
    std::srand(static_cast<uint64_t>(std::time(0)));
    OneXAPI::setLoggerConfig(R"({"main":{"logLevel":"error","outputMethod":"file"},"websocket":{"logLevel":"info","outputMethod":"file"}})");

    int count = 0;

    while(true){
        LOGGER.error("loop " + std::to_string(count++) + " start");
        OneXAPI::Upbit::Spot upbitSpotclient;
        OneXAPI::Binance::Spot binanceSpotclient;

        spotHelper upbitSpot(upbitSpotclient);
        spotHelper binanceSpot(binanceSpotclient);

        auto upbitTickers = upbitSpot.getMarketTickers("KRW");
        auto binanceTickers = binanceSpot.getMarketTickers("USDT");

        auto upbitCurrency = volumeFilter(upbitTickers, "KRW", 20);
        auto binanceCurrency = volumeFilter(binanceTickers, "USDT", 20);

        std::vector<std::pair<std::string, std::string>> upbitTickerSubscribedSymbol, binanceTickerSubscribedSymbol;
        std::vector<std::pair<std::string, std::string>> upbitOrderbookSubscribedSymbol, binanceOrderbookSubscribedSymbol;

        upbitSpot.subscriber(subscribeType::TICKER, upbitTickerSubscribedSymbol, upbitCurrency, "upbitSpot");
        binanceSpot.subscriber(subscribeType::TICKER, binanceTickerSubscribedSymbol, binanceCurrency, "binanceSpot");

        upbitSpot.subscriber(subscribeType::ORDERBOOK, upbitOrderbookSubscribedSymbol, upbitCurrency, "upbitSpot");
        binanceSpot.subscriber(subscribeType::ORDERBOOK, binanceOrderbookSubscribedSymbol, binanceCurrency, "binanceSpot");

        if(
            compareSymbols(upbitCurrency, upbitTickerSubscribedSymbol, upbitOrderbookSubscribedSymbol) && 
            compareSymbols(binanceCurrency, binanceTickerSubscribedSymbol, binanceOrderbookSubscribedSymbol)){
            continue;
        }

        bool isFound = false;

        for(int i = 0; i < 5 ; i++){
            std::vector<std::pair<std::string, std::string>> upbitTickerFailedSymbol = upbitCurrency, binanceTickerFailedSymbol = binanceCurrency;
            std::vector<std::pair<std::string, std::string>> upbitOrderbookFailedSymbol = upbitCurrency, binanceOrderbookFailedSymbol = binanceCurrency;

            for(const auto& subscribedSymbol : upbitTickerSubscribedSymbol){
                upbitTickerFailedSymbol.erase(
                    std::remove(upbitTickerFailedSymbol.begin(), upbitTickerFailedSymbol.end(), 
                        subscribedSymbol), 
                    upbitTickerFailedSymbol.end()
                );
            }

            for(const auto& subscribedSymbol : upbitOrderbookSubscribedSymbol){
                upbitOrderbookFailedSymbol.erase(
                    std::remove(upbitOrderbookFailedSymbol.begin(), upbitOrderbookFailedSymbol.end(), 
                        subscribedSymbol), 
                    upbitOrderbookFailedSymbol.end()
                );
            }
        
            for(const auto& subscribedSymbol : binanceTickerSubscribedSymbol){
                binanceTickerFailedSymbol.erase(
                    std::remove(binanceTickerFailedSymbol.begin(), binanceTickerFailedSymbol.end(), 
                        subscribedSymbol), 
                    binanceTickerFailedSymbol.end()
                );
            }

            for(const auto& subscribedSymbol : binanceOrderbookSubscribedSymbol){
                binanceOrderbookFailedSymbol.erase(
                    std::remove(binanceOrderbookFailedSymbol.begin(), binanceOrderbookFailedSymbol.end(), 
                        subscribedSymbol), 
                    binanceOrderbookFailedSymbol.end()
                );
            }

            upbitSpot.subscriber(subscribeType::TICKER, upbitTickerSubscribedSymbol, upbitTickerFailedSymbol, "upbitSpot");
            binanceSpot.subscriber(subscribeType::TICKER, binanceTickerSubscribedSymbol, binanceTickerFailedSymbol, "binanceSpot");

            upbitSpot.subscriber(subscribeType::ORDERBOOK, upbitOrderbookSubscribedSymbol, upbitOrderbookFailedSymbol, "upbitSpot");
            binanceSpot.subscriber(subscribeType::ORDERBOOK, binanceOrderbookSubscribedSymbol, binanceOrderbookFailedSymbol, "binanceSpot");

            if(
                compareSymbols(upbitCurrency, upbitTickerSubscribedSymbol, upbitOrderbookSubscribedSymbol) && 
                compareSymbols(binanceCurrency, binanceTickerSubscribedSymbol, binanceOrderbookSubscribedSymbol)){
                isFound = true;
                break;
            }
        }

        if(!isFound){
            error("Can't Subscribe in 5 loop");
        }
    }
}