#pragma once
#include "ScreenMake.h"
#include "Collision.h"

class Object
{
public:
  virtual void Update() = 0;
  virtual void Draw() = 0;
 
private:
 
  Vec2f pos;
  Vec2f size;
};