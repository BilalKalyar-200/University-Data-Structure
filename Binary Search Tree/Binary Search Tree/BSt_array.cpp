//#include <iostream>
//using namespace std;
//
//class BST {
//private:
//    int* arr;
//    int capacity;
//    int size;
//
//public:
//    BST(int cap) 
//    {
//        capacity = cap;
//        size = 0;
//        arr = new int[capacity + 1];
//        for (int i = 0; i <= capacity; i++) 
//        {
//            arr[i] = 0;
//        }
//    }
//
//    ~BST() 
//    {
//        delete[] arr;
//    }
//
//    void insert(int value) 
//    {
//        if (size >= capacity) {
//            cout << "tree is full......" << endl;
//            return;
//        }
//        size++;
//        arr[size] = value;
//        int index = size;
//
//        //fixing if not in order
//       while (index > 1) 
//        {
//            int parent = index / 2;
//            if (arr[parent] > arr[index])
//            {
//                int temp = arr[parent];
//                arr[parent] = arr[index];
//                arr[index] = temp;
//                index = parent;
//            }
//            else
//            {
//                break;
//            }
//        }
//    }
//
//    int search(int value) 
//    {
//        for (int i = 1; i <= size; i++) 
//        {
//            if (arr[i] == value) 
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//    void deleteElement(int value) 
//    {
//        int index = search(value);
//        if (index == -1) 
//        {
//            cout << "this value not in tree\n";
//            return;
//        }
//
//        //replace with the rightmost leaf or leftmost leaf
//        if (arr[index * 2] == 0 && arr[index * 2 + 1] == 0) //case1: no child
//        {
//            arr[index] = 0;
//        }
//        //case2: one child
//        //right
//        else if (arr[index * 2] == 0) 
//        { 
//            arr[index] = arr[index * 2 + 1];
//            arr[index * 2 + 1] = 0;
//        }
//        //left
//        else if (arr[index * 2 + 1] == 0) 
//        {
//            arr[index] = arr[index * 2];
//            arr[index * 2] = 0;
//        }
//        else
//        {
//            //case3:two children
//            int min_ind= index * 2 + 1;
//            //finding left most on the right of the node to delete
//            while (arr[min_ind* 2] != 0)
//            {
//                min_ind= min_ind* 2;
//            }
//            arr[index] = arr[min_ind];
//            deleteElement(arr[min_ind]);
//        }
//    }
//
//    void post_order(int index = 1)
//    {
//        if (size == 0) {
//            cout << "nothing to show\n";
//            return;
//        }
//        if (index > capacity || arr[index] == 0)
//            return;
//        post_order(index * 2);
//        post_order(index * 2 + 1);
//        cout << arr[index] << " ";
//    }
//
//    void pre_order(int index = 1)
//    {
//        if (size == 0) {
//            cout << "nothing to show\n";
//            return;
//        }
//        if (index > capacity || arr[index] == 0)
//            return;
//        cout << arr[index] << " ";
//        pre_order(index * 2);
//        pre_order(index * 2 + 1);
//    }
//
//    void in_order(int index = 1)
//    {
//        if (size == 0) {
//            cout << "nothing to show\n";
//            return;
//        }
//        if (index > capacity || arr[index] == 0)
//            return;
//        in_order(index * 2);
//        cout << arr[index] << " ";
//        in_order(index * 2 + 1);
//    }
//
//
//    int leafCount(int index = 1) 
//    {
//        if (index > size) 
//            return 0;
//        if (arr[index * 2] == 0 && arr[index * 2 + 1] == 0) 
//            return 1;
//        return leafCount(index * 2) + leafCount(index * 2 + 1);
//    }
//
//    int length() 
//    {
//        return size;
//    }
//};
//
//int main() 
//{
//    BST bst(20);
//    int ch, value;
//
//    while(true)
//    {
//        cout << "1.insert\n";
//        cout << "2.delete\n";
//        cout << "3.print Post-order Traversal\n";
//        cout << "4.print Pre-order Traversal\n";
//        cout << "5.print In-order Traversal\n";
//        cout << "6.count Leaf Nodes\n";
//        cout << "7.get Length of Tree\n";
//        cout << "8.exit\n";
//        cout << "Enter your ch: ";
//        cin >> ch;
//
//        if (ch == 1) 
//        {
//            cout << "Enter value: ";
//            cin >> value;
//            bst.insert(value);
//        }
//        else if (ch == 2) 
//        {
//            cout << "Enter value to delete: ";
//            cin >> value;
//            bst.deleteElement(value);
//        }
//        else if (ch == 3) 
//        {
//            cout << "post order traversal: ";
//            bst.post_order();
//            cout << endl;
//        }
//        else if (ch == 4)
//        {
//            cout << "pre order traversal: ";
//            bst.pre_order();
//            cout << endl;
//        }
//        else if (ch == 5)
//        {
//            cout << "In order traversal: ";
//            bst.in_order();
//            cout << endl;
//        }
//        else if (ch == 6) 
//        {
//            cout << "leaf Count: " << bst.leafCount() << endl;
//        }
//        else if (ch == 7) 
//        {
//            cout << "length of Tree: " << bst.length() << endl;
//        }
//        else if (ch == 8)
//        {
//            cout << "exiting...\n";
//        }
//        else 
//        {
//            cout << "Invalid choice\n";
//        }
//    }
//
//    return 0;
//}
