/**
* Title: Algorithm Efficiency and Sorting
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 1
* Description: This is the header file for sorting.cpp. It contains prototypes
* for insertion sort, quick sort, merge sort
*/
using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

// helper methods
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void helperMergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void swap(int &first, int &second, int &moveCount);
void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void helperQuickSort(int *arr, int first, int last, int &compCount, int &moveCount);
