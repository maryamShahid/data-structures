/**
* Title: Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 2
* Description: This is the header file for NgramTree.cpp. It contains
* function prototypes for creating and maintaining an Ngram tree
*/

#include <string>
#include <iostream>
#include <fstream>

#include "NgramNode.h"
using namespace std;

class NgramTree {
public:
    NgramTree();
    ~NgramTree();
    NgramTree(const NgramTree &tree);

    void addNgram(string ngram);
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);

protected:
    NgramNode* copyTree( NgramNode *treePtr);
    void destroyTree(NgramNode* subTreePtr);
    bool isCompleteHelper(NgramNode* subTreePtr, int index, int size);
    bool isFullHelper(NgramNode* subTreePtr);
    void getTotalNgramCountHelper(NgramNode* subTreePtr, int& count);
    NgramNode* searchNode(string ngram);
    ostream& outputHelper(ostream &output, NgramNode* root);

private:
    NgramNode* rootPtr;
    friend ostream& operator <<( ostream& out, const NgramTree& tree );
};