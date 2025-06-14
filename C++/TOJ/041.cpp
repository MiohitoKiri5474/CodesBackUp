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
// #define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 100005;

struct node {
    int u, v, w;

    inline bool operator < ( const node &a ) const {
        return w < a.w;
    }
    inline bool operator > ( const node &a ) const {
        return w > a.w;
    }

    node (int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

int dis[maxN];
vector<pii> edges[maxN];
bitset<maxN> pushed;

int find (int x) {
    return dis[x] == x ? x : dis[x] = find(dis[x]);
}

signed main() {
    gura;

    int n, m, ans = 0, cnt = 0;
    MinHeap<node> pq;
    cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }

    for (int i = 0; i < n; i++)
        dis[i] = i;
    pushed[0] = true;
    for (auto [i, dist] : edges[0])
        pq.push(node(0, i, dist));

    while (!pq.empty() && cnt < n - 1) {
        auto [u, v, w] = pq.top();
        pq.pop();
        while (!pq.empty() && find(u) == find(v)) {
            u = pq.top().u;
            v = pq.top().v;
            w = pq.top().w;
            pq.pop();
        }

        cnt++;
        dis[find(u)] = find(v);
        ans += w;
        if (!pushed[u]) {
            pushed[u] = true;
            for (auto [i, dist] : edges[u])
                pq.push(node(u, i, dist));
        }
        if (!pushed[v]) {
            pushed[v] = true;
            for (auto [i, dist] : edges[v])
                pq.push(node(v, i, dist));
        }
    }

    cout << ( cnt == n - 1 ? ans : -1 ) << endl;
}
