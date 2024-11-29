#include<iostream>
using namespace std;

int recursivesum(int n)
{
    if (n == 1)
    {
        return 0;
    }
    return n * n + recursivesum(n - 1);
}

int main()
{
    cout << "Enter number: ";
    int n;
    cin >> n;
    cout << recursivesum(n);
}