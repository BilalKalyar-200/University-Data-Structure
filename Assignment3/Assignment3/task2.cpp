//#include "task2.h"
//#include <iostream>
//using namespace std;
//
//node::node() {
//    left = right = NULL;
//    data = 0;
//}
//
//// BST constructor
//BST::BST() {
//    root = NULL;
//}
//
//// Convert sorted array to BST with minimal height
//node* BST::array_to_BST(int* arr, int start, int end) 
//{
//    if (start > end) 
//    {
//        return NULL;
//    }
//    int mid = (start + end) / 2;
//    node* ptr = new node;
//    ptr->data = arr[mid];
//    ptr->left = array_to_BST(arr, start, mid - 1);
//    ptr->right = array_to_BST(arr, mid + 1, end);
//    return ptr;
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
//    if (ptr != NULL) 
//    {
//        cout << ptr->data << " ";
//        preorder(ptr->left);
//        preorder(ptr->right);
//    }
//}
//
//void sort_array(int* arr, int size) 
//{
//    for (int i = 0; i < size - 1; i++) 
//    {
//        for (int j = 0; j < size - i - 1; j++) 
//        {
//            if (arr[j] > arr[j + 1]) 
//            {
//
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
