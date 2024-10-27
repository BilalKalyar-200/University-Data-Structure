////THIS QUESTION WAS ABOUT BREATH FIRST SEARCH ON BINARY TREE
//#include<iostream>
//using namespace std;
//class node {
//public:
//	node* left, * right;
//	string data;
//	node() {
//		left = right = NULL;
//		data = "";
//	}
//};
//class node_queu {
//public:
//	node* node_queue_tree;
//	node_queu* next;
//
//	node_queu(node* node) 
//	{
//		next = nullptr;
//		node_queue_tree = node;
//	}
//};
//class queue {
//	node_queu* front, * rear;
//public:
//	queue() 
//	{
//		front = rear = NULL;
//	}
//	bool isempty()
//	{
//		return front == NULL;
//	}
//	void enqueue(node* neww)
//	{
//		node_queu* ptr = new node_queu(neww);
//		if (rear == nullptr) 
//		{
//			front = rear = ptr;
//		}
//		else {
//			rear->next = ptr;
//			rear = ptr;
//		}
//	}
//	node* dequeue()
//	{
//		if (isempty())
//		{
//			return NULL;
//		}
//		node_queu* temp = front;
//		front = front->next;
//		if (front == NULL)
//		{
//			rear = NULL;
//		}
//		node* temp2 = temp->node_queue_tree;
//		delete temp;
//		return temp2;
//	}
//
//};
//class tree {
//public:
//	node* root;
//	tree() {
//		root = NULL;
//	}
//	bool search_BFT(string tofind)
//	{
//		if (root == NULL)
//		{
//			return false;
//		}
//		queue q1;
//		q1.enqueue(root);
//		while (!q1.isempty())
//		{
//			node* temp2 = q1.dequeue();
//			if (temp2->data == tofind)
//			{
//				return true;
//			}
//			if (temp2->left != NULL)
//			{
//				q1.enqueue(temp2->left);
//			}
//			if (temp2->right != NULL)
//			{
//				q1.enqueue(temp2->right);
//			}
//		}
//		return false;
//	}
//	void insert(string d)
//	{
//		node* ptr = new node;
//		ptr->data = d;
//		if (root == NULL) {
//			root = ptr;
//			return;
//		}
//		queue q1;
//		q1.enqueue(root);
//		while (!(q1.isempty()))
//		{
//			node* temp2 = q1.dequeue();
//			if (temp2->left == NULL)
//			{
//				temp2->left = ptr;
//				break;
//			}
//			else {
//				q1.enqueue(temp2->left);
//			}
//			if (temp2->right == NULL)
//			{
//				temp2->right = ptr;
//				break;
//			}
//			else {
//				q1.enqueue(temp2->right);
//			}
//		}
//
//	}
//	
//};
//int main()
//{
//	tree obj;
//	cout << "how many nodes: ";
//	int size; cin >> size;
//	for (int i = 0; i < size; i++)
//	{
//		cout << "Enter word " << i + 1 << ": ";
//		string str; cin >> str;
//		obj.insert(str);
//	}
//
//	cout << "Enter word to find: ";
//	string str; cin >> str;
//	if (obj.search_BFT(str)) 
//	{
//		cout << "found\n";
//	}
//	else cout << "not found\n";
//	return 0;
//
//}