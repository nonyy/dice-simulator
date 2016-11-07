#!/usr/bin/env bash

set -e

echo "Installing required packages..."
apt-get update -y > /dev/null
apt-get install -y libwxgtk3.0-dev build-essential codeblocks > /dev/null
echo "All required packages installed successfully"

if [[ -f compiler_test.sh ]]; then
  /bin/bash ./compiler_test.sh
else
  echo "'compiler_test.sh' not present..."
  echo "Compiler test SKIPPED"
  exit 1
fi
