#include<bits/stdc++.h>

using namespace std;

struct node {
	node *l, *r;
	int key, pri, sz;

	node ( int _key ): l ( nullptr ), r ( nullptr ), key ( _key ), pri ( rand() ), sz ( 1 ) {}

	inline void up ( void ) {
		sz = 1;
		if ( l )
			sz += l -> sz;
		if ( r )
			sz += r -> sz;
	}
};

inline int Size ( node *o ) {
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ) {
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ) {
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ) {
	if ( !o ) {
		a = b = nullptr;
		return;
	}
	if ( o -> key < k ) {
		a = o;
		split ( o -> r, a -> r, b, k );
	}
	else {
		b = o;
		split ( o -> l, a, b -> l, k );
	}
	o -> up();
}

inline void insert ( node *&o, int k ) {
	node *a, *b;
	split ( o, a, b, k );
	o = merge ( merge ( a, new node ( k ) ), b );
}

inline void erase1 ( node *&o, int k ) {
	if ( !o )
		return;
	node *a, *b, *c;
	split ( o, a, b, k );
	split ( b, b, c, k + 1 );
	o = merge ( a, merge ( merge ( b -> l, b -> r ), c ) );
}

void erase2 ( node *&o, int k ) {
	if ( !o )
		return;
	if ( o -> key == k ) {
		node *t = o;
		o = merge ( o -> l, o -> r );
		delete t;
		return;
	}
	node *&t = ( k < o -> key ? o -> l : o -> r );
	erase2 ( t, k );
	if ( t )
		o -> up();
}

inline int Rank ( node *o, int k ) {
	node *a, *b;
	split ( o, a, b, k );
	int res = ( a ? a -> sz : 0 );
	o = merge ( a, b );
	return res;
}

void split2 ( node *o, node *&a, node *&b, int k ) {
	if ( !o ) {
		a = b = nullptr;
		return;
	}

	if ( Size ( o -> l ) < k ) {
		a = o;
		split2 ( o -> r, a -> r, b, k - Size ( o -> l ) - 1 );
	}
	else {
		b = o;
		split2 ( o -> l, a, b -> l, k );
	}

	o -> up();
}

inline int kth ( node *o, int k ) {
	node *a, *b, *c;
	split2 ( o, a, c, k );
	split2 ( a, a, b, k - 1 );
	int res = b -> key;
	o = merge ( a, merge ( b, c ) );
	return res;
}
