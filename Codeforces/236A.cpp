#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    string str;
    cin >> str;

    sort(str.begin(), str.end());
    int count=1;
    for(size_t i=1; i<str.length(); i++)
    {
        if(str[i] != str[i-1])
        {
            count++;
        }
    }
    if((count%2) == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
}

int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}