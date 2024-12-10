/*E - commerce Product Catalog

Implement a hash table for product SKUs(17, 26, 15, 9, etc.) using chaining(linked lists)
and bucketing(multiple buckets per slot).Consider rehashing when the load factor 
70 % for better performance.Analyze pros and cons of each method for efficiency and performance*/

#include <iostream>
#include "Task3.h"
using namespace std;
int main() 
{
    int choice;
    int num;
    int* products;
    chaining_hash chainingTable;
    bucket_hash bucketingTable;
    while (true) {
        cout << "1. Insert\n";
        cout << "2. Display --> Chaining\n";
        cout << "3. Display --> Bucketing\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter number of products: ";
            cin >> num;

            products = new int[num]; 

            cout << "Enter " << num << " product IDs (keys):\n";
            for (int i = 0; i < num; i++) {
                cin >> products[i];
            }

            for (int i = 0; i < num; i++) {
                chainingTable.insert(products[i]);
                bucketingTable.insert(products[i]);
            }

            cout << "Products inserted successfully.\n";
        }
        else if (choice == 2)
        {
            cout << "\nHash Table with Chaining:\n";
            chainingTable.display();
        }
        else if (choice == 3) 
        {
            cout << "\nHash Table with Bucketing:\n";
            bucketingTable.display();
        }
        else if (choice == 4) 
        {
            cout << "Exiting the program.\n";
            break;
        }
        else {
            cout << "Enter a valid choice.\n";
        }
    }

    return 0;
}
