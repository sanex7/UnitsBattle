#pragma once
#include "Unit.h"

class Swordman : public Unit {
private:
    unsigned int power;

public:
    Swordman(const String<>& name, int HP, unsigned int power);
    void Attack(Unit& target) override;
    void Defense() override;
};