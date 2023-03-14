/*
* Title: CS202 Spring 2022 hw4
* Author: Oğuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is implementation of minheap which keeps airports
*/



#include "MinHeap.h"


//the code of maxHeap is taken from the book and it is changed as minheap
// Default constructor
MinHeap::MinHeap() : size(0) {

}


bool MinHeap::heapIsEmpty() const {
	return (size == 0);
}


//MinHeap::~MinHeap()
//{
    //dtor
//}

void MinHeap::heapInsert(const HeapItemType& newItem) {

	if (size >= MAX_HEAP)
		return;

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].getKey() < items[parent].getKey()) ) {
		HeapItemType temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}


bool MinHeap::heapDelete(HeapItemType&rootItem) {
	if (heapIsEmpty())
		return false;
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
		return true;
	}
}


void MinHeap::heapRebuild(int root){
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
			HeapItemType temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}

/*int main()
{
    Airport air;
    Airport air1;
    Airport air2;
    Airport air3;
    Airport air4;
    air1.setCost(4);
    air2.setCost(3);
    air3.setCost(2);
    air4.setCost(1);
    MinHeap heap;
    heap.heapInsert(air1);
    heap.heapInsert(air2);
    heap.heapInsert(air3);
    heap.heapInsert(air4);
    heap.heapDelete(air);
    std::cout<<air.getKey()<<std::endl;
    heap.heapDelete(air);
    std::cout<<air.getKey()<<std::endl;
    heap.heapDelete(air);
    std::cout<<air.getKey()<<std::endl;
    heap.heapDelete(air);
    std::cout<<air.getKey()<<std::endl;
}
*/
