//#include "task7.h"
//#include<iostream>
//using namespace std;
//node::node()
//{
//    left = NULL;
//    right = NULL;
//    data = 0;
//}
//
//node::node(int data) 
//{
//    this->data = data;
//    left = right = NULL;
//}
//
//AVL::AVL() {
//    root = NULL;
//}
//
//int AVL::height(node* ptr)
//{
//    if (ptr == NULL)
//    {
//        return -1;
//    }
//    int l_height = height(ptr->left);
//    int R_height = height(ptr->right);
//    if (l_height > R_height)
//    {
//        return l_height + 1;
//    }
//    else return R_height + 1;
//}
//
//int AVL::get_balance(node* ptr)
//{
//    if (ptr == NULL) return -1;
//    return height(ptr->left) - height(ptr->right);
//}
//
//node* AVL::right_rot(node* ptr)
//{
//    node* temp = ptr->left;
//    node* temp2 = temp->right;
//
//    temp->right = ptr;
//    ptr->left = temp2;
//    return temp;
//}
//
//node* AVL::left_rot(node* ptr) 
//{
//    node* temp = ptr->right;
//    node* temp2 = temp->left;
//
//    ptr->right = temp2;
//    temp->left = ptr;
//    return temp;
//}
//
//bool AVL::isempty() 
//{
//    return root == NULL;
//}
//
//void AVL::get_min_from_right(node*& ptr, int& d) 
//{
//    if (ptr->left == NULL) 
//    {
//        d = ptr->data;
//        node* temp = ptr;
//        ptr = ptr->right;
//        delete temp;
//    }
//    else {
//        get_min_from_right(ptr->left, d);
//    }
//}
//
//void AVL::insert(int data) 
//{
//    node* ptr = new node(data);
//    root = insert(root, ptr);
//}
//
//node* AVL::insert(node* r, node* ptr)
//{
//    if (r == NULL) return ptr;
//
//    if (ptr->data < r->data) {
//        r->left = insert(r->left, ptr);
//    }
//    else if (ptr->data > r->data) 
//    {
//        r->right = insert(r->right, ptr);
//    }
//    else {
//        cout << "duplicates not allowed\n";
//        return r;
//    }
//
//    int balance = get_balance(r);
//
//    if (balance > 1 && ptr->data < r->left->data)
//    {
//        return right_rot(r);
//    }
//    if (balance < -1 && ptr->data > r->right->data) {
//        return left_rot(r);
//    }
//    if (balance > 1 && ptr->data > r->left->data) 
//    {
//        r->left = left_rot(r->left);
//        return right_rot(r);
//    }
//    if (balance < -1 && ptr->data < r->right->data) {
//        r->right = right_rot(r->right);
//        return left_rot(r);
//    }
//
//    return r;
//}
//
//void AVL::inorder(node* ptr) 
//{
//    if (ptr != NULL) {
//        inorder(ptr->left);
//        cout << ptr->data << " ";
//        inorder(ptr->right);
//    }
//}
//
//AVL AVL::combine(AVL& T1, AVL& T2) 
//{
//    AVL result;
//    inorder_insert(result, T1.root);
//
//    inorder_insert(result, T2.root);
//    return result;
//}
//
//void AVL::inorder_insert(AVL& new_tree, node* ptr) 
//{
//    if (ptr != nullptr) {
//        inorder_insert(new_tree, ptr->left);
//        new_tree.insert(ptr->data);
//        inorder_insert(new_tree, ptr->right);
//    }
//}
