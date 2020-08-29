/**
* Title: Algorithm Efficiency and Sorting
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 1
* Description: This cpp file contains implementations of insertion sort, merge sort, and quick sort
* in ascending order and also measures the number of key comparisons and data moves
*/

#include <iostream>
#include "sorting.h"
using namespace std;

void insertionSort(int* arr, const int size, int& compCount, int& moveCount) {
    compCount = 0;
    moveCount = 0;
    int key;
    int count = 0;

    for (int unsorted = 1; unsorted < size; unsorted++) {
        count = 0;
        key = arr[unsorted];
        moveCount++; // data move

        int loc = unsorted - 1;
        compCount++;
        while ((loc >= 0) && (arr[loc] > key)) {
            if (count > 0) {
                compCount++; // key comparison
            }
            arr[loc + 1] = arr[loc];
            moveCount++; // data move
            loc--;
            count++;
        }
        arr[loc + 1] = key;
        moveCount++; // data move
    }
}

void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArray[last + 1];

    int first1 = first;    // beginning of first subarray
    int last1 = mid;       // end of first subarray
    int first2 = mid + 1;  // beginning of second subarray
    int last2 = last;      // end of second subarray
    int index = first1; // next available location in temp array

    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++; // first key comparison
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
            moveCount++; // data move
        } else {
            tempArray[index] = arr[first2];
            ++first2;
            moveCount++; // data move
        }
    }
    for (; first1 <= last1; ++first1, ++index) { // finish off the first subarray, if necessary
        moveCount++; // data move
        arr[index] = arr[first1];
    }
    for (; first2 <= last2; ++first2, ++index) { // finish off the second subarray, if necessary
        moveCount++; // data move
        arr[index] = arr[first2];
    }
    for (index = first; index <= last; ++index) { // copy the result back into the original array
        moveCount++; // data move
        arr[index] = arr[index];
    }
}

void helperMergeSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {
        int mid = (first + last) / 2; // index of midpoint
        helperMergeSort(arr, first, mid, compCount, moveCount);
        helperMergeSort(arr, mid + 1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size - 1;
    helperMergeSort(arr, first, last, compCount, moveCount);
}

void swap(int &first, int &second, int &moveCount) {
    int temp = first;
    first = second;
    second = temp;
    moveCount += 3;
}

void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = arr[first]; // first data move
    moveCount++;
    int lastS1 = first;            // index of last item in S1
    int firstUnknown = first + 1;  // index of first item in unknown
    for (; firstUnknown <= last; ++firstUnknown) { // move one item at a time until unknown region is empty
        compCount++; // comparison
        if (arr[firstUnknown] < pivot) { // move item from unknown to proper region
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1], moveCount);
        } // else belongs to S2
    }
    swap(arr[first], arr[lastS1], moveCount);
    pivotIndex = lastS1;
}

void helperQuickSort(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;

    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        helperQuickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        helperQuickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size - 1;
    helperQuickSort(arr, first, last, compCount, moveCount);
}
