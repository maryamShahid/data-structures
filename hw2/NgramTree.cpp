/**
* Title: Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 2
* Description: This cpp file contains implementations of creating and
* maintaining an NgramTree
*/

#include "NgramTree.h"

NgramTree::NgramTree() {
    rootPtr = NULL;
}

NgramTree::NgramTree(const NgramTree &tree) {
    rootPtr = copyTree(tree.rootPtr);
}

NgramTree::~NgramTree() {
    destroyTree(rootPtr);
}

// copy constructor helper
NgramNode* NgramTree::copyTree(NgramNode *treePtr) {
    NgramNode* newTreePtr = nullptr;

    // copy tree nodes in a pre-order traversal
    if (treePtr != nullptr) {
        // copy node
        newTreePtr = new NgramNode(treePtr->getNgram());
        newTreePtr->setNgramCount(treePtr->getNgramCount());
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }
    return newTreePtr;
}

// destructor helper
void NgramTree::destroyTree(NgramNode *subTreePtr) {
    // post-order traversal
    if (subTreePtr != NULL) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }
}

bool NgramTree::isComplete() {
    int index = 0;
    int size = this->getTotalNgramCount();
    return isCompleteHelper(rootPtr, index, size);
}

bool NgramTree::isCompleteHelper(NgramNode* subTreePtr, int index, int size)
{
    // an empty tree is complete
    if (subTreePtr == NULL)
        return (true);
    // if index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= size)
        return (false);
    // recur for left and right subtrees if we assign i as index to parent node
    // leftChildIndex = (2 * i) + 1
    // rightChildIndex = (2 * i) + 2
    return (isCompleteHelper(subTreePtr->getLeftChildPtr(), 2 * index + 1, size) &&
            isCompleteHelper(subTreePtr->getLeftChildPtr(), 2 * index + 2, size));
}

bool NgramTree::isFull() {
    return isFullHelper(rootPtr);
}

bool NgramTree::isFullHelper(NgramNode* subTreePtr)
{
    // if empty tree
    if (subTreePtr == NULL) {
        return true;
    }
    // if leaf node
    else if (subTreePtr->isLeaf()) {
        return true;
    }
    // if both left and right are not NULL, and left & right subtrees are full
    else if ((subTreePtr->getLeftChildPtr()) && (subTreePtr->getRightChildPtr())) {
        return (isFullHelper(subTreePtr->getLeftChildPtr()) && isFullHelper(subTreePtr->getRightChildPtr()));
    }
    // we reach here when none of the above if conditions work
    return false;
}

NgramNode *NgramTree::searchNode(string ngram) {
    // searches for node in a preorder traversal
    if (rootPtr != NULL) {
        NgramNode *temp = rootPtr;
        // check if ngram is not in rootptr
        while (temp && temp->getNgram() != ngram) {
            if (temp->getNgram() > ngram) {
                temp = temp->getLeftChildPtr();
            }
            else {
                temp = temp->getRightChildPtr();
            }
        }
        return temp;
    }
    return NULL;
}

void NgramTree::addNgram(string ngram) {
    NgramNode *temp;
    // lower case all letters
    char s[ngram.length()];
    for (int i = 0; i < ngram.length(); i++) {
        s[i] = tolower(ngram[i]);
    }
    // new string to be added
    string word = "";
    for (int i = 0; i < ngram.length(); i++) {
        word += s[i];
    }
    // if tree is empty
    if (rootPtr == NULL) {
        rootPtr = new NgramNode(word);
    }
    // if the ngram is already in tree, increment its ngramcount
    else if (searchNode(word)) {
        temp = searchNode(word);
        temp->incrementNgramCount();
    } else {
        temp = rootPtr;
        // find position to insert the new node
        while ((word < temp->getNgram() && temp->getLeftChildPtr() != NULL) ||
                (word > temp->getNgram() && temp->getRightChildPtr() != NULL)) {
            if (word > temp->getNgram()) {
                temp = temp->getRightChildPtr();
            } else {
                temp = temp->getLeftChildPtr();
            }
        }
        if (word < temp->getNgram()) {
            temp->setLeftChildPtr(new NgramNode(word));
        } else {
            temp->setRightChildPtr(new NgramNode(word));
        }
    }
}

void NgramTree::generateTree(std::string fileName, int n) {
    ifstream file;
    file.open(fileName);
    string line;
    int index = 0;
    if (file.is_open()) {
        while (file >> line) {
            if (line.length() >= n) {
                for (int i = 0; i + n <= line.length(); i++) {
                    addNgram(line.substr(i, n));
                }
            }
        }
    } else {
        cout << "Unable to open file" << endl;
    }
}

void NgramTree::getTotalNgramCountHelper(NgramNode* subTreePtr, int & count) {
    if (subTreePtr) {
        getTotalNgramCountHelper(subTreePtr->getLeftChildPtr(), count);
        count++;
        getTotalNgramCountHelper(subTreePtr->getRightChildPtr(), count);
    }
}

int NgramTree::getTotalNgramCount() {
    int count = 0;
    getTotalNgramCountHelper(rootPtr, count);
    return count;
}

ostream& operator <<( ostream& out, const NgramTree& tree ) {
    NgramTree temp(tree);
    temp.outputHelper(out, tree.rootPtr);
    return out;
}

ostream& NgramTree::outputHelper(ostream& output, NgramNode* rootPtr) {
    if (rootPtr != NULL) {
        // in order traversal
        outputHelper(output, rootPtr->getLeftChildPtr());
        output << "\"" << rootPtr->getNgram() << "\" appears " << rootPtr->getNgramCount() << " time(s)"<< endl;
        outputHelper(output, rootPtr->getRightChildPtr());
    }
    return output;
}

