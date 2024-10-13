//#include <iostream>
//using namespace std;
//
//class Node 
//{
//public:
//    int data;
//    Node* left;
//    Node* right;
//
//    Node() {
//        data = 0;
//        left = right = nullptr;
//    }
//};
//
//class QueueNode 
//{
//public:
//    Node* treeNode;
//    QueueNode* next;
//
//    QueueNode(Node* node) 
//    {
//        treeNode = node;
//        next = NULL;
//    }
//};
//
//class Queue 
//{
//    QueueNode* front;
//    QueueNode* rear;
//public:
//    Queue() 
//    {
//        front = rear = NULL;
//    }
//
//    bool isEmpty() 
//    {
//        return front == NULL;
//    }
//
//    void enqueue(Node* node) 
//    {
//        QueueNode* ptr = new QueueNode(node);
//        if (rear == NULL) 
//        {
//            front = rear = ptr;
//        }
//        else
//        {
//            rear->next = ptr;
//            rear = ptr;
//        }
//    }
//
//    Node* dequeue() 
//    {
//        if (isEmpty()) 
//            return NULL;
//        QueueNode* temp = front;
//        front = front->next;
//        if (front == NULL)
//        {
//            rear = nullptr;
//        }
//        Node* treeNode = temp->treeNode;
//        delete temp;
//        return treeNode;
//    }
//};
//
//class BinaryTree 
//{
//public:
//    Node* root;
//
//    BinaryTree() 
//    {
//        root = NULL;
//    }
//
//    void insert(int value) 
//    {
//        Node* ptr= new Node;
//        ptr->data = value;
//        if (root == NULL)
//        {
//            root = ptr;
//            return;
//        }
//
//        Queue q;
//        q.enqueue(root);
//
//        while (!q.isEmpty()) 
//        {
//            Node* current = q.dequeue();
//
//            if (current->left == NULL)
//            {
//                current->left = ptr;
//                break;
//            }
//            else 
//            {
//                q.enqueue(current->left);
//            }
//
//            if (current->right == nullptr) 
//            {
//                current->right = ptr;
//                break;
//            }
//            else 
//            {
//                q.enqueue(current->right);
//            }
//        }
//    }
//
//    void bfsTraversal() 
//    {
//        if (root == NULL)
//            return;
//
//        Queue q;
//        q.enqueue(root);
//
//        while (!q.isEmpty()) 
//        {
//            Node* temp = q.dequeue();
//            cout << temp->data << "-";
//
//            if (temp->left != NULL)
//            {
//                q.enqueue(temp->left);
//            }
//
//            if (temp->right != NULL)
//            {
//                q.enqueue(temp->right);
//            }
//        }
//    }
//};
//
//int main() 
//{
//    BinaryTree bt;
//    cout << "How many nodes you want in tree: ";
//    int size; cin >> size;
//    for (int i = 0; i < size; i++)
//    {
//        cout << "Enter value of leave " << i + 1 << ":";
//        int val; cin >> val;
//        bt.insert(val);
//    }
//    cout << "printing value using breadth first traversal\n";
//    bt.bfsTraversal();
//
//    return 0;
//}
