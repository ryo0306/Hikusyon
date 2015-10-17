#include "Collision.h"

bool BoxCollision(Vec2f pos1_, Vec2f size1_, Vec2f pos2_, Vec2f size2_)
{
  return abs(pos1_.x() + size1_.x() / 2 - pos2_.x() + size2_.x() / 2) < size1_.x() / 2 + size2_.x() / 2 &&
    abs(pos1_.y() + size1_.y() / 2 - pos2_.y() + size2_.y() / 2) < size1_.y() / 2 + size2_.x() / 2;
}

bool CircleCollision(Vec2f pos1_, Vec2f size1_, Vec2f pos2_, Vec2f size2_)
{
  return (pos1_.x() - pos2_.x())*(pos1_.x() - pos2_.x()) +
    (pos1_.y() - pos2_.y())*(pos1_.y() - pos2_.y())
    < (size1_.x() + size2_.x()) * (size1_.y() + size2_.y());
}