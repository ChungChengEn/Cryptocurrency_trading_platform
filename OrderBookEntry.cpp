#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price, 
                               double _amount,
                               string _timestamp,
                               string _product,
                               OrderBookType _orderType,
                               string _username) 
: price{_price},
  amount{_amount},
  timestamp{_timestamp},
  product{_product},
  orderType{_orderType},
  username{_username}
{
    
}

OrderBookType OrderBookEntry::stringToOrderBookType(string s)
{
    if(s=="ask")
    {
        return OrderBookType::ask;
    }
    else if(s=="bid")
    {
        return OrderBookType::bid;
    }
    else if(s=="asksale")
    {
        return OrderBookType::asksale;
    }
    else if(s=="bidsale")
    {
        return OrderBookType::bidsale;
    }
    else
    {
        return OrderBookType::unknown;
    }
}

double OrderBookEntry::getPrice() const
{
    return price;
}

double OrderBookEntry::getAmount() const
{
    return amount;
}

string OrderBookEntry::getTimestamp() const
{
    return timestamp;
}

string OrderBookEntry::getProduct() const
{
    return product;
}

OrderBookType OrderBookEntry::getOrderType() const
{
    return orderType;
}

string OrderBookEntry::getUsername() const
{
    return username;
}

void OrderBookEntry::setPrice(double _price)
{
    price = _price;
}

void OrderBookEntry::setAmount(double _amount)
{
    amount = _amount;
}

void OrderBookEntry::setUsername(string _username)
{
    username = _username;
}

void OrderBookEntry::setOrderType(OrderBookType _orderType)
{
    orderType = _orderType;
}