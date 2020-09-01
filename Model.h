//
// Created by justi on 11/19/2019.
//

#ifndef PA3_MODEL_H
#define PA3_MODEL_H


#include "GameObject.h"
#include "Pokemon.h"
#include "View.h"
#include "TradingHub.h"
#include "RivalAI.h"
#include <list>
#include <iterator>

class Model {
private:
    Point2D pt1, pt2, pt3, pt4, pt5, pt6, pt7, pt8;
    int time;
    list <GameObject *> object_ptrs;
    list <GameObject *> active_ptrs;
    list <Pokemon *> pokemon_ptrs;
    list <PokemonCenter *> center_ptrs;
    list <PokemonGym *> gym_ptrs;
    list <Rival *> rival_ptrs;
    list <BattleArena *> arena_ptrs;
    list <TradingHub *> hub_ptrs;
    list <Pokemon *> trade_ptrs;
    list <GameObject *> trade_ptrs2;
    list <RivalAI *> rivalAI_ptrs;
    Pokemon * pokemon1;
    Pokemon * pokemon2;
    Pokemon * pokemon3;
    Pokemon * pokemon4;
    Pokemon * pokemon5;
    Pokemon * pokemon6;
    PokemonCenter * center1;
    PokemonCenter * center2;
    PokemonGym * gym1;
    PokemonGym * gym2;
    Rival * rival1;
    Rival * rival2;
    Rival * rival3;
    RivalAI * AI1;
    BattleArena * arena1;
    TradingHub * hub1;

public:
    Model();
    ~Model();
    Pokemon * GetPokemonPtr(int id);
    PokemonCenter * GetPokemonCenterPtr(int id);
    PokemonGym * GetPokemonGymPtr(int id);
    TradingHub * GetTradingHubPtr(int id);
    Rival * GetRivalPtr(int id);
    BattleArena * GetBattleArenaPtr(int id);
    RivalAI * GetRivalAIPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    void CreateNewObject(char Type, int ID, int x_coord, int y_coord);
    void SwapPokemon(int random, int id_num);
};


#endif //PA3_MODEL_H
