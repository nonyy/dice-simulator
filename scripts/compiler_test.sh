#!/usr/bin/env bash

set -e

if [[ -f compiler_test.cpp ]]; then
  echo "Testing compiler..."
  g++ -std=gnu++11 compiler_test.cpp `wx-config  --version=3.0 --static=no --unicode=yes --debug=no --cflags --libs` -o test && rm test
  echo "Compiler tested successfully!"
else
  echo "'compiler_test.cpp' not present..."
  echo "Compiler test FAILED"
  exit 1
fi
