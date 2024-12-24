#include "Mage.h"

Mage::Mage(const String<>& name, int HP, unsigned int mana)
    : Unit(name, HP), mana(mana) {}

void Mage::Attack(Unit& target) {
    if (mana >= 10) {
        mana -= 10;
        std::cout << name << " casts a spell. Mana left: " << mana << "\n";
    }
    else {
        std::cout << name << " is out of mana!\n";
    }
}

void Mage::Defense() {
    IsDefense = true;
    std::cout << name << " creates a magical shield.\n";
}