#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 1};
    int size = sizeof(a) / sizeof(a[0]);
    int k = 2;
    int sum = 0, i;
    for (i = 0; i < k; i++)
    {
        sum += a[i];
    }
    int maxSum = sum;
    for (i = k; i < size; i++)
    {
        sum = sum - a[i - k] + a[i];
        maxSum = max(sum, maxSum);
    }
    cout << maxSum;
}