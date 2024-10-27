////You are tasked with merging two AVL trees,
////representing different subsets of transaction amounts, into a single AVL tree while
////maintaining the AVL tree properties.
//#include "task7.h"
//#include<iostream>
//using namespace std;
//int main() {
//    AVL obj1, obj2, combine;
//
//	while (true)
//	{
//		cout << "1.insert into tree 1\n";
//		cout << "2.insert into tree 2\n";
//		cout << "3.display tree 1\n";
//		cout << "4.display tree 2\n";
//		cout << "5.Combine tree 1 and Tree 2\n";
//		cout << "6.Display Combined Tree\n";
//		cout << "7.Exit\n";
//		int choice; cin >> choice;
//
//		if (choice == 1)
//		{
//			int data;
//			cout << "Enter value: ";
//			cin >> data;
//			obj1.insert(data);
//		}
//		else if (choice == 2)
//		{
//			int data;
//			cout << "Enter value: ";
//			cin >> data;
//			obj2.insert(data);
//		}
//		else if (choice == 3)
//		{
//			cout << "Tree 1: ";
//			obj1.inorder(obj1.root);
//			cout << endl;
//		}
//		else if (choice == 4)
//		{
//			cout << "Tree 2: ";
//			obj2.inorder(obj2.root);
//			cout << endl;
//
//		}
//		else if (choice == 5)
//		{
//			combine = obj1.combine(obj1, obj2);
//			cout << "Trees combined\n";
//		}
//		else if (choice == 6)
//		{
//			cout << "Combined Tree: ";
//			combine.inorder(combine.root);
//			cout << endl;
//
//		}
//		else if (choice == 7) {
//			break;
//		}
//		else {
//			cout << "enter valid choide\n";
//		}
//	}
//	return 0;
//
//}
