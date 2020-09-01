//
// Created by justi on 11/11/2019.
//

#include "Pokemon.h"
#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "TradingHub.h"
#include <cstdlib>

using namespace std;


Pokemon::Pokemon()
{
    speed = 5;
    cout << "Pokemon default constructed." << endl;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    is_in_hub = false;
    stamina = 50;
    health = 20;
    defense = 15;
    store_health = health;
    physical_damage = 5;
    magical_damage = 4;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    target = 0;


}
Pokemon::Pokemon(char in_code)
{
    speed = 5;
    display_code = in_code;
    cout << "Pokemon constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    is_in_hub = false;
    stamina = 50;
    health = 20;
    defense = 15;
    store_health = health;
    physical_damage = 5;
    magical_damage = 4;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    target = 0;
}
Pokemon::Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc, Move in_attack_1, Move in_attack_2, Move in_attack_3, Move in_attack_4)
{
    speed = in_speed;
    name = in_name;
    location = in_loc;
    id_num = in_id;
    display_code = in_code;
    cout << "Pokemon Constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    is_in_hub = false;
    stamina = 50;
    health = hp;
    defense = def;
    store_health = health;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    attack_1 = in_attack_1;
    attack_2 = in_attack_2;
    attack_3 = in_attack_3;
    attack_4 = in_attack_4;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    target = 0;
}
void Pokemon::StartMoving(Point2D dest)
{
    if (dest.x == location.y && dest.y == location.y)
        cout << display_code << id_num << " I'm already there. See?" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << "): I am exhausted. I may move but you cannot see me." << endl;
    else
    {
        SetupDestination(dest);
        state = MOVING;
        cout << display_code << id_num << " On my way." << endl;
    }

}
void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
    current_center = center;
    if (current_center->GetLocation().x == location.x && current_center->GetLocation().y == location.y)
        cout << display_code << id_num << " I am already at the Pokemon Center!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << "): I am exhausted. I may move but you cannot see me." << endl;
    else
    {
        SetupDestination(current_center->GetLocation());
        state = MOVING_TO_CENTER;
        cout << display_code << id_num << " On my way to the center." << endl;
    }
}
void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    current_gym = gym;
    if (current_gym->GetLocation().x == location.x && current_gym->GetLocation().y == location.y)
        cout << display_code << id_num << " I am already at the Pokemon Gym!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym." << endl;
    else
    {
        SetupDestination(current_gym->GetLocation());
        state = MOVING_TO_GYM;
        cout << display_code << id_num << " On my way to the gym." << endl;
    }
}
void Pokemon::StartMovingToArena(BattleArena* arena)
{
    current_arena = arena;
    if (current_arena->GetLocation().x == location.x && current_arena->GetLocation().y == location.y)
        cout << display_code << id_num << " I am already at the arena!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the arena." << endl;
    else
    {
        SetupDestination(current_arena->GetLocation());
        state = MOVING_TO_ARENA;
        cout << display_code << id_num << " On my way to the arena." << endl;
    }
}

void Pokemon::StartMovingToHub(TradingHub* hub)
{
    current_hub = hub;
    if (current_hub->GetLocation().x == location.x && current_hub->GetLocation().y == location.y)
        cout << display_code << id_num << "I am already at the trading hub!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the arena." << endl;
    else
    {
        SetupDestination(current_hub->GetLocation());
        state = MOVING_TO_HUB;
    }
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
    else if (!is_in_gym)
        cout << display_code << id_num << " I can only train in a Pokemon Gym!" << endl;
    else if (!current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina))
    {
        cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl;
    }
    else if (state == BEATEN)
    {
        cout << display_code << id_num << "): Cannot train! This Pokemon Gym is already beaten!" << endl;
    }
    else
    {
        state = TRAINING_IN_GYM;
        cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() << " with " << num_training_units << " training units" << endl;
        if (num_training_units < current_gym->GetNumTrainingUnitsRemaining())
                training_units_to_buy = num_training_units;
        else
            training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
    }
}
bool Pokemon::CanTrade()
{
    if (!is_in_hub) {
        cout << "You can only trade in the Trading Hub!" << endl;
        return false;
    }
    else if (current_hub->GetTradeCost() > pokemon_dollars) {
        cout << "You don't have enough Pokemon dollars to complete this trade." << endl;
        return false;
    }
    else return true;
}
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (state != IN_CENTER)
        cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
    else if (!current_center->HasStaminaPoints())
        cout << display_code << id_num << " Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
    else if (pokemon_dollars < current_center->getStaminaCost() * num_stamina_points)
        cout << display_code << id_num << " Not enough money to recover stamina." << endl;
    else if (stamina_points_to_buy == 1)
        cout << display_code << id_num << " Started recovering 1 stamina point at Pokemon Center " << current_center->GetId() << endl;
    else {
        state = RECOVERING_STAMINA;
        cout << display_code << id_num << " Started recovering " << num_stamina_points << " stamina points at Pokemon Center " << current_center->GetId() << endl;
        if (num_stamina_points < current_center->GetNumStaminaPointsRemaining())
            stamina_points_to_buy = num_stamina_points;
        else
            stamina_points_to_buy = current_center->GetNumStaminaPointsRemaining();
    }
}

