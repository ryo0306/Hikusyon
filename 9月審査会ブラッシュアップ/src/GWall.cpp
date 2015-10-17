#include "GWall.h"


void Wall::Draw()
{
  //  �傫�������낦���߂��邽��
  int num = static_cast <int> (size.x()) / 128;
  int am = static_cast <int> (size.x()) % 128;
  int num_y = static_cast <int> (size.y()) / 128;
  int am_y = static_cast <int> (size.y()) % 128;

  for (int i = 0; i < num; i++)
  {
    for (int j = 0; j <num_y; j++)
    {
      drawFillBox(pos.x() + (128 + am / num) * i,
                     pos.y() + (128 + am_y / num_y) * j,
                     128 + am / num, 128 + am_y / num_y, Color::gray);
    }
  }
}


void Wall::Update(Object& obj)
{

  collision_corner[0] = pos;
  collision_corner[1] = Vec2f(pos.x(), pos.y() + size.y());
  collision_corner[2] = Vec2f(pos.x() + size.x(), pos.y());
  collision_corner[3] = Vec2f(pos.x() + size.x(), pos.y() + size.y());


  if ((size.x() / 2) + obj.GetSize().x()  > abs(obj.GetPos().x() - (pos.x() + size.x() / 2)) &&
      (size.y() / 2) + obj.GetSize().y() > abs(obj.GetPos().y() - (pos.y() + size.y() / 2)))
  {

  //  DEBUG:
  std::cout <<"wallbef: "<< obj.GetMove().y() << std::endl;
    //��������
    if (obj.GetPos().x() < (pos.x()) &&
        obj.GetPos().y() > pos.y() && obj.GetPos().y() < pos.y() + size.y())
    {
      obj.SetPos(Vec2f(pos.x() - obj.GetSize().x(), obj.GetPos().y()));
      obj.SetMove(Vec2f(-e*obj.GetMove().x(), obj.GetMove().y()));
    }
    else
      //�E������
      if (obj.GetPos().x() > (pos.x() + size.x()) &&
          obj.GetPos().y() > pos.y() && obj.GetPos().y() < pos.y() + size.y())
      {
        obj.SetPos(Vec2f(pos.x() + size.x() + obj.GetSize().x(), obj.GetPos().y()));
        obj.SetMove(Vec2f(-e*obj.GetMove().x(), obj.GetMove().y()));
      }
      else
        //�㑤����
        if (obj.GetPos().y() > (pos.y() + size.y()) &&
            obj.GetPos().x() > pos.x() && obj.GetPos().x() < pos.x() + size.x())
        {
          obj.SetPos(Vec2f(obj.GetPos().x(), pos.y() + size.y() + obj.GetSize().y()));
          obj.SetMove(Vec2f(��*obj.GetMove().x(), -e*obj.GetMove().y()));
        }
        else
          //��������
          if (obj.GetPos().y() < (pos.y()) &&
              obj.GetPos().x() > pos.x() && obj.GetPos().x() < pos.x() + size.x())
          {
            obj.SetPos(Vec2f(obj.GetPos().x(), pos.y() - obj.GetSize().y()));
            obj.SetMove(Vec2f(obj.GetMove().x(), -e*obj.GetMove().y()));
          }
          else
          {

            //�p�̔���
            for (int i = 0; i < 4; i++)
            {

              if ((collision_corner[i].x() - obj.GetPos().x()) * (collision_corner[i].x() - obj.GetPos().x()) +
                  (collision_corner[i].y() - obj.GetPos().y()) * (collision_corner[i].y() - obj.GetPos().y()) <
                  obj.GetSize().x() * obj.GetSize().x())
              {

                obj.SetMove(CollisionCorner(obj, collision_corner[i]));

              }
            }
          }
                //  DEBUG:
                std::cout << " wallaft: " << obj.GetMove().y() << std::endl;
  }
}


Vec2f Wall::CollisionCorner(Object& obj, Vec2f collision_pos)
{

  float range_x = (obj.GetPos().x() - collision_pos.x());      //  ���S�_�̋�����
  float range_y = (obj.GetPos().y() - collision_pos.y());      //  ���S�_�̋�����
  float len = sqrt(range_x * range_x + range_y * range_y);            //  ���S�_�̋���

  float distance = obj.GetSize().x() - len;                    //  

  float SIN = abs(collision_pos.y() - obj.GetPos().y()) / len; //  ���S�_�̋���sin
  float COS = abs(collision_pos.x() - obj.GetPos().x()) / len; //  ���S�_�̋���cos

  Vec2f collision_move;    //  �Œ�̏ꍇ�K�v�ȕԂ��Ă���́i�x�N�g���j
  collision_move.x() = -obj.GetMove().x() * COS + -obj.GetMove().y() * SIN;
  collision_move.y() = -obj.GetMove().x() * SIN + -obj.GetMove().y() * COS;


  if (len > 0)	len = 1 / len;
  range_x *= len;
  range_y *= len;

  distance /= 2.0;

  //  �߂荞�񂾕������߂�
  obj.SetPos(Vec2f(obj.GetPos().x() + range_x * distance,
    obj.GetPos().y() + range_y * distance));


  float put;    //  �ꎞ�I�Ɍv�Z������ϐ�

  put = -(range_x * obj.GetMove().x() + range_y * obj.GetMove().y()) /
    (range_x * range_x + range_y * range_y);
  float arx = obj.GetMove().x() + range_x * put;
  float ary = obj.GetMove().y() + range_y * put;

  put = -(-range_y * obj.GetMove().x() + range_x * obj.GetMove().y()) /
    (range_y * range_y + range_x * range_x);
  float amx = obj.GetMove().x() - range_y * put;
  float amy = obj.GetMove().y() + range_x * put;

  put = -(range_x * collision_move.x() + range_y * collision_move.y()) /
    (range_x * range_x + range_y * range_y);
  float brx = collision_move.x() + range_x * put;
  float bry = collision_move.y() + range_y * put;

  put = -(-range_y * collision_move.x() + range_x * collision_move.y()) /
    (range_y * range_y + range_x * range_x);
  float bmx = collision_move.x() - range_y * put;
  float bmy = collision_move.y() + range_x * put;


  float adx = (1 * amx + 1 * bmx + bmx * e * 1 - amx * e * 1) / (1 + 1);   //  �Փˌ��player�x�N�g���̕�����
  float bdx = -e * (bmx - amx) + adx;                                           //  �Փˌ�̊p�x�N�g���̕���x
  float ady = (1 * amy + 1 * bmy + bmy * e * 1 - amy * e * 1) / (1 + 1);   //  �Փˌ��player�x�N�g���̕�����
  float bdy = -e * (bmy - amy) + ady;                                           //  �Փˌ�̊p�x�N�g���̕���y


  return Vec2f(adx + arx, ady + ary);

};
