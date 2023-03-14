/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is implementation of ADT graph by using adjecency list
*/

#include "Graph.h"

Graph::Graph(int numberOfAirports)
{
    list = new adjList(numberOfAirports);
}

Graph::~Graph()
{
    //delete list;
}

void Graph::addFlight(int airPortOne, int airPortTwo, int duration){
    list->addFlight(airPortOne, airPortTwo, duration);
}
void Graph::List(int airPortNum){
    list->List(airPortNum);
}
void Graph::shortestPath(int startingAirport, int destinationAirport){
    list->shortestPath(startingAirport, destinationAirport, true);
}
void Graph::minimize(){
    list->minimize();
}
