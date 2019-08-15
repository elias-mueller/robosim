#include "application.h"
#include "Ogre.h"

using namespace Ogre;

void Application::setup() {
  ApplicationContextBase::setup();
  addInputListener(this);

  // get a pointer to the already created root
  Root *root = getRoot();
  SceneManager *scnMgr = root->createSceneManager();

  // register our scene with the RTSS
  RTShader::ShaderGenerator *shadergen =
      RTShader::ShaderGenerator::getSingletonPtr();
  shadergen->addSceneManager(scnMgr);

  // -- tutorial section start --
  //! [turnlights]
  scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
  //! [turnlights]

  //! [newlight]
  Light *light = scnMgr->createLight("MainLight");
  SceneNode *lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  lightNode->attachObject(light);
  //! [newlight]

  //! [lightpos]
  lightNode->setPosition(20, 80, 50);
  //! [lightpos]

  //! [camera]
  SceneNode *camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

  // create the camera
  Camera *cam = scnMgr->createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  camNode->attachObject(cam);
  camNode->setPosition(0, 0, 140);

  // and tell it to render into the main window
  getRenderWindow()->addViewport(cam);
  //! [camera]

  //! [entity1]
  Entity *ogreEntity = scnMgr->createEntity("ogrehead.mesh");
  //! [entity1]

  //! [entity1node]
  SceneNode *ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  //! [entity1node]

  //! [entity1nodeattach]
  ogreNode->attachObject(ogreEntity);
  //! [entity1nodeattach]

  //! [cameramove]
  camNode->setPosition(0, 47, 222);
  //! [cameramove]

  //! [entity2]
  Entity *ogreEntity2 = scnMgr->createEntity("ogrehead.mesh");
  SceneNode *ogreNode2 =
      scnMgr->getRootSceneNode()->createChildSceneNode(Vector3(84, 48, 0));
  ogreNode2->attachObject(ogreEntity2);
  //! [entity2]

  //! [entity3]
  Entity *ogreEntity3 = scnMgr->createEntity("ogrehead.mesh");
  SceneNode *ogreNode3 = scnMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode3->setPosition(0, 104, 0);
  ogreNode3->setScale(2, 1.2, 1);
  ogreNode3->attachObject(ogreEntity3);
  //! [entity3]

  //! [entity4]
  Entity *ogreEntity4 = scnMgr->createEntity("ogrehead.mesh");
  SceneNode *ogreNode4 = scnMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode4->setPosition(-84, 48, 0);
  ogreNode4->roll(Degree(-90));
  ogreNode4->attachObject(ogreEntity4);
  //! [entity4]
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}
