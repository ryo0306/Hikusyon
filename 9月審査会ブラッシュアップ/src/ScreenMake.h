#pragma once
#include "lib/framework.hpp"
#define env App::get()

enum Window
{
  WIDTH = 2000,
  HEIGHT = 1000,
};

class App
{

private:
  App(){}

public:
  static AppEnv& get()
  {
    static AppEnv s_env(Window::WIDTH, Window::HEIGHT);
    
    return s_env;
  }
};

