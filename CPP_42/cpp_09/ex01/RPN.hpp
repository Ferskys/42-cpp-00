#pragma once
#include <stack>
#include <string>

class RPN {
public:
    RPN();
    ~RPN();
    int evaluate(const std::string &expression);
    
private:
    std::stack<int> values;
};
