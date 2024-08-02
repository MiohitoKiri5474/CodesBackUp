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
#define GL ( n ) getline ( cin, n )
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

struct dsu {
    int dis[maxN];
    int sz[maxN];

    inline void init ( int n ) {
        for ( int i = 0 ; i < n ; i++ )
            dis[i] = i, sz[i] = 1;

    }

    inline int find ( int n ) {
        return dis[n] == n ? n : dis[n] = find ( dis[n] );
    }

    inline void Union ( int a, int b ) {
        a = find ( a ), b = find ( b );
        if ( sz[a] > sz[b] )
            swap ( a, b );
        dis[a] = b;
        sz[b] += sz[a];
    }

    inline bool same ( int a, int b ) {
        return find ( a ) == find ( b );
    }
} dis;

struct node {
    int u, v, w;

    inline bool operator < ( const node &b ) const {
        return w < b.w;
    }

    inline bool operator > ( const node &b ) const {
        return w > b.w;
    }
};

vector < pii > edges[maxN];
bitset < maxN > pushed;

inline void prim ( int n ) {
    LL ans = 0;
    MinHeap < node > pq;
    for ( auto [i, dist]: edges[0] )
        pq.push ( node { 0, i, dist } );
    pushed[0] = true;

    while ( dis.sz[dis.find ( 0 )] != n && !pq.empty() ) {
        auto [u, v, w] = pq.top();
        pq.pop();

        while ( !pq.empty() && dis.same ( u, v ) ) {
            u = pq.top().u, v = pq.top().v, w = pq.top().w;
            pq.pop();
        }
        dis.Union ( u, v );
        ans += w;

        if ( !pushed[u] ) {
            for ( auto [i, dist]: edges[u] )
                if ( !pushed[i] )
                    pq.push ( node { u, i, dist } );
            pushed[u] = true;
        }
        if ( !pushed[v] ) {
            for ( auto [i, dist]: edges[v] )
                if ( !pushed[i] )
                    pq.push ( node { v, i, dist } );
            pushed[v] = true;
        }
    }

    cout << ( dis.sz[dis.find ( 0 )] == n ? ans : -1 ) << '\n';
}

signed main() {
    gura;

    int n, m;
    while ( cin >> n >> m ) {
        // init
        dis.init ( n );
        for ( int i = 0 ; i < n ; i++ )
            edges[i].clear();
        pushed.reset();

        for ( int i = 0, u, v, w ; i < m ; i++ ) {
            cin >> u >> v >> w;
            edges[u].pb ( pii ( v, w ) );
            edges[v].pb ( pii ( u, w ) );
        }

        prim ( n );
    }
}
