#include "Wallet.h"
#include "CSVReader.h"
#include <iostream>

Wallet::Wallet()
{

}

/** insert currency to the wallet */
void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if(amount < 0)
    {
        throw std::exception{};
    }
    if(currencies.count(type)==0)
    {
        balance = 0;
    }
    else
    {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

/** remove currency from the wallet */
bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;
    if(amount < 0)
    {
        throw std::exception{};
    }
    if(currencies.count(type)==0)
    {
        return true;
    }
    else    // is there - do we have enough
    {
        if(containsCurrency(type,amount))   // we have enough
        {
            currencies[type] -= amount;
            return true;
        }
        else    // they have it but not enough
            return true;
    }
}

/** check if the wallet contains this much currency or more */
bool Wallet::containsCurrency(std::string type, double amount)
{
    if(currencies.count(type)==0)
        return false;
    else
        return currencies[type]>=amount;
}

/** generate a string representation of the wallet */
std::string Wallet::toString()
{
    std::string s;
    for(std::pair<std::string,double> pair: currencies)
    {
        std::string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}

bool Wallet::canFulfillOrder(OrderBookEntry order) 
{
    std::vector<std::string> currs = CSVReader::tokenise(order.getProduct(),'/');
    // ask
    if(order.getOrderType()==OrderBookType::ask)
    {
        double amount = order.getAmount();
        std::string currency = currs[0];
        std::cout << "Wallet::canFulfillOrder " << currency << ":" << amount << std::endl; 
        return containsCurrency(currency, amount);
    }
    // bid 
    if(order.getOrderType()==OrderBookType::bid)
    {
        double amount = order.getAmount()*order.getPrice();
        std::string currency = currs[1];
        return containsCurrency(currency, amount);
    }

    return false;
}

std::ostream& operator <<(std::ostream& os, Wallet wallet)
{
    os << wallet.toString();
    return os;
}

void Wallet::processSale(OrderBookEntry& sale)
{
    std::vector<std::string> currs = CSVReader::tokenise(sale.getProduct(),'/');
    // ask
    if(sale.getOrderType()==OrderBookType::asksale)
    {
        double outgoingAmount = sale.getAmount();
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.getAmount()*sale.getPrice();
        std::string incomingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    // bid 
    if(sale.getOrderType()==OrderBookType::bidsale)
    {
        double incomingAmount = sale.getAmount();
        std::string incomingCurrency = currs[0];
        double outgoingAmount = sale.getAmount()*sale.getPrice();
        std::string outgoingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}