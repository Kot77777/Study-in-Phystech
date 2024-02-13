#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    ~A()
    {
        cout << "Osvobogdeny Pamyt" << endl;
    }
};

class B: public A
{
public:
    B()
    {
        cout << "Vydelit Pamyt" << endl;
    }
    ~B()
    {
        cout << "Osvobogdeny Pamyt" << endl;
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
