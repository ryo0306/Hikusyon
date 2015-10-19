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
  Wall(WallType type_, Vec2f pos_, Vec2f size_, float e_)
  {
    type = type_;
    pos = pos_;
    size = size_;
    e = e_;
  }
  void Update(Object& obj);
  void Draw();
  Vec2f PushBack(Object& obj, Vec2f obj2_pos, Vec2f size);  //円同士の押し戻す処理＆移動量の変化
  void BoxWall(Object& obj);
  void CircleWall(Object& obj);
private:

  float e;
  Vec2f collision_corner[4];
  WallType type;
};