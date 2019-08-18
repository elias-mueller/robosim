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
  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  void setup_scene(Ogre::SceneManager &scn_mgr);
  void setup_camera(Ogre::SceneManager &scn_mgr) const;
  void setup_light(Ogre::SceneManager &scn_mgr) const;
  void create_entities(Ogre::SceneManager &scn_mgr);
  Ogre::SceneNode *create_entity(Ogre::SceneManager &scn_mgr,
                                 const std::string &mesh_name) const;
  void create_plane(Ogre::SceneManager &scn_mgr) const;

  Ogre::SceneNode *sphere_node;
  Ogre::Real time_passed{ 0 };
  void create_sphere(Ogre::SceneManager &scn_mgr);
  void create_plane(Ogre::SceneManager &scn_mgr);
};

}
