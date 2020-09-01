//
// Created by justi on 12/11/2019.
//

#ifndef PA3_RIVALAI_H
#define PA3_RIVALAI_H


#include "Pokemon.h"

class RivalAI: public Pokemon
{
    public:
    RivalAI();
    RivalAI(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc, Move in_attack_1, Move in_attack_2, Move in_attack_3, Move in_attack_4);
    ~RivalAI();
    char AI_Controller();
    int stamina_amount_finder();
    int training_unit_amount_finder();
};


#endif //PA3_RIVALAI_H
