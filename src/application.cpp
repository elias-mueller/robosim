#include "application.h"
#include "Ogre.h"

using namespace Ogre;

void Application::setup() {
  ApplicationContextBase::setup();
  addInputListener(this);

  // get a pointer to the already created root
  auto root = getRoot();
  auto scn_mgr = root->createSceneManager();

  // register our scene with the RTSS
  auto shader_gen = RTShader::ShaderGenerator::getSingletonPtr();
  shader_gen->addSceneManager(scn_mgr);

  // -- tutorial section start --
  //! [turnlights]
  scn_mgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
  //! [turnlights]

  //! [newlight]
  auto light = scn_mgr->createLight("MainLight");
  auto light_node = scn_mgr->getRootSceneNode()->createChildSceneNode();
  light_node->attachObject(light);
  //! [newlight]

  //! [lightpos]
  light_node->setPosition(20, 80, 50);
  //! [lightpos]

  //! [camera]
  auto cam_node = scn_mgr->getRootSceneNode()->createChildSceneNode();

  // create the camera
  auto cam = scn_mgr->createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  cam_node->attachObject(cam);
  cam_node->setPosition(0, 0, 140);

  //! [cameramove]
  cam_node->setPosition(0, 47, 222);
  //! [cameramove]

  // and tell it to render into the main window
  getRenderWindow()->addViewport(cam);
  //! [camera]

  //! [entity1]
  auto ogre_entity = scn_mgr->createEntity("ogrehead.mesh");
  //! [entity1]

  //! [entity1node]
  auto ogre_node = scn_mgr->getRootSceneNode()->createChildSceneNode();
  //! [entity1node]

  //! [entity1nodeattach]
  ogre_node->attachObject(ogre_entity);
  //! [entity1nodeattach]

  //! [entity2]
  auto ogre_entity_2 = scn_mgr->createEntity("ogrehead.mesh");
  auto ogre_node_2 =
      scn_mgr->getRootSceneNode()->createChildSceneNode(Vector3(84, 48, 0));
  ogre_node_2->attachObject(ogre_entity_2);
  //! [entity2]
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}
