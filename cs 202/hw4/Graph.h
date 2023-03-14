/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file of graph
*/

#ifndef GRAPH_H
#define GRAPH_H
#include "adjList.h"

class Graph
{
    public:
        Graph(int numOfAirports);
        virtual ~Graph();
        void addFlight(int airPortOne, int airPortTwo, int duration);
        void List(int airPortNum);
        void shortestPath(int startingAirport, int destinationAirport);
        void minimize();
    protected:

    private:
        adjList* list;


};

#endif // GRAPH_H
