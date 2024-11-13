#!/bin/bash

# Check if the filename is provided as an argument
if [ -z "$1" ]; then
    echo "No file specified."
    exit 1
fi

# Use the filename provided as an argument
filename="$1"

# Get the name without the extension
base_filename="${filename%.*}"

# Compile the C++ file
g++ "$filename" -o "$base_filename"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the compiled executable
    ./"$base_filename"
else
    # Print an error message if compilation fails
    echo "Compilation failed."
fi