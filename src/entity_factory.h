#pragma once

#include "creatable_node.h"
#include "entity_type.h"
#include <Ogre.h>
#include <iostream>

namespace robosim {

class Entity_factory
{
  class Type_not_supported_exception : public std::exception
  {};

public:
  // Singleton
  static Entity_factory &get_instance();
  Entity_factory(Entity_factory &) = delete;
  void operator=(Entity_factory &) = delete;
  Entity_factory(Entity_factory &&) = delete;
  void operator=(Entity_factory &&) = delete;

  Creatable_node &create(Entity_type);

private:
  Entity_factory() = default;

  std::vector<std::unique_ptr<Creatable_node>> created_nodes;
};

}
