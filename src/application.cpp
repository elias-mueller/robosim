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
  create_plane(*scn_mgr);
  create_entities(*scn_mgr);
}

void Application::setup_light(SceneManager &scn_mgr) const {
  scn_mgr.setAmbientLight(ColourValue(0.5, 0.5, 0.5));
  scn_mgr.setShadowTechnique(ShadowTechnique::SHADOWTYPE_TEXTURE_MODULATIVE);

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

  auto vp = getRenderWindow()->addViewport(cam);
  vp->setBackgroundColour(ColourValue::White);
}

void Application::create_plane(Ogre::SceneManager &scn_mgr) const {
  Plane plane(Vector3::UNIT_Y, 0);
  MeshManager::getSingleton().createPlane("ground", RGN_DEFAULT, plane, 1500,
                                          1500, 20, 20, true, 1, 5, 5,
                                          Vector3::UNIT_Z);
  auto entity = scn_mgr.createEntity("ground");
  entity->setCastShadows(false); // No need for shadows from the ground.
  entity->setMaterialName("Examples/Rockwall");

  auto node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);
}

void Application::create_entities(SceneManager &scn_mgr) const {
  auto node = create_entity(scn_mgr, "ogrehead.mesh");
  node->setPosition(Vector3(-84, 48, 0));

  node = create_entity(scn_mgr, "ogrehead.mesh");
  node->setPosition(Vector3(84, 48, 0));

  node = create_entity(scn_mgr, "ninja.mesh");
  node->scale(Vector3::UNIT_SCALE * 0.5);
  node->rotate(Quaternion(Radian(Degree(180)), Vector3::UNIT_Y));
}

SceneNode *Application::create_entity(SceneManager &scn_mgr,
                                      const std::string &mesh_name) const {
  auto entity = scn_mgr.createEntity(mesh_name);
  auto node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);

  return node;
}

bool Application::keyPressed(const OgreBites::KeyboardEvent &evt) {
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}
