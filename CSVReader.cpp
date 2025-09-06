#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;
    if(csvFile.is_open())//check if the file is opened
    {
        while(std::getline(csvFile,line))
        {
            try
            {
                OrderBookEntry obe = stringsToOBE(tokenise(line,','));
                entries.push_back(obe);
            }
            catch(const std::exception& e)
            {
                std::cout << "CSVReader::readCSV bad data" << std::endl;
            }
            
        }
    }

    std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end;
    start = csvLine.find_first_not_of(separator,0);
    do{
        end = csvLine.find_first_of(separator,start);
        if(start == csvLine.length() || start==end) break;

        if(end >= 0)    token = csvLine.substr(start, end-start);
        else    token = csvLine.substr(start);

        tokens.push_back(token);

        start = end+1;
    }while(end != std::string::npos); // while(end > 0);
    // std::string::npos --> static member constant value, represent not found position within a string

    return tokens;
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::string priceString,
                                       std::string amountString,
                                       std::string timestamp,
                                       std::string product,
                                       OrderBookType orderType)
{
    double price, amount;
    try
    {
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }
    catch(const std::exception& e)
    {
        std::cout << "CSVReader::stringToOBE Bad float! " << priceString << std::endl;
        std::cout << "CSVReader::stringToOBE Bad float! " << amountString << std::endl;
        throw;
    }
    OrderBookEntry obe{price,
                       amount,
                       timestamp,
                       product,
                       orderType};
    return obe;
    
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    if(tokens.size() != 5)  // bad
    {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    // we have 5 tokens
    try{
        price = std::stod(tokens[3]);// std::stod --> string to double
        amount = std::stod(tokens[4]);
    }catch(const std::exception& e){
        std::cout << "Bad float !" << tokens[3] << std::endl;
        std::cout << "Bad float !" << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{price,amount,tokens[0],tokens[1],OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}