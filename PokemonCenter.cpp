//
// Created by justi on 11/6/2019.
//

#include <iostream>
#include "PokemonCenter.h"
#include "Building.h"
#include "GameObject.h"

using namespace std;

PokemonCenter::PokemonCenter()
{
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)
{
    display_code = 'C';
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_stamina_point = stamina_cost;
    stamina_capacity = stamina_cap;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
    num_stamina_points_remaining = stamina_capacity;
}

bool PokemonCenter::HasStaminaPoints()
{
    return num_stamina_points_remaining > 0;
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;
}
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    return budget >= (dollar_cost_per_stamina_point * stamina_points);
}
double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    double dollar_cost = dollar_cost_per_stamina_point * stamina_points;
    return dollar_cost;
}
unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed) {
    if (num_stamina_points_remaining >= points_needed) {
        num_stamina_points_remaining = num_stamina_points_remaining - points_needed;
        return points_needed;
    } else if (num_stamina_points_remaining < points_needed) {
        int points_got;
        points_got = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return points_got;
    }
}
bool PokemonCenter::Update() {
    if (num_stamina_points_remaining == 0) {
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
        return true;
    } else
        return false;
}
void PokemonCenter::ShowStatus()
{
cout << "Pokemon Center Status: ";
Building::ShowStatus();
cout << "   Pokemon dollar cost per stamina point: " << dollar_cost_per_stamina_point << endl;
if (num_stamina_points_remaining == 1)
    cout << "   has 1 stamina point remaining." << endl;
else
cout << "   has " << num_stamina_points_remaining << " stamina points remaining." << endl;
}
double PokemonCenter::getStaminaCost()
{
    return dollar_cost_per_stamina_point;
}
PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter destructed" << endl;
}
