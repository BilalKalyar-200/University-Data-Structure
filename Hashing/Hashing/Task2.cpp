////I was assigned to-->
// /*Library Book Management :
// Part i: Storing books using hash function h(ISBN) = ISBN % 15.
// Two collision strategies:
// 1) Sequential Probing: Use the next available slot in order.
// 2) Variable Steps: Use a dynamic step size to resolve collisions.
// Simulate both methods to analyze efficiency.
// Part ii: To improve performance:
// - Max load factor set to 70% (rehashing required beyond this).
// - Secondary Hashing: Use another hash function to calculate step size for collision resolution.
// Write code to implement these techniques and analyze efficiency, determining when rehashing is needed.*/
//
//


#include <iostream>
using namespace std;
#include "Task2.h"
int main()
{
    Hash_class linear_obj, double_obj;
    int ch;
    int numBooks;
    int* books;

    while (true)
    {
        cout << "1.Insert books\n";
        cout << "2.Display---> Linear Probing\n";
        cout << "3.Display---> Double Hashing\n";
        cout << "4.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter number of books: ";
            cin >> numBooks;

            books = new int[numBooks];

            cout << "Enter " << numBooks << " book IDs:\n";
            for (int i = 0; i < numBooks; i++) 
            {
                cin >> books[i];
            }

            for (int i = 0; i < numBooks; i++)
            {
                linear_obj.insertLinear(books[i]);
            }

            for (int i = 0; i < numBooks; i++) {
                double_obj.insertDoubleHash(books[i]);
            }

        }
        else if (ch == 2) 
        {
            cout << "\nDisplaying books using Linear Probing\n";
            linear_obj.display();
        }
        else if (ch == 3) {
            cout << "\nDisplaying books using Double Hashing\n";
            double_obj.display();
        }
        else if (ch == 4)
        {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Enter valid choice\n";
        }
    }
}