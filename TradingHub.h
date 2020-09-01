//
// Created by justi on 12/10/2019.
//

#ifndef PA3_TRADINGHUB_H
#define PA3_TRADINGHUB_H
#include <list>

#include "Building.h"

enum TradingHubStates {
    POKEMON_AVAILABLE = 0,
    NO_POKEMON_AVAILABLE = 20
};

class TradingHub: public Building {
private:
    unsigned int num_pokemon_remaining;
    int trade_cost;
    int max_pokemon;
public:
    TradingHub();
    TradingHub(unsigned int max_pokemon, unsigned int trade_cost, int in_id, Point2D in_loc);
    ~TradingHub();
    int GetNumPokemonRemaining();
    bool Update();
    int GetTradeCost();
    void ShowStatus();
};


#endif //PA3_TRADINGHUB_H
