#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, string& arrangement, string& name)
{
    sort(arrangement.begin(), arrangement.end());
    sort(name.begin(), name.end());

    for(int i = 0; i < n; i++)
    {
        if (arrangement[i] != name[i])
            return false;
    }

    return true;
}

int main()
{
    int n;

    cin >> n;

    vector<int> cubes(n);
    vector<string> arrangemts(n), names(n);

    for(int i = 0; i < n; i++)
    {
        cin >> cubes[i] >> arrangemts[i] >> names[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << (isPossible(cubes[i], arrangemts[i], names[i]) ? "YES" : "NO") << endl;
    }

    return 0;


}