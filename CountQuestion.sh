#!/bin/bash

# Check if a directory is passed as an argument, otherwise use the current directory
DIRECTORY="${1:-.}"

# Find all .cpp files in the directory and its subdirectories and count them
count=$(find "$DIRECTORY" -type f -name "*.cpp" | wc -l)

# Output the result
echo "Total number of .cpp files in '$DIRECTORY' and its subdirectories: $count"
