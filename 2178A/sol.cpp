#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long

void solve()
{
    string str;

    cin >> str;

    while(str.size() > 1)
    {


        bool allN = true;

        for(int i= 0; i < str.size() && allN; i++)
            if (str[i] == 'Y') allN = false;

        if (allN)
        {
            cout << "yes\n"; break;
        }

        

        bool allY = true;

        for(int i= 0; i < str.size() && allY; i++)
            if (str[i] == 'N') allY = false;

        if (allY)
        {
            cout << "no\n"; break;
        }

        for(int i = 0; i < str.size() - 1; i++)
        {
            

            if (str[i] == 'N' && str[i + 1] == 'N')
            {
                str.erase(i, 1);
                i--;
            }
            else if (str[i] != str[i + 1])
            {
                str[i] = 'Y';
                str.erase(i + 1, 1);
                i--;
            }

        }
    }

    if (str.size() == 1)
        cout << "yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while(t--) solve();
}