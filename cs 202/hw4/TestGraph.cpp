/*
* Title: CS202 Spring 2022 hw4
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 4
* Description: this is class to implement main function
*/


#include "TestGraph.h"

TestGraph::TestGraph()
{
    //ctor
}

TestGraph::~TestGraph()
{

}


void TestGraph::operate(std::string textureFile ) {

    std::ifstream stream;
    stream.open(textureFile);
    //HeapItemType* tasks;

    int totalNumOfAirports;
    int totalNumOfOrders;

    stream >> totalNumOfAirports;
    Graph g(totalNumOfAirports);
    stream >> totalNumOfOrders;
    //tasks = new HeapItemType[totalTask];
    for (int orderSoFar = 0; orderSoFar < totalNumOfOrders; orderSoFar ++){
        std::string opcode;
        int in1 = 0;
        int in2 = 0;
        int in3 = 0;
        stream >> opcode;
        if(opcode == "I"){
            stream >> in1;
            stream >> in2;
            stream >> in3;
            g.addFlight(in1, in2, in3);
        }
        else if(opcode == "L"){
            stream >> in1;
            g.List(in1);
        }
        else if(opcode == "S"){
            stream >> in1;
            stream >> in2;
            g.shortestPath(in1, in2);
        }
        else if(opcode == "M"){
            g.minimize();
        }
        else{
            std::cout<<"the opcode may be wrong"<<std::endl;
        }
    }
}
int main( int arguementNum, char* arguements[]
         )

{

    TestGraph test;
    std:: string textureFile(arguements[1]);
	//test.operate("test.txt");
	test.operate(textureFile);
    return 0;
}
