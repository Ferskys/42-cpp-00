#include "newZombie.hpp"
#include "randomChump.hpp"

int main() {
    Zombie* zombie1 = newZombie("HeapZombie");
    zombie1->announce();
    delete zombie1;

    randomChump("StackZombie");

    return 0;
}