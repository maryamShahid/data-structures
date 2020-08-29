/**
* Title: Algorithm Efficiency and Sorting
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 1
* Description: This the main driver for sorting.cpp. It analyzes the time count, and the
* number of key comparisons and data moves by various sorting algorithms for different input sizes.
*/

#include <iostream>
#include "sorting.h"
#include <time.h>

int main() {
    int compCount, moveCount;
    int *arr1, *arr2, *arr3;
    const int size = 20000;

    // Three identical arrays with ​random 20,000 integers
    arr1 = new int [size]; // for insertion sort
    arr2 = new int [size]; // for merge sort
    arr3 = new int [size]; // for quick sort
    srand( time(NULL) );
    for (int i = 0; i < size; i ++){
        arr1[i] = rand() % (2 * size);
        arr2[i] = arr3[i] = arr1[i];
    }

    // Arrays in random order
    cout << "\nRANDOM ARRAYS" << endl;

    // Insertion sort
    compCount = 0, moveCount = 0;

    clock_t timer1 = clock();
    insertionSort(arr1, size, compCount, moveCount);
    double timePassed1 = double( clock () - timer1 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Insertion Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed1 << " ms" << endl;

    // Merge sort
    compCount = 0, moveCount = 0;

    clock_t timer2 = clock();
    mergeSort(arr2, size, compCount, moveCount);
    double timePassed2 = double( clock () - timer2 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << " \n ----Merge Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed2 << " ms" << endl;

    // Quick sort
    compCount = 0, moveCount = 0;

    clock_t timer3 = clock();
    quickSort(arr3, size, compCount, moveCount);
    double timePassed3 = double( clock () - timer3 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n ----Quick Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed3 << " ms" << endl;

    // Three identical arrays ​with 20,000 integers that are sorted in descending order​
    for (int i = 0; i < size; i++) {
        int item = size - i;
        arr1[i] = item;
        arr2[i] = item;
        arr3[i] = item;
    }

    // Arrays in descending order
    cout << "\nARRAYS IN DESCENDING ORDER" << endl;

    // Insertion sort
    compCount = 0, moveCount = 0;

    clock_t timer4 = clock();
    insertionSort(arr1, size, compCount, moveCount);
    double timePassed4 = (double)(clock() - timer4) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Insertion Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed4 << " ms" << endl;

    // Merge sort
    compCount = 0, moveCount = 0;

    clock_t timer5 = clock();
    mergeSort(arr2, size, compCount, moveCount);
    double timePassed5 = double( clock () - timer5 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Merge Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed5 << " ms" << endl;

    // Quick sort
    compCount = 0, moveCount = 0;

    clock_t timer6 = clock();
    quickSort(arr3, size, compCount, moveCount);
    double timePassed6 = double( clock () - timer6 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Quick Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed6 << " ms" << endl;

    // Three identical arrays with 20,000 integers that are sorted in ascending order​
    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
    }

    // Arrays in ascending order
    cout << "\nARRAYS IN ASCENDING ORDER" << endl;

    // Insertion sort
    compCount = 0, moveCount = 0;

    clock_t timer7 = clock();
    insertionSort(arr1, size, compCount, moveCount);
    double timePassed7 = (double)(clock() - timer7) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Insertion Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed7 << " ms" << endl;

    // Merge sort
    compCount = 0, moveCount = 0;

    clock_t timer8 = clock();
    mergeSort(arr2, size, compCount, moveCount);
    double timePassed8 = double( clock () - timer8 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Merge Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed8 << " ms" << endl;

    // Quick sort
    compCount = 0, moveCount = 0;

    clock_t timer9 = clock();
    quickSort(arr3, size, compCount, moveCount);
    double timePassed9 = double( clock () - timer9 ) * 1000 / (double) CLOCKS_PER_SEC;

    cout << "\n----Quick Sort----" << endl;
    cout << "Key comparisons: " << compCount << endl;
    cout << "Data moves: " << moveCount << endl;
    cout << "Elapsed Time: " << timePassed9 << " ms" << endl;
}

