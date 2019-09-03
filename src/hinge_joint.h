#pragma once

#include "Ogre.h"
#include "creatable_node.h"

namespace robosim {

class Hinge_joint : public Ogre::FrameListener
{
public:
  Hinge_joint(Creatable_node &parent, Creatable_node &child, bool rotate);

  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  Creatable_node &parent;
  Creatable_node &child;

  Ogre::Quaternion orientation_src;
  Ogre::Quaternion orientation_dest;

  bool in_rotation = false;
  Real rotation_progress = 0.0;
  Real rotation_factor = 0.01;
};

}
