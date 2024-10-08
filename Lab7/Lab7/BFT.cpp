#include <iostream>
using namespace std;
class queue
{
	int* arr;
	int front;
	int rear;
	int numitems;
	int size;
public:
	queue()
	{
		size = 20;
		arr = new int[size];
		front = 0;
		rear = -1;
		numitems = 0;
	}
	~queue()
	{
		delete[] arr;
	}
	int frontindex()
	{
		return arr[front];
	}

	void enqueue(int value)
	{
		if (isfull())
		{
			cout << "max size reched\n";
		}
		else
		{
			rear = (rear + 1) % size;
			arr[rear] = value;
			numitems++;
		}
	}
	void dequeue()
	{
		if (isempty())
		{
			cout << "nothing to remove\n";
		}
		else
		{
			front = (front + 1) % size;
			numitems--;
		}
	}

	bool isempty()
	{
		if (numitems == 0)
		{
			return true;
		}
		return false;
	}
	bool isfull()
	{
		if (numitems == size)
		{
			return true;
		}
		return false;
	}
};
class tree 
{
	queue q1;
	int* tree_arr;
	int size;
	int counter;
public:
	tree()
	{
		size = 10;
		tree_arr = new int[size];
		counter = 1;
		for (int i = 0; i < size; i++)
		{
			tree_arr[i] = -1;
		}
	}
	~tree()
	{
		delete[] tree_arr;
	}
	void creatingtree(int value)
	{
		if (counter < size)
		{
			tree_arr[counter] = value;
			counter++;
		}
		else
		{
			cout << "can't insert queue if full\n";
		}
	}
	void BFT()
	{
		if (counter <= 1)
		{
			cout << "nothing in tree\n";
			return;
		}
		q1.enqueue(tree_arr[1]);
		while (!q1.isempty())
		{
			int index = q1.frontindex();
			q1.dequeue();
			cout << tree_arr[index] << endl;
			int left = 2 * index;
			if (left < counter)
			{
				q1.enqueue(tree_arr[left]);
			}
			int right = 2 * index + 1;
			if (right < counter)
			{
				q1.enqueue(tree_arr[right]);
			}
		}
	}
};
int main()
{
	tree obj;
	for (int i = 1; i <= 6; i++)
	{
		obj.creatingtree(i);
	}
	cout << endl;
	cout << "printing tree using BFT rule \n";
	obj.BFT();
	return 0;
}