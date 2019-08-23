#include "entity_factory.h"
#include "application.h"
#include "box_node.h"
#include "sphere_node.h"

using namespace Ogre;

namespace robosim {

Entity_factory &
Entity_factory::get_instance()
{
  static Entity_factory entity_factory;
  return entity_factory;
}

std::weak_ptr<Creatable_node>
Entity_factory::create(const Entity_type type)
{
  auto &scn_mgr = robosim::Application::get_scene_manager();

  switch (type) {
    case Entity_type::SPHERE: {
      created_nodes.emplace_back(std::make_shared<Sphere_node>(scn_mgr));
      return created_nodes.back();
    }
    case Entity_type::BOX: {
      created_nodes.emplace_back(std::make_shared<Box_node>(scn_mgr));
      return created_nodes.back();
    }
    default:
      throw Type_not_supported_exception();
  }
}

}
