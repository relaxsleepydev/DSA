#include <iostream>
using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    long long counter=0;
    while(a%b!=0)
    {
        a+=1;
        counter++;
    }
    cout << counter << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

// efficient solution
#include <iostream>
using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;

    if(a%b==0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (b-(a%b)) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}