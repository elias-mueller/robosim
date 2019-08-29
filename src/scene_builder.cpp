#include "scene_builder.h"
#include "application.h"
#include "box_node.h"
#include "entity_factory.h"
#include "hinge_joint.h"
#include <string>

using namespace Ogre;

namespace robosim {

namespace {

void
setup_light()
{
  auto &scn_mgr = Application::get_scene_manager();

  scn_mgr.setAmbientLight(ColourValue{ 0.5, 0.5, 0.5 });
  scn_mgr.setShadowTechnique(ShadowTechnique::SHADOWTYPE_TEXTURE_MODULATIVE);

  Light *light = scn_mgr.createLight("MainLight");
  SceneNode *light_node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  light_node->attachObject(light);

  light_node->setPosition(20, 80, 50);
}

void
setup_camera()
{
  auto &scn_mgr = Application::get_scene_manager();

  SceneNode *cam_node = scn_mgr.getRootSceneNode()->createChildSceneNode();

  Camera *cam = scn_mgr.createCamera("myCam");
  cam->setNearClipDistance(5); // specific to this sample
  cam->setAutoAspectRatio(true);
  cam_node->attachObject(cam);
  cam_node->setPosition(0, 47, 222);

  Viewport *vp = Application::get_render_window().addViewport(cam);
  vp->setBackgroundColour(ColourValue::White);
}

void
create_plane()
{
  auto &scn_mgr = Application::get_scene_manager();

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

SceneNode *
create_entity(const std::string &mesh_name)
{
  auto &scn_mgr = Application::get_scene_manager();

  Entity *entity = scn_mgr.createEntity(mesh_name);
  SceneNode *node = scn_mgr.getRootSceneNode()->createChildSceneNode();
  node->attachObject(entity);

  return node;
}

void
create_entities()
{

  SceneNode *node = create_entity("ogrehead.mesh");
  node->setPosition(Vector3{ -84, 48, 0 });

  node = create_entity("ogrehead.mesh");
  node->setPosition(Vector3{ 84, 48, 0 });

  auto &entity_factory = robosim::Entity_factory::get_instance();

  entity_factory.create(Entity_type::SPHERE);

  std::shared_ptr<Creatable_node> box0 =
    entity_factory.create(Entity_type::BOX);
  std::shared_ptr<Creatable_node> box1 =
    entity_factory.create(Entity_type::BOX);

  box1->translate(Vector3{ 0, 50, 0 });
  box1->scale(Vector3{ 2, 1, 1 });

  new Hinge_joint{ box0, box1, true };
}

}

void
robosim::Scene_builder::build()
{
  setup_light();
  setup_camera();
  create_plane();
  robosim::create_entities();
}

}
