/*
* Title: Trees
* Author: Oðuz Kuyucu
* ID: 21902683
* Section: 1
* Assignment: 2
* Description: implementation of binary search tree
*/


#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    head = NULL;
    indexx = -1;
}

BinarySearchTree::~BinarySearchTree()
{
    //dtor
}
/*struct Node(int val){
    int val = value
    Node* parent = NULL;
    Node* leftChild = NULL;
    Node* rightChild = NULL;
    int size = 0;
};
*/
bool BinarySearchTree::add(int newEntry){
    if(newEntry <= 0){
        return false;
    }

    BinaryNode* newEnt = new BinaryNode(newEntry);
    if(head == NULL){
        head = newEnt;
        return true;
    }
    else{
        return addNode(newEnt, head);
    }

}
bool BinarySearchTree::addNode(BinaryNode* newEnt, BinaryNode* parent){
    if(newEnt->value == parent->value){
        delete newEnt;
        return false;
    }
    else if(newEnt-> value > parent->value){
        if(parent->rightChild == NULL){
            parent->rightChild = newEnt;
            newEnt->parent = parent;
            BinaryNode* current;
            current = parent;
            while(current != NULL){
                int size = current->size;
                size++;
                current->size = size;
                current = current->parent;
            }
            //std::cout<<newEnt->value<<" is added to the right of " <<parent->value<<std::endl;
            //parent->size = parent->size+1;
            return true;
        }
        else{
            return addNode(newEnt, parent->rightChild);
        }
    }
    else{
        if(parent->leftChild == NULL){
            parent->leftChild = newEnt;
            newEnt->parent = parent;
            BinaryNode* current;
            current = parent;
            while(current!= NULL){
                int size = current->size;
                size++;
                current->size = size;
                current = current->parent;
            }
            //parent->size = parent->size + 1;
            return true;
        }
        else{
            return addNode(newEnt, parent->leftChild);
        }
    }
}
bool BinarySearchTree::remove(int anEntry){
    BinaryNode* successor;
    BinaryNode* cur = head;
    BinaryNode* par;
    if(head == NULL){
        return false;
    }
    //remove the head
    if(anEntry == head->value){
        if(head->leftChild == NULL && head->rightChild == NULL){
            head->size = 0;
            BinaryNode* poi = head;
            head = NULL;
            delete poi;
            //delete head;
            //head->value = NULL;
            //head = NULL;
            return true;
        }
        else if(head->leftChild == NULL){
            BinaryNode* poi = head;
            head = head->rightChild;
            head->parent = NULL;
            delete poi;
            //Node* temp = head->rightChild;
            //int size = head->size - 1;
            //delete head;
            //head = temp;
            //head->size = size;
            return true;
        }
        else if(head->rightChild == NULL){
            BinaryNode* poi = head;
            head = head->leftChild;
            head->parent = NULL;
            delete poi;
            //Node* temp = head->leftChild;
            //int size = head->size - 1;
            //delete head;
            //head = temp;
            //head->size = size;
            return true;
        }
        else{
            successorOfNode(successor, head);
            head->value = successor-> value;
            //head->size = head->size - 1;
            par = successor->parent;
            if(par->value > successor->value){
                par->leftChild = successor->rightChild;
                if(successor->rightChild){
                    successor->rightChild->parent = par;
                }
            }
            else{
                par->rightChild = successor->rightChild;
                if(successor->rightChild){
                    successor->rightChild->parent = par;
                }
            }
            while(par){
                par->size = par->size -1;
                par = par->parent;
            }
            //successor->parent = NULL;
            delete successor;
            return true;
        }
    }
    //it is not head, then, look for node
    while(cur != NULL){
        if(anEntry > cur->value){
            cur = cur->rightChild;
        }
        else if(anEntry < cur->value){
            cur = cur->leftChild;
        }
        else //if(anEntry == cur->value){
        {

            if(cur->leftChild == NULL && cur->rightChild == NULL){
                par = cur->parent;
                //if(par){
                    if(par->value < anEntry){
                        par->rightChild = NULL;
                    }
                    else{
                        par->leftChild = NULL;
                    }
                //}
                while(par){
                    par->size = par->size -1;
                    par = par->parent;
                }
                //std::cout<<"deleted"<<std::endl;
                cur->parent = NULL;
                delete cur;
                return true;
            }

            else if(cur->leftChild == NULL){
                int size = cur->size;
                par = cur->parent;
                //if(par){
                    if(par->value < anEntry){
                        par->rightChild = cur->rightChild;
                        //cur->rightChild->parent = par;
                    }
                    else{
                        par->leftChild = cur->rightChild;
                        //cur->rightChild->parent = par;
                    }
                //}
                while(par){
                    par->size = par->size -1;
                    par = par->parent;
                }
                cur->rightChild->parent = cur->parent;
                cur->parent = NULL;
                delete cur;
                return true;
            }
            else if(cur->rightChild == NULL){

                par = cur->parent;
                BinaryNode* par2 = cur->parent;

                //if(par){
                    if(par->value < anEntry){
                        par->rightChild = cur->leftChild;
                    }
                    else{
                        par->leftChild = cur->leftChild;
                    }

                //}

                while(par){
                    par->size = par->size -1;
                    par = par->parent;
                }
                cur->leftChild->parent = cur->parent;
                cur->parent = NULL;
                delete cur;
                return true;
            }
            else{
                //par = cur->parent;
                BinaryNode* par2 = cur->parent;
                int a;
                a = successorOfNode(successor, cur);
                par = successor->parent;
                BinaryNode* par3 = successor->parent;
                //std::cout<<"here for "<<anEntry<<std::endl;
                if(a == -1){
                    return false;
                }
                //std::cout<<"123"<<std::endl;
                //std::cout<<"here for "<<anEntry<<"  "<<successor->parent->value <<std::endl;
                while(par){
                    par->size = par->size -1;
                    par = par->parent;
                    //std::cout<<"par is  "<<par->value<<std::endl;
                }
                //std::cout<<"14342"<<std::endl;
                //par->parent->size = par->parent->size - 1;
                //std::cout<<"here forrrrr "<<anEntry<<std::endl;

                /*if(a == -2){
                    std::cout<<"done"<<std::endl;
                    par2->rightChild = cur->leftChild;
                    cur->leftChild->parent = par2;
                    delete cur;
                    return true;
                }
                */
                int size = cur->size;
                //std::cout<<"here for "<<anEntry<<std::endl;
                //std::cout<<successor->value<<std::endl;
                //cur->value = successor->value;


                /*if(par2){
                    if(par2->value < anEntry){
                        par2->rightChild->value = successor->value;
                        successor->size = size - 1;
                        par2->rightChild->size = size;
                    }
                    else{
                        par2->leftChild->value = successor->value;
                        successor->size = size - 1;
                        par2->leftChild->size = size;
                        }
                }
                */
                //std::cout<<"heree"<<std::endl;
                cur->value = successor->value;

                //successor->leftChild = cur->leftChild;
                //successor->parent->leftChild = successor->leftChild;
                //successor->parent = par2;
                if(par3->value > successor->value){
                    par3->leftChild = successor->rightChild;
                    if(successor->rightChild){
                        successor->rightChild->parent = par3;
                    }
                }
                else{
                    par3->rightChild = successor->rightChild;
                    if(successor->rightChild){
                        successor->rightChild->parent = par3;
                    }
                }
                //std::cout<<"hereeee"<<std::endl;
                //successor->parent = NULL;
                delete successor;
                return true;
            }
        }
    }
    return false;
}
bool BinarySearchTree::contains(int anEntry){
    BinaryNode* current = head;
    if(current->value == anEntry){
        return true;
    }
    while(current){
        if(anEntry > current->value){
            if(current->rightChild){
                current = current->rightChild;
            }
            else{
                return false;
            }
        }
        else if(anEntry < current->value){
            if(current->leftChild){
                current = current->leftChild;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    return true;
}
void BinarySearchTree::inorderTraverse(){
    int index;
    if(head == NULL){
        std::cout<<"the tree is empty"<<std::endl;
        return;
    }
    inorderTraverse(head);

}
int BinarySearchTree::getWidth(){
    /*int height = getHeight();
    int[height] arr;
    if(isEmpty){
        return 0;
    }
    arr[0] = 1;
    for(int i = 1; i <= height; i++){

    }*/
    return getWidthOfTree(head);
}
int BinarySearchTree::count(int a, int b){
    int count = 0;
    inorderTraverseCount(head, a, b, count);
    return count;
}
int BinarySearchTree::select(int anEntry){
    //Node* cur;
    //int a = -1;
    /*while(cur != NULL){
        posOfSmallest = posOfSmallest + 1;
        cur = cur->leftChild;
    }
    */


    //std::cout<<"here"<<std::endl;
    //inorderTraverseSelect(head, anEntry, a);
    //int a = indexx;
    //indexx = -1;
    //return a;
    BinaryNode* cur;
    cur = head;
    int index;
    if(head->leftChild){
        index = head->leftChild->size + 1;
    }
    else{
        index = 0;
    }
    while(cur){
        if(cur->value == anEntry){
            return index;
        }
        else if(cur->value > anEntry){
            cur = cur->leftChild;
            if(cur){
                if(cur->rightChild){
                    index = index -( cur->rightChild->size + 1);
                }
            }
            index = index - 1;
        }
        else{
            cur = cur->rightChild;
            if(cur){
                if(cur->leftChild){
                    index = index + (cur->leftChild->size + 1);
                }
            }
            index  = index + 1;
        }
    }
    return -1;
}
int BinarySearchTree::successor(int anEntry){
    BinaryNode* cur = head;
    BinaryNode* n;
    while(cur){
        if(anEntry > cur->value){
            cur = cur->rightChild;
        }
        else if(anEntry < cur->value){
            cur= cur->leftChild;
        }
        else if(anEntry == cur->value){
            return (successorOfNode(n, cur));
        }
    }
    return -1;
}
bool BinarySearchTree::isEmpty(){
    if(head){
        return false;
    }
    return true;
}
int BinarySearchTree::getHeight(){
    int height = 2;
    BinaryNode* cur = head;

    if(isEmpty()){
        return 0;
    }
    else{
        return heightOfNode(head, height);
        //return height;
    }
}
int BinarySearchTree::getNumberOfNodes(){
    if(!isEmpty()){
        return head->size + 1;
    }
    return 0;
}
int BinarySearchTree::successorOfNode(BinaryNode*& successor, BinaryNode* nod){
    BinaryNode* cur = nod;
    if(cur->rightChild == NULL){
        while(cur->parent){
            cur = cur->parent;
            if(cur->value > nod->value){
                successor = cur;
                return cur->value;
            }
        }
        successor = nod;
        return -2;
    }
    else{
        nod = nod->rightChild;
        while(nod->leftChild){
            nod = nod->leftChild;
        }
        successor = nod;
        return successor->value;
    }
}
void BinarySearchTree::inorderTraverse(BinaryNode* node){
    if(node != NULL){
        inorderTraverse(node->leftChild);
        std::cout<<node->value<<std::endl;
        inorderTraverse(node->rightChild);
    }
}
void BinarySearchTree::inorderTraverseSelect(BinaryNode* node, int value, int& a){
    /*if(node != NULL){
        select = select - 1;
        inorderTraverseSelect(node->leftChild, value, select );
        select = select + 1;
        if(node->value == value){
            return select;

        }
        select = select + 1;
        inorderTraverseSelect(node->rightChild, value, select);
    }
    return -1;
    */
    //index = index + 1;
    if(node != NULL){
        if(node->leftChild)
            inorderTraverseSelect(node->leftChild, value, a);
        indexx = indexx + 1;
        if(node->value == value){
            a = indexx;
            return;
        }
        if(node->rightChild)
            inorderTraverseSelect(node->rightChild, value, a);

    }
    //std::cout<<"-1"<<std::endl;
    return;
}
int BinarySearchTree::inorderTraverseCount(BinaryNode* node, int a, int b, int& count){
    if(node != NULL){

        inorderTraverseCount(node->leftChild,a, b, count );

        if(node->value > a && node->value < b){
            count = count + 1;
        }

        inorderTraverseCount(node->rightChild,a, b, count );
    }
    return count;
}
int BinarySearchTree::heightOfNode(BinaryNode* cur, int height){
    if(cur == NULL){
        return 0;
    }
    /*int leftHeight = 0;
    int rightHeight = 0;
    if(cur->leftChild != NULL){
        //height = height + 1;
        cur = cur->leftChild;
        leftHeight = heightOfNode(cur, height) + 1;
    }
    if(cur->rightChild != NULL){
        //height = height + 1;
        cur = cur->rightChild;
        rightHeight = heightOfNode(cur, height) + 1;
    }
    if(rightHeight > leftHeight){
        return rightHeight;
    }
    return leftHeight;
    */
    int leftDepth = heightOfNode(cur->leftChild, height);
    int rightDepth = heightOfNode(cur->rightChild, height);
    if(leftDepth > rightDepth){
        return leftDepth + 1;
    }
    return rightDepth + 1;
}
int BinarySearchTree::getWidthOfTree(BinaryNode* head){
    int heig;
    int zero = 0;
    heig = heightOfNode(head, zero);

    int widthSoFar;
    int width = 0;
    for (int heightSoFar = 1; heightSoFar <= heig; heightSoFar++) {
        widthSoFar = getWidthOfHeight(head, heightSoFar);
        if (widthSoFar > width)
            width = widthSoFar;
    }

    return width;
}
int BinarySearchTree::getWidthOfHeight(BinaryNode* head, int height){
    //base
    if (head == NULL){
        return 0;
    }
    if (height == 1){
        return 1;
    }
    //recursive
    else if (height > 1){
        int widthOfRightOfHeight = getWidthOfHeight(head->rightChild, height - 1);
        int widthOfLeftOfHeight = getWidthOfHeight(head->leftChild, height - 1);
        return widthOfRightOfHeight + widthOfLeftOfHeight;
    }
    return -2;
}
void BinarySearchTree::inorderTraverse(BinaryNode* node, int index){
    static int a = 0;
    if(node != NULL){
        if(node->leftChild)
            inorderTraverse(node->leftChild, index);
        std::cout<<node->value<<"   index:"<<a<<std::endl;
        a++;
        if(node->rightChild)
            inorderTraverse(node->rightChild,index );
    }
}
/* analyzeBST(){
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
*/

/*int main(){
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
