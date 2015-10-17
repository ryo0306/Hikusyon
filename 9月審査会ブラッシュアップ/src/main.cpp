#include "Player.h"
#include "GWall.h"
#include "Gravity.h"

int main() {

  env;

  Player player(Vec2f(0.0f,0.0f),Vec2f(100,100),0.8f,300.0f);
  Wall wall(Vec2f(-1000, -100), Vec2f(2000, 200), 0.8f);

  while (env.isOpen()) {
  
    env.begin();

    //TODO: 試し
    
  /*  if (player.GravityActiveCheck())
    {
      player.SetMove(Gravity(player.GetMove()));
    }*/
    wall.Update(player);
    player.Update();
    
    player.Draw();
    wall.Draw();

    env.end();
  }
}
