//#include<iostream>
//using namespace std;
//template<class T>
//class node {
//public:
//	node* next;
//	T data;
//	int size;
//	node(int size=0)
//	{
//		next = NULL;
//		this->size = size;
//	}
//};
//template<class T>
//class Queue {
//public:
//	node<T>* front;
//	node<T>* rear;
//	Queue()
//	{
//		front = NULL;
//		rear = NULL;
//	}
//	void enqueue(T d)
//	{
//		node<T>* ptr = new node<T>(d);
//		ptr->data = d;
//		if (rear == NULL)
//		{
//			front = rear = ptr;
//		}
//		else {
//			rear->next = ptr;
//			rear = ptr;
//		}
//
//	}
//	T dequeue()
//	{
//		if (iempty()) {
//			cout << "Nothing to dequeue\n";
//			return -1;
//		}
//		else {
//			node<T>* temp = front;
//			T dd = front->data;
//			front = front->next;
//			if (front == nullptr)
//			{
//				rear = nullptr;
//			}
//			delete temp;
//			return dd;
//		}
//	}
//	void setfront(node<T>* f) {
//		front = f;
//	}
//	void setrear(node<T>* r) {
//		rear = r;
//	}
//	node<T>* getfront() {
//		return front;
//	}
//	node<T>* getrear() {
//		return rear;
//	}
//	bool iempty()
//	{
//		if (front == NULL) return true;
//		else return false;
//	}
//	void display(int QN,int n) 
//	{
//		cout << "\nShowing queues after merging\n\n";
//		for (int i = 0; i < QN; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cout << i + 1 << "-" << dequeue() << " ";	//where i+1 shows the actual number of queue that was before merging
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//};
//template<class T>
//void merge(Queue<T>& q1, Queue<T>& q2)
//{
//	q1.getrear()->next = q2.getfront();
//	q1.setrear(q2.getrear());
//	q2.setfront(NULL);
//	q2.setrear(NULL);
//}
//int main()
//{
//	cout << "How many queues you want?";
//	int QN; cin >> QN;
//	Queue<int>* queues = new Queue<int>[QN];
//	cout << "How many elements you want in each queue: ";
//	int val; cin >> val;
//	for (int i = 0; i < QN; i++)
//	{
//		cout << "Enter " << val << " elements for queue " << i + 1 << "\n";
//		for (int j = 0; j < val; j++)
//		{
//			int n; cin >> n;	//change this if you want to take advantage of template (data type)
//			queues[i].enqueue(n);
//		}
//	}
//	for (int i = 1; i < QN; i++)
//	{
//		merge(queues[0], queues[i]);
//	}
//	queues[0].display(QN, val);		//paassing these to show actual queue number from which data is being retrieved
//	return 0;
//
//}