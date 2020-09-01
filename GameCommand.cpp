//
// Created by justi on 11/19/2019.
//

#include "GameCommand.h"
#include "Model.h"
#include "TradingHub.h"
#include <iostream>
#include <cstdlib>
#include "Input_Handling.h"

using namespace std;



void GameCommand::DoMoveCommand(Model &model, int pokemon_id, Point2D p1) {
    if (model.GetPokemonPtr(pokemon_id) != 0)
    {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Moving " << CurrentPokemon->GetName() << " to " << p1 << "." << endl;
        CurrentPokemon->StartMoving(p1);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoMoveToCenterCommand(Model &model, int pokemon_id, int center_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0)
    {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonCenter *CurrentCenter = model.GetPokemonCenterPtr(center_id);
        cout << "Moving " << CurrentPokemon->GetName() << " to " << CurrentCenter->GetId() << "." << endl;
        CurrentPokemon->StartMovingToCenter(CurrentCenter);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoMoveToGymCommand(Model &model, int pokemon_id, int gym_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonGym *CurrentGym = model.GetPokemonGymPtr(gym_id);
        cout << "Moving " << CurrentPokemon->GetName() << " to " << CurrentGym->GetId() << endl;
        CurrentPokemon->StartMovingToGym(CurrentGym);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetBattleArenaPtr(arena_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        BattleArena *CurrentArena = model.GetBattleArenaPtr(arena_id);
        cout << "Moving " << CurrentPokemon->GetName() << " to " << CurrentArena->GetId() << endl;
        CurrentPokemon->StartMovingToArena(CurrentArena);
    }
    else
        cout << "Invalid ID" << endl;
}
void GameCommand::DoMoveToHubCommand(Model &model, int pokemon_id, int hub_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetTradingHubPtr(hub_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        TradingHub *CurrentHub = model.GetTradingHubPtr(hub_id);
        cout << "Moving " << CurrentPokemon->GetName() << " to " << CurrentHub->GetId() << endl;
        CurrentPokemon->StartMovingToHub(CurrentHub);
    }
}

void GameCommand::DoStopCommand(Model &model, int pokemon_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Stopping " << CurrentPokemon->GetName() << "." << endl;
        CurrentPokemon->Stop();
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoTrainInGymCommand(Model &model, int pokemon_id, unsigned int training_units) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Training " << CurrentPokemon->GetName() << "." << endl;
        CurrentPokemon->StartTraining(training_units);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoRecoverInCenterCommand(Model &model, int pokemon_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Recovering " << CurrentPokemon->GetName() << "'s stamina" << endl;
        CurrentPokemon->StartRecoveringStamina(stamina_points);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoBattleCommand(Model &model, int pokemon_id, int rival_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetRivalPtr(rival_id)) {
        Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
        Rival *CurrentRival = model.GetRivalPtr(rival_id);
        CurrentPokemon->ReadyBattle(CurrentRival);
    }
    else
        cout << "Invalid ID" << endl;
}

void GameCommand::DoGoCommand(Model &model, View &view) {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void GameCommand::DoRunCommand(Model &model, View &view) {
    cout << "Advancing to next event" << endl;
    for (int i = 0; i < 5; i++) {
        if (!model.Update())
            model.Update();
    }
    model.ShowStatus();
    model.Display(view);
}

void GameCommand::CreateNewObjectCommand(Model &model, char Type, int ID, int x_coord, int y_coord) {
    model.CreateNewObject(Type, ID, x_coord, y_coord);
}



void GameCommand::DoTradeCommand(Model &model, int pokemon_id) {
    char input = ' ';
    int random = rand() % 4;
    Pokemon *CurrentPokemon = model.GetPokemonPtr(pokemon_id);
//    if (CurrentPokemon->CanTrade()) {
        cout << "Would you like to trade your pokemon for a new random one? 'y' or 'n'" << endl;
        cin >> input;
        if (input == 'n') {
            cout << "You cancelled this trade!" << endl;
        } else if (input == 'y') {
            model.SwapPokemon(random, pokemon_id);
            cout << "Trade successful! Advance time by one step to check out your new pokemon!" << endl;
        }
    }
//}
