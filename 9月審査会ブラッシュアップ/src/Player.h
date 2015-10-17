#pragma once
#include "Object.h"
#define μ 0.95f     //  摩擦力


class Player : public Object
{
public:
  
  //def_pos         スタート位置
  //size 　　       サイズ
  //e               反発係数
  //power_limit     威力制限
  Player(Vec2f def_pos_, Vec2f size_, float e_, float power_limit_)
  : def_pos(def_pos_), size(size_),e(e_), power_limit(power_limit_)
  {
    pos = def_pos;
    move = Vec2f(0, 0);
    throw_active = false;
    gravity = false;
    g = 0.8;
  }
  void Setup();
  void Update();
  void Draw();
  void Reset();
  void Move();
  void Throw();
  void Gravity();
  inline Vec2f GetPos(){ return pos;}
  inline Vec2f GetSize(){ return size;}
  
private:

  //  範囲指定    
  void RangeSpecification();

  Vec2f def_pos;           //  初期位置
  Vec2f pos;               //  位置
  Vec2f size;              //  サイズ
  Vec2f move;              //  加速度
  float e;                 //  反発係数
  float power_limit;       //  威力の上限
  bool gravity;            //  重力フラグ
  bool throw_active;       //  つまんだかどうか
  Vec2f mouse_pos;
  float throw_angle;
  Vec2f throw_power;
  float g;
};