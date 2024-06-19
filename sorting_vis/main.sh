#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR=$(pwd)

echo "Select the sorting algorithm you want to visualize:"
echo "1) Bubble Sort"
echo "2) Insertion Sort"
echo "3) Selection Sort"
echo "4) Quick Sort"
echo "5) Merge Sort"
echo "6) Count Sort"
echo "7) Radix Sort"
read -p "Enter the number corresponding to your choice: " choice

case $choice in
    1)
        echo "Running Bubble Sort visualization..."
        "$SCRIPT_DIR/bubblesort"
        ;;
    2)
        echo "Running Insertion Sort visualization..."
        "$SCRIPT_DIR/insertionsort"
        ;;
    3)
        echo "Running Selection Sort visualization..."
        "$SCRIPT_DIR/selectionsort"
        ;;
    4)
        echo "Running Quick Sort visualization..."
        "$SCRIPT_DIR/quicksort"
        ;;
    5)
        echo "Running Merge Sort visualization..."
        "$SCRIPT_DIR/mergesort"
        ;;
    6)
        echo "Running Count Sort visualization..."
        "$SCRIPT_DIR/countsort"
        ;;
    7)
        echo "Running Radix Sort visualization..."
        "$SCRIPT_DIR/radixsort"
        ;;
    *)
        echo "Invalid choice. Please run the script again and select a valid option."
        ;;
esac
