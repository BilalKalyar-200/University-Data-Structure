////Heap Sort Algorithm for sorting in increasing order :
////1. Build a max heap from the input data.
////2. At this point, the largest item is stored at the root of the heap.Replace it with the last item
////of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
////3. Repeat above steps while size of heap is greater than 1.
//
//#include <iostream>
//using namespace std;
//
//class Heap {
//public:
//    int* arr;
//    int size;
//    Heap(int* input_arr, int n)
//    {
//        arr = input_arr;
//        size = n;
//    }
//
//    int get_parent(int i) 
//    {
//        return (i - 1) / 2;
//    }
//
//    int get_left(int i) 
//    {
//        return i * 2 + 1;
//    }
//
//    int get_right(int i) 
//    {
//        return i * 2 + 2;
//    }
//
//    void heapify(int i, int size) 
//    {
//        int left = get_left(i);
//        int right = get_right(i);
//        int largest = i;
//
//        if (left < size && arr[left] > arr[i]) 
//        {
//            largest = left;
//        }
//        if (right < size && arr[right] > arr[largest]) 
//        {
//            largest = right;
//        }
//        if (largest != i) 
//        {
//            int temp = arr[i];
//            arr[i] = arr[largest];
//            arr[largest] = temp;
//            heapify(largest, size);
//        }
//    }
//    
//
//    void heap_sort() 
//    {
//        for (int i = size / 2 - 1; i >= 0; i--)
//        {
//            heapify(i, size);       //heapify every non leaf
//        }
//
//        for (int i = size - 1; i > 0; i--) 
//        {
//            int temp = arr[i];      //swapping the current index with last index as required
//            arr[i] = arr[0];
//            arr[0] = temp;
//
//            heapify(0, i);
//        }
//    }
//
//    void print()
//    {
//        for (int i = 0; i < size; i++) 
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() 
//{
//    int size;
//    cout << "enter size of array: ";
//    cin >> size;
//    int* arr = new int[size];
//    cout << "enter elements of array: ";
//    for (int i = 0; i < size; i++)
//    {
//        cin >> arr[i];
//    }
//
//    Heap obj(arr, size);
//
//    cout << "array before heap sort: ";
//    obj.print();
//    cout << endl;
//    obj.heap_sort();
//    cout << endl;
//    cout << "array after heap sort: ";
//    obj.print();
//
//    return 0;
//}
