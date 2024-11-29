////#include <iostream>
////using namespace std;
////
////class node
////{
////public:
////    int data;
////    node* left;
////    node* right;
////
////    node(int val)
////    {
////        data = val;
////        left = NULL;
////        right = NULL;
////    }
////};
////
////class min_heap
////{
////public:
////    node* root;
////
////    min_heap()
////    {
////        root = NULL;
////    }
////
////
////
////    void insert(int data)
////    {
////        if (root == NULL)
////        {
////            root = new node(data);
////            return;
////        }
////
////        node* current = root;
////        while (true)
////        {
////            if (current->left == NULL)
////            {
////                current->left = new node(data);
////                break;
////            }
////            else if (current->right == NULL)
////            {
////                current->right = new node(data);
////                break;
////            }
////            else if (count_nodes(current->left) <= count_nodes(current->right))
////            {
////                current = current->left;
////            }
////            else
////            {
////                current = current->right;
////            }
////        }
////    }
////
////    int count_nodes(node* current)
////    {
////        if (current == NULL)
////            return 0;
////        return 1 + count_nodes(current->left) + count_nodes(current->right);
////    }
////
////    void min_heapify(node* current)
////    {
////        if (current == NULL)
////            return;
////
////        node* smallest = current;
////
////        if (current->left && current->left->data < smallest->data)
////        {
////            smallest = current->left;
////        }
////        if (current->right && current->right->data < smallest->data)
////        {
////            smallest = current->right;
////        }
////
////        if (smallest != current)
////        {
////            int temp = current->data;
////            current->data = smallest->data;
////            smallest->data = temp;
////            min_heapify(smallest);
////        }
////    }
////
////
////    void to_min_heap(node* current)
////    {
////        if (current->left)
////            to_min_heap(current->left);
////
////        if (current->right)
////            to_min_heap(current->right);
////
////        min_heapify(current);
////    }
////
////    void inorder(node* current)
////    {
////        if (current == NULL)
////            return;
////
////        inorder(current->left);
////        cout << current->data << " ";
////        inorder(current->right);
////    }
////};
////
////int main()
////{
////    min_heap obj;
////
////    while (true)
////    {
////        cout << "1.insert element\n";
////        cout << "2.convert to nin-heap\n";
////        cout << "3.display min-heap\n";
////        cout << "4.exit\n";
////        int ch;  cin >> ch;
////
////        if (ch == 1)
////        {
////            cout << "Enter element to insert: ";
////            int data; cin >> data;
////            obj.insert(data);
////        }
////        else if (ch == 2)
////        {
////            obj.to_min_heap(obj.root);
////        }
////        else if (ch == 3)
////        {
////            obj.inorder(obj.root);
////            cout << endl;
////        }
////        else if (ch == 4)
////        {
////            break;
////        }
////        else
////        {
////            cout << "enter valid choice\n";
////        }
////    }
////
////    return 0;
////}
