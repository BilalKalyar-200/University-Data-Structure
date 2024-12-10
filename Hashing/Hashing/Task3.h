#pragma once

const int TABLE_SIZE = 15;
const int BUCKET_SIZE = 3;

class Node {
public:
    int key;
    Node* next;

    Node(int k);
};

class chaining_hash {
    static const int SIZE = 15; //size of hash table
    Node* table[SIZE];

    int hashFunction(int key);

public:
    chaining_hash();
    void insert(int key);
    void display();
};


class bucket_hash {
    int table[TABLE_SIZE][BUCKET_SIZE];
    int bucketCounts[TABLE_SIZE];

    int hashFunction(int key);

public:
    bucket_hash();
    void insert(int key);
    void display();
};
