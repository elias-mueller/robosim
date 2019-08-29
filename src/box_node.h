#pragma once

#include "creatable_node.h"
#include <OgrePrerequisites.h>

namespace robosim {

class Box_node : public Creatable_node
{
public:
  explicit Box_node(Ogre::SceneManager &scn_mgr);

  void translate(const Ogre::Vector3 &v) override;
  void scale(const Ogre::Vector3 &v) override;

  [[nodiscard]] const Ogre::Quaternion &get_orientation() const override;
  void set_orientation(const Ogre::Quaternion &orientation) override;

private:
  Ogre::SceneNode *ogre_node;
};

}
