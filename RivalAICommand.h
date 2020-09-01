//
// Created by justi on 12/11/2019.
//

#ifndef PA3_RIVALAICOMMAND_H
#define PA3_RIVALAICOMMAND_H


#include "Model.h"

class RivalAICommand {
public:
    void DoMoveCommand(Model & model, int pokemon_id, Point2D p1);
    void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id);
    void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id);
    void DoMoveToArenaCommand(Model & model, int pokemon_id, int arena_id);
    void DoStopCommand(Model & model, int pokemon_id);
    void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units);
    void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points);
    void DoBattleCommand(Model& model, int pokemon_id, int rival_id);
};

#endif //PA3_RIVALAICOMMAND_H
