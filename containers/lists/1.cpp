#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4); // 2,4
    ls.push_front(1); //1,2,4
    for(int i : ls){
        cout << i << " ";
    }
}