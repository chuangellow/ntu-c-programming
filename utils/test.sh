#!/bin/bash

# Compile the C program
gcc main.c -o main -std=c99 -O2

# Loop to run the program with inputs from 0.in to 10.in
for i in {0..10}
do
    echo "Running test case $i..."
    ./main < "$i.in" > "$i_output.txt"

    # Compare the output with the expected output
    diff -w "$i_output.txt" "$i.out" > /dev/null
    if [ $? -eq 0 ]
    then
        echo "Test case $i passed."
    else
        echo "Test case $i failed. Check $i_output.txt for details."
    fi
done

# Cleanup: Remove the compiled executable
rm main

