#ifndef MAGE_H
#define MAGE_H

#include "Unit.h"

namespace SpecializedUnits {

    using namespace BaseUnits;

    class Mage : public Unit {
    private:
        unsigned int mana;

    public:
        Mage(const String<>& name, int HP, unsigned int mana);
        void Attack(Unit& target) override;
        void Defense() override;
    };

}

#endif