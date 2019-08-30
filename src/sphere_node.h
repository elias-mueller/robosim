#pragma once

#include "Ogre.h"
#include "creatable_node.h"

namespace robosim {

class Sphere_node
  : public Ogre::FrameListener
  , public Creatable_node
{
public:
  explicit Sphere_node(Ogre::SceneManager &scn_mgr);
  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  Ogre::Real time_passed = 0.0;

  void sine_float();
};

}
