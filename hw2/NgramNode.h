/**
* Title: Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 2
* Description: This header file contains a class of nodes for a link-based binary tree
* to maintain an Ngram tree
*/

#include <iostream>
#include <string>
using namespace std;

class NgramNode {
public:
    NgramNode();
    NgramNode(string aWord);

    void setNgram(string val);
    void setNgramCount(int count);
    void setLeftChildPtr(NgramNode *leftPtr);
    void setRightChildPtr(NgramNode *rightPtr);

    string getNgram();
    int getNgramCount();
    NgramNode *getLeftChildPtr();
    NgramNode *getRightChildPtr();

    void incrementNgramCount();
    bool isLeaf();

private:
    string ngram;
    int ngramCount;
    NgramNode *leftChildPtr;
    NgramNode *rightChildPtr;
};