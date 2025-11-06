// 1. pick a pivot and place it in its correct place in the sorted array
// 2. smaller on the left, larger on the right
// 3. keep on swapping & repeating as array gets smaller
//  TC - O(n logn)

#include <iostream>
using namespace std;

int partition_Index(int a[], int low, int high) // to find the correct sorted position of pivot in the array
{
    int pivot = a[low];
    int i = low, j = high;
    while (i < j)
    {
        while (a[i] < pivot && i <= high)
        {
            i++;
        }
        while (a[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
            swap(a[i], a[j]);
    }
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int index = partition_Index(a, low, high);
        quick_sort(a, low, index - 1);
        quick_sort(a, index + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}