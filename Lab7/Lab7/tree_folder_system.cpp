#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string name;
    Node* left;
    Node* right;

    Node(string FN)
    {
        name = FN;
        left = right = nullptr;
    }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert(string FN)
    {
        Node* ptr = new Node(FN);

        if (root == nullptr)
        {
            root = ptr;
            return;
        }

        insert_recursion(root, ptr);
    }

    void insert_recursion(Node* current, Node* ptr)
    {
        if (current->left == nullptr)
        {
            current->left = ptr;
        }
        else if (current->right == nullptr)
        {
            current->right = ptr;
        }
        else
        {
            insert_recursion(current->left, ptr);
        }
    }

    void pre_order_traverse(Node* node)
    {
        if (node == nullptr)
            return;
        cout << node->name << " ";
        pre_order_traverse(node->left);
        pre_order_traverse(node->right);
    }

    void post_order_travese(Node* node)
    {
        if (node == nullptr)
            return;
        post_order_travese(node->left);
        post_order_travese(node->right);
        cout << node->name << " ";
    }

    void in_order_traverse(Node* node)
    {
        if (node == nullptr)
            return;
        in_order_traverse(node->left);
        cout << node->name << " ";
        in_order_traverse(node->right);
    }
};

int main()
{
    BinaryTree tree;
    int num;

    cout << "How many folders do you want to add? ";
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++)
    {
        cout << "Enter name of folder " << i + 1 << ": ";
        string FN;
        getline(cin, FN);
        tree.insert(FN);
    }
    while (true) {
        int ch;
        cout << "\nchoose traversal method:\n";
        cout << "1.pre order traversal\n";
        cout << "2.post order traversal\n";
        cout << "3.in order traversal\n";
        cout << "4.Exit\n";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Pre-order traversal:\n";
            tree.pre_order_traverse(tree.root);
        }
        else if (ch == 2)
        {
            cout << "Post-order traversal:\n";
            tree.post_order_travese(tree.root);
        }
        else if (ch == 3)
        {
            cout << "In-order traversal:\n";
            tree.in_order_traverse(tree.root);
        }
        else if (ch == 4) break;
        else
        {
            cout << "Invalid ch!";
        }
        cout << endl;
    }

    return 0;
}
