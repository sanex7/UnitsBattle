#include <iostream>
#include "string.h"

enum class Grade {
    Common,
    Rare,
    Epic,
    Legendary,
    Mythic
};

//класс Unit
class Unit {
protected:
    int HP;
    String<> weapon;
    int speed;
    String<> name;

public:
    Unit(const String<>& name, int HP) : name(name), HP(HP) {}
    Unit(int HP) : HP(HP) {}
    Unit(const String<>& name) : name(name) {}

    virtual void Attack(Unit& target) = 0;
    virtual void Defense() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Unit& unit) {
        os << "Unit Name: " << unit.name << ", HP: " << unit.HP;
        return os;
    }
};

//класс Swordman
class Swordman : public Unit {
private:
    unsigned int power;

public:
    Swordman(const String<>& name, int HP, unsigned int power)
        : Unit(name, HP), power(power) {}

    void Attack(Unit& target) override {
        std::cout << name << " attacks with sword power " << power << "!\n";
    }

    void Defense() override {
        std::cout << name << " defends with a shield.\n";
    }
};

//класс Archer
class Archer : public Unit {
private:
    unsigned int arrows;

public:
    Archer(const String<>& name, int HP, unsigned int arrows)
        : Unit(name, HP), arrows(arrows) {}

    void Attack(Unit& target) override {
        if (arrows > 0) {
            std::cout << name << " shoots an arrow. Arrows left: " << --arrows << "\n";
        }
        else {
            std::cout << name << " is out of arrows!\n";
        }
    }

    void Defense() override {
        std::cout << name << " dodges the attack.\n";
    }
};

//класс Mage
class Mage : public Unit {
private:
    unsigned int mana;

public:
    Mage(const String<>& name, int HP, unsigned int mana)
        : Unit(name, HP), mana(mana) {}

    void Attack(Unit& target) override {
        if (mana >= 10) {
            mana -= 10;
            std::cout << name << " casts a spell. Mana left: " << mana << "\n";
        }
        else {
            std::cout << name << " is out of mana!\n";
        }
    }

    void Defense() override {
        std::cout << name << " creates a magical shield.\n";
    }
};

//класс Weapon
class Weapon {
protected:
    Grade grade;
    String<> name;
    int damage;

public:
    Weapon(Grade grade, const String<>& name) : grade(grade), name(name), damage(0) {}
    Weapon(const String<>& name) : name(name), damage(0) {}

    virtual Grade GetDamage() const = 0;
    virtual void UpGrage() = 0;
};

//класс Sword
class Sword : public Weapon {
public:
    Sword(Grade grade, const String<>& name) : Weapon(grade, name) {}

    Grade GetDamage() const override {
        return grade;
    }

    void UpGrage() override {
        std::cout << name << " upgraded to a stronger sword!\n";
    }
};

//класс Bow
class Bow : public Weapon {
private:
    int max_damage;

public:
    Bow(Grade grade, const String<>& name, int max_damage)
        : Weapon(grade, name), max_damage(max_damage) {}

    Grade GetDamage() const override {
        return grade;
    }

    void UpGrage() override {
        std::cout << name << " upgraded to deal more damage!\n";
    }
};

//класс Stick
class Stick : public Weapon {
private:
    int charges;

public:
    Stick(Grade grade, const String<>& name, int charges)
        : Weapon(grade, name), charges(charges) {}

    Grade GetDamage() const override {
        return grade;
    }

    void UpGrage() override {
        std::cout << name << " upgraded with more charges!\n";
    }
};