/*
* Title: Trees
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 2
* Description: node of a binary tree which contains left child, right child, parent, size and value
*/


#ifndef BINARYNODE_H
#define BINARYNODE_H


class BinaryNode
{
    public:
        BinaryNode(int val);
        virtual ~BinaryNode();

    protected:
    BinaryNode* parent;
    BinaryNode* leftChild;
    BinaryNode* rightChild;
    int value;
    int size;
    private:
    friend class BinarySearchTree;
};

#endif // BINARYNODE_H
