/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file of flight object
*/

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
class Flight
{
    public:
        Flight();
        virtual ~Flight();
        Flight(int too, int costt, int fromm);
        void setNext(Flight* newNext);
        int getCost();
        int getDestination();
        int getStarting();
        int getKey();
    protected:
        int to;
        int cost;
        Flight* next;
        int from;

    private:
        friend class adjList;
        friend class Airport;


};

#endif // FLIGHT_H
