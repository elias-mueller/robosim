#pragma once

#include <OgreApplicationContext.h>
#include <OgreSceneNode.h>

namespace robosim {

class Application
  : public OgreBites::ApplicationContext
  , public OgreBites::InputListener
{
public:
  void setup() override;
  bool keyPressed(const OgreBites::KeyboardEvent &evt) override;

  static Ogre::SceneManager &get_scene_manager();
  static Ogre::RenderWindow &get_render_window();

private:
  static Ogre::SceneManager *scene_manager;
  static Ogre::RenderWindow *render_window;
};

}
