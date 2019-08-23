#include "sphere_node.h"
#include "application.h"
#include <Ogre.h>

using namespace Ogre;

namespace robosim {

Sphere_node::Sphere_node(Ogre::SceneManager &scn_mgr)
{
  Entity *entity =
    scn_mgr.createEntity("sphere", Ogre::SceneManager::PT_SPHERE);
  ogre_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  ogre_node->attachObject(entity);
  ogre_node->setPosition(0, 40, 0);
  ogre_node->scale(Ogre::Vector3::UNIT_SCALE * 0.3);

  Root::getSingleton().addFrameListener(this);
}

bool
Sphere_node::frameStarted(const Ogre::FrameEvent &evt)
{
  time_passed += evt.timeSinceLastFrame;
  sine_float();
  return FrameListener::frameStarted(evt);
}

void
Sphere_node::sine_float()
{
  ogre_node->translate(0, Math::Sin(time_passed), 0);
}

}
