#pragma once
#include "ScreenMake.h"
#include "Object.h"


//  MIGHT:�ړ��ł���ǂ�p��

enum WallType
{
  BOX,
  CIRCLE,
};


//  �L�[�ɂ����
//  �ǂ̕ǂ��g���̂�������
class Wall : public Object
{
public:

  void Update();
  void Draw();

private:

};