#pragma once

class Hash_class 
{
    static const int size_table = 15; //hash table size
    int table[size_table];
    bool occupied[size_table];

    int hashFunction(int key);        //primary hash function
    int secondaryHash(int key);       //secondary hash function

public:
    Hash_class();                     
    void insertLinear(int key);       
    void insertDoubleHash(int key);
    void display();                   
};


