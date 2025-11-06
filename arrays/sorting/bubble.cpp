// find max and swap through end
// done in n-1 steps in worst case scenario, else depends on how many unsorted numbers (unsorted nos - 1)
//  Time Complexity - O(n^2) for worst case and avg case; O(n) for best case

#include <iostream>
using namespace std;

void bubble(int a[], int n)
{
    int i, j;
    for (i = n - 1; i >= 1; i--) // n-1 passes
    {
        bool swapped = false;
        for (j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        cout << "ran" << endl;
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
    bubble(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}