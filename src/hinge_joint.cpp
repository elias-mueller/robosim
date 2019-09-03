#include "hinge_joint.h"

#include "Ogre.h"
#include "spdlog/spdlog.h"
#include <iostream>
#include <utility>

using namespace Ogre;

namespace robosim {

const Real rotation = sqrtf(0.5);

Hinge_joint::Hinge_joint(Creatable_node &parent,
                         Creatable_node &child,
                         bool rotate)
  : parent{ parent }
  , child{ child }
  , orientation_src{ Quaternion{ 1, 0, 0, 1 } }
  , orientation_dest{ Quaternion{ -1, 0, 0, 1 } }
  , in_rotation{ rotate }

{
  Root::getSingleton().addFrameListener(this);
}

bool
Hinge_joint::frameStarted(const Ogre::FrameEvent &evt)
{
  std::cout << orientation_src << std::endl;
  std::cout << orientation_dest << std::endl;
  std::cout << rotation_progress << std::endl;
  if (in_rotation) {
    rotation_progress += rotation_factor;
    if (rotation_progress > 1) {
      rotation_progress = 0;
      std::swap(orientation_src, orientation_dest);
      orientation_dest = orientation_src.Inverse();
    } else {
      Quaternion delta = Quaternion::Slerp(
        rotation_progress, orientation_src, orientation_dest, true);
      child.set_orientation(delta);
    }
  }
  return FrameListener::frameStarted(evt);
}

}
