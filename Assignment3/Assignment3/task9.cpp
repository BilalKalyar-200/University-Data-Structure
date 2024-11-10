#include "task9.h"
#include <iostream>
using namespace std;

node::node(int val)
{
    left = right = NULL;
    data = val;
}

queue_node::queue_node(node* n)
{
    data = n;
    next = NULL;
}

queue::queue()
{
    front = back = NULL;

}

bool queue::is_empty()
{
    return front == NULL;
}

void queue::enqueue(node* x)
{
    queue_node* new_node = new queue_node(x);
    if (is_empty()) {
        front = back = new_node;
    }
    else {
        back->next = new_node;
        back = new_node;
    }
}

node* queue::dequeue()
{
    if (is_empty()) {
        return NULL;
    }
    queue_node* temp = front;
    front = front->next;
    node* data = temp->data;
    delete temp;
    return data;
}

queue::~queue() {
    while (!is_empty()) {
        dequeue();
    }
}

binary_tree::binary_tree() {
    root = NULL;
}
void binary_tree::insert_rec(int pre[], int post[], int& pre_idx, int start, int end, int size, node*& ptr)
{
    if (pre_idx >= size || start > end)
    {
        ptr = NULL;
        return;
    }
    ptr = new node(pre[pre_idx++]);
    if (start == end) return;

    int i;
    for (i = start; i <= end; i++) {
        if (pre[pre_idx] == post[i]) break;
    }
    if (i <= end)
    {
        insert_rec(pre, post, pre_idx, start, i, size, ptr->left);
        insert_rec(pre, post, pre_idx, i + 1, end - 1, size, ptr->right);
    }
}

void binary_tree::insert(int pre[], int post[], int& size)
{
    int start = 0;
    insert_rec(pre, post, start, 0, size - 1, size, root);
}


void binary_tree::display()
{
    if (!root)
    {
        cout << "tree is empty\n";
        return;
    }

    cout << "level order traversal: ";
    queue q;
    q.enqueue(root);

    while (!q.is_empty())
    {
        node* curr = q.dequeue();
        cout << curr->data << " ";
        if (curr->left) q.enqueue(curr->left);
        if (curr->right) q.enqueue(curr->right);
    }
    cout << endl;
}
