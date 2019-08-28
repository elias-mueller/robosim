#pragma once

namespace robosim {

class Creatable_node
{
public:
  virtual ~Creatable_node() = default;

  Creatable_node(Creatable_node &) = delete;
  void operator=(Creatable_node &) = delete;

protected:
  Creatable_node() = default;
};

}
