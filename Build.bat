#!/usr/bin/env bash

EXEC="main.out"

# Compile the C++ source file
g++ -std=c++11 -O2 -Wall -o "$EXEC" main.cpp

# If compilation fails, exit early
if [ $? -ne 0 ]; then
  echo "❌ Compilation failed."
  exit 1
fi

# Check if the executable exists before running
if [ -x "$EXEC" ]; then
  echo "✅ Build successful. Running $EXEC..."
  ./"$EXEC"
else
  echo "⚠️ $EXEC not found or not executable."
fi

# Clean up: delete the executable if it exists
rm -f "$EXEC"
echo "🧹 Cleaned up $EXEC"
