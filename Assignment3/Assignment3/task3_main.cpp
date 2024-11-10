//// main.cpp
//#include <iostream>
//#include "task3.h"
//#include "task3_queue.h"
//#include "max_sum.h"
//
//using namespace std;
//
//int main()
//{
//    Queue queue;
//    Node* root = NULL;
//
//    while (true)
//    {
//        cout << "1.Enter value\n";
//        cout << "2.Create tree\n";
//        cout << "3.Max path sum\n";
//        cout << "4.Exit\n";
//        int ch;
//        cin >> ch;
//
//        if (ch == 1)
//        {
//            cout << "Enter node value to enqueue (-1 for null): ";
//            int val;
//            cin >> val;
//            queue.enqueue(new Node(val));
//
//        }
//        else if (ch == 2)
//        {
//            if (queue.isEmpty())
//            {
//                cout << "Queue is empty\n";
//            }
//            else
//            {
//                root = create_tree(queue);
//                cout << "Tree created.\n";
//            }
//
//        }
//        else if (ch == 3)
//        {
//            if (root)
//            {
//                cout << "maximum path um: " << max_sum_path(root) << endl;
//            }
//            else
//            {
//                cout << "Nothing in tree\n";
//            }
//
//        }
//        else if (ch == 4)
//        {
//            break;
//        }
//        else
//        {
//            cout << "Enter valid choice\n";
//        }
//    }
//
//    return 0;
//}