void Pokemon::ReadyBattle(Rival *in_target)
{
        if (state != IN_ARENA)
            cout << "Battles may only take place at the arena." << endl;
        else if (current_arena->IsBeaten())
            cout << "You have already defeated all the Rivals at this arena." << endl;
        else if (!in_target->is_alive())
            cout << "This Rival has already been defeated!" << endl;
        else if (!current_arena->IsAbleToFight(pokemon_dollars, stamina)){
            state = IN_ARENA;
            cout << "This pokemon is not ready for battle yet. Collect more stamina and Pokemon dollars." << endl;
        }
        else {
            target = in_target;
            state = BATTLE;
            cout << "Battle has commenced!" << endl;
            stamina = stamina - current_arena->GetStaminaCost();
            pokemon_dollars = pokemon_dollars - current_arena->GetDollarCost();
        }
}
bool Pokemon::StartBattle()
{
    TakeHit(target->get_phys_damage(), target->get_magic_dmg(), target->get_defense());
    if (health <= 0 && target->get_health() > 0)
    {
        state = FAINTED;
        target->is_alive();
        health = 0;
        cout << "The Rival has defeated you! This pokemon has fainted." << endl;
        return false;
    }
    target->TakeHit(name, physical_damage, magical_damage, defense, attack_1, attack_2, attack_3, attack_4);
    if (health > 0 && target->get_health() <= 0)
    {
        health = store_health;
        state = IN_ARENA;
        target->is_alive();
        cout << "You defeated this Rival!" << endl;
        current_arena->RivalDefeated();
        return true;
    }
}

void Pokemon::StartTrading()
{
    state = TRADING;
}

