#include "Player.h"

void Player::Setup()
{

}

void Player::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color::red);
}

void Player::Update()
{
  mouse_pos = env.mousePosition();

  Throw();
  RangeSpecification();
  Gravity();
  Move();

  if (env.isPushButton(Mouse::RIGHT))
  {
    Reset();
  }

}


void Player::Throw()
{

  //角度
  throw_angle = atan2(def_pos.y() - mouse_pos.y(),
                      def_pos.x() - mouse_pos.x());

  if (CircleCollision(def_pos, size,
    mouse_pos, Vec2f(1, 1)))
  {
    if (env.isPressButton(Mouse::LEFT))
    {
      throw_active = true;       //  長押し中はマウスについてくる
    }
  }

  //  マウスを押してる間ついてくる
  //  範囲外には持っていけない
  if (throw_active)
  {
    if (!CircleCollision(mouse_pos, Vec2f(1, 1),
      def_pos, Vec2f(power_limit, power_limit)))
    {
      pos.x() = def_pos.x() + power_limit * -cos(throw_angle);
      pos.y() = def_pos.y() + power_limit * -sin(throw_angle);
    }
    else
    {
      pos.x() = mouse_pos.x();
      pos.y() = mouse_pos.y();
    }

    throw_power = Vec2f(def_pos - pos);

    if (env.isPullButton(Mouse::LEFT))
    {
      move = 0.15f * throw_power;

      gravity = true;
      throw_active = false;
    }
  }


}

void Player::Gravity()
{
  if (gravity)
    move.y() -= g;
}

void Player::Move()
{
  pos += move;
}

void Player::RangeSpecification()
{
  if (pos.x() > Window::WIDTH / 2 + size.x())
  {
    pos.x() = Window::WIDTH / 2 + size.x();
    move.x() = -e*move.x();
  }

  if (pos.x() < -Window::WIDTH/2 - size.x())
  {
    pos.x() = -Window::WIDTH / 2 - size.x();
    move.x() = -e*move.x();
  }

  if (pos.y() <= -Window::HEIGHT / 2 + size.y())
  {
    pos.y() = -Window::HEIGHT / 2 + size.y();
    move.x() *= μ;
    move.y() *= -e;
  }
}

void Player::Reset()
{
  gravity = false;
  pos = def_pos;
  move = Vec2f(0, 0);
}