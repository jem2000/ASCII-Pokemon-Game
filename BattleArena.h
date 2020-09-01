//
// Created by justi on 11/30/2019.
//

#ifndef PA3_BATTLEARENA_H
#define PA3_BATTLEARENA_H

#include "Point2D.h"
#include "Building.h"

enum BattleArenaStates {
    RIVALS_AVAILABLE = 0,
    NO_RIVALS_AVAILABLE = 20
};

class BattleArena: public Building
{
private:
    unsigned int max_num_rivals;
    unsigned int num_rivals_remaining;
    double dollar_cost_per_fight;
    unsigned int stamina_cost_per_fight;
    unsigned int pokemon_count;
public:
    BattleArena();
    BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc);
    unsigned int GetNumRivalsRemaining();
    bool HasEnoughRivals();
    double GetDollarCost();
    unsigned int GetStaminaCost();
    bool IsAbleToFight(double budget, unsigned int stamina);
    bool Update();
    bool IsBeaten();
    void ShowStatus();
    void RivalDefeated();


};


#endif //PA3_BATTLEARENA_H
