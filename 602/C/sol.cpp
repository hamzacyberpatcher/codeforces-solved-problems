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

int bfs(int start, int end, vector<vector<int>>& mat)
{
    vector<bool> visited(end + 1, false);

    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty())
    {
        int u = q.front().first;
        int level = q.front().second;
        q.pop();

        if (u == end) return level;

        L(v, 0, end + 1)
        {
            if (mat[u][v] && !visited[v])
            {
                visited[v] = true;
                q.push({v, level + 1});
            }
        }
    }

    return -1;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> rails(n, vector<int>(n, 0));

    L(i, 0, m)
    {
        int a, b; cin >> a >> b; a--; b--;
        rails[a][b] = 1;
        rails[b][a] = 1;
    }

    vector<vector<int>> roads(n, vector<int>(n, 0));

    L(i, 0, n)
    {
        L(j, 0, n)
        {
            if (i == j) continue;

            if (!rails[i][j])
            {
                roads[i][j] = 1;
                roads[j][i] = 1;
            }

        }
    }


    if (m == 0 || m == n * (n - 1) / 2)
    {
        cout << -1 << endl;
        return;
    }

    int dist1 = bfs(0, n - 1, rails);
    int dist2 = bfs(0, n - 1, roads);

    if (dist1 == -1 || dist2 == -1)
    {
        cout << -1 << endl;
        return;
    }

    cout << max(dist1, dist2) << endl;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();

    return 0LL;
}