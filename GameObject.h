//
// Created by justi on 11/4/2019.
//

#ifndef PA3_GAMEOBJECT_H
#define PA3_GAMEOBJECT_H


#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

class GameObject
{
protected:
    Point2D location;
    int id_num;
    char display_code, state;
public:
    GameObject();
    explicit GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D GetLocation();
    int GetId();
    char GetState();
    void ShowStatus();
    virtual ~GameObject();
    virtual bool Update() = 0;
    virtual bool ShouldBeVisible() = 0;
    void DrawSelf(char * ptr);
};



#endif //PA3_GAMEOBJECT_H
