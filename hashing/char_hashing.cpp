#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i, hash_arr[256] = {0};
    for(i = 0; s[i] != '\0'; i++){
        hash_arr[s[i]] += 1;
    }

    int t;
    cin >> t;
    while(t--){
        char ch;
        cin >> ch;

        //fetch
        cout << "No of times " << ch << " occurs = " << hash_arr[ch] << endl; 
    }
}