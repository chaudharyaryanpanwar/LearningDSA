#!/bin/bash

# Define the file extensions to deletep
extensions=("*.o" "*.out" "*.exe" "*.a" "*.so" "*.obj" "*.bin")

# Loop through each extension and delete the files
for ext in "${extensions[@]}"; do
    echo "Looking for files with extension: $ext"
    found_files=$(find . -name "$ext" -type f)
    if [ -n "$found_files" ]; then
        echo "Deleting files:"
        echo "$found_files"
        find . -name "$ext" -type f -exec rm -f {} +
    else
        echo "No files found with extension: $ext"
    fi
done

# Additionally, find and delete files without extensions
echo "Looking for executable files without extensions"
found_executables=$(find . -type f ! -name "*.*" -perm -111)
if [ -n "$found_executables" ]; then
    echo "Deleting executable files without extensions:"
    echo "$found_executables"
    find . -type f ! -name "*.*" -perm -111 -exec rm -f {} +
else
    echo "No executable files found without extensions."
fi

echo "Cleanup complete."