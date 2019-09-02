#pragma once

#include <iostream>

namespace robosim::utils {

template<typename... T>
static void
println(T &&... args)
{
  (std::cout << ... << args) << '\n';
}

}
