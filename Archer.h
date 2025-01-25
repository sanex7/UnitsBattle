#ifndef ARCHER_H
#define ARCHER_H

#include "Unit.h"

namespace SpecializedUnits {

    using namespace BaseUnits;

    class Archer : public Unit {
    private:
        unsigned int arrows;

    public:
        Archer(const String<>& name, int HP, unsigned int arrows);
        void Attack(Unit& target) override;
        void Defense() override;
    };

}

#endif