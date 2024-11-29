//#include<iostream>
//using namespace std;
//class HEap {
//public:
//	int* arr;
//	int max_size;
//	int count;	//current number of elements in heap
//	HEap(int c)
//	{
//		count = 0;
//		max_size = c;
//		arr = new int[max_size];
//	}
//	bool search(int val)
//	{
//		for (int i = 0; i < count; i++)
//		{
//			if (arr[i] == val)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	int height()
//	{
//		return log2(count + 1) - 1;
//	}
//	int get_parent(int i)
//	{
//		int temp = (i - 1) / 2;
//		return temp;
//	}
//	int get_left(int i)
//	{
//		int temp = i * 2 + 1;
//		return temp;
//	}
//	int get_right(int i)
//	{
//		int temp = i * 2 + 2;
//		return temp;
//	}
//	void insert(int d)
//	{
//		if (count == max_size)
//		{
//			cout << "Heap is full\n";
//			return;
//		}
//		int i = count;
//		arr[i] = d;
//		count++;
//		while (i != 0 && arr[get_parent(i)] > arr[i])
//		{
//			//swapping
//			int temp = arr[i];
//			arr[i] = arr[get_parent(i)];
//			arr[get_parent(i)] = temp;
//			i = get_parent(i);
//		}
//
//	}
//	void heapify(int i)
//	{
//		int left = get_left(i);
//		int right = get_right(i);
//		int smallest = i;		
//		if (left < count && arr[left] < arr[i])
//		{
//			smallest = left;
//		}
//		if (right < count && arr[right] < arr[i])
//		{
//			smallest = right;
//		}
//		if (smallest != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[smallest];
//			arr[smallest] = temp;
//			heapify(smallest);
//		}
//	}
//	int extract_min()
//	{
//		if (count == 0)
//		{
//			cout << "nothing in heap\n";
//			return INT_MIN;		//returning something, we can also use this to check if its empty or not inside main
//		}
//		if (count == 1)//only one element
//		{
//			int temp = arr[0];
//			count--;
//			return temp;
//		}
//		int temp = arr[0];
//		arr[0] = arr[count - 1];
//		count--;
//		heapify(0);			//function to make the heap min again
//		return temp;
//	}
//	void process_key_to_delete(int i, int min)
//	{
//		arr[i] = min;
//		while (i != 0 && arr[get_parent(i)] > arr[i])
//		{
//			//swapping
//			int temp = arr[i];
//			arr[i] = arr[get_parent(i)];
//			arr[get_parent(i)] = temp;
//			i = get_parent(i);
//		}
//	}
//	void deletee(int val)
//	{
//		bool found = false;
//		if (count == 0)
//		{
//			cout << "nothing in heap to delete\n";
//			return;
//		}
//		int i = 0;
//		for (; i < count; i++)
//		{
//			if (arr[i] == val)
//			{
//				found = true;
//				break;		//means we found the index to delete
//			}
//		}
//		if (found) 
//		{
//			int temp = arr[i];
//			process_key_to_delete(i, INT_MIN);
//			extract_min();		//this will remove that INT_MIN and also heapify to fix the heap
//			cout << "The deleted value is: " << temp << endl;
//		}
//		else {
//			cout << "Value wasn't found in heap\n";
//		}
//	}
//	void display()
//	{
//		for (int i = 0; i < count; i++)
//		{
//			cout << arr[i] << " ";
//
//		}
//		cout << endl;
//	}
//
//};
//int main()
//{
//	cout << "Enter size of heap: ";
//	int n; cin >> n;
//	HEap obj(n);
//	while (true)
//	{
//		cout << "1.Insert\n2.delete\n3.search\n4.get min\n5.extract min\n6.get height\n7.print\n8.exit\n";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter value to insert: ";
//			int val; cin >> val;
//			obj.insert(val);
//		}
//		else if (ch == 2)
//		{
//			cout << "Enter value to delete: ";
//			int val; cin >> val;
//			obj.deletee(val);
//		}
//		else if (ch == 3)
//		{
//			cout << "Enter value to search: ";
//			int val; cin >> val;
//			if (obj.search(val)) {
//				cout << "Value found\n";
//			}
//			else cout << "not found\n";
//		}
//		else if (ch == 4)
//		{
//			cout << "minimum element of heep is(root): " << obj.arr[0] << endl;
//		}
//		else if (ch == 5)
//		{
//			int temp = obj.extract_min();
//			if (temp == INT_MIN)
//			{
//				continue;		//bcz msg already in the function
//			}
//			else {
//				cout << "The extracted min is: " << temp << endl;
//			}
//		}
//		else if (ch == 7)
//		{
//			obj.display();
//		}
//		else if (ch == 8)
//		{
//			break;
//		}
//		else cout << "Enter valid choice\n";
//	}
//}
