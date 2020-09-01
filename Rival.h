//
// Created by justi on 11/30/2019.
//

#ifndef PA3_RIVAL_H
#define PA3_RIVAL_H


#include "Point2D.h"
#include "GameObject.h"
#include "BattleArena.h"


using namespace std;

enum RivalStates {
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL = 20
};

enum RivalMove {
    Pursuit = 0,
    Payback = 1,
    Extreme_Speed = 2,
    Retaliate = 3,
    Crunch = 4,
    Hyper_Beam = 5,
    Slash = 6,
    Slam = 7
};


class Rival: public GameObject
{
private:
    string name;
protected:
    double health;
    double physical_damage;
    double magical_damage;
    double defense;
    double stamina_cost_per_fight;
    bool is_in_arena;
    BattleArena *current_arena;
public:
    Rival();
    Rival(string name, double hp, double phys_dmg, double magic_dmg, double def, int in_id);
    void TakeHit(string PokemonName, int physical_damage, int magical_damage, int defense, int attack_1, int attack_2, int attack_3, int attack_4);
    bool is_alive();
    double get_phys_damage();
    double get_magic_dmg();
    double get_defense();
    string get_name();
    double get_health();
    bool Update();
    void ShowStatus();
    bool ShouldBeVisible();
};

#endif //PA3_RIVAL_H
