#pragma once

#include <OgreApplicationContext.h>

class Application : public OgreBites::ApplicationContext,
                    public OgreBites::InputListener {
public:
  void setup() override;
  bool keyPressed(const OgreBites::KeyboardEvent &evt) override;
};
