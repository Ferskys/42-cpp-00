#pragma once

#include <string>
#include <iostream>

class Brain {
public:
    Brain();
    ~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &oterh);

    std::string ideas[100];
};
