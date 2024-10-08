#include<iostream>
using namespace std;
class node {
public:
	node* left;
	node* right;
	int data;
	node() {
		left = right = NULL;
		data = 0;
	}

};
class qnode {
public:
	qnode* next;
	node* tree_node;
	qnode(node* n)
	{
		next =  NULL;
		tree_node = n;
	}

};
class queue {
public:
	qnode* front, * rear;
	queue()
	{
		front = rear = NULL;
	}
	void enqueue(node* newnode)
	{
		qnode* ptr = new qnode(newnode);
		if (rear == NULL)
		{
			rear = front = ptr;
		}
		else {
			rear->next = ptr;
			rear = ptr;
		}
	}
	node* dequeue()
	{
		if (isempty())
		{
			return NULL;
		}
		qnode* temp = front;
		node* toret = front->tree_node;
		front = front->next;
		delete temp;
		if (front == NULL)
			rear = NULL;
		return toret;
	}
	bool isempty()
	{
		return front == NULL;
	}
};
class tree {
public:
	node* root;
	tree()
	{
		root = nullptr;
	}
	
	void insert(int val)
	{
		node* ptr = new node;
		ptr->data = val;
		if (root == NULL)
		{
			root = ptr;
			return;
		}
		queue q;
		q.enqueue(root);

		while (!q.isempty())
		{
			node* temp = q.dequeue();
			if (temp->left == nullptr)
			{
				temp->left = ptr;
				break;
			}
			else {
				q.enqueue(temp->left);
			}
			if (temp->right == NULL)
			{
				temp->right = ptr;
				break;
			}
			else {
				q.enqueue(temp->right);
			}
		}
	}
	void lvl_order_traver()
	{
		if (root == NULL)
		{
			cout << "tree is empty\n";
			return;
		}
		queue q;
		q.enqueue(root);
		while (!q.isempty())
		{
			node* temp = q.dequeue();
			cout << temp->data << endl;
			if (temp->left != NULL)
			{
				q.enqueue(temp->left);
			}
			if (temp->right != NULL)
			{
				q.enqueue(temp->right);
			}

		}
		
	}
	node* leftnode(node* n)
	{
		if (n == NULL)
		{
			return nullptr;
		}
		return n->left;
	}
	node* rgihtnode(node* n)
	{
		if (n == NULL)
		{
			return nullptr;
		}
		return n->right;
	}
	int total_node(node* n) 
	{
		if (n == nullptr) return 0;
		return 1 + total_node(n->left) + total_node(n->right);
	}
	void prnt_subtree(node* ptr) 
	{
		if (ptr == nullptr)
			return;
		cout << ptr->data << " ";
		prnt_subtree(ptr->left);
		prnt_subtree(ptr->right);
	}

	bool isinternal(node* n)
	{
		if (n == NULL)
			return false;
		if (n->left != NULL || n->right != NULL)
			return true;
		else return false;
	}


	bool is_ancestor(node* ansector, node* child)
	{
		if (ansector == NULL)
			return false;
		queue q;
		q.enqueue(ansector);	//starting with this instead of root bcz we dont need to
		while (!q.isempty())
		{
			node* temp = q.dequeue();

			if (temp == child)
			{
				return true;
			}
			if(temp->left!=NULL)
			{
				q.enqueue(temp->left);
			}
			if (temp->right != NULL)
			{
				q.enqueue(temp->right);
			}
		}
		return false; //if not found throught out the treee

	}
	bool is_decendant(node* ansector, node* descendant)
	{
		return is_ancestor(ansector, descendant);
	}
	bool sibling_check(node* a, node* b) 
	{
		node* A_parent = parent(a);
		node* B_parent = parent(b);
		if (A_parent == B_parent && A_parent != nullptr)
			return true;
		else return false;
	}
	bool isleaf(node* n)
	{
		if (n == NULL)
		{
			return false;
		}
		if (n->left == NULL && n->right == NULL)
		{
			return true;
		}
		else return false;
	}
	node* parent(node* child)
	{
		if (root == NULL || child == NULL)
		{
			return nullptr;
		}
		queue q;
		q.enqueue(root);

		while (!q.isempty())
		{

			node* temp = q.dequeue();
			if (temp->left != NULL && temp->left == child || temp->right != NULL && temp->right == child)
			{

				return temp;//returning parent
			}
			if (temp->left != NULL)
				q.enqueue(temp->left);
			if (temp->right != NULL)
				q.enqueue(temp->right);

		}
		return nullptr;


	}
	int level(node* current) 
	{
		return lvl_finder2(root, current, 0);
	}

