#include "Identify.hpp"
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    Base* base = generate();
    identify(base);
    identify(*base);

    delete base;
    return 0;
}