#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
    node() {
        data = 0;
        left = right = NULL;
    }
};

node* buildTree(int* pre_order, int* post_order, int& preIndex, int start, int end, int size)
{
    if (preIndex >= size || start > end) // Base case
        return nullptr;

    // Creating root from preorder because the first element in preorder is always the root
    node* root = new node(pre_order[preIndex++]);

    // When there is only one element, no need to find left and right children
    if (start == end) return root;

    // Find the index of the next element in preorder within the postorder array
    int i;
    for (i = start; i <= end; i++) {
        if (post_order[i] == pre_order[preIndex]) break;
    }

    // If we found a match, recursively construct the left and right subtrees
    if (i <= end) {
        root->left = buildTree(pre_order, post_order, preIndex, start, i, size);
        root->right = buildTree(pre_order, post_order, preIndex, i + 1, end - 1, size);
    }

    return root;
}

node* create_tree(int* pre_order, int* post_order, int size)
{
    int preIndex = 0;
    return buildTree(pre_order, post_order, preIndex, 0, size - 1, size);
}

void inorder(node* root)
{
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    int size;
    cout << "Enter the number of nodes: ";
    cin >> size;

    int* pre_order = new int[size];
    int* post_order = new int[size];

    cout << "Enter preorder array: ";
    for (int i = 0; i < size; i++) cin >> pre_order[i];

    cout << "Enter postorder array: ";
    for (int i = 0; i < size; i++) cin >> post_order[i];

    node* root = create_tree(pre_order, post_order, size);

    cout << "Inorder traversal of constructed tree: ";
    inorder(root);
    cout << endl;

    delete[] pre_order;
    delete[] post_order;

    return 0;
}
