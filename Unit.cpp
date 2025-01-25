#include "Unit.h"

namespace BaseUnits {

    Unit::Unit(const String<>& name, int HP) : name(name), HP(HP) {}
    Unit::Unit(int HP) : HP(HP) {}
    Unit::Unit(const String<>& name) : name(name) {}

    void Unit::TakeDamage(int value) {
        if (IsDefense) {
            value /= 2;
        }
        HP -= value;
        std::cout << name << " takes " << value << " damage. HP left: " << HP << "\n";
    }

    std::ostream& operator<<(std::ostream& os, const Unit& unit) {
        os << "Unit Name: " << unit.name << ", HP: " << unit.HP;
        return os;
    }

}