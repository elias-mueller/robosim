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

  void translate(const Ogre::Vector3 &v) override {}
  void scale(const Ogre::Vector3 &v) override {}
  [[nodiscard]] const Ogre::Quaternion &get_orientation() const override
  {
    return ogre_node->getOrientation();
  }
  void set_orientation(const Ogre::Quaternion &orientation) override {}

private:
  Ogre::SceneNode *ogre_node;
  Ogre::Real time_passed = 0.0;

  void sine_float();
};

}
