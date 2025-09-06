#pragma once // tell the compiler only include this header file once (if there are multiple cpp files including this header file)

#include <string>
using namespace std;

enum class OrderBookType{bid,ask,unknown,bidsale,asksale};

class OrderBookEntry
{
    public:
        OrderBookEntry(double, double, string, string, OrderBookType,string username="dataset");
        double getPrice() const;
        double getAmount() const;
        string getTimestamp() const;
        string getProduct() const;
        OrderBookType getOrderType() const;
        string getUsername() const;

        void setPrice(double price);
        void setAmount(double amount);
        void setUsername(string username);
        void setOrderType(OrderBookType orderType);


        static OrderBookType stringToOrderBookType(string);

        static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2)
        {
            return e1.getTimestamp() < e2.getTimestamp();
        }
        static bool compareByPriceAsc(const OrderBookEntry& e1, const OrderBookEntry& e2)
        {
            return e1.getPrice() < e2.getPrice();
        }
        static bool compareByPriceDesc(const OrderBookEntry& e1, const OrderBookEntry& e2)
        {
            return e1.getPrice() > e2.getPrice();
        }
    private:
        double price;
        double amount;
        string timestamp;
        string product;
        OrderBookType orderType;
        string username;
};