/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is implementation of adjecency list
*/


#include "adjList.h"

adjList::adjList()
{
    //ctor
}

adjList::~adjList()
{

}
adjList::adjList(int numOfAirportss){
    numOfAirports = numOfAirportss;
    airports = new Airport[numOfAirportss];
    for(int i = 0; i < numOfAirportss; i++){
        airports[i].setId(i);
    }
}


//insert two way flight.
void adjList::addFlight(int airPortOne, int airPortTwo, int duration){
    airports[airPortOne].addFlight(airports[airPortTwo].getId(), duration);
    airports[airPortTwo].addFlight(airports[airPortOne].getId(), duration);
    std::cout<<"Inserted a new flight between "<<airPortOne<<" and "<<airPortTwo<<std::endl;
    int numOfFlights = 0;
    while(airports[airPortOne].getCurrentFlight()){
        numOfFlights++;
        airports[airPortOne].nextFlight();
    }
    airports[airPortOne].reset();
    std::cout<<"    Number of flights from "<<airPortOne<<" is "<<numOfFlights<<std::endl;
}


void adjList::List(int airPortNum){
    airports[airPortNum].List();
}


int adjList::shortestPath(int startingAirport, int destination, bool print){
    Airport currentAirport;
    int knownDistances[numOfAirports];
    bool visitedAirports[numOfAirports];
    for(int i = 0; i < numOfAirports; i++){
        knownDistances[i] = MAX_INT;
        visitedAirports[i] = false;
    }
    knownDistances[startingAirport] = 0;
    visitedAirports[startingAirport] = true;
    airports[startingAirport].setCost(0);
    MinHeap heap;
    while(airports[startingAirport].getCurrentFlight()){
        airports[airports[startingAirport].getCurrentFlight()->getDestination()].setCost(airports[startingAirport].getCurrentFlight()->getCost());
        heap.heapInsert(airports[airports[startingAirport].getCurrentFlight()->getDestination()]);
        airports[airports[startingAirport].getCurrentFlight()->getDestination()].setPrev(startingAirport);
        airports[startingAirport].nextFlight();

    }
    while(!heap.heapIsEmpty()){
        heap.heapDelete(currentAirport);
        if(currentAirport.getKey() > knownDistances[currentAirport.getId()]){
            continue;
        }
        int id = currentAirport.getId();
        visitedAirports[currentAirport.getId()] = true;

        while(airports[id].getCurrentFlight()){
            //std::cout<<"here"<<std::endl;

            if(airports[id].getCurrentFlight()->getCost() + airports[id].getKey() <
               airports[airports[id].getCurrentFlight()->getDestination()].getKey()
            ){
                airports[airports[id].getCurrentFlight()->getDestination()].setCost(airports[id].getCurrentFlight()->getCost() + airports[id].getKey());

                knownDistances[airports[id].getCurrentFlight()->getDestination()] = airports[id].getCurrentFlight()->getCost() + airports[id].getKey();
                airports[airports[id].getCurrentFlight()->getDestination()].setPrev(currentAirport.getId());
                //std::cout<<"here"<<std::endl;
                if(!visitedAirports[airports[id].getCurrentFlight()->getDestination()]){
                    heap.heapInsert(airports[airports[id].getCurrentFlight()->getDestination()]);
                }

            }
            airports[id].nextFlight();
        }

    }
    if(visitedAirports[destination]){
        int prev;
        int cur = destination;
        if(print){
            std::string print = "";
            std::cout<<" shortest path from "<<startingAirport<< " to " <<destination<<std::endl;
            while(cur != startingAirport){
                prev =  airports[cur].getPrev();
                //std::cout<<"from "<<cur<<" to "<< prev<< " with a duration of " << airports[cur].getKey() - airports[prev].getKey()<<std::endl;
                std::string oneLine = "   from " + std::to_string(prev) + " to " + std::to_string(cur) + " with a duration of " + std::to_string(airports[cur].getKey() - airports[prev].getKey()) + "\n";
                print = oneLine + print;
                cur = prev;
            }
            std::cout<<print<<std::endl;
            std::cout<<"total cost: "<<airports[destination].getKey()<<std::endl;
        }
    }
    else{
        if(print){
            std::cout<<"there is no path from "<<startingAirport<<" to "<<destination<<std::endl;
        //std::cout<<knownDistances[destination]<<std::endl;
        }

    }
    knownDistances[destination] = airports[destination].getKey();
    for(int i = 0; i < numOfAirports; i++){
        airports[i].reset();
    }
    return knownDistances[destination];
}

