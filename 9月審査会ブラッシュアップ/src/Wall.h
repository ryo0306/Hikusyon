#pragma once
#include "ScreenMake.h"
#include "Object.h"


//  MIGHT:移動できる壁を用意

enum WallType
{
  BOX,
  CIRCLE,
};


//  キーによって
//  どの壁を使うのか分ける
class Wall : public Object
{
public:

  void Update();
  void Draw();

private:

};