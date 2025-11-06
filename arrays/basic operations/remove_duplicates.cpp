#include <iostream>
using namespace std;

int remove(int a[], int size);
int main()
{
    int a[] = {1, 2, 2, 3, 3, 4, 4, 4};
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Length = " << remove(a,size);
}

int remove(int a[], int n)
{
    if (n == 0 || n == 1)
        return n;

    int k = 0, i;
    for (i = 1; i < n; i++)
    {
        if (a[i] != a[k])
        {
            k++;
            a[k] = a[i];
        }
    }
    return k + 1;
}