#include<iostream>
using namespace std;

class node
{
	string cnic;
	double salary;
	node* next;
	int key;
public:
	string getcnic()
	{
		return cnic;
	}
	node* getnext()
	{
		return next;
	}
	void setcnic(string cnic)
	{
		this->cnic = cnic;
	}
	void setnext(node* next)
	{
		this->next = next;
	}
	void setkey(int k)
	{
		key = k;
	}
	int getkey()
	{
		return key;
	}
	void setsalar(double s)
	{
		salary = s;
	}
	double getsal()
	{
		return salary;
	}
};
class siglelink {
	node* head;
public:
	node* gethead()
	{
		return head;
	}
	siglelink()
	{
		head = nullptr;
	}
	bool isempty()
	{
		if (head == nullptr)
		{
			return true;
		}
		else { return false; }
	}
	bool checkalready(int key)	//to check if node with same key exitsts
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->getkey() == key)
			{
				return true;
			}
			temp = temp->getnext();
		}
		return false;
	}
	void append(string cnic, double salary, int key)
	{
		if (checkalready(key))
		{
			cout << "Node with this key already exists\n";
			return;
		}
		node* ptr = new node;
		ptr->setcnic(cnic);
		ptr->setsalar(salary);
		ptr->setkey(key);
		ptr->setnext(nullptr);

		if (head == NULL)
		{
			head = ptr;
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

	void insert(string cnic, double salary, int key, int key2)
	{
		if (checkalready(key))
		{
			cout << "Node with this key already exists\n";
			return;
		}
		node* ptr = new node;
		ptr->setcnic(cnic);
		ptr->setsalar(salary);
		ptr->setkey(key);
		bool found = false;
		node* temp = head;
		if (head == NULL)
		{
			head = ptr;
			ptr->setnext(NULL);
		}
		else {
			while (temp != NULL)
			{
				if (temp->getkey() == key2)
				{
					found = true;
					ptr->setnext(temp->getnext());
					temp->setnext(ptr);
					break;
				}
				temp = temp->getnext();
			}

		}

		if (!found)
		{
			cout << "Enter valid key after which you want to insert\n";
		}
	}
	void deletedata(string cnic)
	{
		bool found = false;
		node* temp = head;
		if (head->getcnic() == cnic)
		{
			head = head->getnext();
			found = true;
			delete temp;
		}
		else {
			while (temp->getnext() != NULL)
			{
				if (temp->getnext()->getcnic() == cnic)
				{
					node* temp2 = temp->getnext()->getnext();
					temp->setnext(temp2);
					found = true;
					break;
				}
				else {
					temp = temp->getnext();
				}
			}
		}
		if (!found)
		{
			cout << "Not found with the given cnic\n";
		}

	}
	void update(string cnic)
	{
		bool found = false;
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->getcnic() == cnic)
			{
				cout << "Enter new salary: ";
				double sal; cin >> sal;
				temp->setsalar(sal);
				found = true;
				return;
			}
		}
		if (!found)
		{
			cout << "Enter valid cnic to update: \n";
		}

	}
	void display(siglelink& highsal)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->getsal() >= 100000)
			{
				cout << "Key: " << temp->getkey() << endl;
				cout << "Cnic: " << temp->getcnic() << endl;
				cout << "salary: " << temp->getsal() << endl;
				highsal.append(temp->getcnic(), temp->getsal(), temp->getkey());
			}
			temp = temp->getnext();
		}
	}

};


int main()
{

	siglelink obj;
	siglelink highsalary;
	while (true)
	{
		cout << "Welcome to Bilal's company\n"
			<< "1.Append data\n2.Insert data\n3.Delete data\n4.Update data\n5.Display data\n6.Exit\n7.Clear scrren\n";
		char ch; cin >> ch;
		if (ch == '1')
		{
			cout << "Enter key: ";
			int key; cin >> key;
			cout << "Enter CNIC: ";
			string cnic; cin >> cnic;
			cout << "Enter Salary: ";
			double sal; cin >> sal;
			obj.append(cnic, sal, key);
			cout << "Node Appended\n";
		}
		else if (ch == '2')
		{
			cout << "Enter key: ";
			int key; cin >> key;
			cout << "Enter CNIC: ";
			string cnic; cin >> cnic;
			cout << "Enter Salary: ";
			double sal; cin >> sal;
			cout << "Enter key of node after which you want to insert: ";
			int key2; cin >> key2;
			obj.insert(cnic, sal, key, key2);
			cout << "Node Inserted\n";
		}
		else if (ch == '3')
		{
			if (obj.isempty())
			{
				cout << "List is empty...cant delete\n";
				continue;
			}
			cout << "Enter cnic of the user you want to delete\n";
			string cnic; cin >> cnic;
			obj.deletedata(cnic);
		}
		else if (ch == '4')
		{

			if (obj.isempty())
			{
				cout << "List is empty...cant update\n";
				continue;
			}
			cout << "Enter CNIC of the employee you want to update:";
			string cnic; cin >> cnic;
			obj.update(cnic);

		}
		else if (ch == '5')
		{
			cout << "Displaying with salary above 100000: \n";
			obj.display(highsalary);
		}
		else if (ch == '6')
		{
			break;
		}
		else if (ch == '7')
		{
			system("cls");
		}


	}


	return 0;

}
