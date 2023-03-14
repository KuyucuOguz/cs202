/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is implementation of airport object which keeps flights
*/


#include "Airport.h"

Airport::Airport()
{
    flights = nullptr;
    currentFlight = nullptr;
    prev = -1;
}

Airport::~Airport()
{
    //if(flights == nullptr){
    //    currentFlight = nullptr;
    //    return;
    //}
    /*
    else{
        while(getCurrentFlight() != nullptr){
            Flight* next = flights->next;
            //delete flights;
            flights = next;
            currentFlight = next;
            //std::cout<<"here"<<std::endl;
        }
        //std::cout<<"here2"<<std::endl;
        delete flights;
        flights = nullptr;
        currentFlight = nullptr;
    }
    */
    //delete flights;
    //std::cout<<"here2"<<std::endl;
}

void Airport::addFlight(int to, int duration){
    Flight* newFlight;
    newFlight = new Flight(to, duration, id);
    if(flights == nullptr){
        flights = newFlight;
        currentFlight = flights;
        return;
    }
    else{
        Flight* temp = flights;
        flights = newFlight;
        newFlight->setNext(temp);
        currentFlight = flights;
        return;
    }
}

void Airport::setId(int idd){
    id = idd;
}
int Airport::getId(){
    return id;
}

void Airport::List(){
    Flight* cur = flights;
    int num = 0;
    if(cur == nullptr){
        std::cout<<"there is no flight from airport " <<id<<" to anywhere"<<std::endl;
        return;
    }
    std::cout<<"List of flights from "<<id<<std::endl;
    while(cur != NULL){
        std::cout<<"    "<<id<<" to "<<cur->getDestination()<< " with a duration of "<<cur->getCost()<<std::endl;
        cur = cur->next;
        num = num + 1;
        //std::cout<<cur->getCost()<<std::endl;
    }
    std::cout<<"    The number of flights is "<<num<<std::endl;
}

Flight* Airport::getCurrentFlight(){
    Flight* cur = currentFlight;
    return cur;
}

void Airport::SetCurrentFlight(){
    currentFlight = flights;
}

int Airport::getKey(){
    return cost;
}

void Airport::setCost(int newCost){
    cost = newCost;
}

void Airport::nextFlight(){
    //Flight* cur = currentFlight;
    currentFlight = currentFlight->next;
}
void Airport::reset(){
    currentFlight = flights;
    cost = 9999999;
    prev = -1;

}
void Airport::setPrev(int prevv){
    prev = prevv;
}

int Airport::getPrev(){
    return prev;
}
Airport Airport::copy(){

    Airport neww;

    while(this->getCurrentFlight()){
        neww.addFlight(this->getCurrentFlight()->getDestination(), this->getCurrentFlight()->getKey());
    }
    return neww;
}
