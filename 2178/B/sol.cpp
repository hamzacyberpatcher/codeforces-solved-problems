#include <bits/stdc++.h>
using namespace std;

bool isSus(const string& str)
{
    if (str[0] == 'u' || str[str.size() - 1] == 'u')
        return false;
    
    bool allU = true;
    bool allS = true;

    for(auto ch : str)
    {
        if (ch == 's') allU = false;
        if (ch == 'u') allS = false;
    }

    if (allU) return false;

    if (allS) return true;

    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'u')
        {
            int ll = 0, lr = 0;

            for(int j = i - 1; j >= 0 && str[j] != 's'; j--)
                ll++;

            for(int j = i + 1; j < str.size() && str[j] != 's'; j++)
                lr++;


            if (ll != lr) return false;
        }
    }

    return true;
}

void solve()
{
    string str;

    cin >> str;

    if (isSus(str))
    {
        cout << 0 << "\n";
        return;
    }


    int steps = 0;

    if (str[0] == 'u')
    {
        str[0] = 's';
        steps++;
    }

    

    for(int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == 'u')
        {
            if (str[i + 1] == 'u')
            {
                str[i + 1] = 's';
                steps++;
            }
        }
    }

    if (str[str.size() - 1] == 'u')
        steps++;

    

    cout << steps << "\n";

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--) solve();

    
}