#pragma once
#include "Gimmick.h"

//  MIGHT:移動できる壁を用意

enum WallType
{
  BOX,
  CIRCLE,
};


//  キーによって
//  どの壁を使うのか分ける
class Wall : public Gimmick
{
public:
  Wall(Vec2f pos_, Vec2f size_, float e_)
  {
    pos = pos_;
    size = size_;
    e = e_;
  }
  void Update(Object& obj);
  void Draw();
  Vec2f CollisionCorner(Object& obj, Vec2f collision_pos);

private:

  float e;
  Vec2f collision_corner[4];
};