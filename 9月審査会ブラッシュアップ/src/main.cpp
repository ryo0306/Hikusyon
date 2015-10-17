#include "Player.h"

int main() {

  env;

  Player player(Vec2f(0.0f,0.0f),Vec2f(100,100),0.8f,300.0f);

  while (env.isOpen()) {
  
    env.begin();

    player.Update();

    player.Draw();

    env.end();
  }
}
