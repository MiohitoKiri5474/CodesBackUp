#include<bits/stdc++.h>

using namespace std;

const int maxN = 100005;

struct dsu {
	int dis[maxN], rank[maxN];

	inline void init ( void );
	int find1 ( int );
	int find2 ( int );
	inline void Union1 ( int, int );
	inline void Union2 ( int, int );
	inline bool same ( int, int );
};

inline void dsu::init ( void ) {
	for ( int i = 0 ; i < maxN ; i++ )
		dis[i] = i, rank[i] = 1;
}

// basic version
int dsu::find ( int n ) {
	if ( dis[n] == n )
		return n;
	return find ( dis[n] );
}

// path compression version
int dsu::find ( int n ) {
	if ( dis[n] == n )
		return n;
	return dis[n] = find ( dis[n] );
}

// basic version
inline void dsu::Union1 ( int a, int b ) {
	dis[find ( a )] = find ( b );
}

// Union by Rank version
inline void dsu::Union2 ( int a, int b ) {
	if ( same ( a, b ) )
		return;
	a = find ( a ), b = find ( b );
	if ( rank[a] < rank[b] )
		swap ( a, b );
	dis[[dis[b]] = dis[a];
	rank[a]++;
}

inline bool dsu::same ( int a, int b ) {
	return find ( a ) == find ( b );
}
