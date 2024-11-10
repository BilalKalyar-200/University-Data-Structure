#pragma once

class node 
{
public:
    int data;
    node* left;
    node* right;
    node(int val);
};

class queue_node {
public:
    node* data;
    queue_node* next;
    queue_node(node* n);
};

class queue {
    queue_node* front;
    queue_node* back;
public:
    queue();
    bool is_empty();
    void enqueue(node* x);
    node* dequeue();
    ~queue();
};

class binary_tree {
private:
    node* root;
public:
    binary_tree();
    void insert(int pre[], int post[], int& size);
    void display();
private:
    void insert_rec(int pre[], int post[], int& pre_idx, int start, int end, int size, node*& ptr);
};


