// returning the frequency of inputted integers

#include <iostream>
using namespace std;
int hash_arr[10000000];
int main()
{
    int n;
    cin >> n;
    int arr[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    //precomputation
    for(i = 0; i < n; i++){
        hash_arr[arr[i]] += 1;
    }

    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        //fetch
        cout << "No of times " << num << " occurs = " << hash_arr[num] << endl; 
    }
}