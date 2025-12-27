#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;

    int m; cin >> m;

    for(int i = 0; i < n - 1; i++)
    {
        int num; cin >> num;
        m = max(m, num);
    }

    cout << m << endl;


}

int main()
{
    int t; cin >> t;
    while(t--) solve();
}