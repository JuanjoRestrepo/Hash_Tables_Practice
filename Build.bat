#!/usr/bin/env bash

# Compile with flags
g++ -std=c++11 -O2 -Wall -o main.out main.cpp

# Exit if compilation failed
if [ $? -ne 0 ]; then
  echo "❌ Compilation failed."
  exit 1
fi

echo -e "\n✅ Build successful. Running program..."
./main.out