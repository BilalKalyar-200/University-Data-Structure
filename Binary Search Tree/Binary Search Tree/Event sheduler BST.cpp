#include<iostream>
using namespace std;
class node {
public:
	node* left, * right;
	string data;
	node() {
		left = right = NULL;
		data = "";
	}
	node(string d) {
		left = right = NULL;
		data = d;
	}
};
class BST {
public:
	int count;
	node* root;
	BST() {
		count = 0;
		root = NULL;
	}
	bool isempty() {
		return root == NULL;
	}
	void insert(string data)
	{
		node* ptr = new node(data);
		if (isempty())
		{
			root = ptr;
			return;
		}
		node* temp = root;
		while (temp)
		{
			if (temp->data == ptr->data)
			{
				cout << "Dublicates not allowed\n";
				return;
			}
			else if (temp->data > ptr->data)
			{
				if (temp->left == NULL)
				{
					temp->left = ptr;
					count++;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL)
				{
					temp->right = ptr;
					count++;
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	void find_min_left(node*& ptr, string& d)
	{
		if (ptr->left == NULL)
		{
			d = ptr->data;
			node* temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else {
			find_min_left(ptr->left, d);
		}
	}
	void delete_node(node*& ptr, string d)
	{
		if (ptr == NULL)
		{
			return;
		}
		//traversing to find the node to delete
		if (ptr->data > d)
		{
			delete_node(ptr->left, d);
		}
		else if (ptr->data < d)
		{
			delete_node(ptr->right, d);
		}
		//means we found node(ptr->data==d)
		else {
			count--;
			//case1:
			//no child
			if (ptr->left == NULL && ptr->right == NULL)
			{
				delete ptr;
				ptr = NULL;
				return;
			}
			//case2: 
			//only one child
			if (ptr->left == NULL)
			{
				node* temp = ptr;
				ptr = ptr->right;
				delete temp;
				return;
			}
			if (ptr->right == NULL)
			{
				node* temp = ptr;
				ptr = ptr->left;
				delete temp;
				return;
			}
			//case3:
			//if two childs
			find_min_left(ptr->right, d);
			ptr->data = d;
		}
	}
	node* search(node* ptr, string n)
	{
		if (ptr == NULL)
			return NULL;
		if (ptr->data == n)
			return ptr;
		else if (ptr->data > n)
			search(ptr->left, n);
		else search(ptr->right, n);
	}
	int leaf_count(node* ptr) 
	{
		if (ptr == NULL)
			return 0;
		//if leaf node found
		if (ptr->left == NULL && ptr->right == NULL)
			return 1;

		return leaf_count(ptr->left) + leaf_count(ptr->right);
	}
	int getlength()
	{
		return count;
	}
	void preoder_traverse(node* ptr)//root-left-right
	{
		if (ptr == NULL)
			return;
		cout << ptr->data << " ";
		preoder_traverse(ptr->left);
		preoder_traverse(ptr->right);
	}
	void inorder_traverse(node* ptr)//left-root-right
	{
		if (ptr == NULL)
			return;
		inorder_traverse(ptr->left);
		cout << ptr->data << " ";
		inorder_traverse(ptr->right);
	}
	void postorder_traverse(node* ptr)//left-right-root
	{
		if (ptr == NULL)
			return;
		postorder_traverse(ptr->left);
		postorder_traverse(ptr->right);
		cout << ptr->data << " ";
	}

};

int main()
{
	BST obj;
	while (true)
	{
		cout << "1.Insert\n2.Delete\n3.Search\n4.print\n5.count leaf node\n6.length\n7.Exit\n8.Exit\n9.CLS\n";
		int ch; cin >> ch;
		if (ch == 1)
		{
			cout << "Enter value to inert: ";
			string val; cin >> val;
			obj.insert(val);
			cout << endl;
		}
		else if (ch == 2)
		{
			cout << "Enter value of node to delte: ";
			string val; cin >> val;
			node* temp = obj.search(obj.root, val);
			if (temp == NULL)
			{
				cout << "This value is not in tree\n";
				continue;
			}
			else obj.delete_node(obj.root, val);
		}
		else if (ch == 3)
		{
			cout << "Enter value to search: ";
			string val; cin >> val;
			node* temp = obj.search(obj.root, val);
			if (temp != NULL)
			{
				cout << "value found\n";
			}
			else cout << "Value not found\n";
		}
		else if (ch == 4)
		{
			system("cls");
			cout << "1.Pre order traversal\n2.In order traversal\n3.Post order traversal\n";
			int ch2; cin >> ch2;
			if (ch2 == 1)
				obj.preoder_traverse(obj.root);
			else if (ch2 == 2)
				obj.inorder_traverse(obj.root);
			else if (ch2 == 3)
				obj.postorder_traverse(obj.root);
			else {
				cout << "Enter valid choice";
				continue;
			}
			cout << endl;
		}
		else if (ch == 5)
		{
			cout << "number of leaf nodes are: " << obj.leaf_count(obj.root) << endl;
		}
		else if (ch == 6)
		{
			cout << "length is: " << obj.getlength() << endl;
		}
		else if (ch == 7)
		{
			system("cls");
		}
		else if (ch == 8) break;
		else {
			cout << "Enter valid choice\n";
			continue;
		}
	}
}