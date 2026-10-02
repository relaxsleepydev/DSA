#include <iostream>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    
    if(n%2==0)
    {
        cout << (n/2) << endl;
    }
    else
    {
        cout << -((n+1)/2) << endl;
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