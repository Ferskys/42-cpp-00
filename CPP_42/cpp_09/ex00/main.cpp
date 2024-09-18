#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>    // Include this for std::ifstream
#include <sstream>    // Include this for std::stringstream

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: invalid arguments." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.loadDatabase("bitcoin_data.csv");

    std::ifstream file(argv[1]);
    std::string line, date;
    float value;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> date >> value;
        float rate = btc.getRateForDate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }

    return 0;
}