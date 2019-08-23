#pragma once

#include "Creatable_node.h"
#include "Ogre.h"

namespace robosim {

class Sphere_node
  : public Ogre::FrameListener
  , public Creatable_node
{
public:
  explicit Sphere_node(Ogre::SceneManager &scn_mgr);
  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  Ogre::SceneNode *ogre_node;
  Ogre::Real time_passed{ 0 };

  void sinus_float();
};

}
