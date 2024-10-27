//In this task we have to convert a BST into doubly circular linked list that is sorted and follows
////inorder traversal of BST
//#include "task4.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    BST obj;
//    doublycircular dll;
//    bool convertedToDLL = false;
//
//    while (true) 
//    {
//        cout << "\n1.insert\n";
//        cout << "2.Display BST\n";
//        cout << "3.Convert BST to linked list\n";
//        cout << "4.Display doubly circular list\n";
//        cout << "5.Exit\n";
//        int choice, data;
//        cin >> choice;
//
//        if (choice == 1) 
//        {
//            cout << "Enter data: ";
//            cin >> data;
//            obj.insert(obj.root, data);
//            convertedToDLL = false;     //to set it as false bcz we need to convert again to make sure new value also include
//        }
//        else if (choice == 2)
//        {
//            cout << "BST Inorder Traversal: ";
//            obj.inorder(obj.root);
//            cout << endl;
//        }
//        else if (choice == 3) 
//        {
//            if (!convertedToDLL) 
//            {
//                obj.BST_to_doubly(obj.root, dll);
//                convertedToDLL = true;
//                cout << "Conversion successful\n";
//            }
//            else {
//                cout << "already converted\n";
//            }
//        }
//        else if (choice == 4) 
//        {
//            cout << "Doubly Circular Linked List: ";
//            dll.display();
//            cout << endl;
//        }
//        else if (choice == 5)
//        {
//            break;
//        }
//        else {
//            cout << "enter valid choice\n";
//        }
//    }
//
//    return 0;
//}
