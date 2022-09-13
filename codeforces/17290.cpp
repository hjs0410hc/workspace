#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
    {
        cout << 1 << "\n";
        return;
    }
    int calc1 = a;
    int calc2 = b < c ? b + 2 * (c - b) : b;

    if (calc1 < calc2)
    {
        cout << 1 << "\n";
    }
    else if (calc1 > calc2)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 3 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}