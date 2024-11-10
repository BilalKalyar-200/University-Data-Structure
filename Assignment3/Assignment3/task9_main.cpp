//Construct BST using preorder and post order
//Traversal. Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a
//binary tree of distinct values and postorder is the postorder traversal of the same tree,
//reconstruct and return the binary tree.


#include <iostream>
#include "task9.h"
using namespace std;

int main() {
    int size;
    binary_tree tree;

    cout << "size of array: ";
    cin >> size;

    int* pre = new int[size];
    int* post = new int[size];

    cout << "enter preorder values: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> pre[i];
    }
    cout << "enter postorder values: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> post[i];
    }

    tree.insert(pre, post, size);
    tree.display();


    return 0;
}
