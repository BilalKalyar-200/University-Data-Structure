////The task is to convert a sorted array into BST tree of minimal height

//#include "task2.h"
//#include<iostream>
//using namespace std;
//int main() {
//    BST obj;
//
//    cout << "Enter size of array: ";
//    int size;
//    cin >> size;
//
//    cout << "Enter " << size << " elements of array: ";
//    int* arr = new int[size];
//    for (int i = 0; i < size; i++) {
//        cin >> arr[i];
//    }
//
//    sort_array(arr, size);
//
//    cout << "Array after sorting: ";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    obj.root = obj.array_to_BST(arr, 0, size - 1);
//
//    cout << "Inorder traversal: ";
//    obj.inorder(obj.root);
//    cout << endl;
//
//    cout << "Postorder traversal: ";
//    obj.postorder(obj.root);
//    cout << endl;
//
//    cout << "Preorder traversal: ";
//    obj.preorder(obj.root);
//    cout << endl;
//
//    delete[] arr;
//    return 0;
//}
