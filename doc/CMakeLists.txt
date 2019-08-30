find_package(Doxygen REQUIRED dot)

if(DOXYGEN_FOUND)
  doxygen_add_docs(doc
                   ../src
                   COMMENT
                   "Generate man pages")
else()
  message(STATUS "Doxygen not found. Documentation won't be build.")
endif()
