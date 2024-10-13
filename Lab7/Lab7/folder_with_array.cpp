//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node 
//{
//public:
//    string data;
//    Node() : data("") {}
//};
//
//class BinaryTree {
//private:
//    Node* tree;
//    int capacity;
//    int size;
//
//public:
//    BinaryTree(int cap) : capacity(cap), size(0)
//    {
//        tree = new Node[capacity];
//    }
//
//    ~BinaryTree() 
//    {
//        delete[] tree;
//    }
//
//    void insert(string value) 
//    {
//        if (size < capacity) 
//        {
//            tree[size].data = value;
//            size++;
//        }
//        else
//        {
//            cout << "tree is full!" << endl;
//        }
//    }
//
//    void pre_order(int index) 
//    {
//        if (index < size)
//        {
//            cout << tree[index].data << " ";
//            pre_order(2 * index + 1);
//            pre_order(2 * index + 2);
//        }
//    }
//
//    void post_order(int index)
//    {
//        if (index < size) 
//        {
//            post_order(2 * index + 1);
//            post_order(2 * index + 2);
//            cout << tree[index].data << " ";
//        }
//    }
//
//    void in_order(int index) 
//    {
//        if (index < size) 
//        {
//            in_order(2 * index + 1);
//            cout << tree[index].data << " ";
//            in_order(2 * index + 2);
//        }
//    }
//};
//
//int main() 
//{
//    int capacity;
//    cout << "Enter the maximum number of folders:";
//    cin >> capacity;
//
//    BinaryTree bt(capacity);
//    cout << "How many folders do you want to add? ";
//    int size;
//    cin >> size;
//
//    for (int i = 0; i < size; i++)
//    {
//        cout << "Enter name of folder " << i + 1 << ": ";
//        string val;
//        cin >> val;
//        bt.insert(val);
//    }
//
//    cout << "Pre-order traversal: ";
//    bt.pre_order(0);    //sending first index to traverse
//    cout << endl;
//    cout << endl;
//
//
//    cout << "Post-order traversal: ";
//    bt.post_order(0);
//    cout << endl;
//    cout << endl;
//
//    cout << "In-order traversal: ";
//    bt.in_order(0);
//    cout << endl;
//    cout << endl;
//
//    return 0;
//}
