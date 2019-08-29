#pragma once

#include "Ogre.h"
#include "creatable_node.h"

namespace robosim {

class Hinge_joint : public Ogre::FrameListener
{
public:
  Hinge_joint(std::shared_ptr<Creatable_node> parent,
              std::shared_ptr<Creatable_node> child,
              bool rotate);

  bool frameStarted(const Ogre::FrameEvent &evt) override;

private:
  std::shared_ptr<Creatable_node> parent;
  std::shared_ptr<Creatable_node> child;

  Ogre::Quaternion orientation_src;
  Ogre::Quaternion orientation_dest;

  bool in_rotation = false;
  Ogre::Real rotation_progress = 0.0;
  Ogre::Real rotation_factor = 0.01;
};

}
