#!/usr/bin/env bash

# Ruta completa al archivo fuente y ejecutable
SRC="src/main.cpp"
EXEC="main.out"

# Compilación
g++ -std=c++11 -O2 -Wall -o "$EXEC" "$SRC"
if [ $? -ne 0 ]; then
  printf "\n❌ Compilation failed for %s." "$SRC"
  exit 1
fi

# Mensaje con saltos de línea
printf "\n✅ Build successful. Running program..."

# Ejecución si existe y es ejecutable
if [ -x "$EXEC" ]; then
  ./"$EXEC"
else
  printf "\n⚠️ %s not found or not executable." "$EXEC"
fi
