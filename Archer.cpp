#include "Archer.h"

namespace SpecializedUnits {

    Archer::Archer(const String<>& name, int HP, unsigned int arrows)
        : Unit(name, HP), arrows(arrows) {}

    void Archer::Attack(Unit& target) {
        if (arrows > 0) {
            std::cout << name << " shoots an arrow. Arrows left: " << --arrows << "\n";
        }
        else {
            std::cout << name << " is out of arrows!\n";
        }
    }

    void Archer::Defense() {
        IsDefense = true;
        std::cout << name << " dodges the attack.\n";
    }

}