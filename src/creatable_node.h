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

  virtual void translate(const Ogre::Vector3 &v);
  virtual void scale(const Ogre::Vector3 &v);

  [[nodiscard]] virtual const Ogre::Quaternion &get_orientation() const;
  virtual void set_orientation(const Ogre::Quaternion &orientation);

protected:
  explicit Creatable_node(Ogre::SceneManager &);

  Ogre::SceneNode *ogre_node;
};

}
