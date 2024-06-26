#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap("Guardian");

    scavTrap.attack("Bandit");
    scavTrap.guardGate();
    scavTrap.takeDamage(20);
    scavTrap.beRepaired(10);

    return 0;
}
