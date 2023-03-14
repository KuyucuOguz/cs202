/*
* Title: Sorting and Algorithm Efficiency
* Author:Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 1
* Description: c++ program which includes main method to test sorting.cpp
*/



#include "sorting.h"

int main(){
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
