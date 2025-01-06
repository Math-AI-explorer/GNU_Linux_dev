#!/bin/sh
set -e

echo "Generating configure script..."
mkdir -p m4
autoreconf --install --force --verbose
echo "Done!"