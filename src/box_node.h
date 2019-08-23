#pragma once

#include "Creatable_node.h"
#include <OgrePrerequisites.h>

namespace robosim {

class Box_node : public Creatable_node
{
public:
  explicit Box_node(Ogre::SceneManager &scn_mgr);

private:
  Ogre::SceneNode *ogre_node;
};

}
