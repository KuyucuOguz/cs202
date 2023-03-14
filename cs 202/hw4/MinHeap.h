/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file of minheap 1
*/

#ifndef MINHEAP_H
#define MINHEAP_H



//this is taken from the book
const int MAX_HEAP = 5000;
#include "Airport.h"// definition of KeyedItem
typedef Airport HeapItemType;

class MinHeap {
public:
	MinHeap();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty() const;
	void heapInsert(const HeapItemType& newItem) ;
	bool heapDelete(HeapItemType& rootItem);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	HeapItemType items[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items
};


#endif // MINHEAP_H
