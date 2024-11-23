#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& filename) const;

private:
    std::map<std::string, float> exchangeRates;

    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& valueStr, float& value);
    float getRateForDate(const std::string& date) const;

    void displayResult(const std::string& date, float value, float rate) const;

    // Adicionando as funções auxiliares ao cabeçalho
    void cleanWhitespace(std::string& str) const;
    void reportBadInput(const std::string& line) const;
};
