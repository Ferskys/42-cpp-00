#pragma once
#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void loadDatabase(const std::string &filename);
    float getRateForDate(const std::string &date) const;
    
private:
    std::map<std::string, float> exchangeRates; // date -> rate
};
