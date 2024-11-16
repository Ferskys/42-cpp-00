#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <limits> 

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    float getRateForDate(const std::string &date) const;
    std::map<std::string, float> getExchangeRates() const;

private:
    std::map<std::string, float> exchangeRates;
    void clear();
    void loadDatabaseFromFile(std::ifstream &file);
    bool processLine(const std::string &line, std::string &date, float &rate);
    bool validateDateAndRate(const std::string &date, float rate);
    void showExchangeRates() const;
};