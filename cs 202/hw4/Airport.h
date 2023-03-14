/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is header file of airport object
*/

#ifndef AIRPORT_H
#define AIRPORT_H

#include "Flight.h"
#include <iostream>
class Airport
{
    public:
        Airport();
        virtual ~Airport();
        void setId(int idd);
        void addFlight(int to, int duration);
        int getId();
        void List();
        Flight* getCurrentFlight();
        void SetCurrentFlight();
        int getKey();
        void setCost(int newCost);
        void nextFlight();
        void reset();
        void setPrev(int prevv);
        int getPrev();
        Airport copy();
    protected:
        Flight* flights;
        Flight* currentFlight;
        int cost = 99999999;
        int prev;
    private:
        int id;

};

#endif // AIRPORT_H
