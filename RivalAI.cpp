//
// Created by justi on 12/11/2019.
//

#include "RivalAI.h"
#include <cmath>

RivalAI::RivalAI()
{
    cout << "RivalAI default constructed." << endl;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
    stamina = 50;
    health = 20;
    defense = 15;
    store_health = health;
    physical_damage = 5;
    magical_damage = 4;
    pokemon_dollars = 50;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    current_arena = 0;
    target = 0;
}

RivalAI::RivalAI(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc, Move in_attack_1, Move in_attack_2, Move in_attack_3, Move in_attack_4)
{
    speed = in_speed;
    name = in_name;
    location = in_loc;
    id_num = in_id;
    display_code = in_code;
    cout << "RivalAI Constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    is_in_arena = false;
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

RivalAI::~RivalAI()
{
    cout << "RivalAI destructed" << endl;
}

char RivalAI::AI_Controller()
{
    int random = rand() % 2;
    if (pokemon_dollars <= 10)
        return 'm';
    else if (stamina <= 10) {
        if (state == IN_CENTER)
            return 'r';
        else
            return 'c';
    }
    else if (random == 0) {
        if (state == IN_GYM)
            return 't';
        else
            return 'g';
    }
    else if (random == 1) {
        return 'm';
    }
}

int RivalAI::stamina_amount_finder()
{
    int random = (rand() % 3) + 2;
    return (pokemon_dollars / random);
}
int RivalAI::training_unit_amount_finder()
{
    int random = (rand() % 3) + 2;
    return (stamina / random);
}