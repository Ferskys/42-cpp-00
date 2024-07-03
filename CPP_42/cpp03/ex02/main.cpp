#include "FragTrap.hpp"

int main() {
    FragTrap fragTrap("Fragger");

    fragTrap.attack("Bandit");
    fragTrap.highFivesGuys();
    fragTrap.takeDamage(40);
    fragTrap.beRepaired(20);

    return 0;
}
