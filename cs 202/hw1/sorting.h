/*
* Title: Sorting and Algorithm Efficiency
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 1
* Description: header file of sorting.cpp
*/




#ifndef SORTING_H
#define SORTING_H
#include <math.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


typedef int DataType;
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void swap(int*arr, int n, int k);
void mergesort2( DataType theArray[], int first, int last, int &compCount, int &moveCount);
void merge( DataType theArray[], int first, int mid, int last, int &compCount, int &moveCount);
void quicksort2(DataType theArray[], int first, int last, int &compCount, int &moveCount );
void partition(DataType theArray[], int first, int last, int &pivotIndex, int &compCount, int &moveCount );
void performanceAnalysis();
void performanceAnalysis2();
class sorting
{
    public:
        sorting();
        virtual ~sorting();


    protected:

    private:
};

#endif // SORTING_H
