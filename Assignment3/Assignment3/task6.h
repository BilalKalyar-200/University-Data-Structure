//#pragma once
//#include<iostream>
//using namespace std;
//template<class t>
//class node {
//public:
//    node<t>* left, * right;
//    t data;
//
//    node();
//    node(t data);
//};
//
//template<class t>
//class avl {
//public:
//    node<t>* root;
//    avl();
//    int height(node<t>* ptr);
//    int get_balance(node<t>* ptr);
//    node<t>* right_rot(node<t>* ptr);
//    node<t>* left_rot(node<t>* ptr);
//    bool isempty();
//    void get_min_right(node<t>*& ptr, t& d);
//    node<t>* delete_node(node<t>*& ptr, t d);
//    node<t>* insert(node<t>* rr, node<t>* ptr);
//    void inorder(node<t>* ptr);
//    void preorder(node<t>* ptr);
//    void postorder(node<t>* ptr);
//};
//
//template<class t>
//node<t>::node() {
//    data = 0;
//    left = right = NULL;
//}
//
//template<class t>
//node<t>::node(t data) : data(data) {
//    left = right = NULL;
//}
//
//template<class t>
//avl<t>::avl() {
//    root = NULL;
//}
//
//template<class t>
//int avl<t>::height(node<t>* ptr)
//{
//    if (ptr == NULL) {
//        return -1;
//    }
//    else {
//        int left_height = height(ptr->left);
//        int right_height = height(ptr->right);
//        if (left_height > right_height)
//        {
//            return 1 + left_height;
//        }
//        else return 1 + right_height;
//    }
//}
//
//template<class t>
//int avl<t>::get_balance(node<t>* ptr)
//{
//    if (ptr == NULL) {
//        return -1;
//    }
//    return height(ptr->left) - height(ptr->right);
//}
//
//template<class t>
//node<t>* avl<t>::right_rot(node<t>* ptr)
//{
//    node<t>* temp = ptr->left;
//    node<t>* temp2 = temp->right;
//    temp->right = ptr;
//    ptr->left = temp2;
//    return temp;
//}
//
//template<class t>
//node<t>* avl<t>::left_rot(node<t>* ptr)
//{
//    node<t>* temp = ptr->right;
//    node<t>* temp2 = temp->left;
//    ptr->right = temp2;
//    temp->left = ptr;
//    return temp;
//}
//
//template<class t>
//bool avl<t>::isempty() {
//    return root == NULL;
//}
//
//template<class t>
//void avl<t>::get_min_right(node<t>*& ptr, t& d)
//{
//    if (ptr->left == NULL)
//    {
//        d = ptr->data;
//        node<t>* temp = ptr;
//        ptr = ptr->right;
//        delete temp;
//    }
//    else {
//        get_min_right(ptr->left, d);
//    }
//}
//
//template<class t>
//node<t>* avl<t>::delete_node(node<t>*& ptr, t d) {
//    if ((ptr == NULL))
//    {
//        cout << "nothing to delete\n";
//        return NULL;
//    }
//    if (ptr->data > d) {
//        ptr->left = delete_node(ptr->left, d);
//    }
//    else if (ptr->data < d)
//    {
//        ptr->right = delete_node(ptr->right, d);
//    }
//    else {
//        if (ptr->left == nullptr && ptr->right == nullptr)
//        {
//            delete ptr;
//            ptr = NULL;
//            return root;
//        }
//        if (ptr->left == NULL)
//        {
//            node<t>* temp = ptr->right;
//            delete ptr;
//            return temp;
//        }
//        if (ptr->right == NULL)
//        {
//            node<t>* temp = ptr->left;
//            delete ptr;
//            return temp;
//        }
//        get_min_right(ptr->right, d);
//        ptr->data = d;
//        int balance = get_balance(ptr);
//        if (balance == 2 && get_balance(ptr->left) >= 0) {
//            return right_rot(ptr);
//        }
//        if (balance == 2 && get_balance(ptr->left) == -1) {
//            ptr->left = left_rot(ptr->left);
//            return right_rot(ptr);
//        }
//        if (balance == -2 && get_balance(ptr->right) <= 0) {
//            return left_rot(ptr);
//        }
//        if (balance == -2 && get_balance(ptr->right) == 1) {
//            ptr->right = right_rot(ptr->right);
//            return left_rot(ptr);
//        }
//    }
//    return ptr;
//}
//
//template<class t>
//node<t>* avl<t>::insert(node<t>* rr, node<t>* ptr)
//{
//    if (rr == nullptr) {
//        return ptr;
//    }
//    if (ptr->data < rr->data)
//
//    {
//        rr->left = insert(rr->left, ptr);
//    }
//    else if (ptr->data > rr->data)
//    {
//        rr->right = insert(rr->right, ptr);
//    }
//    else {
//        cout << "no duplicates are allowed\n";
//        return rr;
//    }
//    int balance = get_balance(rr);
//    if (balance > 1 && ptr->data < rr->left->data)
//    {
//        return right_rot(rr);
//    }
//    if (balance < -1 && ptr->data > rr->right->data)
//    {
//        return left_rot(rr);
//    }
//    if (balance > 1 && ptr->data > rr->left->data)
//    {
//        rr->left = left_rot(rr->left);
//        return right_rot(rr);
//    }
//    if (balance < -1 && ptr->data < rr->right->data) {
//        rr->right = right_rot(rr->right);
//        return left_rot(rr);
//    }
//    return rr;
//}
//
//template<class t>
//void avl<t>::inorder(node<t>* ptr)
//{
//    if (ptr != NULL) {
//        inorder(ptr->left);
//        cout << ptr->data << endl;
//        inorder(ptr->right);
//    }
//}
//
//template<class t>
//void avl<t>::preorder(node<t>* ptr)
//{
//    if (ptr != NULL) {
//        cout << ptr->data << endl;
//        preorder(ptr->left);
//        preorder(ptr->right);
//    }
//}
//
//template<class t>
//void avl<t>::postorder(node<t>* ptr)
//{
//    if (ptr != NULL) {
//        postorder(ptr->left);
//        postorder(ptr->right);
//        cout << ptr->data << endl;
//    }
//}
