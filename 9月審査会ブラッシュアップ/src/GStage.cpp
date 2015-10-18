#include "GStage.h"


void Stage::Draw()
{
  //  ”wŒi•`ŽÊ
  drawFillBox(-Window::WIDTH / 2, -Window::HEIGHT / 2,
              Window::WIDTH, Window::HEIGHT,
              Color::white);

  // ƒS[ƒ‹•`ŽÊ
  drawFillBox(goal.pos.x() - goal.size.x(),
                 goal.pos.y() - goal.size.y(),
                 goal.size.x() * 2, goal.size.y() * 2,
                 Color::yellow);
}


void Stage::Update(Object& obj)
{
  Ground(obj);
  Goal(obj);
}

void Stage::Ground(Object& obj)
{
  if (obj.GetPos().x() > Window::WIDTH / 2 + obj.GetSize().x())
  {
    obj.SetPos(Vec2f(Window::WIDTH / 2 + obj.GetSize().x(), obj.GetPos().y()));
    obj.SetMove(Vec2f(-ground.e* obj.GetMove().x(), obj.GetMove().y()));
  }

  if (obj.GetPos().x() < -Window::WIDTH / 2 - obj.GetSize().x())
  {
    obj.SetPos(Vec2f(-Window::WIDTH / 2 - obj.GetSize().x(), obj.GetPos().y()));
    obj.SetMove(Vec2f(-ground.e* obj.GetMove().x(), obj.GetMove().y()));
  }

  if (obj.GetPos().y() <= -Window::HEIGHT / 2 + obj.GetSize().y())
  {
    obj.SetPos(Vec2f(obj.GetPos().x(), -Window::HEIGHT / 2 + obj.GetSize().y()));
    obj.SetMove(Vec2f(ƒÊ* obj.GetMove().x(), -ground.e*obj.GetMove().y()));
  }
}

void Stage::Goal(Object& obj)
{
  
  if (CircleCollision(obj.GetPos(), obj.GetSize(), goal.pos, goal.size))
  {
    goal.is_goal = true;
  }
  else
  {
    goal.is_goal = false;
  }
}
