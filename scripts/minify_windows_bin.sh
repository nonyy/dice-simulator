#!/usr/bin/env bash

if [[ -z "$(upx --help 2>/dev/null)" ]]; then
  echo "upx is not installed. Please install it and try again."
  exit 1
fi

BIN_PATH='../bin/dice_simulator.exe'

if [[ -f "$BIN_PATH" ]]; then
  upx -9 --ultra-brute "$BIN_PATH"
else
  echo "Windows binary seems to be not compiled. Please compile it before packing."
fi
