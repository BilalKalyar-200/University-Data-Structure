//The task is...
//Implement the following functions for the Binary Search Tree :
//a) Function to insert a node in BST.
//b) Function to search a specific node in BST.
//c) Function to display all the nodes.
class node {
public:
	node* right, * left;
	int data;
	node() {
		left = right = NULL;
		data = 0;
	}
};
class BST {
public:
	node* root;
	BST() {
		root = NULL;
	}
	void insert(node* root, int data)
	{
		node* newnode = new node;
		newnode->data = data;
		insert(root, newnode);
	}
	node* insert(node* rr, node* ptr)	//using recursion
	{
		if (rr == NULL) {
			rr = ptr;
			return rr;
		}
		if (rr->data > ptr->data)
		{
			rr->left = insert(rr->left, ptr);
		}
		else if (rr->data < ptr->data) {
			rr->right = insert(rr->right, ptr);
		}
		else {
			cout << "Dublicates are not allowed\n";
			return nullptr;
		}
		return rr;
	}
	node* search(node* ptr, int data)
	{
		if (ptr == NULL)
		{
			return NULL;
		}
		if (ptr->data == data)
		{
			return ptr;
		}
		else if (ptr->data > data)
		{
			return search(ptr->left, data);
		}
		else return search(ptr->right, data);
	}
	void inorder(node* ptr)
	{
		if (ptr != NULL)
		{
			inorder(ptr->left);
			cout << ptr->data << " ";
			inorder(ptr->right);
		}
	}
	void postorder(node* ptr)
	{
		if (ptr != NULL)
		{
			postorder(ptr->left);
			postorder(ptr->right);
			cout << ptr->data << " ";
		}
	}
	void preorder(node* ptr)
	{
		if (ptr != NULL)
		{
			cout << ptr->data << " ";
			preorder(ptr->left);
			preorder(ptr->right);
		}
	}
};
int main()
{
	BST obj;

	obj.insert(obj.root,50);
	obj.insert(obj.root,30);
	obj.insert(obj.root,20);
	obj.insert(obj.root,40);
	obj.insert(obj.root,70);
	obj.insert(obj.root,60);
	obj.insert(obj.root,80);

	if (obj.search(obj.root, 20))
	{
		cout << "Value found\n";
	}
	else cout << "Value not found\n";

	cout << "inorder traversal: ";
	obj.inorder(obj.root);
	cout << endl;

	cout << "postorder traversal: ";
	obj.postorder(obj.root);
	cout << endl;

	cout << "preorder traversal: ";
	obj.preorder(obj.root);
	cout << endl;
}