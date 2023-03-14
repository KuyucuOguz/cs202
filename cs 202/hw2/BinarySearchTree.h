/*
* Title: Trees
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 2
* Description: binary search tree class which can add item, remove item etc
*/



#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"
#include <cstddef>
#include <iostream>

//void analyzeBST();
class BinarySearchTree
{
    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();
        bool add(int newEntry);
        bool remove(int anEntry);
        bool contains(int anEntry);
        void inorderTraverse();
        int getWidth();
        int count(int a, int b);
        int select(int anEntry);
        int successor(int anEntry);
        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();
        void inorderTraverse(BinaryNode* node, int index);
    protected:

    private:
        //Node* root;
        /*struct Node(int val){
            int val;
            Node* parent;
            Node* leftChild;
            Node* rightChild;
            int size;
        };
        */
        BinaryNode* head;
        bool addNode(BinaryNode* newEnt, BinaryNode* parent);
        int successorOfNode(BinaryNode*& successor, BinaryNode* nod);
        void inorderTraverse(BinaryNode* node);
        void inorderTraverseSelect(BinaryNode* node, int value, int& a);
        int inorderTraverseCount(BinaryNode* node, int a, int b, int& count);
        int heightOfNode(BinaryNode* cur, int height);
        int getWidthOfTree(BinaryNode* root);
        int getWidthOfHeight(BinaryNode* root, int height);
        friend class BinaryNode;
        int indexx;
};

#endif // BINARYSEARCHTREE_H
