#pragma once

#include <Ogre.h>
namespace robosim {

class Creatable_node
{
public:
  virtual ~Creatable_node() = default;

  Creatable_node(Creatable_node &) = delete;
  void operator=(Creatable_node &) = delete;
  Creatable_node(Creatable_node &&) = delete;
  void operator=(Creatable_node &&) = delete;

  virtual void translate(const Ogre::Vector3 &v) = 0;
  virtual void scale(const Ogre::Vector3 &v) = 0;

  [[nodiscard]] virtual const Ogre::Quaternion &get_orientation() const = 0;
  virtual void set_orientation(const Ogre::Quaternion &orientation) = 0;

protected:
  Creatable_node() = default;
};

}
