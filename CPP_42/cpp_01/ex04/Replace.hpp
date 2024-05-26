#pragma once
#include <string>

class Replace {
public:
    Replace(const std::string& filename, const std::string& s1, const std::string& s2);
    bool performReplacement();
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    std::string replaceOccurrences(const std::string& line) const;
};