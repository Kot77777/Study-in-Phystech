#include <iostream>
#include <string>
#include "Class_weapon.h"
#include "Gun.h"
#include "SubmachinGun.h"
#include "Knife.h"
#include "Bazooka.h"
#include "Player.h"
using namespace std;

int main()
{
    Gun gun;
    SubmachinGun machingun;
    Bazooka bazooka;
    Knife knife;

    Player player;
    player.Shoot(&machingun);
    return 0;
}
