/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file of minheap2
*/


#ifndef MINHEAP2_H
#define MINHEAP2_H


//this is taken from the book
const int MAX_HEAPP = 5000;
#include "Flight.h"// definition of KeyedItem
typedef Flight HeapItemTypee;

class MinHeap2 {
public:
	MinHeap2();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty() const;
	void heapInsert(const HeapItemTypee& newItem) ;
	bool heapDelete(HeapItemTypee& rootItem);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
private:
	HeapItemTypee items[MAX_HEAPP];	// array of heap items
	int          size;            	// number of heap items
};


#endif // MINHEAP2_H
