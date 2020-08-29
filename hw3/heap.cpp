/**
* Title: Heaps
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 3
* Description: This cpp file contains the implementation for creating
* and maintaining a max heap
*/

#include "heap.h"

heap::heap() {
    maxItems = 3000;
    itemCount = 0;
    compCount = 0;
    items = new int[maxItems];
}

heap::heap(int max) {
    maxItems = max;
    itemCount = 0;
    compCount = 0;
    items = new int[maxItems];
}

heap::~heap() {
    delete items;
}

void heap::insert(const int a) {
    if (itemCount >= maxItems) {
        int *temp = new int[maxItems * 2];
        for (int i = 0; i < maxItems; i++) {
            temp[i] = items[i];
        }
        int *toDelete = items;
        items = temp;
        delete[] toDelete;
        maxItems = maxItems * 2;
    }

    items[itemCount] = a;

    int place = itemCount;
    int parent = (place - 1) / 2;

    while ((place > 0) && (items[place] > items[parent])) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
        compCount++;
    }
    itemCount++;
}

int heap::maximum() {
    if (itemCount > 0)
        return items[0];
    else
        return -1;
}

int heap::popMaximum() {
    if (itemCount == 0) {
        return -1;
    }
    int max = maximum();
    itemCount--;
    items[0] = items[itemCount];

    // heap rebuild function
    int parent = 0;
    int child = 2 * parent + 1;
    int rightChild;

    while (child < itemCount) {
        rightChild = child + 1;

        if (rightChild < itemCount && items[rightChild] > items[child])
            child = rightChild;

        if (items[child] > items[parent])
            swap(items[child], items[parent]);

        compCount += 2;

        parent = child;
        child = 2 * parent + 1;
    }
    return max;
}

void heap::heapRebuild(int root) {
    int child = 2 * root + 1; // index of left child
    if (child < itemCount) {
        // root has a left child
        int rightChild = child + 1; // index of right child
        // if right child, find larger child
        if ((rightChild < itemCount) && (items[rightChild] > items[child])) {
            child = rightChild; // index of larger child
        }
        compCount++;
        // if root is smaller then larger child, swap'
        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = items[temp];
            // build heap from new subtree
            heapRebuild(child);
        }
        compCount++;
    } else return;
}

int heap::getCompCount() {
    return compCount;
}

bool heap::isEmpty() {
    return itemCount == 0;
}


