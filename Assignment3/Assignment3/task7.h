//#pragma once
//
//
//class node {
//public:
//    node* left, * right;
//    int data;
//    node();
//    node(int data);
//};
//
//class AVL {
//public:
//    node* root;
//    AVL();
//    int height(node* ptr);
//    int get_balance(node* ptr);
//    node* right_rot(node* ptr);
//    node* left_rot(node* ptr);
//    bool isempty();
//    void get_min_from_right(node*& ptr, int& d);
//    void insert(int data);
//    node* insert(node* r, node* ptr);
//    void inorder(node* ptr);
//    AVL combine(AVL& T1, AVL& T2);
//    void inorder_insert(AVL& new_tree, node* ptr);
//};