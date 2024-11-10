//#include "task8.h"
//
//#include <iostream>
//using namespace std;
//int main()
//{
//    AVL_song obj;
//    while (true) {
//        cout << "\n1.Insert new song\n2.Delete song\n3.Play song\n4.Display all songs\n5.Exit\n";
//        int ch; cin >> ch;
//        if (ch == 1) 
//        {
//            cout << "Enter frequency: ";
//            int f; cin >> f;
//            cout << "Enter name: ";
//            string n; cin >> n;
//            obj.insert(n, f);
//        }
//        else if (ch == 2) 
//        {
//            cout << "Enter name of song to delete: ";
//            string n; int f;
//            cin >> n;
//            f = obj.find_frequency(obj.root, n);
//            if (f == -1)
//            {
//                cout << "Song not found\n";
//            }
//            else {
//                obj.root = obj.delete_node(obj.root, f, n);
//            }
//        }
//        else if (ch == 3) 
//        {
//            cout << "Enter name of song to play: ";
//            string n; cin >> n;
//            cout << "Enter its frequency: ";
//            int f; cin >> f;
//            obj.play(f, n);
//        }
//        else if (ch == 4) 
//        {
//            obj.inorder(obj.root);
//        }
//        else if (ch == 5)
//        {
//            break;
//        }
//        else {
//            cout << "Enter a valid choice\n";
//        }
//    }
//    return 0;
//}
