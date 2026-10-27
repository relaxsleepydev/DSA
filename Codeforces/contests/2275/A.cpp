#include <iostream>
using namespace std;

void solve()
{
    long long x0, y0, R;
    cin >> x0 >> y0 >> R;
    for(long long x = -R; x <= R; x++)
    {
        for(long long y = -R; y <= R; y++)
        {
            if(x*x + y*y == R*R)
            {
                cout << x0 + x << " " << y0 + y << endl;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}