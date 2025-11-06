#include <iostream>
#include <unordered_map>
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

    /*for(auto it : freq){
        cout << it.first << " = " << it.second << endl;
    }*/
    int t;
    cout << "Enter testcases: ";
    cin >> t;
    while (t--)
    {
        int num;
        cout << "Enter number whose frequency you want to find: ";
        cin >> num;
        cout << "Frequency of " << num << " is = " << freq[num] << endl;
    }
}