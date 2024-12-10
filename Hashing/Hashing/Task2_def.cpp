#include "Task2.h"
#include <iostream>
using namespace std;

int Hash_class::hashFunction(int key)
{
    return key % size_table;
}

int Hash_class::secondaryHash(int key) 
{
    return 7 - (key % 7); //prime to avoid repetetion and 7 avoid -ve index
}

Hash_class::Hash_class()        //constructor
{
    for (int i = 0; i < size_table; i++)
    {
        table[i] = -1;
        occupied[i] = false;
    }
}

void Hash_class::insertLinear(int key)      //inserting using linear probing-> R(k, i) = (R(k) + i) % size of table
{
    int i = 0;
    int index = (hashFunction(key) + i) % size_table;

    while (occupied[index]) {
        i++;
        index = (hashFunction(key) + i) % size_table;
    }

    table[index] = key;
    occupied[index] = true;
}

void Hash_class::insertDoubleHash(int key)        //inserting using linear probing-> R(k, i) = (R(k) + i * R(k)) % size of table
{
    int i = 0;
    int index = (hashFunction(key) + i * secondaryHash(key)) % size_table;

    while (occupied[index]) {
        i++;
        index = (hashFunction(key) + i * secondaryHash(key)) % size_table;
    }

    table[index] = key;
    occupied[index] = true;
}

void Hash_class::display()          //displaying occupies places
{   
    for (int i = 0; i < size_table; i++)
    {
        if (occupied[i]) {
            cout << "Slot " << i << ": " << table[i] << endl;
        }
    }
}
