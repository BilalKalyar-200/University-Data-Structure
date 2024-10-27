//#include "task4.h"
//
//node::node() {
//	left = right = NULL;
//	data = 0;
//}
//
//doublycircular::doublycircular() {
//	head = NULL;
//}
//
//void doublycircular::insert(int data)
//{
//	node* ptr = new node;
//	ptr->data = data;
//	if (ptr == NULL)
//		return;
//	if (head == NULL) {
//		head = ptr;
//		head->right = head;
//		head->left = head;
//	}
//	else if (head->data >= ptr->data) 
//	{		//checking if head needs to be moved
//		node* tail = head->left;
//		ptr->left = tail;
//		ptr->right = head;
//		tail->right = ptr;
//		head->left = ptr;
//		head = ptr;
//	}
//	else {
//		//in middle or at last
//		node* temp = head;
//		while (temp->right != head && temp->right->data < ptr->data) {
//			temp = temp->right;
//		}
//		ptr->right = temp->right;
//		ptr->left = temp;
//		temp->right->left = ptr;
//		temp->right = ptr;
//	}
//}
//
//void doublycircular::display()
//{
//	if (head == NULL) {
//		cout << "Nothing to display\n";
//		return;
//	}
//	node* temp = head;
//	do {
//		cout << "Data: " << temp->data << " ";
//		temp = temp->right;
//	} while (temp != head);
//	cout << endl;
//}
//
//BST::BST() {
//	root = NULL;
//}
//
//void BST::insert(node*& root, int data) 
//{
//	node* newnode = new node;
//	newnode->data = data;
//	insert(root, newnode);
//}
//
//node* BST::insert(node*& rr, node*& ptr) 
//{
//	if (rr == NULL) {
//		rr = ptr;
//		return rr;
//	}
//	if (rr->data > ptr->data) {
//		rr->left = insert(rr->left, ptr);
//	}
//	else if (rr->data < ptr->data) {
//		rr->right = insert(rr->right, ptr);
//	}
//	else {
//		cout << "Dublicates are not allowed\n";
//		return nullptr;
//	}
//	return rr;
//}
//
//void BST::inorder(node* ptr) {
//	if (ptr != NULL) {
//		inorder(ptr->left);
//		cout << ptr->data << " ";
//		inorder(ptr->right);
//	}
//}
//
//void BST::BST_to_doubly(node* ptr, doublycircular& obj) 
//{
//	if (ptr != NULL) {
//		BST_to_doubly(ptr->left, obj);
//		obj.insert(ptr->data);
//		BST_to_doubly(ptr->right, obj);
//	}
//}
