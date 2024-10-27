//#include "task1.h"
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
//    if (rr->data > ptr->data) {
//        rr->left = insert(rr->left, ptr);
//    }
//    else if (rr->data < ptr->data) {
//        rr->right = insert(rr->right, ptr);
//    }
//    else {
//        cout << "Duplicate are not allowed\n";
//        return nullptr;
//    }
//    return rr;
//}
//
//node* BST::search(node* ptr, int data) 
//{
//    if (ptr == NULL) {
//        return NULL;
//    }
//    if (ptr->data == data) {
//        return ptr;
//    }
//    else if (ptr->data > data) {
//        return search(ptr->left, data);
//    }
//    else {
//        return search(ptr->right, data);
//    }
//}
//
//void BST::inorder(node* ptr) 
//{
//    if (ptr != NULL) {
//        inorder(ptr->left);
//        cout << ptr->data << " ";
//        inorder(ptr->right);
//    }
//}
//
//void BST::postorder(node* ptr) 
//{
//    if (ptr != NULL) {
//        postorder(ptr->left);
//        postorder(ptr->right);
//        cout << ptr->data << " ";
//    }
//}
//
//void BST::preorder(node* ptr)
//{
//    if (ptr != NULL) {
//        cout << ptr->data << " ";
//        preorder(ptr->left);
//        preorder(ptr->right);
//    }
//}
