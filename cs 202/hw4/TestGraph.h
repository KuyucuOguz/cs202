/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file for TestGraph class
*/


#ifndef TESTGRAPH_H
#define TESTGRAPH_H


#include <iostream>
#include <fstream>
#include <string.h>
#include "Graph.h"
class TestGraph
{
    public:
        TestGraph();
        virtual ~TestGraph();
        void operate(std::string filename);
    protected:

    private:
};
#endif // TESTGRAPH_H
