#pragma once

#include "Ogre.h"
#include <OgrePrerequisites.h>

namespace robosim {

class Sphere_creator : public Ogre::FrameListener
{
public:
  void create();
  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  Ogre::SceneNode *sphere_node;

  Ogre::Real time_passed{ 0 };
};

}