void Pokemon::Stop()
{
    state = STOPPED;
    cout << display_code << id_num << ": Stopping." << endl;
}
bool Pokemon::IsExhausted()
{
    return stamina == 0;
}
bool Pokemon::ShouldBeVisible()
{
    return state != EXHAUSTED;
}
void Pokemon::ShowStatus()
{
    cout << name << " status: ";
    GameObject::ShowStatus();

    switch (state)
    {
        case STOPPED:
            cout << "stopped" << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case MOVING:
            cout << "moving at a speed of " << speed << " to destination (" << destination << ") at each step of "  << delta << "." << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_CENTER:
            cout << "heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << "." << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_GYM:
            cout << "heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << "." << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_ARENA:
            cout << "heading to Battle Arena " << current_arena->GetId() << " at a speed of " << speed << " at each step of " << delta << "." << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_HUB:
            cout << "heading to Trading Hub " << current_hub->GetId() << " at a speed of " << speed << " at each step of " << delta << "." << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case IN_CENTER:
            cout << "inside Pokemon Center " << current_center->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case IN_GYM:
            cout << "inside Pokemon Gym " << current_gym->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case IN_ARENA:
            cout << "inside Battle Arena " << current_arena->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case IN_HUB:
            cout << "inside Trading Hub" << current_hub->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case TRAINING_IN_GYM:
            cout << "training in Pokemon Gym " << current_gym->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case RECOVERING_STAMINA:
            cout << "recovering stamina in Pokemon Center " << current_center->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case BATTLE:
            cout << "battling " << target->get_name() << " at Arena " << current_arena->GetId() << endl;
            cout << "   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case EXHAUSTED:
            cout << "\n   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
        case FAINTED:
            cout << "\n   Health: " << health << endl;
            cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
            cout << "   Defense: " << defense << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl;
            break;
    }
}
bool Pokemon::Update()
{
    bool HasArrived = false;
    bool HasArrivedAtCenter = false;
    bool HasArrivedAtGym = false;
    bool HasArrivedAtArena = false;
    bool HasArrivedAtHub = false;
    switch (state) {
        case STOPPED:
            return false;
        case MOVING:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            if (is_in_gym) {
                current_gym->RemoveOnePokemon();
            is_in_gym = false;
            }
            if (is_in_arena) {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }

            if (is_in_hub) {
                current_hub->RemoveOnePokemon();
                is_in_hub = false;
            }

            HasArrived = UpdateLocation();
            if (HasArrived)
            {
                state = STOPPED;
                is_in_gym = false;
                is_in_center = false;
                is_in_arena = false;
                is_in_hub = false;
                return true;
            }
            else {
                return false;
            }
        case MOVING_TO_CENTER:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            if (is_in_arena) {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (is_in_hub) {
                current_hub->RemoveOnePokemon();
                is_in_hub = false;
            }


            HasArrivedAtCenter = UpdateLocation();
            if (HasArrivedAtCenter)
            {
            state = IN_CENTER;
            current_center->AddOnePokemon();
            is_in_center = true;
            return true;
            } else {
            return false;
            }
        case MOVING_TO_GYM:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            if (is_in_arena) {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (is_in_hub) {
                current_hub->RemoveOnePokemon();
                is_in_hub = false;
            }

            HasArrivedAtGym = UpdateLocation();
            if (HasArrivedAtGym)
            {
            state = IN_GYM;
            current_gym->AddOnePokemon();
            is_in_gym = true;
            return true;
            } else {
            return false;
            }
        case MOVING_TO_ARENA:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            if (is_in_arena) {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (is_in_hub) {
                current_hub->RemoveOnePokemon();
                is_in_hub = false;
            }

            HasArrivedAtArena = UpdateLocation();
            if (HasArrivedAtArena)
            {
                state = IN_ARENA;
                current_arena->AddOnePokemon();
                is_in_arena = true;
                return true;
            } else {
                return false;
            }
        case MOVING_TO_HUB:
            if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            if (is_in_arena) {
                current_arena->RemoveOnePokemon();
                is_in_arena = false;
            }
            if (is_in_hub) {
                current_hub->RemoveOnePokemon();
                is_in_hub = false;
            }

            HasArrivedAtHub = UpdateLocation();
            if (HasArrivedAtHub)
            {
                state = IN_HUB;
                current_hub->AddOnePokemon();
                is_in_hub = true;
                return true;
            } else {
                return false;
            }
        case IN_CENTER:
            return false;
        case IN_GYM:
            return false;
        case IN_ARENA:
            return false;
        case TRAINING_IN_GYM:
            if (current_gym->IsAbleToTrain(training_units_to_buy, pokemon_dollars, stamina))
            {
                stamina = stamina - current_gym->GetStaminaCost(training_units_to_buy);
                pokemon_dollars = pokemon_dollars - current_gym->GetDollarCost(training_units_to_buy);
                unsigned int old_exp = experience_points;
                experience_points = experience_points + current_gym->TrainPokemon(training_units_to_buy);
                unsigned int new_exp = experience_points;
                LevelUp(new_exp, old_exp);
                if (training_units_to_buy == 1)
                    cout << "** " << name << " completed 1 training unit!" << endl;
                else
                    cout << "** " << name << " completed " << training_units_to_buy << " training units!" << endl;
                if (experience_points == 1)
                    cout << "** " << name << " gained 1 experience point!" << endl;
                else
                    cout << "** " << name << " gained " << experience_points << " experience points!" << endl;
            } else
                cout << "Unable to train" << endl;
            state = IN_GYM;
            return true;
        case RECOVERING_STAMINA:
            if (current_center->CanAffordStaminaPoints(stamina_points_to_buy, pokemon_dollars)) {
                stamina = stamina + current_center->DistributeStamina(stamina_points_to_buy);
                pokemon_dollars = pokemon_dollars - current_center->GetDollarCost(stamina_points_to_buy);
                if (stamina_points_to_buy == 1)
                    cout << "** " << name << " recovered 1 stamina point!" << endl;
                else
                    cout << "** " << name << " recovered " << stamina_points_to_buy << " stamina points!" << endl;
            }
            else
                cout << "Not enough Pokemon dollars to recover stamina." << endl;
            state = IN_CENTER;
            return true;
        case BATTLE:
            StartBattle();
            break;
        case FAINTED:
            return false;
    }
}
bool Pokemon::UpdateLocation()
{
    Vector2D DestMinusLoc = destination - location;
    if (fabs(DestMinusLoc.x) <= fabs(delta.x) && fabs(DestMinusLoc.y) <= fabs(delta.y)) //within one step of destination
    {
        if (!IsExhausted()) {
            location = destination;
            cout << "You've arrived." << endl;
            state = STOPPED;
            pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
            stamina = stamina - 1;
            return true;
        } else {
            location = destination;
            cout << "You've arrived." << endl;
            state = EXHAUSTED;
            cout << name << " is exhausted" << endl;
            pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
            return true;
        }
    }
    else {
        if (!IsExhausted()) {
            location = location + delta;
            cout << "You've moved" << endl;
            pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
            stamina = stamina - 1;
            return false;
        } else {
            cout << name << " is exhausted" << endl;
            state = EXHAUSTED;
            return false;
        }
    }
}
void Pokemon::SetupDestination(Point2D dest)
{
    destination = dest;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
}

bool Pokemon::IsAlive()
{
    return state != FAINTED;
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
{
    double damage;
    string MoveTypes[] =
            {
                    "Pursuit",
                    "Payback",
                    "Extreme Speed",
                    "Retaliate",
                    "Crunch",
                    "Hyper Beam",
                    "Slash",
                    "Slam"
            };
    double DamageMultipliers[] =
            {
                    0.8,
                    0.85,
                    1.15,
                    0.9,
                    0.95,
                    1.25,
                    0.7,
                    0.75,

            };
    int chosen_move = rand() % 7;
    string move_name = MoveTypes[chosen_move];
    int damage_type = rand() % 2;
    if (damage_type == 0) {
        damage = (100.0 - defense) / 100 * physical_damage;
        damage = damage * DamageMultipliers[chosen_move];
        health = health - damage;
        cout << target->get_name() << " used " << move_name << "! You took " << damage << " physical damage." << endl;
    }
    else if (damage_type == 1) {
        damage = (100.0 - defense) / 100 * magical_damage;
        damage = damage * DamageMultipliers[chosen_move];
        health = health - damage;
        cout << target->get_name() << " used " << move_name << "! You took " << damage << " magic damage." << endl;
    }
}

double GetRandomAmountOfPokemonDollars()
{
    double amount;

    amount = rand() % 200;
    amount = amount / 100;

    return amount;
}

Pokemon::~Pokemon()
{
    cout << "Pokemon destructed" << endl;
}

string Pokemon::GetName()
{
    return name;
}


//Extra Credit

void Pokemon::LevelUp(unsigned int new_exp, unsigned int old_exp)
{


    if (new_exp >= 5 && old_exp <= 4) {
        magical_damage = magical_damage + 1;
        physical_damage = physical_damage + 1;
        cout << name << " has reached Level 2! " << endl;
    }
    if (new_exp >= 10 && old_exp <= 9) {
        magical_damage = magical_damage + 1;
        physical_damage = physical_damage + 1;
        cout << name << " has reached Level 3! " << endl;
    }
    if (new_exp >= 15  && old_exp <= 14) {
        magical_damage = magical_damage + 1;
        physical_damage = physical_damage + 1;
        cout << name << " has reached Level 4! " << endl;
    }
    if (new_exp >= 20 && old_exp <= 19) {
        magical_damage = magical_damage + 2;
        physical_damage = physical_damage + 2;
        cout << name << " has reached Level 5! " << endl;
    }
    if (new_exp >= 25  && old_exp <= 24) {
        magical_damage = magical_damage + 2;
        physical_damage = physical_damage + 2;
        cout << name << " has reached Level 6! " << endl;
    }
    if (new_exp >= 30 && old_exp <= 29) {
        magical_damage = magical_damage + 2;
        physical_damage = physical_damage + 2;
        cout << name << " has reached Level 7! " << endl;
    }
    if (new_exp >= 35 && old_exp <= 34) {
        magical_damage = magical_damage + 3;
        physical_damage = physical_damage + 3;
        cout << name << " has reached Level 8! " << endl;
    }
    if (new_exp >= 40 && old_exp <= 39) {
        magical_damage = magical_damage + 3;
        physical_damage = physical_damage + 3;
        cout << name << " has reached Level 9! " << endl;
    }
    if (new_exp >= 45 && old_exp <= 44) {
        magical_damage = magical_damage + 3;
        physical_damage = physical_damage + 3;
        cout << name << " has reached Level 10! That is the maximum level. Congratulations!" << endl;
    }
}
