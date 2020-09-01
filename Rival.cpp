//
// Created by justi on 11/30/2019.
//

#include <cstdlib>
#include "Rival.h"


Rival::Rival()
{
    health = 20;
    defense = 15;
    physical_damage = 5;
    magical_damage = 4;
    stamina_cost_per_fight = 2;
    is_in_arena = false;
    current_arena = 0;
    location.x = -2; location.y = -2;
}

Rival::Rival(string in_name, double hp, double phys_dmg, double magic_dmg, double def, int in_id)
{
    name = in_name;
    id_num = in_id;
    health = hp;
    defense = def;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    stamina_cost_per_fight = 2;
    is_in_arena = false;
    current_arena = 0;
    location.x = -2; location.y = -2;
}
void Rival::TakeHit(string PokemonName, int physical_damage, int magical_damage, int defense, int attack_1, int attack_2, int attack_3, int attack_4)
{
    double damage;
    int chosenMove;
    string MoveTypes[] =
            {
                    "Psychic",
                    "Psyshock",
                    "Toxic",
                    "Light of Ruin",
                    "Spirit Shackle",
                    "Leaf Blade",
                    "Giga Drain",
                    "Brave Bird",
                    "Blizzard",
                    "Ice Beam",
                    "Power Gem",
                    "Heavy SLam",
                    "Air Slash",
                    "Water Shuriken",
                    "Hydro Pump",
                    "Dark Pulse",
                    "Flamethrower",
                    "Fire Blast",
                    "Overheat"
            };
    double DamageMultipliers[] =
            {
                    0.9,
                    0.8,
                    1.1,
                    1.0,
                    1.2,
                    1.15,
                    0.95,
                    0.85,
                    0.98,
                    1.2,
                    1.17,
                    1.07,
                    0.88,
                    0.86,
                    1.3,
                    0.94,
                    1.1,
                    1.05,
                    1.15
            };
    cout << "Choose your attack! " << attack_1 << ": " << MoveTypes[attack_1] << ", " << attack_2 << ": " << MoveTypes[attack_2] << ", " << attack_3 << ": " << MoveTypes[attack_3] << ", " << attack_4 << ": " << MoveTypes[attack_4] << endl;
    cin >> chosenMove;

    int damage_type = rand() % 2;
    if (damage_type == 0) {
        damage = (100.0 - defense) / 100 * physical_damage;
        damage = damage * DamageMultipliers[chosenMove];
        health = health - damage;
        cout << PokemonName << " used " << MoveTypes[chosenMove] << "! ";
        cout << "You attacked " << name << ". He took " << damage << " physical damage." << endl;
    }
    else if (damage_type == 1) {
        damage = (100.0 - defense) / 100 * magical_damage;
        damage = damage * DamageMultipliers[chosenMove];
        health = health - damage;
        cout << PokemonName << " used " << MoveTypes[chosenMove] << "! ";
        cout << "You attacked " << name << ". He took " << damage << " magic damage." << endl;
    }
}
bool Rival::is_alive()
{
    if (health > 0) {
        state = ALIVE_RIVAL;
        return true;
    }
    else if (health <= 0) {
        state = FAINTED_RIVAL;
        return false;
    }
}
double Rival::get_phys_damage()
{
    return physical_damage;
}
double Rival::get_magic_dmg()
{
    return magical_damage;
}
double Rival::get_defense()
{
    return defense;
}
double Rival::get_health()
{
    return health;
}
string Rival::get_name()
{
    return name;
}

bool Rival::Update()
{
    switch (state) {
        case ALIVE_RIVAL:
            return false;
        case FAINTED_RIVAL:
            return true;
    }
}
void Rival::ShowStatus()
{
    cout << name << " status: ";
    cout << display_code << id_num;
    if (is_alive())
        cout << " alive" << endl;
    else if (!is_alive())
        cout << " defeated" << endl;
    cout << "   Health: " << health << endl;
    cout << "   Attack: " << physical_damage << ", M. Attack: " << magical_damage << endl;
    cout << "   Defense: " << defense << endl;
}
bool Rival::ShouldBeVisible()
{
    return false;
}