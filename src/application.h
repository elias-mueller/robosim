#pragma once

#include <OgreApplicationContext.h>
#include <OgreSceneNode.h>

namespace robosim {

static const auto DEFAULT_SCENE_MANAGER_INSTANCE_NAME = "default";

class Application
  : public OgreBites::ApplicationContext
  , public OgreBites::InputListener
{
public:
  void setup() override;
  bool keyPressed(const OgreBites::KeyboardEvent &evt) override;

  static Ogre::SceneManager &get_scene_manager();

private:
  static Ogre::SceneManager *scene_manager;

  void setup_scene();
  void setup_camera() const;
  void setup_light() const;
  void create_entities();
  Ogre::SceneNode *create_entity(const std::string &mesh_name) const;
  void create_plane() const;

};

}
