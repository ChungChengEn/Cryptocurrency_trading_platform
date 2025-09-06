#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "OrderBook.h"
#include "Wallet.h"


int main()
{

    MerkelMain app{};
    app.init();
    //CSVReader::readCSV("CSV_orderbook_data.csv");
    // Wallet wallet;
    // wallet.insertCurrency("BTC", 10);
    // wallet.insertCurrency("USDT", 10000);
    // std::cout << "Wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
    // std::cout << wallet << std::endl;
    // wallet.removeCurrency("USDT",1000);
    // std::cout << wallet << std::endl;
    // std::cout << wallet << std::endl;
    return 0;
}
