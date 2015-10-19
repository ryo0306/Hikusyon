#pragma once
#include "Gimmick.h"

//  MIGHT:�ړ��ł���ǂ�p��

enum WallType
{
  BOX,
  CIRCLE,
};


//  �L�[�ɂ����
//  �ǂ̕ǂ��g���̂�������
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
  Vec2f PushBack(Object& obj, Vec2f obj2_pos, Vec2f size);  //�~���m�̉����߂��������ړ��ʂ̕ω�
  void BoxWall(Object& obj);
  void CircleWall(Object& obj);
private:

  float e;
  Vec2f collision_corner[4];
  WallType type;
};