#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <bit>
#include <chrono>

using namespace std;

#define YN(valid) cout << (valid ? "YES" : "NO") << endl;
#define nl cout << endl
#define ll long long int
#define ld long double
#define L(i, j, n) for (ll i = j; i < n; i++)
#define R(i, j, n) for (ll i = j; i >= n; i--)
#define vn vector<int>
#define PLL pair<ll, ll>
#define PII pair<int, int>
#define pb push_back
#define vll vector<long long>


const double eps = 1e-9;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

bool checkVowel(char c) {
    if (c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

ll XOR1toN(ll n) {
    if (n % 4 == 1) return 1LL;
    if (n % 4 == 2) return n + 1LL;
    if (n % 4 == 3) return 0LL;
    return n;
}

inline bool isPrime(long long n)
{
    if (n < 2) return false;
    if (n < 4) return true;          // 2, 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}


void solve() {
    int n; cin >> n;
    vector<vector<int>> al(n + 1, vector<int>(2));

    L(i, 1, n + 1)
    {
        cin >> al[i][0] >> al[i][1];
    }

    vector<bool> visited(n + 1, false);

    vn ans;

    visited[1] = true;
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int u = q.front(); q.pop();

        ans.pb(u);
        int first = al[u][0];
        int second = al[u][1];
        visited[u] = true;

        if (!visited[first] && (al[first][0] == second || al[first][1] == second))
        {
            q.push(first);
        } else if (!visited[second])
        {
            q.push(second);
        }
    }

    for(auto x:ans) cout << x << ' ';
    cout << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--)
    solve();

    return 0LL;
}