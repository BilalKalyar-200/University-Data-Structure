//#include<iostream>
//using namespace std;
//class Queue {
//	int rear, front, size;
//	string* arr;
//	int numpeople;
//public:
//	Queue(int s)
//	{
//		size = s;
//		arr = new string[size];
//		front = -1;
//		rear = -1;
//		numpeople = 0;
//	}
//	bool isfull()
//	{
//		if (numpeople == size)
//		{
//			return true;
//		}
//		else return false;
//	}
//	void enquqe(string d)
//	{
//		if (isfull())
//		{
//			cout << "Full\n";
//			return;
//		}
//		else if (front == -1)
//		{
//			front = 0;
//		}
//		rear = (rear + 1) % size;
//		arr[rear] = d;
//		numpeople++;
//	}
//	void makenull() {
//		numpeople = 0;
//		front = -1;
//		rear = -1;
//	}
//	bool isempty()
//	{
//		if (numpeople == 0)
//			return true;
//		else return false;
//	}
//	string deque()
//	{
//		if (isempty()) {
//			cout << "Nothing to deque\n";
//			return "";
//		}
//		else
//		{
//			string num = arr[front];
//			front = (front + 1) % size;
//			numpeople--;
//			return num;
//		}
//	}
//	void display() {
//		if (isempty()) 
//		{
//			cout << "Queue is empty\n";
//			return;
//		}
//		int i = front;
//		for (int count = 0; count < numpeople; count++) 
//		{
//			cout << arr[i] << " ";
//			i = (i + 1) % size;
//		}
//		cout << endl;
//	}
//	~Queue()
//	{
//		delete[] arr;
//	}
//};
//int main()
//{
//	cout << "how many people can be in queue at once: ";
//	int size; cin >> size;
//	Queue q1(size);
//	while (true)
//	{
//		cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.isFull\n5.isEmpty\n6.Exit\n";
//		cout << "Your choice: ";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter name: ";
//			string n; cin >> n;
//			q1.enquqe(n);
//		}
//		else if (ch == 2)
//		{
//			cout << "The guy who left is: " << q1.deque() << endl;
//		}
//		else if (ch == 3)
//		{
//			q1.display();
//		}
//		else if (ch == 4)
//		{
//			if (q1.isfull())
//				cout << "Queue is full\n";
//			else cout << "Not full\n";
//		}
//		else if (ch == 5)
//		{
//			if (q1.isempty())
//				cout << "Queue is empty\n";
//			else cout << "Not empty\n";
//		}
//		else if (ch == 6)
//		{
//			break;
//		}
//		else {
//			cout << "enter correct choice\n";
//			continue;
//		}
//	}
//	return 0;
//}