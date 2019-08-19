#include "sphere_creator.h"
#include "application.h"
#include <Ogre.h>

using namespace Ogre;

namespace robosim {

void
Sphere_creator::create()
{
  auto &scn_mgr = robosim::Application::get_scene_manager();

  Entity *entity =
    scn_mgr.createEntity("sphere", Ogre::SceneManager::PT_SPHERE);
  SceneNode *node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);
  node->setPosition(0, 40, 0);
  node->scale(Ogre::Vector3::UNIT_SCALE * 0.3);

  sphere_node = node;
}

bool
Sphere_creator::frameStarted(const Ogre::FrameEvent &evt)
{
  time_passed += evt.timeSinceLastFrame;
  sphere_node->translate(0, Math::Sin(time_passed), 0);

  return FrameListener::frameStarted(evt);
}

}
