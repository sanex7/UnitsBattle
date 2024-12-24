#pragma once
#include "Unit.h"

class Mage : public Unit {
private:
    unsigned int mana;

public:
    Mage(const String<>& name, int HP, unsigned int mana);
    void Attack(Unit& target) override;
    void Defense() override;
};