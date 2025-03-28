#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
public:
    Character(int id, string n, int lvl, int hp, string w)
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(w) {}
    
    virtual void attack() {
        cout << name << " attacks with " << weaponType << endl;
    }
    virtual void defend() {
        cout << name << " defends!" << endl;
    }
    virtual void displayStats() {
        cout << "ID: " << characterID << "\nName: " << name << "\nLevel: " << level << "\nHP: " << healthPoints << "\nWeapon: " << weaponType << endl;
    }
};
class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int a, int d)
        : Character(id, n, lvl, hp, weapon), armorStrength(a), meleeDamage(d) {}
    
    void attack() override {
        cout << name << " attacks with " << weaponType << " for " << meleeDamage << " damage!" << endl;
    }
    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << "\nDamage: " << meleeDamage << endl;
    }
};
class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(int id, string n, int lvl, int hp, string weapon, int m, int p)
        : Character(id, n, lvl, hp, weapon), manaPoints(m), spellPower(p) {}
    
    void defend() override {
        cout << name << " casts a magic shield!" << endl;
    }
    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << "\nSpell Power: " << spellPower << endl;
    }
};
class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(int id, string n, int lvl, int hp, string w, int a, int acc)
        : Character(id, n, lvl, hp, w), arrowCount(a), rangedAccuracy(acc) {}
    
    void attack() override {
        cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }
    void displayStats() override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << "\nRanged Accuracy: " << rangedAccuracy << "%" << endl;
    }
};
class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(int id, string n, int lvl, int hp, string w, int s, int ag)
        : Character(id, n, lvl, hp, w), stealthLevel(s), agility(ag) {}
    
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << endl;
    }
};
int main() {
    Warrior w1(1, "Abdullah", 10, 100, "Sword", 50, 20);
    Mage m1(2, "Fatima", 12, 80, "Staff", 100, 30);
    Archer a1(3, "Manahil", 9, 90, "Bow", 20, 85);
    Rogue r1(4, "Shimaz", 11, 85, "Dagger", 75, 95);
    
    cout << "\nWarrior Stats:\n";
    w1.displayStats();
    w1.attack();
    
    cout << "\nMage Stats:\n";
    m1.displayStats();
    m1.defend();
    
    cout << "\nArcher Stats:\n";
    a1.displayStats();
    a1.attack();
    
    cout << "\nRogue Stats:\n";
    r1.displayStats();
    
    return 0;
}

