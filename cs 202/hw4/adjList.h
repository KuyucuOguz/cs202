/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file for adjecency list
*/


#ifndef ADJLIST_H
#define ADJLIST_H

#include "Airport.h"
#include "MinHeap.h"
#include <iostream>
#include <string.h>
#include "string.h"
#include "MinHeap2.h"
class adjList
{
    public:
        adjList();
        adjList(int numOFAirportss);
        virtual ~adjList();
        void addFlight(int airPortOne, int airPortTwo, int duration);
        //void List(int airPort);
        int shortestPath(int startingAirport, int destination, bool print);
        int MAX_INT = 300000;
        void List(int i);
        void minimize(int i, Airport air[], int& cost, bool visitedAirports[]);
        void minimize();
    protected:

    private:
        int numOfAirports;
        Airport* airports;
        //void addFlight(int airPortOne, int AirPortTwo, int duration);

};

#endif // ADJLIST_H
