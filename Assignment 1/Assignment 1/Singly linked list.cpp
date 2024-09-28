#include<iostream>
using namespace std;
class node {
	int data;
	int key;
	node* next;
public:
	node()
	{
		data = 0; key = 0; next = NULL;
	}
	void setdata(int d)
	{
		data = d;
	}
	int getdata()
	{
		return data;
	}
	void setkey(int key)
	{
		this->key = key;
	}
	int getkey()
	{
		return key;
	}
	void setnext(node* next)
	{
		this->next = next;
	}
	node* getnext()
	{
		return next;
	}
};
class LinkedList {
	node* head;
public:
	LinkedList()
	{
		head = NULL;
	}
	void insert_at_start(int data, int key)	//Time complexity O(1)
	{
		node* ptr = new node;
		ptr->setdata(data);
		ptr->setkey(key);
		if (head == NULL)
		{
			head = ptr;
			ptr->setnext(NULL);
		}
		else {
			ptr->setnext(head);
			head = ptr;
		}
	}
	void insert_in_mid(int data, int key, int key2)	//Time complexity O(n)  where n= no. of nodes
	{
		node* ptr = new node;
		ptr->setdata(data);
		ptr->setkey(key);
		if (head == NULL)
		{
			head = ptr;
			ptr->setnext(NULL);
		}
		else {
			node* temp = head;
			while (temp != NULL)
			{
				if (temp->getkey() == key2)
				{
					ptr->setnext(temp->getnext());
					temp->setnext(ptr);
					return;
				}
				temp = temp->getnext();
			}
			cout << "Key not found\n";
		}
	}
	void insert_end(int data, int key)			//Time complexity O(n)  where n= no. of nodes
	{
		node* ptr = new node;
		ptr->setdata(data);
		ptr->setkey(key);
		ptr->setnext(nullptr);
		if (head == NULL)
		{
			head = ptr;
			ptr->setnext(NULL);
		}
		else {
			node* temp = head;
			while (temp->getnext() != NULL)
			{
				temp = temp->getnext();
			}
			temp->setnext(ptr);
		}
	}
	bool delete_first()
	{
		if (head == NULL)
		{
			cout << "Nothing to delete.....\n";
			return false;
		}
		if (head->getnext() == NULL)	//in case of only one node
		{
			head = NULL;
			return true;

		}
		node* temp = head;
		head = head->getnext();
		return true;
	}
	bool delete_a_node(int key)				//Time complexity O(n)  where n= no. of nodes
	{
		if (head == NULL)
		{
			cout << "Nothing to delete.....\n";
			return false;
		}
		if (head->getkey() == key)
		{
			head = NULL;
			return true;
		}
		node* temp = head;
		while (temp->getnext() != NULL)
		{
			if (temp->getnext()->getkey() == key)
			{
				node* to_del = temp->getnext();
				temp->setnext(temp->getnext()->getnext());
				delete to_del;
				to_del = NULL;
				return true;
			}
		}
		cout << "Key not found.....\n";
		return false;
	}
	bool delete_last()	//Time complexity O(n)  where n= no. of nodes
	{
		if (head == NULL)
		{
			cout << "Nothing to delete.....\n";
			return false;
		}

		node* temp = head;
		while (temp->getnext()->getnext() != NULL)
		{
			temp = temp->getnext();
		}

		node* L_N = temp->getnext();
		temp->setnext(NULL);
		delete L_N;
		return true;
	}
	void display()	 //time complexity O(n) where n = number of nodes
	{
		if (head == NULL)
		{
			cout << "list is empty...nothing to show\n";
			return;
		}

		node* temp = head;
		while (temp != NULL)
		{
			cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
			temp = temp->getnext();
		}
	}
	bool search(int data)   //time complexity O(n) where n = number of nodes
	{
		if (head == NULL)
		{
			cout << "list is empty...nothing to search\n";
			return false;
		}
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->getdata() == data)
			{
				cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
				return true;
			}
			temp = temp->getnext();
		}
		return false;
	}
};
void input(int& data, int& key)
{
	cout << "Enter data: ";
	cin >> data;
	cout << "Enter key: ";
	cin >> key;
}
int main()
{
	LinkedList obj;
	int data, key, ch;
	while (true)
	{
		cout << "Menu:\n";
		cout << "1.Insert node at beginning\n";
		cout << "2.Insert node in middle\n";
		cout << "3.Insert node at end\n";
		cout << "4.Delete first node\n";
		cout << "5.Delete node\n";
		cout << "6.Delete last node\n";
		cout << "7.Display list\n";
		cout << "8.Search node\n";
		cout << "9.Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;

		if (ch == 1)
		{
			input(data, key);
			obj.insert_at_start(data, key);
		}
		else if (ch == 2)
		{
			input(data, key);
			int key2;
			cout << "Enter key of the node after which you want to insert: ";
			cin >> key2;
			obj.insert_in_mid(data, key, key2);
		}
		else if (ch == 3)
		{
			input(data, key);
			obj.insert_end(data, key);
		}
		else if (ch == 4)
		{
			bool dell = obj.delete_first();
			if (dell)
			{
				cout << "Deletion was a success....first node deleted\n";
			}
		}
		else if (ch == 5)
		{
			cout << "Enter key to delete: ";
			int key2; cin >> key2;
			bool dell = obj.delete_a_node(key2);
			if (dell)
			{
				cout << "Deletion was a success....asked node deleted\n";
			}
		}
		else if (ch == 6)
		{
			bool dell = obj.delete_last();
			if (dell)
			{
				cout << "Deletion was a success....last node deleted\n";
			}
		}
		else if (ch == 7)
		{
			obj.display();
		}
		else if (ch == 8)
		{
			cout << "Enter data to search: ";
			int d; cin >> d;
			bool found = obj.search(d);
			if (found)
			{
				cout << "Search was a success\n";
			}
		}
		else if (ch == 9)
		{
			cout << "exititing\n";
			break;
		}
		else {
			cout << "Enter valid choice\n";
			continue;
		}
	}
}