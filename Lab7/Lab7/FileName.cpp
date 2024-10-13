#include<iostream>

#include<string>

using namespace std;



class Node {

public:

	int duration;

	string title;

	string artist;

	Node* next;

};



class LinkedListQueue {

	Node* front;

	Node* rear;



public:

	LinkedListQueue() {

		front = NULL;

		rear = NULL;



	}



	void addSong(int duration, string title, string artist) {

		Node* newnode = new Node;

		newnode->duration = duration;

		newnode->title = title;

		newnode->artist = artist;

		newnode->next = NULL;



		if (front == NULL) {

			front = newnode;

			rear = newnode;

		}

		else {

			rear->next = newnode;

			rear = newnode;

		}



	}



	bool isEmpty() {

		if (front == NULL) {

			return true;

		}

		else

			return false;

	}



	void removeSong(string& title) {

		if (isEmpty()) {

			cout << "Queue is Empty\n";

		}

		else {

			Node* temp = front;

			title = front->title;

			front = front->next;

			delete temp;

		}

	}







	void makeNull() {

		front = NULL;

		rear = NULL;

	}



	~LinkedListQueue() {

		string x;

		while (!isEmpty()) {

			removeSong(x);

		}

		makeNull();

	}



};





int main() {

	LinkedListQueue q1;

	int size;

	cout << "Enter Size of the Playlist: ";

	cin >> size;



	int d;

	string t;

	string a;

	cout << "Enter duration, tile and artist of songs: \n";

	for (int i = 0; i < size; i++) {

		cin >> d;

		cin >> t;

		cin >> a;

		cout << endl;



		q1.addSong(d, t, a);

	}



	string x;

	cout << "Removing songs\n";

	while (!q1.isEmpty()) {

		q1.removeSong(x);

		cout << x << endl;

	}



	system("pause");

	return 0;

}
