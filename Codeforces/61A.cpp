#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i] == s2[i])
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }
    }
    cout << endl;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}