#include <iostream>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    menu[1] = &MerkelMain::printHelp;
    menu[2] = &MerkelMain::printMarketStats;
    menu[3] = &MerkelMain::enterAsk;
    menu[4] = &MerkelMain::enterBid;
    menu[5] = &MerkelMain::printWallet;
    menu[6] = &MerkelMain::gotoNextTimeframe;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC",10);
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu(void)
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer: sell
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid: buy
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "===============" << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
    std::cout << "Type in 1-6" << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make asks/bids" << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (const std::string p: orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains : " << entries.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e:entries)
    // {
    //     if(e.getOrderType()==OrderBookType::ask)
    //     {
    //         asks++;
    //     }
    //     if(e.getOrderType()==OrderBookType::bid)
    //     {
    //         bids++;
    //     }
    // }
    // std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an offer - enter the amount: product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size() != 3)
    {
        std::cout << "Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );
            obe.setUsername("simuser");
            if(wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds. " << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input " << std::endl;
        }
        
    }
    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product,price,amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');
    if(tokens.size() != 3)
    {
        std::cout << "Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid
            );
            obe.setUsername("simuser");
            if(wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                std::cout << "Wallet has insufficient funds. " << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterBid Bad input " << std::endl;
        }
        
    }
    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << wallet;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame" << std::endl;
    for(std::string p: orderBook.getKnownProducts())
    {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        processSales(sales);
    }
    currentTime = orderBook.getNextTime(currentTime);
}

// get the user option
int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::getline(std::cin, line);
    
    try
    {
        userOption = std::stoi(line);
    }
    catch(const std::exception& e)
    {
        
    }

    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

// process the user option
void MerkelMain::processUserOption(int userOption)
{
    if(userOption < 1 || userOption > 6)
    {
        std::cout << "Invallid choice. Choose 1-6" << std::endl;
    }
    else
    {
        (this->*menu[userOption])();
    }
}

void MerkelMain::processSales(std::vector<OrderBookEntry>& sales)
{
    for(OrderBookEntry& sale: sales)
    {
        std::cout << "Sale price: " << sale.getPrice() << " amount " << sale.getAmount() << std::endl;
        if(sale.getUsername()=="simuser")
        {
            // update the wallet
            wallet.processSale(sale);
        }
    }
}