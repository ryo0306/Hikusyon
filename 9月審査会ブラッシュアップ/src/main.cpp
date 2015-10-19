#include "Player.h"
#include "GWall.h"
#include "Gravity.h"
#include "GStage.h"


int main() {

  env;

  Player player(Vec2f(0.0f,0.0f),Vec2f(100,100),0.8f,300.0f);
  Wall wall(WallType::CIRCLE,Vec2f(-500, -100), Vec2f(200, 200), 0.8f);
  Stage stage(Vec2f(200, 500), Vec2f(100, 100));

  while (env.isOpen()) {
  
    env.begin();


    stage.Update(player);
    wall.Update(player);
    player.Update();

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
