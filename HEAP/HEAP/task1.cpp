////THE TASK I GOT IS
//// 
////Implement Binary heap.
////1. getMini() : It returns the root element of Min Heap.
////2. deleteMin() : Removes the minimum element from MinHeap.
////3. insert() : Inserting a new key.We add a new key at the end of the tree.If new key is greater
////than its parent, then we don’t need to do anything.Otherwise, we need to traverse up to fix
////the violated heap property.
//
//#include<iostream>
//using namespace std;
//class heap {
//public:
//	int* arr;
//	int count;		//current number of elements in heep
//	int max_size;
//	heap(int c)
//	{
//		max_size = c;
//		count = 0;
//		arr = new int[max_size];
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
//	void insert(int val)
//	{
//		if (count == max_size)
//		{
//			cout << "cannot insert size is full\n";
//			return;
//		}
//		arr[count] = val;
//		int i = count - 1;
//		count++;	
//		while (i != 0 && arr[get_parent(i)] > arr[i])
//		{
//			//swapping
//			int temp = arr[i];
//			arr[i] = arr[get_parent(i)];
//			arr[get_parent(i)] = temp;
//			i = get_parent(i);
//		}
//	}
//	int getmin()
//	{
//		return arr[0];
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
//	int delete_min()
//	{
//		if (count == 0)
//		{
//			cout << "nothing to delete\n";
//			return  INT_MIN;
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
//		heapify(0);
//		return temp;
//	}
//	void print()
//	{
//		for (int i = 0; i < count; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//};
//int main()
//{
//	cout << "Enter size of heap: ";
//	int s; cin >> s;
//	heap obj(s);
//	while (true)
//	{
//		cout << "1.Insert\n2.Get mini\n3.Delete min\n4.print\n";
//		int ch; cin >> ch;
//		if (ch == 1)
//		{
//			cout << "Enter value to insert: ";
//			int val; cin >> val;
//			obj.insert(val);
//		}
//		else if (ch == 2)
//		{
//			cout << "minimum value from heap is: " << obj.getmin() << endl;
//		}
//		else if (ch == 3)
//		{
//			cout << "Delted min value from heap is: " << obj.delete_min() << endl;
//		}
//		else if (ch == 4)
//		{
//			obj.print();
//		}
//		else if (ch == 5)
//		{
//			break;
//		}
//		else cout << "Enter valid choice\n";
//	}
//}