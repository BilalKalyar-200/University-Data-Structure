//#pragma once
//
//#include "task3.h"
//#include <iostream>
//using namespace std;
//class queueue
//{
//public:
//    Node* treeNode;
//    queueue* next;
//
//    queueue(Node* node) {
//        treeNode = node;
//        next = NULL;  
//    }
//};
//
//class Queue {
//private:
//    queueue* front;
//    queueue* rear;
//
//public:
//    Queue() {
//        front = NULL;  
//        rear = NULL;   
//    }
//
//    bool isEmpty() {
//        return front == NULL;  
//    }
//
//    void enqueue(Node* node)
//    {
//        queueue* newNode = new queueue(node);
//        if (rear) {
//            rear->next = newNode;
//        }
//        else {
//            front = newNode;
//        }
//        rear = newNode;
//    }
//
//    Node* dequeue()
//    {
//        if (isEmpty())
//        {
//             cout << "Queue is empty" <<  endl;
//            return NULL;  
//        }
//        queueue* temp = front;
//        Node* treeNode = front->treeNode;
//        front = front->next;
//        if (front == NULL) {
//            rear = NULL;  
//        }
//        delete temp;
//        return treeNode;
//    }
//};
//
