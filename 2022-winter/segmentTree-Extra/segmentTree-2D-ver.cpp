// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 105

struct node1 {
	int seg[maxN << 2];

	inline void init ( void );
	void update ( int, int, int, int, int );
	int query ( int, int, int, int, int );
	inline void merge ( const node1, const node1, int l, int r, int n );
};

struct node2 {
	node1 seg[maxN << 2];
	int len;

	inline void init ( int, int, int );
	void build ( void );
	void update ( int, int, int, int, int, int );
	int query ( int, int, int, int, int, int, int );
};

// node1 function define

inline void node1::init ( void ) {
	memset ( seg, 0, sizeof seg );
}

void node1::update ( int l, int r, int index, int value, int n ) {
	if ( l == r )
		seg[n] = value;
	else {
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;

		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

int node1::query ( int l, int r, int nowL, int nowR, int n ) {
	if ( l <= nowL && nowR <= r )
		return seg[n];

	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;

	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

inline void node1::merge ( const node1 &a, const node1 &b, int l, int r, int n ) {
	seg[n] = max ( a.seg[n], b.seg[n] );
	if ( l == r )
		return;
	int mid = ( l + r ) >> 1;
	merge ( a, b, l, mid, n << 1 );
	merge ( a, b, mid + 1, r, ( n << 1 ) | 1 );
}


// node2 function define

inline void node2::init ( int u, int d, int _len ) {
	len = _len;
	build ( u, d, 1 );
}

void node2::build ( int u, int d, int n ) {
	int mid = ( u + d ) >> 1;
	seg[n].init();
	build ( u, mid );
	build ( mid + 1, d );
}

void node2::update ( int u, int d, int x, int y, int value, int n ) {
	if ( u == d )
		seg[n].update ( 1, len, y, value, 1 );
	else{
		int mid = ( u + d ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( x <= mid )
			update ( u, mid, x, y, value, leftSon );
		else
			update ( mid + 1, d, x, y, value, rightSon );

		seg[n].merge ( seg[leftSon], seg[rightSon], 1, len, 1 );
	}
}

int node2::query ( int u, int d, int nowU, int nowD, int l, int r, int n ) {
	if ( u <= nowU && nowD <= d )
		return seg[n].query ( l, r, 1, len, 1 );
	int mid = ( nowU + nowD ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( d <= mid )
		return query ( u, d, nowU, mid, l, r, leftSon );
	if ( mid < u )
		return query ( u, d, mid + 1, nowD, l, r, rightSon );

	return max ( query ( u, d, nowU, mid, l, r, leftSon ), query ( u, d, mid + 1, nowD, l, r, rightSon ) );
}
