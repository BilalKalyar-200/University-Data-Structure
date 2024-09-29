//#include<iostream>
//using namespace std;
//class deque {
//	int* arr;
//	int size;
//	int front;
//	int rear;
//public:
//	deque(int size = 10)
//	{
//		this->size = size;
//		arr = new int[size];
//		front = -1;
//		rear = -1;
//	}
//	bool isempty()
//	{
//		if (front == -1)
//			return true;
//		else return false;
//	}
//	bool isfull()
//	{
//		if (front == 0 && rear == size - 1)
//			return true;
//		else return false;
//	}
//	void insertfront(int val)
//	{
//		if (isfull())
//		{
//			cout << "Queue is full!!!wait!!!\n";
//			return;
//		}
//		if (front == -1) //if nothing on queue
//		{ 
//			front = rear = 0;
//		}
//		else if (front == 0) //wrapping around and using last index as front
//		{
//			front = size- 1;
//		}
//		else {
//			front--;
//		}
//		arr[front] = val;
//	}
//	void inserback(int val)
//	{
//		if (isfull())
//		{
//			cout << "Queue is full!!!wait!!!\n";
//			return;
//		}
//
//		if (front == -1) //if nothing on queue
//		{
//			front = rear = 0;
//		}
//		else if (rear = size - 1)
//		{
//			rear = 0;
//		}
//		else {
//			rear++;
//		}
//		arr[rear] = val;
//
//	}
//	int removefront()
//	{
//		if (isempty())
//		{
//			cout << "Nothing to removed\n";
//			return -1;
//		}
//		int val = arr[front];
//		if (front == rear) //only one in queue
//		{
//			front = rear = -1;
//		}
//		else if (front == size - 1) //wrap around
//		{  
//			front = 0;
//		}
//		else 
//		{
//			front++;	//moves front to next
//		}
//		return val;
//	}
//	int removeback()
//	{
//		if (isempty())
//		{
//			cout << "Nothing to removed\n";
//			return -1;
//		}
//		int val = arr[rear];
//		if (front == rear) //only one in queue
//		{
//			front = rear = -1;
//		}
//		else if (rear == 0)	//wraparound
//		{	
//			rear = size - 1;
//		}
//		else {
//			rear--;
//		}
//		return val;
//	}
//	void display()
//	{
//		if (isempty())
//		{
//			cout << "nothing to show\n";
//			return;
//		}
//		if (front <= rear)
//		{
//			for (int i = front; i <= rear; i++)
//			{
//				cout << arr[i] << " ";
//			}
//		}
//		else
//			{
//			for (int i = front; i < size; i++) 
//			{
//				cout << arr[i] << " ";
//			}
//			for (int i = 0; i <= rear; i++) 
//			{
//				cout << arr[i] << " ";
//			}
//		}
//		cout << endl;
//	}
//};
//int main()
//{
//	deque dd;
//	while (true)
//	{
//		cout << "1.insert at front\n2.insert at rear\n3.delete from front\n4.delete from rear\n5.exit\nYour choice:";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter value: ";
//			int val; cin >> val;
//			dd.insertfront(val);
//		}
//		else if (ch == 2)
//		{
//			cout << "Enter value: ";
//			int val; cin >> val;
//			dd.inserback(val);
//		}
//		else if (ch == 3)
//		{
//			int val = dd.removefront();
//			cout << "That value is " << val << endl;
//		}
//		else if (ch == 4)
//		{
//			int val = dd.removeback();
//			cout << "That value is " << val << endl;
//		}
//		else if (ch == 5)
//		{
//			exit;
//		}
//		else cout << "enter valid choice\n";
//	}
//	return 0;
//}