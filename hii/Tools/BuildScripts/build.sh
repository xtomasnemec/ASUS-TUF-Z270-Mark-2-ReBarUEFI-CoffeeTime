#!/bin/bash

# This script automates the build process for the BIOS driver project.

# Set the working directory to the project root
PROJECT_DIR="$(dirname "$(realpath "$0")")/.."
cd "$PROJECT_DIR" || exit 1

# Define build output directory
OUTPUT_DIR="BuildOutput"

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Clean previous builds
echo "Cleaning previous builds..."
rm -rf "$OUTPUT_DIR/*"

# Build the project
echo "Building the BIOS driver project..."
# Assuming a build command is available, replace with actual build command
# For example: build_command --output "$OUTPUT_DIR"
echo "Build command executed."

# Check for build success
if [ $? -eq 0 ]; then
    echo "Build completed successfully."
else
    echo "Build failed."
    exit 1
fi

# Additional steps can be added here, such as packaging or deployment

echo "Build script finished."