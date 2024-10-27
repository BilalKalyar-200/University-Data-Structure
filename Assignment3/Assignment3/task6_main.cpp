//TASK IS--->
//Provide a C++ implementation of AVL tree using Templates that must include :
// Recursive Height
// Finding Balancing Factor
// RR_Rotation
// LL_Rotation
// RL_Rotation
// LR_Rotation
// AVL node deletion
// AVL node insertion
// Display Nodes
//Test All Functions.It must Run on All user defined Inputs.
//You should consider the data of published research papers in a journal.The data in a node include
//the title, authors name, publication date, publication id.The primary data to create BST in this case
//is the publication id(integer data).
//TEMPLATE BASED AVL IMPLEMENTATION
//#include<iostream>
//using namespace std;
//#include "task6.h"
//
//int main() {
//    AVL<int> obj;
//    while (true) 
//    {
//        cout << "1.Insert\n2.Delete\n3.Height\n4.Isempty\n5.inorder\n6.Preorder\n7.Postorder\n8.Exit\n";
//        int ch;
//        cin >> ch;
//        if (ch == 1) 
//        {
//            int data;
//            cout << "Enter data: ";
//            cin >> data;
//            node<int>* ptr = new node<int>(data);
//            obj.root = obj.insert(obj.root, ptr);
//            obj.inorder(obj.root);
//            cout << endl;
//        }
//        else if (ch == 2) 
//        {
//            cout << "Enter value to delete: ";
//            int val; cin >> val;
//            node<int>* temp = obj.delete_node(obj.root, val);
//            if (temp) {
//                cout << "Node with " << val << " data deleted\n";
//            }
//            else cout << "Node was not found\n";
//        }
//        else if (ch == 3) 
//        {
//            cout << "height of tree is: " << obj.height(obj.root) << endl;
//        }
//        else if (ch == 4) {
//            if (obj.isempty()) {
//                cout << "Tree is empty\n";
//            }
//            else {
//                cout << "not empty\n";
//            }
//        }
//        else if (ch == 5)
//        {
//            obj.inorder(obj.root);
//            cout << endl;
//        }
//        else if (ch == 6) 
//        {
//            obj.preorder(obj.root);
//            cout << endl;
//        }
//        else if (ch == 7) {
//            obj.postorder(obj.root);
//            cout << endl;
//        }
//        else if (ch == 8) 
//        {
//            break;
//        }
//        else cout << "Enter valie choice\n";
//    }
//    return 0;
//}
