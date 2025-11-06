#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int a;
    for (a = 1; a <= 5; a++)
    {
        vec.push_back(a);
    }
    vector<int>::iterator i;
    for (i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    auto ji = vec.begin();
    for (ji = vec.begin(); ji != vec.end(); ji++)
    {
        cout << *ji << " ";
    }
    vec.insert(vec.begin() + 1, 5);
    cout << endl;

    for (ji = vec.begin(); ji != vec.end(); ji++)
    {
        cout << *ji << " ";
    }
    return 0;
}