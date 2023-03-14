/*
* Title: Trees
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 2
* Description: node of a binary tree which contains left child, right child, parent, size and value
*/

#include "BinaryNode.h"
#include <cstddef>
BinaryNode::BinaryNode(int val)
{
    value = val;
    parent = NULL;
    leftChild = NULL;
    rightChild = NULL;
    size = 0;

}

BinaryNode::~BinaryNode()
{
    //dtor
}
