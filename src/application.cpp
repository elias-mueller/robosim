#include "application.h"
#include "Ogre.h"
#include "entity_factory.h"
#include "sphere_node.h"

using namespace Ogre;

namespace robosim {

void
Application::setup()
{
  ApplicationContextBase::setup();
  addInputListener(this);

  auto &shader_gen = RTShader::ShaderGenerator::getSingleton();
  shader_gen.addSceneManager(&get_scene_manager());

  setup_scene();
}

void
Application::setup_scene()
{
  setup_light();
  setup_camera();
  create_plane();
  create_entities();
}

void
Application::setup_light() const
{
  auto &scn_mgr = get_scene_manager();

  scn_mgr.setAmbientLight(ColourValue{ 0.5, 0.5, 0.5 });
  scn_mgr.setShadowTechnique(ShadowTechnique::SHADOWTYPE_TEXTURE_MODULATIVE);

  Light *light = scn_mgr.createLight("MainLight");
  SceneNode *light_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  light_node->attachObject(light);

  light_node->setPosition(20, 80, 50);
}

void
Application::setup_camera() const
{
  auto &scn_mgr = get_scene_manager();

  SceneNode *cam_node = scn_mgr.getRootSceneNode()->createChildSceneNode();

  Camera *cam = scn_mgr.createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  cam_node->attachObject(cam);
  cam_node->setPosition(0, 47, 222);

  Viewport *vp = getRenderWindow()->addViewport(cam);
  vp->setBackgroundColour(ColourValue::White);
}

void
Application::create_plane() const
{
  auto &scn_mgr = get_scene_manager();

  Plane plane{ Vector3::UNIT_Y, 0 };
  MeshManager::getSingleton().createPlane("ground",
                                          RGN_DEFAULT,
                                          plane,
                                          1500,
                                          1500,
                                          20,
                                          20,
                                          true,
                                          1,
                                          5,
                                          5,
                                          Vector3::UNIT_Z);
  Entity *entity = scn_mgr.createEntity("ground");
  entity->setCastShadows(false); // No need for shadows from the ground.
  entity->setMaterialName("Examples/Rockwall");

  SceneNode *node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);
}

void
Application::create_entities()
{

  SceneNode *node = create_entity("ogrehead.mesh");
  node->setPosition(Vector3{ -84, 48, 0 });

  node = create_entity("ogrehead.mesh");
  node->setPosition(Vector3{ 84, 48, 0 });

  node = create_entity("ninja.mesh");
  node->scale(Vector3::UNIT_SCALE * 0.5);
  node->rotate(Quaternion(Radian{ Degree{ 180 } }, Vector3::UNIT_Y));

  auto &entity_factory = robosim::Entity_factory::get_instance();
  entity_factory.create(Entity_type::SPHERE);
  entity_factory.create(Entity_type::BOX);
}

SceneNode *
Application::create_entity(const std::string &mesh_name) const
{
  auto &scn_mgr = get_scene_manager();

  Entity *entity = scn_mgr.createEntity(mesh_name);
  SceneNode *node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);

  return node;
}

bool
Application::keyPressed(const OgreBites::KeyboardEvent &evt)
{
  if (evt.keysym.sym == OgreBites::SDLK_ESCAPE) {
    getRoot()->queueEndRendering();
  }
  return true;
}

Ogre::SceneManager *Application::scene_manager;

Ogre::SceneManager &
Application::get_scene_manager()
{
  if (!scene_manager) {
    auto &root = Ogre::Root::getSingleton();
    scene_manager = root.createSceneManager();
  }

  return *scene_manager;
}

}
