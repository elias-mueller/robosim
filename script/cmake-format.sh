#!/usr/bin/env bash

script_dir=$(dirname "$0")
cd "$script_dir"/.. || exit 1

cmake-format -i $(find . -name CMakeLists.txt)