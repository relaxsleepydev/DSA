#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve()
{
    string str1, str2;
    cin >> str1 >> str2;

    reverse(str2.begin(), str2.end());
    if(str1 == str2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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