#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> legs(n);

    for(int i = 0 ; i < n; i++)
    {
        int leg;
        cin >> leg;
        legs[i] = leg;
    }

    for(int i = 0; i < n; i++)
    {
        int leg = legs[i];

        if (leg & 1 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << leg / 4 + 1 << endl;
        }
    }

    return 0;
}