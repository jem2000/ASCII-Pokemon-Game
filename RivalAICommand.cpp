//
// Created by justi on 12/11/2019.
//

#include "RivalAICommand.h"

void RivalAICommand::DoMoveCommand(Model &model, int RivalAI_id, Point2D p1) {
    if (model.GetRivalAIPtr(RivalAI_id) != 0)
    {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        cout << "Moving " << CurrentRivalAI->GetName() << " to " << p1 << "." << endl;
        CurrentRivalAI->StartMoving(p1);
    }

}

void RivalAICommand::DoMoveToCenterCommand(Model &model, int RivalAI_id, int center_id) {
    if (model.GetRivalAIPtr(RivalAI_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0)
    {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        PokemonCenter *CurrentCenter = model.GetPokemonCenterPtr(center_id);
        cout << "Moving " << CurrentRivalAI->GetName() << " to " << CurrentCenter->GetId() << "." << endl;
        CurrentRivalAI->StartMovingToCenter(CurrentCenter);
    }
}

void RivalAICommand::DoMoveToGymCommand(Model &model, int RivalAI_id, int gym_id) {
    if (model.GetRivalAIPtr(RivalAI_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        PokemonGym *CurrentGym = model.GetPokemonGymPtr(gym_id);
        cout << "Moving " << CurrentRivalAI->GetName() << " to " << CurrentGym->GetId() << endl;
        CurrentRivalAI->StartMovingToGym(CurrentGym);
    }
}

void RivalAICommand::DoMoveToArenaCommand(Model &model, int RivalAI_id, int arena_id) {
    if (model.GetPokemonPtr(RivalAI_id) != 0 && model.GetBattleArenaPtr(RivalAI_id) != 0) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        BattleArena *CurrentArena = model.GetBattleArenaPtr(arena_id);
        cout << "Moving " << CurrentRivalAI->GetName() << " to " << CurrentArena->GetId() << endl;
        CurrentRivalAI->StartMovingToArena(CurrentArena);
    }
    else
        cout << "Invalid ID" << endl;
}

void RivalAICommand::DoStopCommand(Model &model, int RivalAI_id) {
    if (model.GetPokemonPtr(RivalAI_id) != 0) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        cout << "Stopping " << CurrentRivalAI->GetName() << "." << endl;
        CurrentRivalAI->Stop();
    }
}

void RivalAICommand::DoTrainInGymCommand(Model &model, int RivalAI_id, unsigned int training_units) {
    if (model.GetPokemonPtr(RivalAI_id) != 0) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        cout << "Training " << CurrentRivalAI->GetName() << "." << endl;
        CurrentRivalAI->StartTraining(training_units);
    }
}

void RivalAICommand::DoRecoverInCenterCommand(Model &model, int RivalAI_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(RivalAI_id) != 0) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        cout << "Recovering " << CurrentRivalAI->GetName() << "'s stamina" << endl;
        CurrentRivalAI->StartRecoveringStamina(stamina_points);
    }
}

void RivalAICommand::DoBattleCommand(Model &model, int RivalAI_id, int rival_id) {
    if (model.GetPokemonPtr(RivalAI_id) != 0 && model.GetRivalPtr(rival_id)) {
        RivalAI *CurrentRivalAI = model.GetRivalAIPtr(RivalAI_id);
        Rival *CurrentRival = model.GetRivalPtr(rival_id);
        CurrentRivalAI->ReadyBattle(CurrentRival);
    }
} //REWRITE