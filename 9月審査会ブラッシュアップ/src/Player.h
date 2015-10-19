#pragma once
#include "Object.h"



class Player : public Object
{
public:
  
  //def_pos         スタート位置
  //size 　　       サイズ
  //e               反発係数
  //power_limit     威力制限
  Player(Vec2f def_pos_, Vec2f size_, float e_, float power_limit_)
  {
    def_pos = def_pos_;
    size = size_;
    e = e_;
    power_limit = power_limit_;
    pos = def_pos;
    move = Vec2f(0, 0);
    throw_active = false;
    gravity = false;
    gimmick_is_active = false;
  }
  void Setup();
  void Update();
  void Draw();
  void Reset();
  void Move();
  void Throw();
  
private:


  Vec2f def_pos;           //  初期位置
  float e;                 //  反発係数
  float power_limit;       //  威力の上限
  bool throw_active;       //  つまんだかどうか
  bool gimmick_is_active;
  Vec2f mouse_pos;
  float throw_angle;
  Vec2f throw_power;
};