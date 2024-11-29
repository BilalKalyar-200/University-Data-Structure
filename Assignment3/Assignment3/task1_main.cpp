//#include "task1.h"
//#include <iostream>
//using namespace std;
//
//int main() 
//{
//    BST obj;
//    int choice, value;
//
//    do {
//        cout << "\n--- Menu ---\n";
//        cout << "1.Insert\n";
//        cout << "2.Search\n";
//        cout << "3.display inorder\n";
//        cout << "4.display postorder\n";
//        cout << "5.display preorder\n";
//        cout << "6.Exit\n";
//        cin >> choice;
//
//        if (choice == 1) 
//        {
//            cout << "Enter value: ";
//            cin >> value;
//            obj.insert(obj.root, value);
//
//        }
//        else if (choice == 2) 
//        {
//            cout << "Enter value to search: ";
//            cin >> value;
//            if (obj.search(obj.root, value) != NULL) 
//            {
//                cout << "Value found\n";
//            }
//            else {
//                cout << "Value not found\n";
//            }
//
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
//            cout << "Postorder Traversal: ";
//            obj.postorder(obj.root);
//            cout << endl;
//
//        }
//        else if (choice == 5)
//        {
//            cout << "Preorder Traversal: ";
//            obj.preorder(obj.root);
//            cout << endl;
//
//        }
//        else if (choice == 6) 
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
