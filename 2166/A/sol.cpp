#include <bits/stdc++.h>
using namespace std;

int stepsRequired(int n, string str)
{
    int steps = 0;

    for(int i = n - 2; i >= 0; i--)
    {
        if (str[i] != str[i + 1])
        {
            str[i] = str[i + 1]; steps++;
        }
        else
            continue;
    }

    return steps;
}

int main()
{
    int n;

    cin >> n;

    vector<int> lengths(n);
    vector<string> strs(n);

    for(int i = 0; i < n; i++)
    {
        cin >> lengths[i] >> strs[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << stepsRequired(lengths[i], strs[i]) << endl;
    }

}