void adjList::minimize(int flightNo, Airport newAirports[], int& cost, bool visitedAirports[]){
    //Flight* fligg;
    int costBefore = 0;
    int costAfter = 0;
    //bool visitedAirports[numOfAirports];
    MinHeap2 heap;
    //this should be minimum spanning tree
    //Airport newAirports[numOfAirports];
    for(int i = 0; i < numOfAirports; i++){
        newAirports[i].setId(i);
    }

    for(int i = 0; i < numOfAirports; i++){
        while(airports[i].getCurrentFlight()){
            costBefore = costBefore + airports[i].getCurrentFlight()->getCost();
            airports[i].nextFlight();
        }
        //visitedAirports[i] = false;
    }
   ;

    for(int i = 0; i < numOfAirports; i++){
        airports[i].reset();
    }


    //mark vertex 0 as visited and include it in minimum spanning tree
    visitedAirports[flightNo] = true;
    while(airports[flightNo].getCurrentFlight()){

        heap.heapInsert(*(airports[flightNo].getCurrentFlight()));
        airports[flightNo].nextFlight();

    }

    //std::cout<<"here4"<<std::endl;
    while(!heap.heapIsEmpty()){
        Flight flig;
        heap.heapDelete(flig);
        //Airport neww;
        if(visitedAirports[flig.getDestination()]){
            continue;
        }
        //Airport new;
        newAirports[flig.getDestination()].addFlight(flig.from, flig.getCost());
        newAirports[flig.getStarting()].addFlight(flig.to, flig.getCost());
        visitedAirports[flig.getDestination()] = true;
        int visitedAirportNum = flig.getDestination();
        //std::cout<<"here6"<<std::endl;
        while(airports[visitedAirportNum].getCurrentFlight()){
            //if(visitedAirports[airports[visitedAirportNum].getCurrentFlight()->getDestination()]  == false){
            heap.heapInsert(*airports[visitedAirportNum].getCurrentFlight());
            airports[visitedAirportNum].nextFlight();
            //std::cout<<"here7"<<std::endl;
        }

    }
    cost = costBefore;
     //std::cout<<"here5"<<std::endl;

}

void adjList::minimize(){
    bool* visitedAirports = new bool[numOfAirports];
    for(int i = 0; i < numOfAirports; i++){
        visitedAirports[i] = false;
    }
    Airport* news = new Airport[numOfAirports];
    int cost;
    //std::cout<<"here2"<<std::endl;
    this->minimize(0, news, cost, visitedAirports);
    //std::cout<<"here"<<std::endl;
    int costAfter = 0;
    std::cout<<"total cost of operations before minimization: "<<cost / 2<<std::endl;

    for(int i = 1; i<numOfAirports; i++){
        if(this->shortestPath(0, i, false) > 9999998){
            minimize(i, news, cost, visitedAirports);
        }
    }
    //std::cout<<"here6"<<std::endl;
    for(int i = 0; i < numOfAirports; i++){
        while(news[i].getCurrentFlight()){
            costAfter = costAfter + news[i].getCurrentFlight()->getCost();
            news[i].nextFlight();
        }
    }
    for(int i = 0; i < numOfAirports; i++){
        news[i].reset();
    }
    delete[] airports;
    airports = news;
    std::cout<<"total cost of operations after minimization: "<<costAfter / 2<<std::endl;
    delete[] visitedAirports;
}

/*int main(){
    adjList graph(5);
    graph.addFlight(0, 1, 2);
    //std::cout<<"1"<<std::endl;
    graph.addFlight(0, 2, 3);
    graph.addFlight(0, 4, 6);
    graph.addFlight(1, 2, 6);
    //std::cout<<"2"<<std::endl;
    graph.List(2);
    graph.shortestPath(2, 3, true);
    //std::cout<<"3"<<std::endl;
    graph.addFlight(3, 4, 3);
    graph.shortestPath(2, 3, true);
    graph.addFlight(1, 3, 6);
    graph.List(2);
    graph.shortestPath(2, 3, true);
    graph.minimize();
    graph.List(2);

    //std::cout<<"4"<<std::endl;
    return 0;
}
*/
