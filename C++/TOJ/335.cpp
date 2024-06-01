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
#define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 100005;
const int maxLog = 20;

struct node {
    int u, v, w;
};

inline bool cmp ( node a, node b ) {
    return a.w > b.w;
}

vector < node > edges;
vector < pii > mst[maxN];
int mi, dis[maxN], D[maxN], n;
pii dp[maxN][maxLog];

inline void init ( void ) {
    for ( int i = 0 ; i < maxN ; i++ )
        dis[i] = i;
}

// disjoin set
int find ( int a ){
    return dis[a] == a ? a : dis[a] = find ( dis[a] );
}

inline void Union ( int a, int b ) {
    dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ) {
    return find ( a ) == find ( b );
}

// Kruskal
inline void Kruskal ( void ) {
    sort ( edges.begin(), edges.end(), cmp );
    init();
    for ( auto [u, v, w]: edges ) {
        if ( same ( u, v ) )
            continue;
        mst[u].pb ( pii ( v, w ) );
        mst[v].pb ( pii ( u, w ) );
        Union ( u, v );
    }
}

inline void dfs ( int d, int p, int dep ){
    D[d] = dep++;
    dp[d][0].F = p;
    for ( auto i: mst[d] ) {
    	if ( i.F == p )
    		continue;
    	dp[i.F][0] = pii ( d, i.S );
    	dfs ( i.F, d, dep );
    }
}

inline void buildLCA ( void ){
    for ( int i = 0 ; i < n ; i++ )
    	for ( int j = 0 ; j < maxLog ; j++ )
    		dp[i][j] = pii ( -1, INF );
    memset ( D, 0, sizeof ( D ) );
    dfs ( 0, -1, 0 );

    for ( int k = 1 ; k < maxLog ; k++ ) {
    	for ( int i = 0 ; i < n ; i++ ) {
    		if ( dp[i][k - 1].F == -1 )
    			continue;
    		dp[i][k].F = dp[dp[i][k - 1].F][k - 1].F;
    		dp[i][k].S = min ( dp[i][k - 1].S, dp[dp[i][k - 1].F][k - 1].S );
    	}
    }
}

inline int findLCA ( int x, int y ){
    int mi = INF;
    if ( D[x] < D[y] )
    	swap ( x, y );

    for ( int i = maxLog - 1 ; i >= 0 ; i-- ) {
    	if ( dp[x][i].F != -1 && D[dp[x][i].F] >= D[y] ){
    		mi = min ( mi, dp[x][i].S );
    		x = dp[x][i].F;
    	}
    }

    if ( x == y )
    	return mi;

    for ( int i = maxLog - 1 ; i >= 0 ; i-- ) {
    	if ( dp[x][i].F != dp[y][i].F ){
    		mi = min ( mi, min ( dp[x][i].S, dp[y][i].S ) );
    		x = dp[x][i].F, y = dp[y][i].F;
    	}
    }

    return min ( mi, min ( dp[x][0].S, dp[y][0].S ) );
}

signed main() {
    gura;

    int m, q, u, v, w;
    cin >> n >> m;
    while ( m-- ) {
        cin >> u >> v >> w;
        edges.pb ( node { u, v, w } );
    }

    Kruskal();
    buildLCA();

    cin >> q;
    while ( q-- ) {
        cin >> u >> v;
        cout << findLCA ( u, v ) << endl;
    }
}
