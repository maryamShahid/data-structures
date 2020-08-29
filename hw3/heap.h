/**
* Title: Heaps
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 3
* Description: This is the header file for heap.cpp. It contains function
* prototypes for creating and maintaining a max heap
*/

#include <iostream>

using namespace std;

class heap {
public:
    heap();
    heap(int max);
    ~heap();

    void insert(const int a);
    int maximum();
    int popMaximum();

    void heapRebuild(int subTreeRootIndex);
    int getCompCount();
    bool isEmpty();

private:
    int* items;    // array of heap items
    int itemCount; // current count of heap items
    int maxItems;  // maximum capacity of heap
    int compCount; // comparison count
};