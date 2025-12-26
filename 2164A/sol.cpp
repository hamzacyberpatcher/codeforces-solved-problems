#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> sizes(n);
    vector<vector<int>> seq(n);
    vector<int> targets(n);

    for(int i = 0; i < n; i++)
    {
        cin >> sizes[i];

        for(int j = 0; j < sizes[i]; j++)
        {
            int x;
            cin >> x;

            seq[i].push_back(x);
        }

        cin >> targets[i];
    }

    for(int i = 0; i < n; i++)
    {
        sort(seq[i].begin(), seq[i].end());

        if (targets[i] >= seq[i][0] && targets[i] <= seq[i][sizes[i] - 1])
            cout << "yes\n";
        else
            cout << "no\n";
    }
}