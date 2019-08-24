#include "application.h"
#include "Ogre.h"
#include "scene_builder.h"

using namespace Ogre;

namespace robosim {

SceneManager *Application::scene_manager;
RenderWindow *Application::render_window;

void
Application::setup()
{
  ApplicationContextBase::setup();
  addInputListener(this);

  auto &shader_gen = RTShader::ShaderGenerator::getSingleton();
  shader_gen.addSceneManager(&get_scene_manager());

  render_window = getRenderWindow();

  Scene_builder::build();
}

bool
Application::keyPressed(const OgreBites::KeyboardEvent &evt)
{
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}

SceneManager &
Application::get_scene_manager()
{
  if (!scene_manager) {
    auto &root = Root::getSingleton();
    scene_manager = root.createSceneManager();
  }

  return *scene_manager;
}
Ogre::RenderWindow &
Application::get_render_window()
{
  return *render_window;
}

}
