#pragma once
#include "Object.h"
#define �� 0.95f     //  ���C��


class Player : public Object
{
public:
  
  //def_pos         �X�^�[�g�ʒu
  //size �@�@       �T�C�Y
  //e               �����W��
  //power_limit     �З͐���
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

  //  �͈͎w��    
  void RangeSpecification();

  Vec2f def_pos;           //  �����ʒu
  Vec2f pos;               //  �ʒu
  Vec2f size;              //  �T�C�Y
  Vec2f move;              //  �����x
  float e;                 //  �����W��
  float power_limit;       //  �З͂̏��
  bool gravity;            //  �d�̓t���O
  bool throw_active;       //  �܂񂾂��ǂ���
  Vec2f mouse_pos;
  float throw_angle;
  Vec2f throw_power;
  float g;
};