////THIS IS BASIC PROGRAM THAT USES MOST IMPORATNT AVL TREE FUNCTIONS TO SHOW HOW AVL WORKS AND WHAT ARE ITS PROPERTIES
//#include<iostream>
//using namespace std;
//class node {
//public:
//	node* left, * right;
//	int data;
//	node() {
//		left =right = NULL;
//		data = 0;
//	}
//};
//class AVL {
//	node* root;
//public:
//	AVL() {
//		root = NULL;
//	}
//	int height(node* ptr) {
//		if (ptr == NULL) {
//			return -1;
//		}
//		else {
//			int left_hegiht = height(ptr->left);
//			int right_height = height(ptr->right);
//			if (left_hegiht > right_height) {
//				return (left_hegiht + 1);
//			}
//			else return (right_height + 1);
//		}
//	}
//	int get_balance(node* ptr) {
//		if (ptr == NULL) {
//			return -1;		//if node child
//		}
//		else return (height(ptr->left) - height(ptr->right));
//	}
//	node* right_rot(node* ptr)
//	{
//		node* temp = ptr->left;
//		node* temp2 = temp->right;
//
//		temp->right = ptr;
//		ptr->left = temp2;
//		return temp;	//new root
//	}
//	bool isempty() {
//		return root == NULL;
//	}
//	node* left_rot(node* ptr)
//	{
//		node* temp = ptr->right;
//		node* temp2 = temp->left;
//
//		ptr->right = temp2;
//		temp->left = ptr;
//		return temp;
//	}
//	node* insert(node* rr,node* ptr)
//	{
//		if (rr == NULL)
//		{
//			rr = ptr;
//			return rr;
//		}
//		if (ptr->data < rr->data)
//		{
//			rr->left = insert(rr->left, ptr);
//		}
//		else if (ptr->data > rr->data) {
//			rr->right = insert(rr->right, ptr);
//		}
//		else {
//			cout << "No dublicates are allowed\n";
//			return NULL;
//		}
//		int balacne = get_balance(rr);
//		if (balacne > 1 && ptr->data < rr->left->data)	//IF OUT OF BALANCE AND BY CHECKING VALUES WE SEE ITS LEFT DISORDER
//		{
//			return right_rot(rr);
//		}
//		if (balacne < -1 && ptr->data > rr->right->data)	//IF OUT OF BALANCE AND BY CHECKING VALUES WE SEE ITS RIGHT DISORDER
//		{
//			return left_rot(rr);
//		}
//		if (balacne > 1 && ptr->data > rr->left->data)	//IF OUT OF BALANCE AND ALSO DATA SO RL ROTATION
//		{
//			rr->left = left_rot(rr->left);
//			return right_rot(rr);
//		}
//		if (balacne< -1 && ptr->data < ptr->right->data)
//		{
//			rr->right = right_rot(rr->right);
//			return left_rot(rr);
//		}
//		return rr;
//	}
//	bool is_AVL(node* ptr) 
//	{
//		if (ptr == NULL) 
//		{
//			return true;
//		}
//		int balance = get_balance(ptr);
//		if (balance > 1 || balance < -1) 
//		{
//			return false;
//		}
//		return is_AVL(ptr->left) && is_AVL(ptr->right);
//	}
//	void inorder_traversal(node* ptr) {
//		if (ptr != NULL)
//		{
//			inorder_traversal(ptr->left);
//			cout << ptr->data << " ";
//			inorder_traversal(ptr->right);
//		}
//	}
//	node* getroot()
//	{
//		return root;
//	}
//	void setroot(node* p) {
//		root = p;
//	}
//	void inserter(int val)
//	{
//		node* ptr = new node;
//		ptr->data = val;
//		root = insert(root, ptr);
//	}
//};
//
//int main()
//{
//	AVL obj;
//	while (true)
//	{
//		cout << "1.Insert\n2.Delete\n3.Print\n";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter value: ";
//			int val; cin >> val;
//			obj.inserter(val);
//		}
//		else if (ch == 2)
//		{
//
//		}
//		else if (ch == 3)
//		{
//			obj.inorder_traversal(obj.getroot());
//			cout << endl;
//		}
//	}
//}
//
//
//
// // avl trees
//
//
//
//
//
//
//
