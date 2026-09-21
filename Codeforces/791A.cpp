#include <iostream>
using namespace std;

void solve() 
{
    int x, y;
    cin >> x >> y;
    int count=0;
    while(x<=y)
    {
        x *= 3;
        y *= 2;
        count++;
    }
    cout << count << endl;
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