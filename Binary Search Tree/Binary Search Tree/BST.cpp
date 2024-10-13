// THIS PROGRAM USES LINKED LIST TO CREATE BINARY SEARCH(BST)
// IN THIS TYPE OF TREE WE INSERT THE VALUE AT LEFT THAT IS SMALLER THAN ITS PARENT NODE
// AND INSERT THE VALUE AT RIGHT THAT IS GREATER THAN ITS PARENT NODE
// IN THIS PROGRAM I ADDED ALMOST ALL FUNCTIONS THAT CAN HELP US TO UDNERSTAND THE USE OF BST EFFECTIVELY
// WE HAVE INSERTION, DELETION, MULTIPLE PRINTING FUNCTIONS, ETC...

#include<iostream>
using namespace std;
const int space_2D = 10;
class node {
public:
	node* left, * right;
	int data;
	node() {
		left = right = NULL;
		data = 0;
	}
	node(int val) {
		left = right = nullptr;
		data = val;
	}
};
class BST {
public:
	node* root;
	BST() {
		root = NULL;
	}
	bool isempty() {
		return root == NULL;
	}

	void insert(node* ptr)
	{
		if (root == NULL) {
			root = ptr;
			return;
		}
		node* temp = root;
		while (temp)
		{
			if (temp->data == ptr->data) {
				cout << "Cannot add dublicates\n";
				return;
			}
			else if (ptr->data < temp->data && temp->left == NULL)
			{
				temp->left = ptr;
				return;
			}
			else if (ptr->data < temp->data) {
				temp = temp->left;
			}
			else if (ptr->data > temp->data && temp->right == NULL)
			{
				temp->right = ptr;
				return;
			}
			else {
				temp = temp->right;
			}
		}
	}
	void delete_smallest_in_right(node*& ptr, int& new_val)
	{
		if (ptr->left == NULL)
		{
			new_val = ptr->data;
			node* temp = ptr;
			ptr = ptr->right;
			delete temp;

		}
		else {
			delete_smallest_in_right(ptr->left, new_val);
		}

	}
	void deletenode(node* ptr, int val)
	{
		if (ptr == NULL)
			return;
		//traversing to find the node to delete
		if (val < ptr->data)
		{
			deletenode(ptr->left, val);
		}
		else if (val > ptr->data)
		{
			deletenode(ptr->right, val);
		}
		else { //means ptr->val== val
			//case1:
			if (ptr->left == NULL && ptr->right == NULL)//leaf node (no child)
			{
				delete ptr;
				ptr = NULL;
				return;
			}

			//case2:(one child)
			if (ptr->left == NULL)//if only right child
			{
				node* temp = ptr; //this child will be placed in correct place from main function
				ptr = ptr->right;
				delete temp;
				return;
			}
			if (ptr->right == NULL)//if only left child
			{
				node* temp = ptr; //this child will be placed in correct place from main function
				ptr = ptr->left;
				delete temp;
			}

			//case3:(two childs)
			int new_val;
			delete_smallest_in_right(ptr->right, new_val);
			ptr->data = new_val;

		}

	}
	bool search(int val)
	{
		if (isempty())
		{
			cout << "tree is empty\n";
			return false;
		}
		node* temp = root;
		while (temp)
		{
			if (temp->data == val) {
				return true;
			}
			else if (temp->data > val) {
				temp = temp->left;
			}
			else temp = temp->right;
		}
		return false;
	}
	node* recusive_search(node* n, int val)
	{
		if (n == NULL)
			return n;
		else if (n->data == val)
			return n;
		else if (n->data > val)
			recusive_search(n->left, val);
		else recusive_search(n->right, val);
	}
	void preoder_traverse(node* ptr) //it prints in preorder way (Root-Left-Right)
		//means it will first print root node and then left child and then right child
	{
		if (ptr == NULL)
			return;
		cout << ptr->data << " ";
		preoder_traverse(ptr->left);
		preoder_traverse(ptr->right);
	}
	void inorder_traverse(node* ptr) //it prints in inorder way (Left-Root-Right)
		//means it will first print Left child and then root node and then right child
	{
		if (ptr == NULL)
			return;
		inorder_traverse(ptr->left);
		cout << ptr->data << " ";
		inorder_traverse(ptr->right);
	}
	void postorder_traverse(node* ptr) //it prints in post order way (Left-Right-Root)
		//means it will first print Left child and then right child and then root node
	{
		if (ptr == NULL)
			return;
		postorder_traverse(ptr->left);
		postorder_traverse(ptr->right);
		cout << ptr->data << " ";
	}
	//This prints the root node at left most side
	//And above that node are its right childs
	//And below that node are its left childs
	void print(node* r, int space)
	{
		if (r == NULL)
			return;
		space += space_2D;
		print(r->right, space);
		cout << endl;
		for (int i = space_2D; i < space; i++)
		{
			cout << " ";
		}
		cout << r->data << endl;
		print(r->left, space);
	}
};
int main()
{
	BST obj;
	while (true)
	{
		cout << "1.Insert\n2.Delete\n3.Search\n4.Recurive search\n5.print\n6.CLS\n";
		int ch; cin >> ch;
		node* ptr = new node;
		if (ch == 1)
		{
			cout << "Enter value to inert: ";
			int val; cin >> val;
			ptr->data = val;
			obj.insert(ptr);
			cout << endl;
		}
		else if (ch == 2)
		{
			cout << "Enter value of node to delte: ";
			int val; cin >> val;
			if (!obj.search(val)) {
				cout << "This value is not in tree\n";
				continue;
			}
			else obj.deletenode(obj.root, val);
		}
		else if (ch == 3)
		{
			cout << "Enter value to search: ";
			int val; cin >> val;
			if (obj.search(val))
			{
				cout << "value found\n";
			}
			else cout << "Value not found\n";
		}
		else if (ch == 4)
		{
			cout << "Enter value to search: ";
			int val; cin >> val;
			node* temp = obj.recusive_search(obj.root, val);
			if (temp == NULL)
				cout << "Value not found\n";
			else cout << "value found\n\b";
		}
		else if (ch == 5)
		{
			system("cls");
			cout << "1.Simple print\n2.Pre order traversal\n3.In order traversal\n4.Post order traversal\n";
			int ch2; cin >> ch2;
			if (ch2 == 1)
				obj.print(obj.root, 5); //this 5 is just number of spaces between nodes (horizontally and vertically)
			else if (ch2 == 2)
				obj.preoder_traverse(obj.root);
			else if (ch2 == 3)
				obj.inorder_traverse(obj.root);
			else if (ch2 == 4)
				obj.postorder_traverse(obj.root);
			else {
				cout << "Enter valid choice";
				continue;
			}
			cout << endl;
		}
		else if (ch == 6)
		{
			system("cls");
		}
		else {
			cout << "Enter valid value\n";
			continue;
		}
	}
}
