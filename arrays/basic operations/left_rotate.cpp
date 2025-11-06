#include <iostream>
using namespace std;
// 32145, 32154, 45123
void reverse(int a[], int start, int end);

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int n;
    cout << "How many times to rotate left: "; // 3 --> 4,5,1,2,3
    cin >> n;

    reverse(a, 0, n - 1);
    reverse(a, n, size - 1);
    reverse(a, 0, size - 1);

    cout << "New array: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}

void reverse(int a[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}