#include<iostream>
using namespace std;
template<class T>
class node {
public:
	node* next;
	T data;
	node(T val)
	{
		data = val;
		next = NULL;
	}
};
template<class T>
class Queue {
public:
	node<T>* front;
	node<T>* rear;
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(T d)
	{
		node<T>* ptr = new node<T>(d);
		ptr->data = d;
		if (rear == NULL)
		{
			front = rear = ptr;
		}
		else {
			rear->next = ptr;
			rear = ptr;
		}
	}
	T dequeue()
	{
		if (iempty()) {
			cout << "Nothing to dequeue\n";
			return -1;
		}
		else {
			node<T>* temp = front;
			T dd = front->data;
			front = front->next;
			if (front == nullptr)
			{
				rear = nullptr;
			}
			delete temp;
			return dd;
		}
	}
	void setfront(node<T>* f) {
		front = f;
	}
	void setrear(node<T>* r) {
		rear = r;
	}
	node<T>* getfront() {
		return front;
	}
	node<T>* getrear() {
		return rear;
	}
	bool iempty()
	{
		if (front == NULL) return true;
		else return false;
	}
	void display() {
		node<T>* current = front;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

};
template<class T>
void merge(Queue<T>& q1, Queue<T>& q2, Queue<T>& q3)
{
	q2.getrear()->next = q3.getfront();
	q1.getrear()->next = q2.getfront();
	q1.setrear(q3.getrear());
	q2.setfront(NULL);
	q2.setrear(NULL);
	q3.setfront(NULL);
	q3.setrear(NULL);
}
int main()
{
	int val, c = 10;
	Queue<int> q1, q2, q3;
	cout << "Enter 10 numbers for 1st queue\n";
	for (int i = 0; i < c; i++)
	{
		cin >> val;
		q1.enqueue(val);
	}

	cout << "Enter 10 numbers for 2nd queue\n";
	for (int i = 0; i < c; i++)
	{
		cin >> val;
		q2.enqueue(val);
	}

	cout << "Enter 10 numbers for 3rd queue\n";
	for (int i = 0; i < c; i++)
	{
		cin >> val;
		q3.enqueue(val);
	}
	merge(q1, q2, q3);
	q1.display();
}