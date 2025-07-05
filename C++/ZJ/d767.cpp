// by. MiohitoKiri5474
#include <bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

// type and pair definition
using LL = long long;
using pii = pair < LL, LL >;
using sstr = stringstream;
#define F first
#define S second
#define mp make_pair

// general definition
#define pb push_back
#define ep emplace_back
#define GL(n) getline ( cin, n )
#define gura ios::sync_with_stdio(false);cin.tie(0)

// define heap
template < class T > using MaxHeap = priority_queue < T, vector < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// number definition
#define INF 0x3f3f3f3f

// some defiine for programing contest
#define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 30005;
const int maxLog = 19;

vector<int> edges[maxN];
int dep[maxN], dp[maxN][maxLog];

void dfs (int n, int p, int d) {
    dep[n] = ++d;
    dp[n][0] = p;
    for (auto i: edges[n]) {
        if (i == p)
            continue;
        dfs(i, n, d);
    }
}

inline void buildLCA (int n) {
    memset (dp, -1, sizeof dp);
    dfs (1, -1, 0);
    for (int k = 1; k < maxLog; k++)
        for (int i = 1; i <= n; i++)
            if (dp[i][k - 1] != -1)
                dp[i][k] = dp[dp[i][k - 1]][k - 1];
}

signed main() {
    gura;

    int n, q, u, v, du, dv;
    cin >> n >> q;
    for (int i = 1, in; i <= n; i++) {
        while (cin >> in) {
            if (!in)
                break;
            edges[i].pb(in);
        }
    }

    buildLCA(n);

    while (q--) {
        cin >> u >> v;

        if (dep[u] > dep[v])
            swap(u, v);

        du = dep[u], dv = dep[v];

        for (int k = maxLog - 1; k >= 0; k--)
            if (dp[v][k] != -1 && dep[dp[v][k]] >= dep[u])
                v = dp[v][k];

        if (u == v) {
            cout << u << ' ' << dv - du << '\n';
            continue;
        }

        for (int k = maxLog - 1; k >= 0; k--)
            if (dp[u][k] != dp[v][k])
                u = dp[u][k], v = dp[v][k];

        cout << dp[u][0] << ' ' << du + dv - (dep[dp[u][0]] << 1) << '\n';
    }
}
