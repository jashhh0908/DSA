#include <iostream>
using namespace std;

void print(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
void move(int a[], int size)
{
    int j = 0, i, temp; // j for pointer of non zero, i for traversal
    for (i = 0; i < size; i++)
    {
        if (a[i] != 0)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
}

int main()
{
    int a[] = {1, 0, 2, 3, 0, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);

    move(a, size);
    print(a, size);
}
