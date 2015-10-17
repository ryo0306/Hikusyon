#include "Gravity.h"

Vec2f GravityCalculation(Vec2f move)
{
  return Vec2f(move.x(), move.y() - GR);
}