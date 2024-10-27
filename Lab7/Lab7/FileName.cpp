//#include<iostream>
//
//#include<string>
//
//using namespace std;
//
//
//
//class Node {
//
//public:
//
//	int duration;
//
//	string title;
//
//	string artist;
//
//	Node* next;
//
//};
//
//
//
//class LinkedListQueue {
//
//	Node* front;
//
//	Node* rear;
//
//
//
//public:
//
//	LinkedListQueue() {
//
//		front = NULL;
//
//		rear = NULL;
//
//
//
//	}
//
//
//
//	void addSong(int duration, string title, string artist) {
//
//		Node* newnode = new Node;
//
//		newnode->duration = duration;
//
//		newnode->title = title;
//
//		newnode->artist = artist;
//
//		newnode->next = NULL;
//
//
//
//		if (front == NULL) {
//
//			front = newnode;
//
//			rear = newnode;
//
//		}
//
//		else {
//
//			rear->next = newnode;
//
//			rear = newnode;
//
//		}
//
//
//
//	}
//
//
//
//	bool isEmpty() {
//
//		if (front == NULL) {
//
//			return true;
//
//		}
//
//		else
//
//			return false;
//
//	}
//
//
//
//	void removeSong(string& title) {
//
//		if (isEmpty()) {
//
//			cout << "Queue is Empty\n";
//
//		}
//
//		else {
//
//			Node* temp = front;
//
//			title = front->title;
//
//			front = front->next;
//
//			delete temp;
//
//		}
//
//	}
//
//
//
//
//
//
//
//	void makeNull() {
//
//		front = NULL;
//
//		rear = NULL;
//
//	}
//
//
//
//	~LinkedListQueue() {
//
//		string x;
//
//		while (!isEmpty()) {
//
//			removeSong(x);
//
//		}
//
//		makeNull();
//
//	}
//
//
//
//};
//
//
//
//
//
//int main() {
//
//	LinkedListQueue q1;
//
//	int size;
//
//	cout << "Enter Size of the Playlist: ";
//
//	cin >> size;
//
//
//
//	int d;
//
//	string t;
//
//	string a;
//
//	cout << "Enter duration, tile and artist of songs: \n";
//
//	for (int i = 0; i < size; i++) {
//
//		cin >> d;
//
//		cin >> t;
//
//		cin >> a;
//
//		cout << endl;
//
//
//
//		q1.addSong(d, t, a);
//
//	}
//
//
//
//	string x;
//
//	cout << "Removing songs\n";
//
//	while (!q1.isEmpty()) {
//
//		q1.removeSong(x);
//
//		cout << x << endl;
//
//	}
//
//
//
//	system("pause");
//
//	return 0;
//
//}

#include<iostream>
using namespace std;
void print_tri(int n, int s)
{
	int sum = 0;
	int c = 0, k = 0;
	for (int i = 1; i <= s; i++)
	{
		for (int k = n * 2; k > i; k--) 
		{ cout << "  "; }

		for (int j = 1; j <= c + i; j++)
		{
			if (j <= i)
			{
				cout << j << " ";
				sum += j;
				k = j - 1;
			}
			else
			{

				cout << k << " ";
				sum += k;
				k--;
			}
		}
		cout << endl;
		c++;
	}

}
int main()
{
	int n; cin >> n;
	int s = n+5;
	print_tri(n, s);
}