//
// Created by justi on 11/11/2019.
//

#ifndef PA3_POKEMON_H
#define PA3_POKEMON_H

#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Rival.h"
#include "BattleArena.h"
#include "TradingHub.h"

using namespace std;

enum PokemonStates {
    STOPPED = 0,
    MOVING = 1,
    EXHAUSTED = 20,
    IN_GYM = 3,
    IN_CENTER = 4,
    MOVING_TO_GYM = 5,
    MOVING_TO_CENTER = 6,
    TRAINING_IN_GYM = 7,
    RECOVERING_STAMINA = 8,
    IN_ARENA = 9,
    MOVING_TO_ARENA = 10,
    BATTLE = 11,
    FAINTED = 21,
    MOVING_TO_HUB = 13,
    IN_HUB,
    TRADING = 14
};

enum Move {
    Psychic = 0,
    Psyshock = 1,
    Toxic = 2,
    Light_of_Ruin = 3,
    Spirit_Shackle = 4,
    Leaf_blade = 5,
    Giga_Drain = 6,
    Brave_Bird = 7,
    Blizzard = 8,
    Ice_Beam = 9,
    Power_Gem = 10,
    Heavy_SLam = 11,
    Air_Slash = 12,
    Water_Shuriken = 13,
    Hydro_Pump = 14,
    Dark_Pulse = 15,
    Flamethrower = 16,
    Fire_Blast = 17,
    Overheat = 18,

};


class Pokemon: public GameObject
{
public:
    Pokemon();
    Pokemon(char in_code);
    Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc, Move in_attack_1, Move in_attack_2, Move in_attack_3, Move in_attack_4);
    void StartMoving(Point2D dest);
    void StartMovingToCenter(PokemonCenter* center);
    void StartMovingToGym(PokemonGym* gym);
    void StartMovingToArena(BattleArena* arena);
    void StartMovingToHub(TradingHub* hub);
    void StartTraining(unsigned int num_training_units);
    void StartRecoveringStamina(unsigned int num_stamina_points);
    void StartTrading();
    void Stop();
    bool IsExhausted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    ~Pokemon();
    string GetName();
    bool IsAlive();
    void TakeHit(double physical_damage, double magical_damage, double defense);
    void ReadyBattle(Rival *in_target);
    bool StartBattle();
    bool CanTrade();
    void LevelUp(unsigned int old_exp, unsigned int new_exp);
protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
    double health;
    double store_health;
    double physical_damage;
    double magical_damage;
    double defense;
    Rival* target;
    bool is_in_arena;
    bool is_in_hub;
    BattleArena* current_arena;
    TradingHub* current_hub;
    double speed;
    bool is_in_gym;
    bool is_in_center;
    unsigned int stamina;
    double pokemon_dollars;
    unsigned int training_units_to_buy;
    unsigned int stamina_points_to_buy;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    string name;
    Move attack_1;
    Move attack_2;
    Move attack_3;
    Move attack_4;
    unsigned int experience_points;
private:
    Point2D destination;
    Vector2D delta;

};
double GetRandomAmountOfPokemonDollars();

#endif //PA3_POKEMON_H
