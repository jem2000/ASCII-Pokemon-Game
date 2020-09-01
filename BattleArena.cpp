//
// Created by justi on 11/30/2019.
//

#include "BattleArena.h"

BattleArena::BattleArena()
{
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = 3;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena default constructed" << endl;
}
BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc)
{
    id_num = in_Id;
    location = in_loc;
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed" << endl;
}
unsigned int BattleArena::GetNumRivalsRemaining()
{
    return num_rivals_remaining;
}
bool BattleArena::HasEnoughRivals()
{
    return num_rivals_remaining >= 1;
}
double BattleArena::GetDollarCost()
{
    return dollar_cost_per_fight;
}
unsigned int BattleArena::GetStaminaCost()
{
    return stamina_cost_per_fight;
}
bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
    return (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight);
}
bool BattleArena::Update()
{
    if (num_rivals_remaining == 0) {
        state = NO_RIVALS_AVAILABLE;
        return true;
    }
    else if (num_rivals_remaining != 0) {
        state = RIVALS_AVAILABLE;
        return false;
    }
}
bool BattleArena::IsBeaten()
{
    return num_rivals_remaining == 0;
}
void BattleArena::ShowStatus()
{
    cout << "BattleArena status: ";
    GameObject::ShowStatus();
    Building::ShowStatus();
    cout << "   Maximum number of rivals: " << max_num_rivals << endl;
    cout << "   Stamina cost per fight: " << stamina_cost_per_fight << endl;
    cout << "   Pokemon dollars per fight: " << dollar_cost_per_fight << endl;
    if (num_rivals_remaining == 1)
        cout << "There is 1 rival remaining in this arena" << endl;
    else if (num_rivals_remaining > 1)
        cout << "   There are " << num_rivals_remaining << " rivals in this arena" << endl;
    else if (num_rivals_remaining == 0)
        cout << "Congratulations! You have defeated all of the rivals at this Arena!" << endl;
}

void BattleArena::RivalDefeated()
{
    num_rivals_remaining--;
}
