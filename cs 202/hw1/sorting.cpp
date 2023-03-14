/*
* Title: Sorting and Algorithm Efficiency
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 1
* Description: a c++ program which is written to observe time complexities of four sort aalgorithms which are insertion sort,
bubble sort, merge sort and quick sort
*/




#include "sorting.h"
#include <math.h>
#include <iostream>
#include <ctime>

typedef int DataType;


void insertionSort(int *arr, const int size, int &compCount, int &moveCount){

    for (int unsorted = 1; unsorted < size; ++unsorted) {
        moveCount++;
        DataType nextItem = arr[unsorted];
        int loc = unsorted;
        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
            arr[loc] = arr[loc-1];
            moveCount++;
            compCount++;
        }
        if(loc > 0){
            compCount++;
        }
        arr[loc] = nextItem;
        moveCount++;


    }
}
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false;

	for (int pass = 1; (pass < size) && !sorted; ++pass) {
      sorted = true;
      for (int index = 0; index < size - pass; ++index) {
         int nextIndex = index + 1;
         compCount++;
         if (arr[index] > arr[nextIndex]) {
            swap(arr, index, nextIndex);
            moveCount = moveCount + 3;
            sorted = false;
         }
      }
   }


}

void swap(int* arr, int n, int k){
    int temp;
    temp = arr[n];
    arr[n] = arr[k];
    arr[k] = temp;
}



void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    mergesort2(arr, 0, size - 1, compCount, moveCount );
}

void mergesort2( DataType theArray[], int first, int last, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergesort2(theArray, first, mid, compCount, moveCount);

      mergesort2(theArray, mid+1, last,compCount, moveCount);

      // merge the two halves
      merge(theArray, first, mid, last, compCount, moveCount);
   }
}
void merge( DataType theArray[], int first, int mid, int last, int &compCount, int &moveCount) {
   const int MAX_SIZE = 50000;
   DataType tempArray[MAX_SIZE]; 	// temporary array

   int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index){
         //compCount++;
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         ++first1;
         //compCount++;
         moveCount++;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
          //compCount++;
          moveCount++;
      }
      compCount++;
   }
   	// finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index){
      moveCount++;
      tempArray[index] = theArray[first1];
   }
   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index){
      moveCount++;
      tempArray[index] = theArray[first2];
   }
   // copy the result back into the original array
   for (index = first; index <= last; ++index){
      theArray[index] = tempArray[index];
      moveCount++;
   }

}


void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    quicksort2(arr, 0, size - 1, compCount, moveCount);
}

void quicksort2(DataType theArray[], int first, int last, int &compCount, int &moveCount ) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

	int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quicksort2(theArray, first, pivotIndex-1, compCount, moveCount);
      quicksort2(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}
void partition(DataType theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount ) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]
   //choosePivot(theArray, first, last);
    moveCount++;
   DataType pivot = theArray[first]; // copy pivot
       // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray, firstUnknown, lastS1);
    	  moveCount = moveCount + 3;
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   moveCount = moveCount + 3;
   swap(theArray, first, lastS1);
   pivotIndex = lastS1;
}

