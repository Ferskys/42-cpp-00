#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

bool Replace::performReplacement() {
    std::ifstream inputFile(_filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open file " << _filename << std::endl;
        return false;
    }

    std::string outputFilename = _filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create file " << outputFilename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceOccurrences(line) << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return true;
}

std::string Replace::replaceOccurrences(const std::string& line) const {
    std::string result;
    size_t pos = 0;
    size_t foundPos;

    while ((foundPos = line.find(_s1, pos)) != std::string::npos) {
        result.append(line, pos, foundPos - pos);
        result.append(_s2);
        pos = foundPos + _s1.length();
    }

    result.append(line, pos, line.length() - pos);
    return result;
}