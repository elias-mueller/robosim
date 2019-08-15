#include "application.h"
#include "Ogre.h"

using namespace Ogre;

void Application::setup() {
  ApplicationContextBase::setup();
  addInputListener(this);

  auto root = getRoot();
  auto scn_mgr = root->createSceneManager();

  auto shader_gen = RTShader::ShaderGenerator::getSingletonPtr();
  shader_gen->addSceneManager(scn_mgr);

  setup_light(*scn_mgr);
  setup_camera(*scn_mgr);
  create_entities(*scn_mgr);
}

void Application::setup_light(SceneManager &scn_mgr) const {
  scn_mgr.setAmbientLight(ColourValue(0.5, 0.5, 0.5));

  auto light = scn_mgr.createLight("MainLight");
  auto light_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  light_node->attachObject(light);

  light_node->setPosition(20, 80, 50);
}

void Application::setup_camera(SceneManager &scn_mgr) const {
  auto cam_node = scn_mgr.getRootSceneNode()->createChildSceneNode();

  auto cam = scn_mgr.createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  cam_node->attachObject(cam);
  cam_node->setPosition(0, 47, 222);

  getRenderWindow()->addViewport(cam);
}

void Application::create_entities(SceneManager &scn_mgr) const {
  auto ogre_entity = scn_mgr.createEntity("ogrehead.mesh");
  auto ogre_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  ogre_node->attachObject(ogre_entity);

  auto ogre_entity_2 = scn_mgr.createEntity("ogrehead.mesh");
  auto ogre_node_2 =
      scn_mgr.getRootSceneNode()->createChildSceneNode(Vector3(84, 48, 0));
  ogre_node_2->attachObject(ogre_entity_2);
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}
