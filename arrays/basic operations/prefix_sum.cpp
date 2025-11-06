#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4};
    int size = sizeof(a) / sizeof(a[0]);

    int prefix[size], i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += a[i];
        prefix[i] = sum;
    }

    for (i = 0; i < size; i++)
    {
        cout << prefix[i] << " ";
    }
}