	int lvl_finder2(node* current, node* target, int lvl)
	{
		if (current == nullptr) 
			return -1;
		if (current == target)
			return lvl;

		int leftLevel = lvl_finder2(current->left, target, lvl + 1);
		if (leftLevel != -1) return leftLevel;

		return lvl_finder2(current->right, target, lvl + 1);
	}

	node* get_root() 
	{
		return root;
	}


};
#include <iostream>
using namespace std;

int main() 
{
	tree trree;
	int choice, value;
	node* tempNode;

	while (true) 
	{
		cout << "\nMenu:\n";
		cout << "1.Insert Node\n";
		cout << "2.Level Order Traversal\n";
		cout << "3.Check if a Node is Leaf\n";
		cout << "4.Get Parent of a Node\n";
		cout << "5.Check if a Node is Ancestor\n";
		cout << "6.Check if Two Nodes are Siblings\n";
		cout << "7.Check if a Node is Internal\n";
		cout << "8.Get Left Node\n";
		cout << "9.Get Right Node\n";
		cout << "10.Total Nodes\n";
		cout << "11.Print Subtree\n";
		cout << "12.Exit\n";
		cout << "Entr your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "enter value to insert:";
			cin >> value;
			trree.insert(value);
		}
		else if (choice == 2)
		{
			trree.lvl_order_traver();
		}
		else if (choice == 3)
		{
			if (trree.isleaf(trree.get_root()))
				cout << "Root node is a leaf\n";
			else cout << "Root node is not a leaf" << endl;
		}
		else if (choice == 4)
		{
			node* to_send = trree.get_root()->left;
			node* parentNode = trree.parent(to_send);
			if (parentNode != nullptr)
				cout << "parent node value: " << parentNode->data << endl;
			else
				cout << "no parent." << endl;

		}
		else if (choice == 5)
		{
			node* lft_node = trree.leftnode(trree.get_root());
			if (lft_node != NULL)
			{
				cout << "left node value: " << lft_node->data << endl;
			}
			else
				cout << "no left child found." << endl;
		}
		else if (choice == 6)
		{
			int val_A, val_B;
			cout << "enter first sibling node value: ";
			cin >> val_A;
			cout << "enter second sibling node value: ";
			cin >> val_B;

			tempNode = trree.get_root();
			node* nodeA = nullptr;
			node* nodeB = nullptr;

			while (tempNode != nullptr)
			{
				if (tempNode->data == val_A)
				{
					nodeA = tempNode;
				}
				if (tempNode->data == val_B)
				{
					nodeB = tempNode;
				}
				if (nodeA != nullptr && nodeB != nullptr) break;

				if (val_A < tempNode->data)
					tempNode = tempNode->left;
				else
					tempNode = tempNode->right;
			}

			if ((trree.sibling_check(nodeA, nodeB)))
				cout << "they are siblings\n";
			else cout << "they are not siblings" << endl;
		}
		else if (choice == 7)
		{
			node* to_send = trree.get_root()->left;
			if (trree.isinternal(to_send))
				cout << "node is internal node\n";
			else cout << "node is not internal" << endl;

		}
		else if (choice == 8)
		{
			node* tosend = trree.get_root();
			node* leftNode = trree.leftnode(tosend);
			if (leftNode != NULL)
				cout << "left node value: " << leftNode->data << endl;
			else
				cout << "no left child found" << endl;
		}
		else if (choice == 9) 
		{
			node* tosend = trree.get_root()->left;
			node* rightNode = trree.rgihtnode(tosend);
			if (rightNode != nullptr)
				cout << "right node value: " << rightNode->data << endl;
			else
				cout << "no right child found\n";
		}
		else if (choice == 10) 
		{
			cout << "total nodes in the tree: " << trree.total_node(trree.get_root()) << endl;
		}
		else if (choice == 11) 
		{
			cout << "subtree of root: ";
			trree.prnt_subtree(trree.get_root());
			cout << endl;
		}
		else if (choice == 12) 
		{
			break;
		}
		else {
			cout << "invalid choice\n";
		}
	}
	return 0;
}
