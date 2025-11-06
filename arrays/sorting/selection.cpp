// find minimum and swap
// done in n-1 steps, n = size
// time complexity - O(n^2)
#include <iostream>
using namespace std;

void selection(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) // till n-2th index because last element will always be sorted
    {
        for (j = i; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[j], a[i]);
            }
        }
    }
}
int main()
{
    int a[] = {13, 45, 9, 2, 23};
    int n = sizeof(a) / sizeof(a[0]);

    selection(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}