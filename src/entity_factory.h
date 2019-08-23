#pragma once

#include "Creatable_node.h"
#include "Entity_type.h"
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
  Entity_factory(Entity_factory const &) = delete;
  void operator=(Entity_factory const &) = delete;

  std::weak_ptr<Creatable_node> create(Entity_type);

private:
  Entity_factory() = default;

  std::vector<std::shared_ptr<Creatable_node>> created_nodes;
};

}
