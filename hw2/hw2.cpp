/**
* Title: Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 2
* Description: This is the main function to run and generate an NgramTree, and also
* display its ngrams and ngramcounts
*/

# include <string>
# include <iostream>

using namespace std;

# include "NgramTree.h"

// main function
int main( int argc , char ** argv ) {
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);
    tree.generateTree(fileName, n);

    cout << "\n Total " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is complete: " << (tree.isComplete() ? " Yes " : "No") << endl;

    // Before insertion of new n- grams
    cout << "\n Total " << n << "-gram count:" << tree.getTotalNgramCount() << endl;

    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");

    cout << "\n Total " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is complete: " << (tree.isComplete() ? " Yes " : "No") << endl;

    cout << n << "-gram tree is full: " << (tree.isFull() ? " Yes " : "No") << endl;

    return 0;
}
