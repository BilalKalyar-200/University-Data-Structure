////Write an efficient program for printing k smallest elements in an array.Elements in array can be in
////any order.For example, if given array is[8, 22, 43, 5, 11, 31, 17] and you are asked for the
////smallest 3 elements i.e., k = 3 then your program should print 5, 8 and 11.
//
//
//#include <iostream>
//using namespace std;
//
//class Heap {
//public:
//    int* arr;
//    int size;
//
//    Heap(int n)
//    {
//        arr = new int[n];
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
//        return 2 * i + 1;
//    }
//
//    int get_right(int i)
//    {
//        return 2 * i + 2;
//    }
//
//    void heapify(int i, int size)
//    {
//        int left = get_left(i);
//        int right = get_right(i);
//        int smallest = i;
//
//        if (left < size && arr[left] < arr[smallest])
//        {
//            smallest = left;
//        }
//
//        if (right < size && arr[right] < arr[smallest])
//        {
//            smallest = right;
//        }
//
//        if (smallest != i)
//        {
//            int temp = arr[i];
//            arr[i] = arr[smallest];
//            arr[smallest] = temp;
//            heapify(smallest, size);
//        }
//    }
//
//    void create_min_heap()
//    {
//        for (int i = size / 2 - 1; i >= 0; i--)
//        {
//            heapify(i, size);       //heapify every non leaf
//        }
//    }
//
//    void print_k_small(int k)
//    {
//        for (int i = 0; i < k; i++)
//        {
//            cout << arr[0] << " ";
//            arr[0] = arr[size - 1 - i];//replace root with last element (reudcing)
//            heapify(0, size - 1 - i);
//        }
//        cout << endl;
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
//    cout << "Enter size of array: ";
//    cin >> size;
//    Heap obj(size); 
//
//    cout << "Enter elements of array: ";
//    for (int i = 0; i < size; i++)
//    {
//        cin >> obj.arr[i];
//    }
//
//    obj.create_min_heap();
//
//    int k;
//    cout << "Enter k for k smallest elements: ";
//    cin >> k;
//
//    cout << "The " << k << " smallest elements are: ";
//    obj.print_k_small(k);
//
//    return 0;
//}
