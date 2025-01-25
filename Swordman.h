#ifndef SWORDMAN_H
#define SWORDMAN_H

#include "Unit.h"

namespace SpecializedUnits {

    using namespace BaseUnits;

    class Swordman : public Unit {
    private:
        unsigned int power;

    public:
        Swordman(const String<>& name, int HP, unsigned int power);
        void Attack(Unit& target) override;
        void Defense() override;
    };

}

#endif
