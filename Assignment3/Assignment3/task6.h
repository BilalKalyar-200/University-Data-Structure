#pragma once
#include<iostream>

using namespace std;
template<class T>
class node {
public:
    node<T>* left, * right;
    T data;

    node();
    node(T data);
};

template<class T>
class AVL {
public:
    node<T>* root;
    AVL();
    int height(node<T>* ptr);
    int get_balance(node<T>* ptr);
    node<T>* right_rot(node<T>* ptr);
    node<T>* left_rot(node<T>* ptr);
    bool isempty();
    void get_min_right(node<T>*& ptr, T& d);
    node<T>* delete_node(node<T>*& ptr, T d);
    node<T>* insert(node<T>* rr, node<T>* ptr);
    void inorder(node<T>* ptr);
    void preorder(node<T>* ptr);
    void postorder(node<T>* ptr);
};

/*template<class T>
node<T>::node() {
    data = 0;
    left = right = NULL;
}

template<class T>
node<T>::node(T data) : data(data) {
    left = right = NULL;
}

template<class T>
AVL<T>::AVL() {
    root = NULL;
}

template<class T>
int AVL<T>::height(node<T>* ptr)
{
    if (ptr == NULL) {
        return -1;
    }
    else {
        int left_height = height(ptr->left);
        int right_height = height(ptr->right);
        if (left_height > right_height)
        {
            return 1 + left_height;
        }
        else return 1 + right_height;
    }
}

template<class T>
int AVL<T>::get_balance(node<T>* ptr)
{
    if (ptr == NULL) {
        return -1;
    }
    return height(ptr->left) - height(ptr->right);
}

template<class T>
node<T>* AVL<T>::right_rot(node<T>* ptr)
{
    node<T>* temp = ptr->left;
    node<T>* temp2 = temp->right;
    temp->right = ptr;
    ptr->left = temp2;
    return temp;
}

template<class T>
node<T>* AVL<T>::left_rot(node<T>* ptr)
{
    node<T>* temp = ptr->right;
    node<T>* temp2 = temp->left;
    ptr->right = temp2;
    temp->left = ptr;
    return temp;
}

template<class T>
bool AVL<T>::isempty() {
    return root == NULL;
}

template<class T>
void AVL<T>::get_min_right(node<T>*& ptr, T& d)
{
    if (ptr->left == NULL)
    {
        d = ptr->data;
        node<T>* temp = ptr;
        ptr = ptr->right;
        delete temp;
    }
    else {
        get_min_right(ptr->left, d);
    }
}

template<class T>
node<T>* AVL<T>::delete_node(node<T>*& ptr, T d) {
    if ((ptr == NULL))
    {
        cout << "Nothing to delete\n";
        return NULL;
    }
    if (ptr->data > d) {
        ptr->left = delete_node(ptr->left, d);
    }
    else if (ptr->data < d)
    {
        ptr->right = delete_node(ptr->right, d);
    }
    else {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            delete ptr;
            ptr = NULL;
            return root;
        }
        if (ptr->left == NULL)
        {
            node<T>* temp = ptr->right;
            delete ptr;
            return temp;
        }
        if (ptr->right == NULL)
        {
            node<T>* temp = ptr->left;
            delete ptr;
            return temp;
        }
        get_min_right(ptr->right, d);
        ptr->data = d;
        int balance = get_balance(ptr);
        if (balance == 2 && get_balance(ptr->left) >= 0) {
            return right_rot(ptr);
        }
        else if (balance == 2 && get_balance(ptr->left) == -1) {
            ptr->left = left_rot(ptr->left);
            return right_rot(ptr);
        }
        else if (balance == -2 && get_balance(ptr->right) <= 0) {
            return left_rot(ptr);
        }
        else if (balance == -2 && get_balance(ptr->right) == 1) {
            ptr->right = right_rot(ptr->right);
            return left_rot(ptr);
        }
    }
    return ptr;
}

template<class T>
node<T>* AVL<T>::insert(node<T>* rr, node<T>* ptr)
{
    if (rr == nullptr) {
        return ptr;
    }
    if (ptr->data < rr->data)

    {
        rr->left = insert(rr->left, ptr);
    }
    else if (ptr->data > rr->data)
    {
        rr->right = insert(rr->right, ptr);
    }
    else {
        cout << "NO duplicates are allowed\n";
        return rr;
    }
    int balance = get_balance(rr);
    if (balance > 1 && ptr->data < rr->left->data)
    {
        return right_rot(rr);
    }
    if (balance < -1 && ptr->data > rr->right->data)
    {
        return left_rot(rr);
    }
    if (balance > 1 && ptr->data > rr->left->data)
    {
        rr->left = left_rot(rr->left);
        return right_rot(rr);
    }
    if (balance < -1 && ptr->data < rr->right->data) {
        rr->right = right_rot(rr->right);
        return left_rot(rr);
    }
    return rr;
}

template<class T>
void AVL<T>::inorder(node<T>* ptr)
{
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->data << endl;
        inorder(ptr->right);
    }
}

template<class T>
void AVL<T>::preorder(node<T>* ptr)
{
    if (ptr != NULL) {
        cout << ptr->data << endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

template<class T>
void AVL<T>::postorder(node<T>* ptr)
{
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << endl;
    }
}*/
