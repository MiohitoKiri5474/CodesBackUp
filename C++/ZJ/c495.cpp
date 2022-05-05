#include<bits/stdc++.h>

using namespace std;

const int maxN = 100005;

struct node {
	int u, v, w;

	inline bool operator < ( const node &b ) const {
		return w < b.w;
	}
};

vector < node > edges, unused;

struct dsu {
	int dis[maxN];

	inline void init ( void ) {
		for ( int i = 0 ; i < n ; i++ )
			dis[i] = i;
	}

	int find ( int n ) {
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	inline void Union ( int a, int b ) {
		dis[find ( a )] = find ( b );
	}

	inline bool same ( int a, int b ) {
		return find ( a ) == find ( b );
	}
};

int dist[maxN];

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	dsu dis;
	int n, m, u, v, w;
	cin >> n >> m;
	for ( int i = 0 ; i < m ; i++ ) {
		cin >> u >> v >> w;
		edges.pb ( node { u, v, w } );
	}

	sort ( edges.begin(), edges.end() );
	dis.init();

	// Kruskal
	for ( auto i: edges ) {
		if ( dis.same ( i.u, i.v ) ) {
			unused.pb ( i );
			continue;
		}
		dis.Union ( i.u, i.v );
		tree[i.u].pb ( pii ( i.v, i.w ) );
		tree[i.v].pb ( pii ( i.u, i.w ) );
	}
}
