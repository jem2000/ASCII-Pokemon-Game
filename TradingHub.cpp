//
// Created by justi on 12/10/2019.
//

#include "TradingHub.h"
#include "GameObject.h"

using namespace std;

TradingHub::TradingHub()
{

}

TradingHub::TradingHub(unsigned int in_max_pokemon, unsigned int in_trade_cost, int in_id, Point2D in_loc)
{
    id_num = in_id;
    display_code = 'H';
    max_pokemon = in_max_pokemon;
    trade_cost = in_trade_cost;
    location = in_loc;
    num_pokemon_remaining = 4;
}
int TradingHub::GetNumPokemonRemaining()
{
    return num_pokemon_remaining;
}

bool TradingHub::Update()
{
    if (num_pokemon_remaining == 0)
    {
        state = NO_POKEMON_AVAILABLE;
        display_code = 'h';

    }
}

void TradingHub::ShowStatus()
{
    {

        cout << "Trading Hub Status: ";
        GameObject::ShowStatus();
        Building::ShowStatus();
        cout << "   Max number of Pokemon: " << max_pokemon << endl;

        if (num_pokemon_remaining == 1)
            cout << "   1 pokemon is remaining for this hub" << endl;
        else
            cout << "   " << num_pokemon_remaining << " pokemon are available for trade" << endl << endl;
    }
}

int TradingHub::GetTradeCost()
{
    return trade_cost;
}

TradingHub::~TradingHub()
{
    cout << "TradingHub destructed" << endl;
}