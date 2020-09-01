//
// Created by justi on 11/7/2019.
//

#include "PokemonGym.h"
#include <iostream>
#include "Building.h"
#include "GameObject.h"

using namespace std;

PokemonGym::PokemonGym()
{
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}
PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
    display_code = 'G';
    state = NOT_BEATEN;
    id_num = in_id;
    max_number_of_training_units = max_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    dollar_cost_per_training_unit = dollar_cost;
    location = in_loc;
    cout << "PokemonGym constructed" << endl;
    num_training_units_remaining = 20;
}
double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
    double total_cost = unit_qty * dollar_cost_per_training_unit;
    return total_cost;
}
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
    unsigned int total_stamina_cost = unit_qty * stamina_cost_per_training_unit;
    return total_stamina_cost;
}
unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
    return num_training_units_remaining;
}
bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
    return ((budget >= (unit_qty * dollar_cost_per_training_unit)) && (stamina >= (unit_qty * stamina_cost_per_training_unit)));
}
unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
    if (num_training_units_remaining >= training_units) {
        num_training_units_remaining = num_training_units_remaining - training_units;
        return training_units * experience_points_per_training_unit;
    }
    else if (num_training_units_remaining <= training_units) {
        num_training_units_remaining = 0;
        return num_training_units_remaining * experience_points_per_training_unit;
    }
}
bool PokemonGym::Update()
{
    if (num_training_units_remaining == 0)
    {
        state = BEATEN;
        display_code = 'g';
        cout << display_code << id_num << " has been beaten" << endl;
    }
}
bool PokemonGym::IsBeaten()
{
    return num_training_units_remaining == 0;
}
void PokemonGym::ShowStatus()
{
cout << "Pokemon Gym Status: ";
Building::ShowStatus();
cout << "   Max number of training units: " << max_number_of_training_units << endl;
cout << "   Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
cout << "   Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
cout << "   Experience points per training unit: " << experience_points_per_training_unit << endl;
if (num_training_units_remaining == 1)
    cout << "   1 training unit is remaining for this gym" << endl;
else
    cout << "   " << num_training_units_remaining << " training units are remaining for this gym" << endl;
}

PokemonGym::~PokemonGym()
{
    cout << "PokemonGym destructed" << endl;
}