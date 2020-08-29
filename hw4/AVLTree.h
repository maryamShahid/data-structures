/**
* Title: AVL Trees
* Author: Maryam Shahid
* ID: 21801344
* Assignment: 4
* Description: This is the header file for the AVL Tree that analyses words in a file
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

class TreeNode {
public:
    TreeNode();
    TreeNode(string aWord);

    string word;
    int count;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;

    friend class AVLTree;
};

class AVLTree {
private:
    TreeNode *rootPtr;

protected:
    int getHeight(TreeNode *nodePtr);
    int getBalance(TreeNode *nodePtr);
    void rotateRight(TreeNode *&nodePtr);
    void rotateLeft(TreeNode *&nodePtr);
    void balanceTree(TreeNode *&nodePtr);
    void totalWordCountHelper(TreeNode *nodePtr, long &count);
    void findMostFrequent(TreeNode *nodePtr, string &word, int &count);
    void findLeastFrequent(TreeNode *nodePtr, string &word, int &count);
    void printWordFrequenciesHelper(TreeNode *nodePtr, ofstream &outputFile);
    void totalFrequency(TreeNode *nodePtr, double &totalFreq);
    void standardDeviationHelper(TreeNode *nodePtr, double average, double &squareDifference);

public:
    AVLTree();
    ~AVLTree();

    void addWord(string aWord, TreeNode *&nodePtr);
    void generateTree(string fileName);
    void printHeight();
    void printTotalWordCount();
    void printWordFrequencies();
    void printMostFrequent();
    void printLeastFrequent();
    void printStandartDeviation();
};