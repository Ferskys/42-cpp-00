#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    std::string line, date;
    float rate;
    
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            ss >> date >> rate;
            exchangeRates[date] = rate;
        }
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}

float BitcoinExchange::getRateForDate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.end()) return it->second;
    return 0.0;
}