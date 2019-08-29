#pragma once

#include "creatable_node.h"
#include <OgrePrerequisites.h>

namespace robosim {

class Box_node : public Creatable_node
{
public:
  explicit Box_node(Ogre::SceneManager &scn_mgr);

  void translate(const Ogre::Vector3 &v);
  void scale(const Ogre::Vector3 &v);

private:
  Ogre::SceneNode *ogre_node;
};

}
