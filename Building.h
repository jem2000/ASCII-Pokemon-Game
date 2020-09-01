//
// Created by justi on 11/6/2019.
//

#ifndef PA3_BUILDING_H
#define PA3_BUILDING_H


#include "Point2D.h"
#include "GameObject.h"

class Building: public GameObject
{
private:
    unsigned int pokemon_count;
public:
    Building();
    Building(char in_code, int in_Id, Point2D in_loc);
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
};


#endif //PA3_BUILDING_H
