//check right elements increasingly and if bigger swap left and keep on swapping leftward until it reaches the correct position
//TC : Best and Avg Case - O(n); Worst Case - O(n^2)
#include <iostream>
using namespace std;

void insertion(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j > 0 && a[j-1] > a[j])
        {
            swap(a[j-1], a[j]);
            j--;
        }
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
    insertion(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}