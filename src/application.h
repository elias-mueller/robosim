#pragma once

#include <OgreApplicationContext.h>

class Application : public OgreBites::ApplicationContext,
                    public OgreBites::InputListener {
public:
  void setup() override;
  bool keyPressed(const OgreBites::KeyboardEvent &evt) override;
private:
  void setup_camera(Ogre::SceneManager &scn_mgr) const;
  void setup_light(Ogre::SceneManager &scn_mgr) const;
  void create_entities(Ogre::SceneManager &scn_mgr) const;
};
