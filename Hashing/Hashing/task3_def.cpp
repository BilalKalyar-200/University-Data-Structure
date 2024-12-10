#include "Task3.h"
#include <iostream>
using namespace std;

Node::Node(int k) {
    key = k;
    next = nullptr;
}

chaining_hash::chaining_hash() 
{
    for (int i = 0; i < SIZE; ++i) {
        table[i] = nullptr;
    }
}

int chaining_hash::hashFunction(int key)
{
    return key % SIZE;
}

void chaining_hash::insert(int key) 
{
    int index = hashFunction(key);
    Node* newNode = new Node(key);

    if (!table[index])
    {
        table[index] = newNode;
    }
    else {
        Node* current = table[index];
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void chaining_hash::display() 
{
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current) {
            cout << current->key << " -> ";
            current = current->next;
        }
        cout << "[NULL]" << endl;
    }
}


bucket_hash::bucket_hash() 
{
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        for (int j = 0; j < BUCKET_SIZE; ++j)
        {
            table[i][j] = -1;
        }
        bucketCounts[i] = 0;
    }
}

int bucket_hash::hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void bucket_hash::insert(int key) {
    int index = hashFunction(key);

    if (bucketCounts[index] < BUCKET_SIZE)
    {
        table[index][bucketCounts[index]] = key;
        bucketCounts[index]++;
    }
    else {
        cout << "Bucket overflow at slot " << index << " for key " << key << endl;
    }
}

void bucket_hash::display()
{
    for (int i = 0; i < TABLE_SIZE; ++i) 
    {
        cout << "Slot " << i << ": ";
        for (int j = 0; j < bucketCounts[i]; ++j) 
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}