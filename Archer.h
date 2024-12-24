#pragma once
#include "Unit.h"

class Archer : public Unit {
private:
    unsigned int arrows;

public:
    Archer(const String<>& name, int HP, unsigned int arrows);
    void Attack(Unit& target) override;
    void Defense() override;
};