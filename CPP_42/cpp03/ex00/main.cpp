#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");

    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("target2");
    clap.takeDamage(10);
    clap.beRepaired(5);

    return 0;
}
