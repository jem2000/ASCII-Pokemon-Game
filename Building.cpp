//
// Created by justi on 11/6/2019.
//
#include <iostream>
#include "Building.h"
#include "GameObject.h"

using namespace std;

Building::Building()
{
    display_code = 'B';
    cout << "Building default constructed" << endl;
    pokemon_count = 0;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code) {
    id_num = in_Id;
    location = in_loc;
    display_code = in_code;
    cout << "Building constructed" << endl;
    pokemon_count = 0;
}

void Building::AddOnePokemon()
{
    pokemon_count++;
}

void Building::RemoveOnePokemon()
{
    pokemon_count--;
}

void Building::ShowStatus()
{
    cout << display_code << id_num << " located at (" << location << ")" << endl;
    cout << "   " << pokemon_count << " pokemon ";
    if (pokemon_count == 1)
        cout << "is ";
    else
        cout << "are ";
    cout << "in this building" << endl;
}

bool Building::ShouldBeVisible()
{
    return true;
}