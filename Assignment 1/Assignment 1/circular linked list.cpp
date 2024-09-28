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
class circular {
	node* head;
public:
	circular()
	{
		head = NULL;
	}
	void insert_at_begin(int data, int key)		//Time complexity = O(n)  n is number of nodes
	{
		node* ptr = new node;
		ptr->setkey(key);
		ptr->setdata(data);
		if (head == NULL)
		{
			head = ptr;
			head->setnext(head);
		}
		else {
			node* temp = head;
			while (temp->getnext() != head)
			{
				temp = temp->getnext();
			}
			ptr->setnext(head);
			temp->setnext(ptr);
			head = ptr;
		}
	}
	void insert_in_middle(int data, int key, int key2)			//Time complexity = O(n) where n equals to number of nodes in list
	{
		node* ptr = new node;
		ptr->setkey(key);
		ptr->setdata(data);
		if (head == NULL)
		{
			head = ptr;
			head->setnext(head);
		}
		else {
			node* temp = head;
			while (temp->getnext() != head)
			{

				if (temp->getkey() == key2)
				{
					ptr->setnext(temp->getnext());
					temp->setnext(ptr);
					return;
				}
				temp = temp->getnext();
			}
		}
		cout << "Key not found\n";
	}
	void insert_at_end(int data, int key)	//Time complexity = O(n) where n equals to number of nodes in list
	{
		node* ptr = new node;
		ptr->setkey(key);
		ptr->setdata(data);
		if (head == NULL)
		{
			head = ptr;
			head->setnext(head);
		}
		else {
			node* temp = head;
			while (temp->getnext() != head)
			{
				temp = temp->getnext();
			}
			temp->setnext(ptr);
			ptr->setnext(head);
		}
	}
	void delte_first_node()	//Time complexity = O(n)
	{
		if (head == NULL)
		{
			cout << "Nothing to delete.....\n";
			return;
		}
		if (head->getnext() == head)	//in case of only one node
		{
			head = NULL;
			return;
		}
		node* temp = head;
		while (temp->getnext() != head)
		{
			temp = temp->getnext();
		}
		node* old = head;
		temp->setnext(head->getnext());
		head = head->getnext();
		delete old;
		old = NULL;

	}
	void delete_a_node(int key)		//Time complexity = O(n) where n equals to number of nodes in list
	{
		if (head == NULL)
		{
			cout << "Nothing to delete.....\n";
			return;
		}
		node* temp = head;
		if (head->getnext() == head)	//in case of only one node
		{
			head = NULL;
			return;
		}
		node* temp2 = head;
		while (temp2->getnext() != head)   //deleting node with key
		{
			temp2 = temp2->getnext();
		}
		if (head->getkey() == key)
		{
			temp2->setnext(head->getnext());
			head = head->getnext();
			delete temp;
			temp = NULL;
			return;
		}
		node* prev = NULL;
		while (temp->getnext() != head)
		{
			if (temp->getkey() == key)
			{
				prev->setnext(temp->getnext());
				delete temp;
				temp = NULL;
				return;
			}
			prev = temp;
			temp = temp->getnext();
		}
		if (temp->getkey() == key) //if last node to delete
		{
			prev->setnext(head);
			delete temp;
			return;
		}
	}
	void delete_last()			//time compleixty O(n)
	{
		if (head == NULL)
		{
			cout << "Nothing to delete....\n";
			return;
		}
		node* temp = head;
		node* prev = NULL;
		if (head->getnext() == head)	//in case of only one node
		{
			head = NULL;
			return;
		}
		while (temp->getnext() != head)
		{
			prev = temp;
			temp = temp->getnext();
		}
		prev->setnext(head);
		delete temp;
		temp = NULL;
	}
	void search(int data) //Time complexity = O(n) where n equals to number of nodes in list
	{
		if (head == NULL)
		{
			cout << "Nothing to showw bruhhh\n";
			return;
		}
		node* temp = head;
		if (head->getdata() == data)
		{
			cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
			return;
		}
		else {
			while (temp->getnext() != head)
			{
				if (temp->getdata() == data)
				{
					cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
					return;
				}
				temp = temp->getnext();
			}
		}
		cout << "No node found with this data: \n";
	}
	void display()          //Time complexity = O(n) where n equals to number of nodes in list
	{
		node* temp = head;
		do
		{
			cout << "Key: " << temp->getkey() << " Data: " << temp->getdata() << endl;
			temp = temp->getnext();
		} while (temp != head);
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
	circular obj;
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
			obj.insert_at_begin(data, key);
		}
		else if (ch == 2)
		{
			input(data, key);
			int key2;
			cout << "Enter key of the node after which you want to insert: ";
			cin >> key2;
			obj.insert_in_middle(data, key, key2);
		}
		else if (ch == 3)
		{
			input(data, key);
			obj.insert_at_end(data, key);
		}
		else if (ch == 4)
		{
			obj.delte_first_node();
		}
		else if (ch == 5)
		{
			cout << "Enter key to delete: ";
			int key2; cin >> key2;
			obj.delete_a_node(key2);
		}
		else if (ch == 6)
		{
			obj.delete_last();
		}
		else if (ch == 7)
		{
			obj.display();
		}
		else if (ch == 8)
		{
			cout << "Enter data to search: ";
			int d; cin >> d;
			obj.search(d);
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