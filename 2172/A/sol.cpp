#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g, c, l;

    cin >> g >> c >> l;

    int maxScore = max(max(g, c), l);
    int minScore = min(min(g, c), l);

    int diff = maxScore - minScore;

    if (diff >= 10)
    {
        cout << "check again";
        return 0;
    }
    else
    {
        cout << "final " << (g + c + l) - maxScore - minScore;
    }

    return 0;


    
}