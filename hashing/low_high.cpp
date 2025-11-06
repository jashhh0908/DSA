#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n], i;
    cout << "Enter elements of array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for (i = 0; i < n; i++)
    {
        freq[arr[i]] += 1;
    }

    int max = 0, min = n + 1;
    for (auto it : freq)
    {
        if (it.second < min)
        {
            min = it.second;
        }
        else if (it.second > max)
        {
            max = it.second;
        }
    }

    vector<int> max_val, min_val;
    for (auto it : freq)
    {
        if (it.second == min)
            min_val.push_back(it.first);
        if (it.second == max)
            max_val.push_back(it.first);
    }
    cout << "Lowest occuring number (frequency: " << min << ") : ";
    for (auto it : min_val)
    {
        cout << it << " ";
    }
    cout << "\nHighest occuring number (frequency: " << max << ") : ";
    for (auto it : max_val)
    {
        cout << it << " ";
    }
}