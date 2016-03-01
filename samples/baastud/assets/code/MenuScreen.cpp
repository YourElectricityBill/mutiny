#include "MenuScreen.h"
#include "Audio.h"

#include <iostream>

using namespace mutiny::engine;

GameObject* MenuScreen::create()
{
  GameObject* mainGo = gcnew<GameObject>("MenuScreen");
  mainGo->addComponent<MenuScreen>();

  return mainGo;
}

void MenuScreen::onAwake()
{
  Audio::playMusic();
  cameraGo = gcnew<GameObject>("MainCamera");
  Camera* camera = cameraGo->addComponent<Camera>();
  titleTexture = Resources::load<Texture2d>("textures/titleLogo");
  wwwTexture = Resources::load<Texture2d>("textures/www");
}

void MenuScreen::onGui()
{
  if(Gui::button(Rect(Screen::getWidth() - 280, 350, 200, 50), "Begin Game") == true)
  {
    Audio::stopMusic();
    Application::loadLevel("game");
  }
  else if(Gui::button(Rect(Screen::getWidth() - 280, 425, 200, 50), "Audio Test") == true)
  {
    Audio::stopMusic();
    Application::loadLevel("audiotest");
  }
  else if(Gui::button(Rect(Screen::getWidth() - 110, Screen::getHeight() - 40, 100, 30), "Quit") == true)
  {
    Application::quit();
  }

  Gui::drawTexture(Rect(10, 10, titleTexture->getWidth(), titleTexture->getHeight()), titleTexture);
  Gui::drawTexture(Rect(10, Screen::getHeight() - wwwTexture->getHeight() + 80, 
    wwwTexture->getWidth(), wwwTexture->getHeight()), wwwTexture);
}

