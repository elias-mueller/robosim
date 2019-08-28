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

SceneNode &
Box_node::get_ogre_node() const
{
  return *ogre_node;
}

}
