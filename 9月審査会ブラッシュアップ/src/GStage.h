#pragma once
#include "Gimmick.h"


class Stage : public Gimmick
{
public:

  //goal_pos     ÉSÅ[Éãà íu
  //goal_size    ÉSÅ[ÉãëÂÇ´Ç≥
  Stage(Vec2f goal_pos, Vec2f goal_size)
  {
    goal.pos = goal_pos;
    goal.size = goal_size;
  }

  void Update(Object& obj);
  void Draw();
  void Ground(Object& obj);
  void Goal(Object& obj);
  bool IsGoal(){ return goal.is_goal; }

private:

  struct GroundObj
  {
    Vec2f pos = Vec2f(-2000, -1100);
    Vec2f size = Vec2f(4000, 200);
    float e = 0.8f;
  };

  struct GoalObj
  {
    Vec2f pos = Vec2f(-600, 600);
    Vec2f size = Vec2f(100, 100);
    bool is_goal = false;
  };

  GroundObj ground;
  GoalObj goal;

};