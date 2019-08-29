#include "box_node.h"
#include "Ogre.h"
#include "application.h"

using namespace Ogre;

namespace robosim {

Box_node::Box_node(Ogre::SceneManager &scn_mgr)
{
  Entity *entity = scn_mgr.createEntity(Ogre::SceneManager::PT_CUBE);
  entity->setMaterialName("Examples/Rockwall");
  ogre_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  ogre_node->attachObject(entity);
  ogre_node->setPosition(0, 40, 0);
  ogre_node->scale(Ogre::Vector3::UNIT_SCALE * 0.3);
}

void
Box_node::translate(const Vector3 &v)
{
  ogre_node->translate(v);
}

void
Box_node::scale(const Ogre::Vector3 &v)
{
  ogre_node->scale(v);
}

const Quaternion &
Box_node::get_orientation() const
{
  return ogre_node->getOrientation();
}

void
Box_node::set_orientation(const Ogre::Quaternion &orientation)
{
  ogre_node->setOrientation(orientation);
}

}
