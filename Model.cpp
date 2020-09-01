//
// Created by justi on 11/19/2019.
//

#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"
#include "TradingHub.h"
#include "RivalAI.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

Model::Model() : object_ptrs(), pokemon_ptrs(), center_ptrs(), gym_ptrs(), rival_ptrs(), arena_ptrs()
{
    time = 0;

    pt1 = Point2D(1,5);
    pokemon1 = new Pokemon("Reuniclus", 2, 20, 5, 10, 3, 1, 'P', pt1, Psychic, Psyshock, Toxic, Light_of_Ruin);
    object_ptrs.push_back(pokemon1);
    active_ptrs.push_back(pokemon1);
    pokemon_ptrs.push_back(pokemon1);

    pt2 = Point2D(10,1);
    pokemon2 = new Pokemon("Decidueye", 3, 30, 10, 5, 6, 2, 'P', pt2, Spirit_Shackle, Leaf_blade, Giga_Drain, Brave_Bird);
    object_ptrs.push_back(pokemon2);
    active_ptrs.push_back(pokemon2);
    pokemon_ptrs.push_back(pokemon2);

    pt7 = Point2D(16, 20);
    pokemon3 = new Pokemon("AlolanNinetales", 2, 24, 4, 12, 6, 3, 'P', pt7, Blizzard, Ice_Beam, Power_Gem, Psychic);
    trade_ptrs.push_back(pokemon3);
    trade_ptrs2.push_back(pokemon3);
    pokemon4 = new Pokemon("Celesteela", 1, 40, 4, 6, 10, 4, 'P', pt7, Heavy_SLam, Toxic, Air_Slash, Psychic);
    trade_ptrs.push_back(pokemon4);
    trade_ptrs2.push_back(pokemon4);
    pokemon5 = new Pokemon("Greninja", 4, 20, 10, 14, 5, 5, 'P', pt7, Water_Shuriken, Hydro_Pump, Dark_Pulse, Blizzard);
    trade_ptrs.push_back(pokemon5);
    trade_ptrs2.push_back(pokemon5);
    pokemon6 = new Pokemon("Blaziken", 3, 20, 14, 7, 7, 6, 'P', pt7, Water_Shuriken, Hydro_Pump, Dark_Pulse, Blizzard);
    trade_ptrs.push_back(pokemon6);
    trade_ptrs2.push_back(pokemon6);

    pt3 = Point2D(1,20);
    center1 = new PokemonCenter(1, 1, 100, pt3);
    object_ptrs.push_back(center1);
    active_ptrs.push_back(center1);
    center_ptrs.push_back(center1);

    pt4 = Point2D(10,20);
    center2 = new PokemonCenter(2, 2, 200, pt4);
    object_ptrs.push_back(center2);
    active_ptrs.push_back(center2);
    center_ptrs.push_back(center2);

    gym1 = new PokemonGym();
    object_ptrs.push_back(gym1);
    active_ptrs.push_back(gym1);
    gym_ptrs.push_back(gym1);

    pt5 = Point2D(5,5);
    gym2 = new PokemonGym(150, 3, 3.25, 20, 2, pt5);
    object_ptrs.push_back(gym2);
    active_ptrs.push_back((gym2));
    gym_ptrs.push_back(gym2);

    pt6 = Point2D(16,12);
    rival1 = new Rival("Gary Oak", 25, 10, 5, 4, 1);
    object_ptrs.push_back(rival1);
    active_ptrs.push_back(rival1);
    rival_ptrs.push_back(rival1);

    rival2 = new Rival("Hau", 20, 7, 8, 6, 2);
    object_ptrs.push_back(rival2);
    active_ptrs.push_back(rival2);
    rival_ptrs.push_back(rival2);

    rival3 = new Rival("Gladion", 40, 5, 5, 2, 3);
    object_ptrs.push_back(rival3);
    active_ptrs.push_back(rival3);
    rival_ptrs.push_back(rival3);

    arena1 = new BattleArena(3, 4, 5, 1, pt6);
    object_ptrs.push_back(arena1);
    active_ptrs.push_back(arena1);
    arena_ptrs.push_back(arena1);


    hub1 = new TradingHub(4, 5, 1, pt7);
    object_ptrs.push_back(hub1);
    active_ptrs.push_back(hub1);
    hub_ptrs.push_back(hub1);

    pt8 = Point2D(20, 1);
    AI1 = new RivalAI("CharizardAI", 1.5, 30, 10, 10, 10, '9', 'A', pt8, Flamethrower, Fire_Blast, Overheat, Air_Slash);
    object_ptrs.push_back(AI1);
    active_ptrs.push_back(AI1);
    rivalAI_ptrs.push_back(AI1);
    cout << "Model default constructed" << endl;

}
Model::~Model()
{
    delete pokemon1;
    delete pokemon2;
    delete center1;
    delete center2;
    delete gym1;
    delete gym2;
    delete rival1;
    delete rival2;
    delete rival3;
    delete arena1;
    delete hub1;

    cout << "Model destructed" << endl;
}

