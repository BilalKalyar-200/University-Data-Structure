//this is a quiz qeustion. They asked for basic binary tree functions
//
//
//
//#include<iostream>
//using namespace std;
//class node {
//public:
//	node* left, * right;
//	int data;
//	node(int d = 0) {
//		left = right = NULL;
//		data = d;
//	}
//};
//class binarytree {
//public:
//	node* root;
//	binarytree() {
//		root = NULL;
//	}
//	bool isempty()
//	{
//		return root == NULL;
//	}
//	void insert(int d)
//	{
//		node* ptr = new node(d);
//		if (isempty())
//		{
//			root = ptr;
//			return;
//		}
//		node* temp = root;
//		while (temp)
//		{
//			if (temp->data == ptr->data)
//			{
//				cout << "Dublicates not allowed\n";
//				delete ptr;
//				return;
//			}
//			if (temp->data > ptr->data)
//			{
//				if (temp->left == NULL)
//				{
//					temp->left = ptr;
//					return;
//				}
//				else {
//					temp = temp->left;
//				}
//			}
//			else {
//				if (temp->right == NULL)
//				{
//					temp->right = ptr;
//					return;
//				}
//				else {
//					temp = temp->right;
//				}
//			}
//		}
//
//	}
//	void find_min_left(node*& ptr, int& d)
//	{
//		if (ptr->left == NULL)
//		{
//			d = ptr->data;
//			node* temp = ptr;
//			ptr = ptr->right;
//			delete temp;
//		}
//		else {
//			find_min_left(ptr->left, d);
//		}
//	}
//	void delete_node(node*& ptr, int d)		//d is to delete
//	{
//		if (isempty())
//		{
//			cout << "Nothing to delete\n";
//			return;
//		}
//		if (ptr->data > d) {
//			delete_node(ptr->left, d);
//		}
//		else if (ptr->data < d)
//		{
//			delete_node(ptr->right, d);
//		}
//		else {
//			//means ptr->data==data
//			//case1:
//			if (ptr->left == NULL && ptr->right == NULL)
//			{
//				delete ptr;
//				ptr = NULL;
//			}
//			//case2:
//			if (ptr->left == NULL)
//			{
//				node* temp = ptr;
//				ptr = ptr->right;
//				delete temp;
//				return;
//			}
//			if (ptr->right == NULL)
//			{
//				node* temp = ptr;
//				ptr = ptr->left;
//				delete temp;
//				return;
//			}
//			//case3:
//			find_min_left(ptr->right, d);
//			ptr->data = d;
//		}
//	}
//	void inorder(node* ptr)
//	{
//		if (ptr != NULL)
//		{
//			inorder(ptr->left);
//			cout << ptr->data << " ";
//			inorder(ptr->right);
//		}
//	}
//	void preorder(node* ptr)
//	{
//		if (ptr != NULL)
//		{
//			cout << ptr->data << " ";
//			preorder(ptr->left);
//			preorder(ptr->right);
//		}
//	}
//	void postorder(node* ptr)
//	{
//		if (ptr != NULL)
//		{
//			postorder(ptr->left);
//			postorder(ptr->right);
//			cout << ptr->data << " ";
//		}
//	}
//
//	node* search(node* ptr, int data) {
//		if (ptr == NULL) {
//			return NULL;
//		}
//		if (ptr->data == data)
//		{
//			return ptr;
//		}
//		else if (ptr->data > data)
//		{
//			search(ptr->left, data);
//		}
//		else {
//			search(ptr->right, data);
//		}
//
//	}
//	node* search_without_rec(node* ptr, int n) 
//	{
//		while (ptr != NULL) {
//			if (ptr->data == n)
//			{
//				return ptr;
//			}
//			else if (ptr->data > n) 
//			{
//				ptr = ptr->left;
//			}
//			else 
//			{
//				ptr = ptr->right;
//			}
//		}
//		return NULL;
//	}
//	int leaf_count(node* ptr)
//	{
//		if (ptr == NULL)
//			return 0;
//		if (ptr->left == NULL && ptr->right == NULL)
//			return 1;
//
//		return leaf_count(ptr->left) + leaf_count(ptr->right);
//	}
//	int node_counter(node* root)
//	{
//		if (root == NULL)
//			return 0;
//
//		return 1 + node_counter(root->left) + node_counter(root->right);
//	}
//	int depth(node* root)
//	{
//		if (root == NULL)
//			return 0;
//
//		int leftDepth = depth(root->left);
//		int rightDepth = depth(root->right);
//
//		if (leftDepth > rightDepth)
//		{
//			return 1 + leftDepth;
//		}
//		else {
//			return 1 + rightDepth;
//		}
//	}
//	void print_subtree(int d)
//	{
//		node* temp = search_without_rec(root,d);
//		if (temp == NULL)
//		{
//			cout << "Nothing found\n";
//			return;
//		}
//		inorder(temp);
//		cout << endl;
//	}
//};
//int main()
//{
//	binarytree obj;
//	while (true)
//	{
//		cout << "1.Insert\n";
//		cout << "2.Delete\n";
//		cout << "3.Search\n";
//		cout << "4.pre order \n";
//		cout << "5.in order\n";
//		cout << "6.post order\n";
//		cout << "7.count Leaf Nodes\n";
//		cout << "8.count Total Nodes\n";
//		cout << "9.clear Screen\n";
//		cout << "10.Print subtree\n";
//		cout << "11.Exit\n";
//		cout << "Enter your choice: ";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter value to inert: ";
//			int val; cin >> val;
//			obj.insert(val);
//			cout << endl;
//		}
//		else if (ch == 2)
//		{
//			cout << "Enter value of node to delte: ";
//			int val; cin >> val;
//			node* temp = obj.search(obj.root, val);
//			if (temp == NULL)
//			{
//				cout << "This value is not in tree\n";
//				continue;
//			}
//			else obj.delete_node(obj.root, val);
//		}
//		else if (ch == 3)
//		{
//			cout << "Enter value to search: ";
//			int val; cin >> val;
//			node* temp = obj.search(obj.root, val);
//			if (temp != NULL)
//			{
//				cout << "value found\n";
//			}
//			else cout << "value not found\n";
//		}
//		else if (ch == 4)
//		{
//			obj.preorder(obj.root);
//			cout << endl;
//		}
//		else if (ch == 5)
//		{
//			obj.inorder(obj.root);
//			cout << endl;
//
//		}
//		else if(ch==6){
//			obj.postorder(obj.root);
//			cout << endl;
//
//		}
//		else if (ch == 7)
//		{
//			cout << "number of leaf nodes are: " << obj.leaf_count(obj.root) << endl;
//		}
//		else if (ch == 8)
//		{
//			cout << "length is: " << obj.node_counter(obj.root) << endl;
//		}
//		else if (ch == 9)
//		{
//			system("cls");
//		}
//		else if (ch == 10)
//		{
//			cout << "Enter value of the tree to search subtree of: ";
//			int val; cin >> val;
//			obj.print_subtree(val);
//		}
//		else if (ch == 11) break;
//		else {
//			cout << "enter valid choice\n";
//			continue;
//		}
//	}
//}