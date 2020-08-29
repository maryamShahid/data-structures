/**
* Title: Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 2
* Description: This cpp file contains the implementation of nodes for a link-based
* binary search tree
*/

#include "NgramNode.h"

NgramNode::NgramNode() {
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

NgramNode::NgramNode(string aWord) {
    ngram = aWord;
    ngramCount = 1;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

string NgramNode::getNgram() {
    return ngram;
}
int NgramNode::getNgramCount() {
    return ngramCount;
}

NgramNode *NgramNode::getLeftChildPtr() {
    return leftChildPtr;
}

NgramNode *NgramNode::getRightChildPtr() {
    return rightChildPtr;
}

void NgramNode::setNgram(string aWord) {
    ngram = aWord;
}

void NgramNode::setNgramCount(int count) {
    ngramCount = count;
}

void NgramNode::incrementNgramCount() {
    ngramCount++;
}

void NgramNode::setLeftChildPtr(NgramNode *leftPtr) {
    leftChildPtr = leftPtr;
}

void NgramNode::setRightChildPtr(NgramNode *rightPtr) {
    rightChildPtr = rightPtr;
}

bool NgramNode::isLeaf() {
    if ((leftChildPtr == NULL) && (rightChildPtr == NULL))
        return true;
    return false;
}
