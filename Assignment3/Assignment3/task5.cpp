//#include "task5.h"
//#include <iostream>
//using namespace std;
//
//node::node()
//{
//    left = right = NULL;
//    data = 0;
//}
//
//BST::BST() {
//    root = NULL;
//}
//
//void BST::insert(node*& root, int data)
//{
//    node* newnode = new node;
//    newnode->data = data;
//    insert(root, newnode);
//}
//
//node* BST::insert(node*& rr, node*& ptr)
//{
//    if (rr == NULL) {
//        rr = ptr;
//        return rr;
//    }
//    if (rr->data > ptr->data)
//    {
//        rr->left = insert(rr->left, ptr);
//    }
//    else if (rr->data < ptr->data)
//    {
//        rr->right = insert(rr->right, ptr);
//    }
//    else {
//        cout << "Duplicate are not allowed\n";
//        return nullptr;
//    }
//    return rr;
//}
//
//
//
//void BST::inorder(node* ptr)
//{
//    if (ptr != NULL) {
//        inorder(ptr->left);
//        cout << ptr->data << " ";
//        inorder(ptr->right);
//    }
//}
//int BST::key_finder(node* ptr, int key, int& count)
//{
//    if (ptr != NULL) 
//    {
//        int L_chcker = key_finder(ptr->left, key, count); //searching in left
//        if (L_chcker != -1)
//            return L_chcker;
//
//        count++;
//        if (count == key) 
//        {
//            return ptr->data; //found that element
//        }
//
//        //searching in right    
//        return key_finder(ptr->right, key, count);
//    }
//    return -1;
//}
//
//
//
//int BST::counter = 0;