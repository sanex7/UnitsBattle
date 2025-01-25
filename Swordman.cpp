#include "Swordman.h"

namespace SpecializedUnits {

    Swordman::Swordman(const String<>& name, int HP, unsigned int power)
        : Unit(name, HP), power(power) {}

    void Swordman::Attack(Unit& target) {
        std::cout << name << " attacks with sword power " << power << "!\n";
        target.TakeDamage(power);
    }

    void Swordman::Defense() {
        IsDefense = true;
        std::cout << name << " defends with a shield.\n";
    }

}