#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class node {
	string name;
	int key;
	node* next, * prev;
public:
	node()
	{
		name = "";
		key = 0;
		next = NULL;
		prev = NULL;
	}
	void setnext(node* next)
	{
		this->next = next;
	}
	node* getnext()
	{
		return next;
	}
	void setpre(node* pre)
	{
		prev = pre;
	}
	node* getpre()
	{
		return prev;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void setkey(int k)
	{
		key = k;
	}
	int getkey()
	{
		return key;
	}
};

class circular {
	node* head;
public:
	static int count;

	circular()
	{
		head = NULL;
	}
	void insert_at_end(int key, string name)
	{
		node* ptr = new node;
		ptr->setname(name);
		ptr->setkey(key);
		if (head == NULL)             // If the playlist is empty
		{
			head = ptr;
			head->setnext(head);
			head->setpre(head);
			count++;
			return;
		}
		node* temp = head;
		while (temp->getnext() != head)
		{
			temp = temp->getnext();
		}
		temp->setnext(ptr);
		ptr->setpre(temp);
		ptr->setnext(head);
		head->setpre(ptr);
		count++;
	}
	void delete_song(int key)
	{
		if (head == NULL)
		{
			cout << "no node ,,, cannot delete\n";
			return;
		}
		if (head->getkey() == key)
		{
			if (head->getnext() == head)   //if only one node
			{
				delete head;
				head = nullptr;
				count--;
			}
			else {
				node* temp = head;
				node* tail = head->getpre();

				head = head->getnext();
				tail->setnext(head);
				head->setpre(tail);
				delete temp;
				temp = nullptr;
				count--;

			}
		}
		else {
			//traverse to find the song with the given key
			node* temp = head;
			while (temp->getnext() != head)
			{
				if (temp->getkey() == key)
				{
					temp->getpre()->setnext(temp->getnext());
					temp->getnext()->setpre(temp->getpre());
					delete temp;
					temp = NULL;
					count--;

					return;
				}
				temp = temp->getnext();
			}

		}
	}
	//function to play next song (counter used to keep track of current song)
	void play_song(int counter)
	{
		if (head == NULL)
		{
			cout << "No songs to play\n";
			return;
		}

		node* temp = head;
		int count2 = 1;

		while (true)
		{
			if (count2 == counter)
			{
				cout << "Playing next song\n";
				cout << "Key: " << temp->getkey() << " Name: " << temp->getname() << endl;
				break;
			}
			temp = temp->getnext();
			count2++;

			if (temp == head)
			{
				count2 = 1;  //reset counter when head is reached
			}
		}
	}
	void play_song_pre(int counter)
	{
		if (head == NULL)
		{
			cout << "No songs to play\n";
			return;
		}

		node* temp = head;
		int count2 = 1;

		while (true)
		{
			if (count2 == counter)
			{
				cout << "Playing next song\n";
				cout << "Key: " << temp->getkey() << " Name: " << temp->getname() << endl;
				break;
			}
			temp = temp->getpre();
			count2++;

			if (temp == head)
			{
				count2 = 1;  //reset counter
			}
		}
	}
	void play_random(int random)
	{
		int n = 1;
		if (head == NULL)
		{
			cout << "No songs to play\n";
			return;
		}
		node* temp = head;
		while (temp->getnext() != head)
		{
			if (n == random)
			{
				cout << "Playing song in shuffle\n";
				cout << "Key: " << temp->getkey() << " Name: " << temp->getname() << endl;
				break;
			}
			else {
				n++;
				temp = temp->getnext();
			}
		}
	}
	void display()
	{
		node* temp = head;
		do {
			cout << "Key: " << temp->getkey() << " Name: " << temp->getname() << endl;
			temp = temp->getnext();
		} while (temp != head);
	}
};
int circular::count = 0;
int main()
{
	circular obj;
	int choice;
	int count = 1;//this is to play next song each time  (for next song)
	while (true)
	{
		cout << "Playlist Menu \n";
		cout << "1-.Add a song to the playlist at end\n";
		cout << "2-.Remove a song from the playlist at any position\n";
		cout << "3-.Play next song\n";
		cout << "4-.Play previous song\n";
		cout << "5-.Display complete playlist\n";
		cout << "6-.Shuffle play\n";
		cout << "7-.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Enter key of the song: ";
			int key; cin >> key;
			cout << "Enter name of the song: ";
			string name; cin >> name;
			obj.insert_at_end(key, name);
		}
		else if (choice == 2)
		{
			cout << "Enter key of the song you want to delete: ";
			int key; cin >> key;
			obj.delete_song(key);
		}
		else if (choice == 3)
		{
			if (count > obj.count)
			{
				count = 1;
			}
			obj.play_song(count);
			count++;
		}
		else if (choice == 4)
		{
			if (count > obj.count)
			{
				count = 1;
			}
			obj.play_song_pre(count);
			count++;
		}
		else if (choice == 5)
		{
			obj.display();
		}
		else if (choice == 6)
		{
			srand(time(0));
			int random = (rand() % obj.count) + 1;
			obj.play_random(random);
		}
		else if (choice == 7)
		{
			cout << "Exiting the program\n";
			break;
		}
		else {
			cout << "invalid choice\n";
			continue;
		}
	}
