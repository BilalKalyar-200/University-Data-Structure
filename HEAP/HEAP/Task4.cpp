//TASK IS:
//Input a binary search tree which is also a complete binary tree and convert it to Min heap.The
//problem is to convert the given BST into a Min Heap with the condition that all the values in the
//left subtree of a node should be less than all the values in the right subtree of the node.This
//condition is applied on all the nodes in the so converted Min Heap.
//1. Create an array arr[] of size n, where n is the number of nodes in the given BST.
//2. Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted
//order.
//3. Now perform the preorder traversal of the tree.While traversing the root during the
//preorder traversal, one by one copy the values from the array arr[] to the nodes
//
//
//#include <iostream>
//using namespace std;
//
//class node {
//public:
//    int data;
//    node* left;
//    node* right;
//
//    node(int val)
//    {
//        left = right = NULL;
//        data = val;
//    }
//};
//
//class BST {
//public:
//    BST()
//    {
//        root = NULL;
//        arr = NULL;
//        index = 0;
//    }
//
//    bool is_empty()
//    {
//        return root == NULL;
//    }
//
//    node* root;
//s    int* arr;
//    int index;
//
//    node* insert(node* root, int data)      //insert in BST
//    {
//        if (root == nullptr)
//            return new node(data);
//
//        if (data < root->data)
//        {
//            root->left = insert(root->left, data);
//        }
//        else {
//            root->right = insert(root->right, data);
//        }
//
//        return root;
//    }
//
//    
//    void inorder_convert(node* root, int* arr, int& index)
//    {//function to insert in inorder format in array
//        if (root == nullptr)
//            return;
//
//        inorder_convert(root->left, arr, index);
//        arr[index] = root->data;
//        index++;
//        inorder_convert(root->right, arr, index);
//    }
//
//    //min-heap using array (pre-order)
//    void preorder_traversal(node* root)
//    {
//        if (root == nullptr)
//            return;
//
//        root->data = arr[index];
//        index++;
//
//        preorder_traversal(root->left);
//        preorder_traversal(root->right);
//    }
//
//    //function to convert BST to Min Heap
//    void convert_to_min_heap()
//    {
//        int n = count_nodes(root);
//        arr = new int[n];
//        index = 0;
//
//        inorder_convert(root, arr, index);   //to store elements in inorder in array
//
//        index = 0;      //as we are creating new so setting to 0
//
//        preorder_traversal(root);
//    }
//
//    int count_nodes(node* root)
//    {
//        if (root == NULL)
//            return 0;
//
//        return 1 + count_nodes(root->left) + count_nodes(root->right);
//    }
//
//    void print_inorder(node* root)
//    {
//        if (root == NULL)
//            return;
//
//        print_inorder(root->left);
//        cout << root->data << " ";
//        print_inorder(root->right);
//    }
//    void display_array(int size)
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
//    BST obj;
//
//    while (true)
//    {
//        cout << "1.insert\n";
//        cout << "2.convert BST to min heap\n";
//        cout << "3.display tree\n";
//        cout << "4.Display array\n";
//        cout << "5.Exit\n";
//        int ch;
//        cin >> ch;
//
//        if (ch == 1)
//        {
//            cout << "Enter element to insert: ";
//            int val;
//            cin >> val;
//            obj.root = obj.insert(obj.root, val);
//        }
//        else if (ch == 2)
//        {
//            obj.convert_to_min_heap();
//        }
//        else if (ch == 3)
//        {
//            if (!obj.is_empty())
//            {
//                cout << "displaying: ";
//                obj.print_inorder(obj.root);
//                cout << endl;
//            }
//            else
//            {
//                cout << "tree is empty\n";
//            }
//        }
//        else if (ch == 4)
//        {
//            obj.display_array(obj.count_nodes(obj.root));
//        }
//        else if (ch == 5)
//        {
//            break;
//        }
//        else
//        {
//            cout << "Enter valid choice\n";
//        }
//    }
//
//    return 0;
//}
