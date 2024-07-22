#pragma once

#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    Brain& operator=(const Brain& other);

    std::string ideas[100];
};
