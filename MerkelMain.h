#pragma once

#include <map>
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();

    private:
        void printMenu(void);
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);
        void processSales(std::vector<OrderBookEntry>& sales);
        std::map<int, void(MerkelMain::*)()> menu;

        std::string currentTime;
        OrderBook orderBook{"CSV_orderbook_data.csv"};
        Wallet wallet;
};