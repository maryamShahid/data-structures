/**
* Title: Heaps
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 3
* Description: This cpp file takes in an input file containing integers and
* uses heap sort to sort the numbers. Output is then written on an output file
*/

#include <fstream>
#include <iostream>
#include "heap.h"

using namespace std;

int main (int argc, char ** argv) {
    if (argc != 3) {
        cout << "Input not found" << endl;
        return 0;
    }

    string line;
    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);

    heap h;
    int count = 0;

    while (getline(inputFile, line)) {
        h.insert(atoi(line.c_str()));
        count++;
    }
    inputFile.close();

    while (!h.isEmpty()) {
        outputFile << h.popMaximum();
        outputFile << "\n";
    }
    outputFile.close();

    cout << "n = " << count << ", Number of comparisons = " << h.getCompCount() << endl;
    return 0;
}