#include "Player.h"
#include "GWall.h"
#include "Gravity.h"
#include "GStage.h"


int main() {

  env;

  Player player(Vec2f(0.0f,0.0f),Vec2f(100,100),0.8f,300.0f);
  Wall wall(Vec2f(-1000, -100), Vec2f(2000, 200), 0.8f);
  Stage stage(Vec2f(200, 200), Vec2f(100, 100));


  while (env.isOpen()) {
  
    env.begin();

    //TODO: 試し
    
  /*  if (player.GravityActiveCheck())
    {
      player.SetMove(Gravity(player.GetMove()));
    }*/
    player.Update();
    wall.Update(player);
    stage.Update(player);
    
    stage.Draw();
    wall.Draw();
    player.Draw();
    
    if (stage.IsGoal())
    {
      break;
    }

    env.end();
  }
}