void displayArray(const int *arr, const int size){
    std::cout<<"{";
    int i;
    for(i = 0; i < size - 1; i++){
        std::cout<<arr[i];
        std::cout<<", ";
    }
    std::cout<<arr[i];
    std::cout<<"}";

}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    arr1 = new int[size];
    for(int i = 0; i < size; i++){
        arr1[i] = rand() % size;
    }
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

}
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for(int i = 0; i < size; i++){
        arr1[i] = i;
    }
    for(int k = 0; k < size/20; k++) {
        int a = rand() % size;
        int b = rand() % size;
        int temp = arr1[a];
        arr1[a] = arr1[b];
        arr1[b] = temp;
    }
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

}
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for(int i = 0; i < size; i++){
        arr1[i] = size - i;
    }
    for(int k = 0; k < size/20; k++) {
        int a = rand() % size;
        int b = rand() % size;
        int temp = arr1[a];
        arr1[a] = arr1[b];
        arr1[b] = temp;
    }
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}
void performanceAnalysis2(){
double duration;
    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;

    int* arr5;
    int* arr6;
    int* arr7;
    int* arr8;

    int* arr9;
    int* arr10;
    int* arr11;
    int* arr12;

    int* arr13;
    int* arr14;
    int* arr15;
    int* arr16;

    int* arr17;
    int* arr18;
    int* arr19;
    int* arr20;

    int* arr21;
    int* arr22;
    int* arr23;
    int* arr24;

    int* arr25;
    int* arr26;
    int* arr27;
    int* arr28;

    int* arr29;
    int* arr30;
    int* arr31;
    int* arr32;

    int* arr33;
    int* arr34;
    int* arr35;
    int* arr36;

    int* arr37;
    int* arr38;
    int* arr39;
    int* arr40;

    int* arr41;
    int* arr42;
    int* arr43;
    int* arr44;

    int* arr45;
    int* arr46;
    int* arr47;
    int* arr48;

    int* arr49;
    int* arr50;
    int* arr51;
    int* arr52;

    int* arr53;
    int* arr54;
    int* arr55;
    int* arr56;

    int* arr57;
    int* arr58;
    int* arr59;
    int* arr60;

    int* arr61;
    int* arr62;
    int* arr63;
    int* arr64;

    int* arr65;
    int* arr66;
    int* arr67;
    int* arr68;

    int* arr69;
    int* arr70;
    int* arr71;
    int* arr72;

    int* arr73;
    int* arr74;
    int* arr75;
    int* arr76;

    int* arr77;
    int* arr78;
    int* arr79;
    int* arr80;

    int* arr81;
    int* arr82;
    int* arr83;
    int* arr84;

    int* arr85;
    int* arr86;
    int* arr87;
    int* arr88;

    int* arr89;
    int* arr90;
    int* arr91;
    int* arr92;

    int* arr93;
    int* arr94;
    int* arr95;
    int* arr96;

    createRandomArrays(arr1, arr2, arr3, arr4, 5000);
    createAlmostSortedArrays(arr5, arr6, arr7, arr8, 5000);
    createAlmostUnsortedArrays(arr9, arr10, arr11, arr12, 5000);

    createRandomArrays(arr13, arr14, arr15, arr16, 10000);
    createAlmostSortedArrays(arr17, arr18, arr19, arr20, 10000);
    createAlmostUnsortedArrays(arr21, arr22, arr23, arr24, 10000);

    createRandomArrays(arr25, arr26, arr27, arr28, 15000);
    createAlmostSortedArrays(arr29, arr30, arr31, arr32, 15000);
    createAlmostUnsortedArrays(arr33, arr34, arr35, arr36, 15000);

    createRandomArrays(arr37, arr38, arr39, arr40, 20000);
    createAlmostSortedArrays(arr41, arr42, arr43, arr44, 20000);
    createAlmostUnsortedArrays(arr45, arr46, arr47, arr48, 20000);

    createRandomArrays(arr49, arr50, arr51, arr52, 25000);
    createAlmostSortedArrays(arr53, arr54, arr55, arr56, 25000);
    createAlmostUnsortedArrays(arr57, arr58, arr59, arr60, 25000);

    createRandomArrays(arr61, arr62, arr63, arr64, 30000);
    createAlmostSortedArrays(arr65, arr66, arr67, arr68, 30000);
    createAlmostUnsortedArrays(arr69, arr70, arr71, arr72, 30000);

    createRandomArrays(arr73, arr74, arr75, arr76, 35000);
    createAlmostSortedArrays(arr77, arr78, arr79, arr80, 35000);
    createAlmostUnsortedArrays(arr81, arr82, arr83, arr84, 35000);

    createRandomArrays(arr85, arr86, arr87, arr88, 40000);
    createAlmostSortedArrays(arr89, arr90, arr91, arr92, 40000);
    createAlmostUnsortedArrays(arr93, arr94, arr95, arr96, 40000);
    int comp = 0;
    int move = 0;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for random arrays"<<std::endl;
    clock_t startTime = clock();
    insertionSort(arr1, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr13, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr25, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr37, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr49, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr61, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr73, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr85, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of bubble sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr2, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr14, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr26, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr38, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr50, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr62, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr74, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr86, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



    ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr3, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr15, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr27, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr39, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr51, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr63, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr75, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr87, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


        ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr4, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr16, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr28, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr40, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr52, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr64, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr76, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr88, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;




    ////////almost sorted part

    /////////
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr5, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr17, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr29, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr41, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr53, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr65, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr77, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr89, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of bubble sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr6, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr18, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr30, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr42, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr54, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr66, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr78, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr90, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr7, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr19, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr31, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr43, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr55, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr67, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr79, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr91, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr8, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr20, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr32, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr44, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr56, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr68, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr80, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr92, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



    /////////almost unsorted part

    ///////
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr9, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr21, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr33, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr45, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr57, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr69, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr81, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr93, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ///////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of bubble sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr10, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr22, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr34, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr46, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr58, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr70, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr82, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr94, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



        ///////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr11, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr23, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr35, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr47, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr59, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr71, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr83, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr95, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


        ///////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr12, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr24, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr36, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr48, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr60, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr72, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr84, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr96, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



}
void performanceAnalysis(){
    double duration;
    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;

    int* arr5;
    int* arr6;
    int* arr7;
    int* arr8;

    int* arr9;
    int* arr10;
    int* arr11;
    int* arr12;

    int* arr13;
    int* arr14;
    int* arr15;
    int* arr16;

    int* arr17;
    int* arr18;
    int* arr19;
    int* arr20;

    int* arr21;
    int* arr22;
    int* arr23;
    int* arr24;

    int* arr25;
    int* arr26;
    int* arr27;
    int* arr28;

    int* arr29;
    int* arr30;
    int* arr31;
    int* arr32;

    int* arr33;
    int* arr34;
    int* arr35;
    int* arr36;

    int* arr37;
    int* arr38;
    int* arr39;
    int* arr40;

    int* arr41;
    int* arr42;
    int* arr43;
    int* arr44;

    int* arr45;
    int* arr46;
    int* arr47;
    int* arr48;

    int* arr49;
    int* arr50;
    int* arr51;
    int* arr52;

    int* arr53;
    int* arr54;
    int* arr55;
    int* arr56;

    int* arr57;
    int* arr58;
    int* arr59;
    int* arr60;

    int* arr61;
    int* arr62;
    int* arr63;
    int* arr64;

    int* arr65;
    int* arr66;
    int* arr67;
    int* arr68;

    int* arr69;
    int* arr70;
    int* arr71;
    int* arr72;

    int* arr73;
    int* arr74;
    int* arr75;
    int* arr76;

    int* arr77;
    int* arr78;
    int* arr79;
    int* arr80;

    int* arr81;
    int* arr82;
    int* arr83;
    int* arr84;

    int* arr85;
    int* arr86;
    int* arr87;
    int* arr88;

    int* arr89;
    int* arr90;
    int* arr91;
    int* arr92;

    int* arr93;
    int* arr94;
    int* arr95;
    int* arr96;

    createRandomArrays(arr1, arr2, arr3, arr4, 5000);
    createAlmostSortedArrays(arr5, arr6, arr7, arr8, 5000);
    createAlmostUnsortedArrays(arr9, arr10, arr11, arr12, 5000);

    createRandomArrays(arr13, arr14, arr15, arr16, 10000);
    createAlmostSortedArrays(arr17, arr18, arr19, arr20, 10000);
    createAlmostUnsortedArrays(arr21, arr22, arr23, arr24, 10000);

    createRandomArrays(arr25, arr26, arr27, arr28, 15000);
    createAlmostSortedArrays(arr29, arr30, arr31, arr32, 15000);
    createAlmostUnsortedArrays(arr33, arr34, arr35, arr36, 15000);

    createRandomArrays(arr37, arr38, arr39, arr40, 20000);
    createAlmostSortedArrays(arr41, arr42, arr43, arr44, 20000);
    createAlmostUnsortedArrays(arr45, arr46, arr47, arr48, 20000);

    createRandomArrays(arr49, arr50, arr51, arr52, 25000);
    createAlmostSortedArrays(arr53, arr54, arr55, arr56, 25000);
    createAlmostUnsortedArrays(arr57, arr58, arr59, arr60, 25000);

    createRandomArrays(arr61, arr62, arr63, arr64, 30000);
    createAlmostSortedArrays(arr65, arr66, arr67, arr68, 30000);
    createAlmostUnsortedArrays(arr69, arr70, arr71, arr72, 30000);

    createRandomArrays(arr73, arr74, arr75, arr76, 35000);
    createAlmostSortedArrays(arr77, arr78, arr79, arr80, 35000);
    createAlmostUnsortedArrays(arr81, arr82, arr83, arr84, 35000);

    createRandomArrays(arr85, arr86, arr87, arr88, 40000);
    createAlmostSortedArrays(arr89, arr90, arr91, arr92, 40000);
    createAlmostUnsortedArrays(arr93, arr94, arr95, arr96, 40000);
    int comp = 0;
    int move = 0;
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for random arrays"<<std::endl;
    clock_t startTime = clock();
    insertionSort(arr1, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr13, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr25, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr37, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr49, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr61, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr73, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr85, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;



    /////////
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr5, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr17, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr29, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr41, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr53, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr65, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr77, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr89, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ///////
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"Analysis of insertion sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr9, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr21, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr33, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr45, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr57, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr69, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr81, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    insertionSort(arr93, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of bubble sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr2, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr14, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr26, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr38, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr50, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr62, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr74, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr86, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of bubble sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr6, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr18, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr30, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr42, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr54, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr66, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr78, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr90, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ///////
    std::cout<<"--------------------------"<<std::endl;
    comp = 0;
    move = 0;
    std::cout<<"Analysis of bubble sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr10, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr22, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr34, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr46, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr58, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr70, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr82, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    bubbleSort(arr94, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;






    ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr3, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr15, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr27, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr39, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr51, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr63, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr75, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr87, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr7, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr19, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr31, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr43, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr55, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr67, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr79, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr91, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ///////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of merge sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr11, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr23, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr35, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr47, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr59, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr71, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr83, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    mergeSort(arr95, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;




        ////////////////////////////////////////////////
    std::cout<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for random arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr4, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr16, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr28, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr40, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr52, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr64, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr76, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr88, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    /////////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for almost sorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr8, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr20, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr32, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr44, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr56, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr68, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr80, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr92, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    ///////
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Analysis of quick sort for almost unsorted arrays"<<std::endl;
    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr12, 5000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"array size   elapsed time  comp count  move count "<<std::endl;
    std::cout<<"5000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr24, 10000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"10000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr36, 15000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"15000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr48, 20000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"20000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr60, 25000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"25000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr72, 30000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"30000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr84, 35000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"35000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;

    comp = 0;
    move = 0;
    startTime = clock();
    quickSort(arr96, 40000,comp, move);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    std::cout<<"40000          "<<duration<<"          "<<comp<<"        "<<move<<std::endl;


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    delete[] arr12;

    delete[] arr13;
    delete[] arr14;
    delete[] arr15;
    delete[] arr16;
    delete[] arr17;
    delete[] arr18;
    delete[] arr19;
    delete[] arr20;
    delete[] arr21;
    delete[] arr22;
    delete[] arr23;
    delete[] arr24;

    delete[] arr25;
    delete[] arr26;
    delete[] arr27;
    delete[] arr28;
    delete[] arr29;
    delete[] arr30;
    delete[] arr31;
    delete[] arr32;
    delete[] arr33;
    delete[] arr34;
    delete[] arr35;
    delete[] arr36;

    delete[] arr37;
    delete[] arr38;
    delete[] arr39;
    delete[] arr40;
    delete[] arr41;
    delete[] arr42;
    delete[] arr43;
    delete[] arr44;
    delete[] arr45;
    delete[] arr46;
    delete[] arr47;
    delete[] arr48;

    delete[] arr49;
    delete[] arr50;
    delete[] arr51;
    delete[] arr52;
    delete[] arr53;
    delete[] arr54;
    delete[] arr55;
    delete[] arr56;
    delete[] arr57;
    delete[] arr58;
    delete[] arr59;
    delete[] arr60;

    delete[] arr61;
    delete[] arr62;
    delete[] arr63;
    delete[] arr64;
    delete[] arr65;
    delete[] arr66;
    delete[] arr67;
    delete[] arr68;
    delete[] arr69;
    delete[] arr70;
    delete[] arr71;
    delete[] arr72;

    delete[] arr73;
    delete[] arr74;
    delete[] arr75;
    delete[] arr76;
    delete[] arr77;
    delete[] arr78;
    delete[] arr79;
    delete[] arr80;
    delete[] arr81;
    delete[] arr82;
    delete[] arr83;
    delete[] arr84;

    delete[] arr85;
    delete[] arr86;
    delete[] arr87;
    delete[] arr88;
    delete[] arr89;
    delete[] arr90;
    delete[] arr91;
    delete[] arr92;
    delete[] arr93;
    delete[] arr94;
    delete[] arr95;
    delete[] arr96;
}
/*int main(){
    int comp;
    int move;

    std::cout<<"insertion Sort:"<<std::endl;
    int arrayy[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    comp = 0;
    move = 0;
    insertionSort(arrayy,16,comp, move );
    displayArray(arrayy, 16);
    std::cout<<std::endl;
    std::cout<<"comparison:"<<comp<<"    "<<"move:"<<move<<std::endl;

    std::cout<<"bubble Sort:"<<std::endl;
    int arrayyy[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    comp = 0;
    move = 0;
    bubbleSort(arrayyy, 16, comp, move );
    displayArray(arrayyy, 16);
    std::cout<<std::endl;
    std::cout<<"comparison:"<<comp<<"    "<<"move:"<<move<<std::endl;

    std::cout<<"merge sort:"<<std::endl;
    int s[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    comp = 0;
    move = 0;
    mergeSort(s, 16,comp, move );
    displayArray(s, 16);
    std::cout<<std::endl;
    std::cout<<"comparison:"<<comp<<"    "<<"move:"<<move<<std::endl;

    std::cout<<"quick Sort:"<<std::endl;
    int arrayyyyy[16] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    comp = 0;
    move = 0;
    quickSort(arrayyyyy,16,comp, move );
    displayArray(arrayyyyy, 16);
    std::cout<<std::endl;
    std::cout<<"comparison:"<<comp<<"    "<<"move:"<<move<<std::endl;
    std::cout<<std::endl;

    performanceAnalysis();
    int a;

    return 0;
}
*/


