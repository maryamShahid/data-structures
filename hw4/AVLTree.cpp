/**
* Title: AVL Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 4
* Description: This is the implementation of the AVL Tree that analyses words in a file
*/

#include "AVLTree.h"

TreeNode::TreeNode() {
    this->word = "";
    this->count = 0;
    this->leftChildPtr = nullptr;
    this->rightChildPtr = nullptr;
}

TreeNode::TreeNode(string aWord) {
    this->word = aWord;
    this->count = 1;
    this->leftChildPtr = nullptr;
    this->rightChildPtr = nullptr;
}

AVLTree::AVLTree() {
    rootPtr = nullptr;
}

AVLTree::~AVLTree() {

}

int AVLTree::getBalance(TreeNode *nodePtr) {
    return getHeight(nodePtr->rightChildPtr) - getHeight(nodePtr->leftChildPtr);
}

int AVLTree::getHeight(TreeNode *nodePtr) {
    if (nodePtr != nullptr) {
        return 1 + max(getHeight(nodePtr->leftChildPtr), getHeight(nodePtr->rightChildPtr));
    }
    return 0;
}

void AVLTree::rotateRight(TreeNode *&nodePtr) {
    TreeNode *tempPtr = nodePtr->leftChildPtr;
    nodePtr->leftChildPtr = tempPtr->rightChildPtr;
    tempPtr->rightChildPtr = nodePtr;
    nodePtr = tempPtr;
    tempPtr = nullptr;
}

void AVLTree::rotateLeft(TreeNode *&nodePtr) {
    TreeNode *tempPtr = nodePtr->rightChildPtr;
    nodePtr->rightChildPtr = tempPtr->leftChildPtr;
    tempPtr->leftChildPtr = nodePtr;
    nodePtr = tempPtr;
    tempPtr = nullptr;
}

void AVLTree::balanceTree(TreeNode *&nodePtr) {
    if (getBalance(nodePtr) > 1) {
        // right-left rotation
        if (getBalance(nodePtr->rightChildPtr) < 0) {
            rotateRight(nodePtr->rightChildPtr);
            rotateLeft(nodePtr);
        } else {
            // left rotation
            rotateLeft(nodePtr);
        }
    } else if (getBalance(nodePtr) < -1) {
        // left-right rotation
        if (getBalance(nodePtr->leftChildPtr) > 0) {
            rotateLeft(nodePtr->leftChildPtr);
            rotateRight(nodePtr);
        } else {
            // right rotation
            rotateRight(nodePtr);
        }
    }
}

void AVLTree::totalWordCountHelper( TreeNode *nodePtr, long &count) {
    if (nodePtr != nullptr) {
        totalWordCountHelper(nodePtr->leftChildPtr, count);
        count++;
        totalWordCountHelper(nodePtr->rightChildPtr, count);
    }
}

void AVLTree::findMostFrequent( TreeNode *nodePtr, string &aWord, int &count) {
    if (nodePtr != nullptr) {
        findMostFrequent(nodePtr->leftChildPtr, aWord, count);
        if (nodePtr->count > count) {
            count = nodePtr->count;
            aWord = nodePtr->word;
        }
        findMostFrequent(nodePtr->rightChildPtr, aWord, count);
    }
}

void AVLTree::findLeastFrequent( TreeNode* nodePtr, string &aWord, int &count) {
    if (nodePtr != nullptr) {
        findLeastFrequent(nodePtr->leftChildPtr, aWord, count);
        if (nodePtr->count < count) {
            count = nodePtr->count;
            aWord = nodePtr->word;
        }
        findLeastFrequent(nodePtr->rightChildPtr, aWord, count);
    }
}

void AVLTree::printWordFrequenciesHelper( TreeNode *nodePtr, ofstream &outputFile) {
    if (nodePtr != nullptr) {
        printWordFrequenciesHelper(nodePtr->leftChildPtr, outputFile);
        outputFile << (nodePtr->word) << " " << (nodePtr->count) << "\n";
        printWordFrequenciesHelper(nodePtr->rightChildPtr, outputFile);
    }
}

void AVLTree::totalFrequency(TreeNode *nodePtr, double &totalFreq) {
    if (nodePtr != nullptr) {
        totalFrequency(nodePtr->leftChildPtr, totalFreq);
        totalFreq += nodePtr->count;
        totalFrequency(nodePtr->rightChildPtr, totalFreq);
    }
}

void AVLTree::standardDeviationHelper(TreeNode *nodePtr, double average, double &squareDifference) {
    if (nodePtr != nullptr) {
        standardDeviationHelper(nodePtr->leftChildPtr, average, squareDifference);
        squareDifference += (average - nodePtr->count) * (average - nodePtr->count);
        standardDeviationHelper(nodePtr->rightChildPtr, average, squareDifference);
    }
}

void AVLTree::addWord(string aWord, TreeNode *&nodePtr) {
    if (nodePtr == nullptr) {
        nodePtr = new TreeNode(aWord);
    } else {
        if (aWord.compare(nodePtr->word) > 0) {
            addWord(aWord, nodePtr->rightChildPtr);
            balanceTree(nodePtr);
        } else if (aWord.compare(nodePtr->word) == 0) {
            nodePtr->count++;
        } else {
            addWord(aWord, nodePtr->leftChildPtr);
            balanceTree(nodePtr);
        }
    }
}

void AVLTree::generateTree(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName.c_str());
    string line;
    while (inputFile >> line) {
        for (int i = 0; i < line.length(); i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            } else {
                line[i] = ' ';
            }
        }
        char *newWord;
        char *wordsArray = new char[line.length() + 1];
        strcpy(wordsArray, line.c_str());
        newWord = strtok(wordsArray, " ");
        while (newWord != nullptr) {
            addWord(newWord, rootPtr);
            newWord = strtok(nullptr, " ");
        }
    }
}

void AVLTree::printHeight() {
    ofstream outputFile;
    outputFile.open("statistics", outputFile.app);
    outputFile << "Tree Height: " << getHeight(rootPtr) << "\n";
    outputFile.close();
}

void AVLTree::printTotalWordCount() {
    long count = 0;
    totalWordCountHelper(rootPtr, count);

    ofstream outputFile;
    outputFile.open("statistics");
    outputFile << "Total Word Count: " << count << "\n";
    outputFile.close();
}

void AVLTree::printWordFrequencies() {
    ofstream outputFile;
    outputFile.open("wordfreqs");
    printWordFrequenciesHelper(rootPtr, outputFile);
    outputFile.close();
}

void AVLTree::printMostFrequent() {
    int count = 0;
    string word = "";
    findMostFrequent(rootPtr, word, count);

    ofstream outputFile;
    outputFile.open("statistics", outputFile.app);
    outputFile << "Most Frequent: " << word << " " << count << "\n";
    outputFile.close();
}

void AVLTree::printLeastFrequent() {
    int count = INT_MAX;
    string word = "";
    findLeastFrequent(rootPtr, word, count);

    ofstream outputFile;
    outputFile.open("statistics", outputFile.app);
    outputFile << "Least Frequent: " << word << " " << count << "\n";
    outputFile.close();
}

void AVLTree::printStandartDeviation() {
    long count = 0;
    totalWordCountHelper(rootPtr, count);

    double freq = 0;
    totalFrequency(rootPtr, freq);

    double average = freq / count;
    double squareDifference = 0;
    standardDeviationHelper(rootPtr, average, squareDifference);

    ofstream outputFile;
    outputFile.open("statistics", outputFile.app);
    outputFile << "Standard Deviation: " << (sqrt(squareDifference / count));
    outputFile.close();
}