/*
* Title: CS202 Spring 2022 hw4
* Author: Oğuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is implementation of minheap which keeps flights.
*/

#include "MinHeap2.h"


//the code of maxHeap is taken from the book and it is changed as minheap
// Default constructor
MinHeap2::MinHeap2() : size(0) {

}


bool MinHeap2::heapIsEmpty() const {
	return (size == 0);
}


//MinHeap::~MinHeap()
//{
    //dtor
//}

void MinHeap2::heapInsert(const HeapItemTypee& newItem) {

	if (size >= MAX_HEAPP)
		return;

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].getKey() < items[parent].getKey()) ) {
		HeapItemTypee temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}


bool MinHeap2::heapDelete(HeapItemTypee& rootItem) {
	if (heapIsEmpty())
		return false;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
		return true;
	}
}


void MinHeap2::heapRebuild(int root){
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild].getKey() < items[child].getKey()) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root].getKey() > items[child].getKey() ) {
			HeapItemTypee temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
