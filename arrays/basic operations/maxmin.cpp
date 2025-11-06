#include <iostream>
using namespace std;

int max(int a[], int size)
{
    int m = a[0], i;
    for (i = 0; i < size; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    return m;
}
int min(int a[], int size)
{
    int m = a[0], i;
    for (i = 0; i < size; i++)
    {
        if (a[i] < m)
            m = a[i];
    }
    return m;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int Max = max(a, size);
    int Min = min(a, size);
    cout << "Maximum = " << Max << endl;
    cout << "Minimum = " << Min << endl;
    return 0;
}