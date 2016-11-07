#!/usr/bin/env bash

set -e

CONVERT_PATH='../src/linux/pngs.h'

if [[ -z "$(bin2c --help 2>/dev/null)" ]]; then
  echo "bin2c is not installed. Please install it and try again."
  exit 1
fi

bin2c -o "$CONVERT_PATH" ../icons/*.png

echo "png icons successfully converted to $CONVERT_PATH"