Pokemon * Model::GetPokemonPtr(int id)
{
    list <Pokemon *> :: iterator i;
    for (i = pokemon_ptrs.begin(); i != pokemon_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
PokemonCenter * Model::GetPokemonCenterPtr(int id)
{
    list <PokemonCenter *> :: iterator i;
    for (i = center_ptrs.begin(); i != center_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
PokemonGym * Model::GetPokemonGymPtr(int id)
{
    list <PokemonGym *> :: iterator i;
    for (i = gym_ptrs.begin(); i != gym_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
TradingHub * Model::GetTradingHubPtr(int id)
{
    list <TradingHub *> :: iterator i;
    for (i = hub_ptrs.begin(); i != hub_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}

Rival * Model::GetRivalPtr(int id)
{
    list <Rival *> :: iterator i;
    for (i = rival_ptrs.begin(); i != rival_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
BattleArena * Model::GetBattleArenaPtr(int id)
{
    list <BattleArena *> :: iterator i;
    for (i = arena_ptrs.begin(); i != arena_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
RivalAI * Model::GetRivalAIPtr(int id)
{
    list <RivalAI *> :: iterator i;
    for (i = rivalAI_ptrs.begin(); i != rivalAI_ptrs.end(); ++i) {
        if (id == (*i)->GetId())
            return *i;
    }
    return 0;
}
bool Model::Update() {
    time++;
    bool check = false; // return value for whole update function
    bool temp;
    list <GameObject *> :: iterator i;
    for (i = active_ptrs.begin(); i != active_ptrs.end(); ++i) {
        temp = (*i)->Update();
        if (temp) {
            check = true;
        }
    }
    bool hasWon = true;
    bool hasLost = true;
    list <PokemonGym *> :: iterator j;
    for (j = gym_ptrs.begin(); j != gym_ptrs.end(); ++j) {
        if (!(*j)->IsBeaten())
            hasWon = false;
    }
    list <Pokemon *> :: iterator k;
    for (k = pokemon_ptrs.begin(); k != pokemon_ptrs.end(); ++k) {
        if (!(*k)->IsExhausted())
            hasLost = false;
    }

    list <GameObject *> :: iterator l;
    for (l = active_ptrs.begin(); l != active_ptrs.end(); ++l)
        if ((*l)->GetState() ==  20 || (*l)->GetState() ==  21) {
            l = active_ptrs.erase(l);
            cout << "Dead object removed. " << (*l)->GetState() << endl;
        }
            if (hasWon) {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (hasLost) {
        cout << "GAME OVER: You lose! All of your Pokemon are exhausted!" << endl;
        exit(EXIT_FAILURE);
    }

    return check;
}


void Model::Display(View& view)
{
    cout << "Time: " << time << endl;
    view.clear();
    list <GameObject *> :: iterator i;
    for (i = active_ptrs.begin(); i != active_ptrs.end(); ++i)
        view.Plot(*i);
    view.Draw();
}
void Model::ShowStatus()
{
    list <Pokemon *> :: iterator i;
    for (i = pokemon_ptrs.begin(); i != pokemon_ptrs.end(); ++i)
        (*i)->ShowStatus();
    list <Rival *> :: iterator j;
    for (j = rival_ptrs.begin(); j != rival_ptrs.end(); ++j)
        (*j)->ShowStatus();
    list <RivalAI *> :: iterator o;
    for (o = rivalAI_ptrs.begin(); o != rivalAI_ptrs.end(); ++o)
        (*o)->ShowStatus();
    list <PokemonCenter *> :: iterator k;
    for (k = center_ptrs.begin(); k != center_ptrs.end(); ++k)
        (*k)->ShowStatus();
    list <PokemonGym *> :: iterator l;
    for (l = gym_ptrs.begin(); l != gym_ptrs.end(); ++l)
        (*l)->ShowStatus();
    list <BattleArena *> :: iterator m;
    for (m = arena_ptrs.begin(); m != arena_ptrs.end(); ++m)
    (*m)->ShowStatus();
    list <TradingHub *> :: iterator n;
    for (n = hub_ptrs.begin(); n != hub_ptrs.end(); ++n)
        (*n)->ShowStatus();
} //I used each separate list instead of object_ptrs in order to control the order.

void Model::CreateNewObject(char Type, int ID, int x_coord, int y_coord)
{
    Point2D pt;
    pt.x = x_coord;
    pt.y = y_coord;
    if (Type == 'p')
    {
        try {
            list <Pokemon *> :: iterator i;
            for (i = pokemon_ptrs.begin(); i != pokemon_ptrs.end(); ++i)
                if (ID == (*i)->GetId())
                    throw Invalid_Input("The ID number of the new pokemon cannot match the ID number of an already existing pokemon.");
        }
        catch(Invalid_Input& except)
        {
            cout << "ERROR: " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }
        string name;
        int speed, hp, phys, magic, def, attack_1, attack_2, attack_3, attack_4;
        Move move1, move2, move3, move4;
        cout << "What is this pokemon's name? ";
        cin >> name;
        cout << "How fast is " << name << "? ";
        cin >> speed;
        cout << "How much hp does "<< name <<" have? ";
        cin >> hp;
        cout << "How much physical damage can " << name << " deal? ";
        cin >> phys;
        cout << "How much magical damage can " << name << " deal? ";
        cin >> magic;
        cout << "What is "<< name << "'s defense? ";
        cin >> def;
        cout << "Choose " << name << "'s attacks? Pick 4. Options are 0 through 18: ";
        cin >> attack_1 >> attack_2 >> attack_3 >> attack_4;
        move1 = static_cast<Move>(attack_1);
        move2 = static_cast<Move>(attack_2);
        move3 = static_cast<Move>(attack_3);
        move4 = static_cast<Move>(attack_4);
        Pokemon * newPokemon = new Pokemon(name, speed, hp, phys, magic, def, ID, 'P', pt, move1, move2, move3, move4);
        object_ptrs.push_back(newPokemon);
        active_ptrs.push_back(newPokemon);
        pokemon_ptrs.push_back(newPokemon);
    }
    else if (Type == 'c')
    {
        try {
            list <PokemonCenter *> :: iterator i;
            for (i = center_ptrs.begin(); i != center_ptrs.end(); ++i)
                if (ID == (*i)->GetId())
                    throw Invalid_Input("The ID number of the new center cannot match the ID number of an already existing pokemon.");
        }
        catch(Invalid_Input& except)
        {
            cout << "ERROR: " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }
        unsigned  int stam_cost, max_stam;
        cout << "How many Pokemon dollars does a stamina point cost at this Pokemon Center? ";
        cin >> stam_cost;
        cout << "How many stamina points are in this Pokemon Center? ";
        cin >> max_stam;
        PokemonCenter * newCenter = new PokemonCenter(ID, stam_cost, max_stam, pt);
        object_ptrs.push_back(newCenter);
        active_ptrs.push_back(newCenter);
        center_ptrs.push_back(newCenter);
    }
    else if (Type == 'g')
    {
        try {
            list <PokemonGym *> :: iterator i;
            for (i = gym_ptrs.begin(); i != gym_ptrs.end(); ++i)
                if (ID == (*i)->GetId())
                    throw Invalid_Input("The ID number of the new gym cannot match the ID number of an already existing gym.");
        }
        catch(Invalid_Input& except)
        {
            cout << "ERROR: " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }
        unsigned int max_tUnits, stam_cost, dollar_cost, exp_per_tUnit;
        cout << "How many training units are in this gym? ";
        cin >> max_tUnits;
        cout << "What is the stamina cost per training unit in this gym? ";
        cin >> stam_cost;
        cout << "What is the dollar cost per training unit in this gym? ";
        cin >> dollar_cost;
        cout << "How many experience points will this gym give per training unit? ";
        cin >> exp_per_tUnit;
        PokemonGym * newGym = new PokemonGym(max_tUnits, stam_cost, dollar_cost, exp_per_tUnit, ID, pt);
        object_ptrs.push_back(newGym);
        active_ptrs.push_back(newGym);
        gym_ptrs.push_back(newGym);
    }
    else if (Type == 'r')
    {
        try {
            list <Rival *> :: iterator i;
            for (i = rival_ptrs.begin(); i != rival_ptrs.end(); ++i)
                if (ID == (*i)->GetId())
                    throw Invalid_Input("The ID number of the new rival cannot match the ID number of an already existing rival.");
        }
        catch(Invalid_Input& except)
        {
            cout << "ERROR: " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(100, '\n');
            return;
        }
        string name;
        double hp, phys, magic, def;
        cout << "What is this rival's name? ";
        cin >> name;
        cout << "How much hp does " << name << " have? ";
        cin >> hp;
        cout << "How much physical damage can " << name << " deal? ";
        cin >> phys;
        cout << "How much magic damage can " << name << " deal? ";
        cin >> magic;
        cout << "What is " << name << "'s defense? ";
        cin >> def;
        Rival * newRival = new Rival(name, hp, phys, magic, def, ID);
        object_ptrs.push_back(newRival);
        active_ptrs.push_back(newRival);
        rival_ptrs.push_back(newRival);
    }
}

void Model::SwapPokemon(int random, int id_num)
{
    list <Pokemon *>::iterator i = trade_ptrs.begin();
    list <GameObject *>::iterator j = trade_ptrs2.begin();
    list <GameObject *>::iterator k = object_ptrs.begin();
    list <GameObject *>::iterator l = active_ptrs.begin();
    list <Pokemon *>::iterator m = pokemon_ptrs.begin();
    if (id_num == 2)
        advance(k, 1);

    if (random == 0) {
        *k = *j;
        *l = *j;
        *m = *i;
    }
    else if (random == 1) {
        advance(i, 1);
        advance(j, 1);
        *k = *j;
        *l = *j;
        *m = *i;
    }
    else if (random == 2) {
        advance(i, 2);
        advance(j, 2);
        *k = *j;
        *l = *j;
        *m = *i;
    }
    else if (random == 3)
    {
        advance(i, 3);
        advance(j, 3);
        *k = *j;
        *l = *j;
        *m = *i;
    }
}