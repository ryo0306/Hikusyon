#pragma once
#include "Object.h"



class Player : public Object
{
public:
  
  //def_pos         �X�^�[�g�ʒu
  //size �@�@       �T�C�Y
  //e               �����W��
  //power_limit     �З͐���
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


  Vec2f def_pos;           //  �����ʒu
  float e;                 //  �����W��
  float power_limit;       //  �З͂̏��
  bool throw_active;       //  �܂񂾂��ǂ���
  bool gimmick_is_active;
  Vec2f mouse_pos;
  float throw_angle;
  Vec2f throw_power;
};