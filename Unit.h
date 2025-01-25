#ifndef UNIT_H
#define UNIT_H

#include "string.h"
#include <iostream>

namespace BaseUnits {

    class Unit {
    protected:
        int HP;
        String<> weapon;
        int speed;
        String<> name;
        bool IsDefense = false;

    public:
        Unit(const String<>& name, int HP);
        Unit(int HP);
        Unit(const String<>& name);

        virtual void Attack(Unit& target) = 0;
        virtual void Defense() = 0;
        virtual void TakeDamage(int value);

        friend std::ostream& operator<<(std::ostream& os, const Unit& unit);
    };

}

#endif