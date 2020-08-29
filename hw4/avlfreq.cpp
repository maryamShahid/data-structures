/**
* Title: AVL Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 4
* Description: This is the main file which takes an input file from user
* and creates two output files - wordfreqs and statistics
*/

#include <iostream>
#include "AVLTree.h"

using namespace std;

int main (int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Incorrect input" << endl;
        return 0;
    }

    AVLTree avlTree;
    avlTree.generateTree(argv[1]);

    avlTree.printWordFrequencies();
    avlTree.printTotalWordCount();
    avlTree.printHeight();
    avlTree.printMostFrequent();
    avlTree.printLeastFrequent();
    avlTree.printStandartDeviation();

    cout << "Output generated" << endl;
}