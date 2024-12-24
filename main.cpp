#include "Swordman.h"
#include "Archer.h"
#include "Mage.h"

int main() {
    Swordman swordman("Arthur", 100, 20);
    Archer archer("Robin", 80, 5);
    Mage mage("Merlin", 60, 50);

    swordman.Attack(archer);
    archer.Defense();
    mage.Attack(swordman);

    return 0;
}