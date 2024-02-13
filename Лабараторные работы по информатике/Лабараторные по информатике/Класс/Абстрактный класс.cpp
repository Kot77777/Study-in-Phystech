#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
    virtual void Shoot() = 0; //делаем читсто виртуальной
    void Foo()
    {
        cout << "Foo" << endl;
    }
};

class Gun: public Weapon
{
public:
    void Shoot() override
    {
        cout << "BANG"  << endl;
    }
};

class SubmachinGun: public Gun
{
public:
    void Shoot() override
    {
        cout << "BANG BANG BANG" << endl;
    }
};

class Bazooka: public Weapon
{
public:
    void Shoot() override
    {
        cout << "BANDBUM" << endl;
    }
};

class Knife: public Weapon
{
public:
    void Shoot() override
    {
        cout << "VGUCH" << endl;
    }
};

class Player
{
public:
    void Shoot(Weapon* weapon)
    {
       weapon->Shoot();
    }
};
int main()
{
    Gun gun;
    SubmachinGun machingun;
    Bazooka bazooka;
    Knife knife;

    knife.Foo();
    Player player;
    player.Shoot(&knife);
    return 0;
}
