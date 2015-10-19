#include "GWall.h"


void Wall::Draw()
{
  if (type == WallType::BOX)
  {
    //  大きさをそろえ調節するため
    int num = static_cast <int> (size.x()) / 128;
    int am = static_cast <int> (size.x()) % 128;
    int num_y = static_cast <int> (size.y()) / 128;
    int am_y = static_cast <int> (size.y()) % 128;

    for (int i = 0; i < num; i++)
    {
      for (int j = 0; j < num_y; j++)
      {
        drawFillBox(pos.x() + (128 + am / num) * i,
                    pos.y() + (128 + am_y / num_y) * j,
                    128 + am / num, 128 + am_y / num_y, Color::gray);
      }
    }
  }
  else if (type == WallType::CIRCLE)
  {
    drawFillCircle(pos.x(), pos.y(), size.x(), size.y(), 20, Color::gray);
  }
  else
  {
    assert(1);
  }
}


void Wall::Update(Object& obj)
{
  if (type == WallType::BOX)
  {
    BoxWall(obj);
  }
  
  if (type == WallType::CIRCLE)
  {
    CircleWall(obj);
  }
}

void Wall::BoxWall(Object& obj)
{
  collision_corner[0] = pos;
  collision_corner[1] = Vec2f(pos.x(), pos.y() + size.y());
  collision_corner[2] = Vec2f(pos.x() + size.x(), pos.y());
  collision_corner[3] = Vec2f(pos.x() + size.x(), pos.y() + size.y());


  if ((size.x() / 2) + obj.GetSize().x()  > abs(obj.GetPos().x() - (pos.x() + size.x() / 2)) &&
      (size.y() / 2) + obj.GetSize().y() > abs(obj.GetPos().y() - (pos.y() + size.y() / 2)))
  {

    //  DEBUG:
    std::cout << "wallbef: " << obj.GetMove().y() << std::endl;
    //左側判定
    if (obj.GetPos().x() < (pos.x()) &&
        obj.GetPos().y() > pos.y() && obj.GetPos().y() < pos.y() + size.y())
    {
      obj.SetPos(Vec2f(pos.x() - obj.GetSize().x(), obj.GetPos().y()));
      obj.SetMove(Vec2f(-e*obj.GetMove().x(), obj.GetMove().y()));
    }
    else
      //右側判定
      if (obj.GetPos().x() > (pos.x() + size.x()) &&
          obj.GetPos().y() > pos.y() && obj.GetPos().y() < pos.y() + size.y())
      {
        obj.SetPos(Vec2f(pos.x() + size.x() + obj.GetSize().x(), obj.GetPos().y()));
        obj.SetMove(Vec2f(-e*obj.GetMove().x(), obj.GetMove().y()));
      }
      else
        //上側判定
        if (obj.GetPos().y() > (pos.y() + size.y()) &&
            obj.GetPos().x() > pos.x() && obj.GetPos().x() < pos.x() + size.x())
        {
          obj.SetPos(Vec2f(obj.GetPos().x(), pos.y() + size.y() + obj.GetSize().y()));
          obj.SetMove(Vec2f(μ*obj.GetMove().x(), -e*obj.GetMove().y()));
        }
        else
          //下側判定
          if (obj.GetPos().y() < (pos.y()) &&
              obj.GetPos().x() > pos.x() && obj.GetPos().x() < pos.x() + size.x())
          {
            obj.SetPos(Vec2f(obj.GetPos().x(), pos.y() - obj.GetSize().y()));
            obj.SetMove(Vec2f(obj.GetMove().x(), -e*obj.GetMove().y()));
          }
          else
          {

            //角の判定
            for (int i = 0; i < 4; i++)
            {

              if ((collision_corner[i].x() - obj.GetPos().x()) * (collision_corner[i].x() - obj.GetPos().x()) +
                  (collision_corner[i].y() - obj.GetPos().y()) * (collision_corner[i].y() - obj.GetPos().y()) <
                  obj.GetSize().x() * obj.GetSize().x())
              {

                obj.SetMove(PushBack(obj, collision_corner[i], Vec2f(1,1)));

              }
            }
          }

  }
}


void Wall::CircleWall(Object& obj)
{
  if (CircleCollision(obj.GetPos(), obj.GetSize(), pos, size))
  {
    obj.SetMove(PushBack(obj, pos, size));
  }
}



Vec2f Wall::PushBack(Object& obj, Vec2f obj2_pos, Vec2f size)
{

  float range_x = (obj.GetPos().x() -obj2_pos.x());          //  中心点の距離ｘ
  float range_y = (obj.GetPos().y() -obj2_pos.y());          //  中心点の距離ｙ
  float len = sqrt(range_x * range_x + range_y * range_y);   //  中心点の距離

  float distance = (obj.GetSize().x() + size.x()) - len;


  if (len > 0)	
   len = 1 / len;
  range_x *= len;
  range_y *= len;

  distance /= 2.0;

  //  めり込んだ分だけ戻す
  obj.SetPos(Vec2f(obj.GetPos().x() + (range_x * distance)/2,
  obj.GetPos().y() + (range_y * distance)/2));


  float put;    //  一時的に計算を入れる変数
  range_x = (obj2_pos.x() - obj.GetPos().x());
  range_y = (obj2_pos.y() - obj.GetPos().y());

  put = -(range_x * obj.GetMove().x() + range_y * obj.GetMove().y()) /
    (range_x * range_x + range_y * range_y);
  float arx = obj.GetMove().x() + range_x * put;
  float ary = obj.GetMove().y() + range_y * put;

  put = -(-range_y * obj.GetMove().x() + range_x * obj.GetMove().y()) /
    (range_y * range_y + range_x * range_x);
  float amx = obj.GetMove().x() - range_y * put;
  float amy = obj.GetMove().y() + range_x * put;

  Vec2f obj2_move;    //  固定の場合必要な返ってくる力（ベクトル）

 obj2_move.x() = -(arx + amx);
 obj2_move.y() = -(ary + amy);

  put = -(range_x *obj2_move.x() + range_y *obj2_move.y()) /
    (range_x * range_x + range_y * range_y);
  float brx =obj2_move.x() + range_x * put;
  float bry =obj2_move.y() + range_y * put;

  put = -(-range_y *obj2_move.x() + range_x *obj2_move.y()) /
    (range_y * range_y + range_x * range_x);
  float bmx =obj2_move.x() - range_y * put;
  float bmy =obj2_move.y() + range_x * put;


  float adx = (1 * amx + 1 * bmx + bmx * e * 1 - amx * e * 1) / (1 + 1);        //  衝突後のplayerベクトルの分解ｘ
  float bdx = -e * (bmx - amx) + adx;                                           //  衝突後の角ベクトルの分解x
  float ady = (1 * amy + 1 * bmy + bmy * e * 1 - amy * e * 1) / (1 + 1);        //  衝突後のplayerベクトルの分解ｙ
  float bdy = -e * (bmy - amy) + ady;                                           //  衝突後の角ベクトルの分解y


  return Vec2f(adx + arx , ady + ary);

};
