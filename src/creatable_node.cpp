#include "creatable_node.h"
#include <iostream>

using namespace Ogre;

namespace robosim {

Creatable_node::Creatable_node(SceneManager & scn_mgr)
  : ogre_node{ scn_mgr.getRootSceneNode()->createChildSceneNode() }
{}

const Ogre::Quaternion &
Creatable_node::get_orientation() const
{
  return ogre_node->getOrientation();
}

void
Creatable_node::translate(const Ogre::Vector3 &v)
{
  ogre_node->translate(v);
}

void
Creatable_node::scale(const Ogre::Vector3 &v)
{
  ogre_node->scale(v);
}

void
Creatable_node::set_orientation(const Ogre::Quaternion &orientation)
{
  ogre_node->setOrientation(orientation);
}

}
