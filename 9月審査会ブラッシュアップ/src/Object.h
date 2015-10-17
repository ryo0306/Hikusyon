#pragma once
#include "ScreenMake.h"
#include "Collision.h"
#include "Gravity.h"
#include "iostream"
#define ƒÊ 0.95f     //  –€C—Í

struct ObjectStatus
{
  Vec2f pos;
  Vec2f size;
};

class Object
{
public:
  virtual void Update() = 0;
  virtual void Draw() = 0;
  virtual void Gravity() 
  { 
    if(gravity)
      move = GravityCalculation(move); 
  }
  virtual inline Vec2f GetPos(){ return pos; }
  virtual inline Vec2f GetSize(){ return size; }
  virtual inline Vec2f GetMove(){ return move; }
  virtual inline void SetPos(Vec2f pos_){ pos = pos_; }
  virtual inline void SetMove(Vec2f move_){ move = move_; }
protected:
  Vec2f pos;
  Vec2f move;
  Vec2f size;
  bool gravity;            //  d—Íƒtƒ‰ƒO
};