#include "Ogre.h"
#include "application.h"
#include <iostream>

int
main(int argc, char *argv[])
{
  try {
    robosim::Application app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();
  } catch (const std::exception &e) {
    std::cerr << "Error during execution: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
