//#include<iostream>
//using namespace std;
//
//int get_parent(int i)
//{
//	int temp = (i - 1) / 2;
//	return temp;
//}
//int get_left(int i)
//{
//	int temp = i * 2 + 1;
//	return temp;
//}
//int get_right(int i)
//{
//	int temp = i * 2 + 2;
//	return temp;
//}
//
//void heapify(int i, int size ,int* arr)
//{
//	int left = get_left(i);
//	int right = get_right(i);
//	int smallest = i;
//	if (left < size && arr[left] < arr[i])
//	{
//		smallest = left;
//	}
//	if (right < size && arr[right] < arr[smallest])
//	{
//		smallest = right;
//	}
//	if (smallest != i)
//	{
//		int temp = arr[i];
//		arr[i] = arr[smallest];
//		arr[smallest] = temp;
//		heapify(smallest, size, arr);
//	}
//	
//}
//int extract_min(int* arr, int& size)
//{
//	int temp = arr[0];
//	arr[0] = arr[size - 1];
//	size--;
//	heapify(0,size,arr);
//	return temp;
//}
//int* heapsort(int* arr, int size)
//{
//	int* sort_arr = new int[size];
//	int temp_size = size;
//	for (int i = 0; i < size; i++)
//	{
//		sort_arr[i] = extract_min(arr, temp_size);
//	}
//	return sort_arr;
//}
//
//int main()
//{
//	int size;
//	cout << "Enter size of array: ";
//	cin >> size;
//	int* arr = new int[size];
//	cout << "Enter elements of array: ";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	cout << endl;
//	cout << "Array before heapify: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	for (int i = size / 2 - 1; i >= 0; i--)			//this will apply heapify on non leafs
//	{
//		heapify(i, size, arr);
//	}
//
//	cout << "Array After heapify: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	int* arr2 = heapsort(arr, size);
//	cout << "Array after sorting: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr2[i] << " ";
//	}
//	cout << endl;
//
//}