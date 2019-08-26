#pragma once

namespace robosim {

class Creatable_node
{
public:
  Creatable_node(Creatable_node &) = delete;
  void operator=(Creatable_node &) = delete;
};

}
