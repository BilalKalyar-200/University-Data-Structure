////You are working on a search engine optimization project for a large e - commerce platform.
////The platform uses a Binary Search Tree(BST) to manage and retrieve product prices
////efficiently.To enhance the user experience, the platform needs to display the kth smallest
////price among the available products.
//
//#include "task5.h"
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    BST obj;
//    int choice;
//
//    do {
//        cout << "1.Insert\n";
//        cout << "2.Find key\n";
//        cout << "3.display inorder\n";
//        cout << "4.Exit\n";
//        cin >> choice;
//
//        if (choice == 1) 
//        {
//            cout << "Enter value: ";
//            int value; cin >> value;
//            obj.insert(obj.root, value);
//
//        }
//        else if (choice == 2) 
//        {
//            cout << "Enter key to search element corresponding to that: ";
//            int key; cin >> key; int count = 0;
//            cout << "The " << key << "th smallest emelent is: " << obj.key_finder(obj.root, key, count) << endl;
//        }
//        else if (choice == 3) 
//        {
//            cout << "Inorder Traversal: ";
//            obj.inorder(obj.root);
//            cout << endl;
//
//        }
//        else if (choice == 4) 
//        {
//            break;
//        }
//        else {
//            cout << "Enter valid choice\n";
//        }
//    } while (choice != 6);
//
//    return 0;
//}
//
