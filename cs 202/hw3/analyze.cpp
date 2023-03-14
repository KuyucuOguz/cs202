/*
* Title: Trees
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 2
* Description: a class to analyze bst
*/


#include "analyze.h"
#include "BinarySearchTree.h"
analyze::analyze()
{
    //ctor
}

analyze::~analyze()
{
    //dtor
}
void analyzeBST(){
    BinarySearchTree tree;
    int arr[10000];
    for(int i = 0; i < 10000; i++){
        arr[i] = rand() % 400000;
    }
    std::cout<<"random BST size vs height (Insertion)"<<std::endl;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            tree.add(arr[i * 100 + j]);
        }
        std::cout<<tree.getNumberOfNodes()<<"     "<<tree.getHeight()<<std::endl;
    }
    for(int i = 0; i < 4000; i++){
        int a = rand() % 9999;
        int b = rand() % 9999;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    std::cout<<"random BST size vs height (Deletion)"<<std::endl;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            tree.remove(arr[(i * 100) + j]);
            //std::cout<<j<<std::endl;
        }
        //std::cout<<"12345"<<std::endl;
        //std::cout<<tree.getNumberOfNodes()<<"     "<<tree.getHeight()<<std::endl;
        //if(i == 8){
        //    tree.inorderTraverse();
        //}
        std::cout<<tree.getNumberOfNodes()<<"     "<<tree.getHeight()<<std::endl;
    }
    //std::cout<<"12344"<<std::endl;
    //tree.inorderTraverse();
    //std::cout<<tree.getWidth()<<std::endl;
}
/*
//int main(){
    BinarySearchTree tree;
    tree.add(10);
    tree.add(20);
    tree.add(25);
    tree.add(26);
    tree.add(18);
    tree.add(5);
    tree.add(23);
    tree.add(6);
    tree.add(4);
    tree.add(27);
    tree.add(28);
    std::cout<<tree.remove(28)<<std::endl;
    tree.remove(25);
    std::cout<<std::endl;
    tree.inorderTraverse();
    std::cout<<tree.getHeight()<<std::endl;
    std::cout<<tree.getWidth()<<std::endl;
    std::cout<<tree.count(3, 27)<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.contains(28)<<std::endl;
    std::cout<<std::endl;
    tree.inorderTraverse();
    std::cout<<std::endl;
    std::cout<<tree.select(4)<<std::endl;
    std::cout<<tree.select(28)<<std::endl;
    std::cout<<tree.getWidth()<<std::endl;
    tree.add(28);
    std::cout<<tree.getHeight()<<std::endl;
    //tree.remove(28);




    /*tree.add(50);
    tree.add(20);
    tree.add(10);
    tree.add(30);
    tree.add(90);
    tree.add(70);
    tree.add(60);
    tree.add(80);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    */

    //std::cout<<tree.successor(10)<<std::endl;
    //std::cout<<tree.successor(50)<<std::endl;
    //std::cout<<tree.successor(70)<<std::endl;
    //std::cout<<tree.successor(40)<<std::endl;


    /*std::cout<<tree.getNumberOfNodes()<<std::endl;
    tree.inorderTraverse();
    std::cout<<tree.successor(90)<<std::endl;
    //tree.successor(90);
    tree.remove(50);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    tree.remove(90);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    tree.remove(10);
    tree.remove(20);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    tree.remove(20);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
     std::cout<<tree.getHeight()<<std::endl;
    tree.remove(30);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    tree.remove(70);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
     std::cout<<tree.getHeight()<<std::endl;
    tree.remove(60);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    tree.remove(80);
    std::cout<<tree.getNumberOfNodes()<<std::endl;
     std::cout<<tree.getHeight()<<std::endl;
    */
    /*tree.remove(80);
    tree.inorderTraverse();
    tree.remove(90);
    tree.inorderTraverse();
    tree.remove(50);
    tree.inorderTraverse();
    tree.remove(5);
    tree.inorderTraverse();
    std::cout<<std::endl;
    tree.remove(10);
    tree.inorderTraverse();
    tree.remove(70);
    tree.inorderTraverse();
    tree.remove(60);
    tree.inorderTraverse();
    tree.remove(20);
    tree.inorderTraverse();
    tree.remove(30);
    tree.inorderTraverse();
    */

    /*
    tree.add(10);
    tree.add(15);
    tree.add(5);
    tree.add(17);
    tree.add(14);
    //tree.add(12);
    //tree.add(15);
    tree.add(18);
    //std::cout<<tree.successor(10)<<std::endl;
    tree.inorderTraverse();
    //tree.remove(10);
    tree.remove(15);
    tree.inorderTraverse();
    std::cout<<tree.successor(17)<<std::endl;
    tree.remove(17);
    tree.inorderTraverse();
    */

    /*
    */
    /*std::cout<<tree.contains(28)<<std::endl;
    std::cout<<tree.contains(30)<<std::endl;
    std::cout<<tree.select(6)<<std::endl;
    std::cout<<tree.select(18)<<std::endl;
    std::cout<<tree.select(20)<<std::endl;
    std::cout<<tree.select(11)<<std::endl;
    std::cout<<tree.select(4)<<std::endl;
    std::cout<<tree.select(5)<<std::endl;
    std::cout<<tree.select(10)<<std::endl;
    //std::cout<<tree.select(18)<<std::endl;
    tree.remove(4);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<tree.getWidth()<<std::endl;
    */

    //analyzeBST();
    //return 0;
//}

