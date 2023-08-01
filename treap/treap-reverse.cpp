#include<bits/stdc++.h>

using namespace std;

struct node {
	node *l, *r;
	int value, pri, sz, rev, ma;

	node ( int _value );

	inline void up ( void );
	inline void down ( void );
};

node::node ( int _value ) {
	l = r = nullptr;
	value = ma = _value;
	sz = 1;
	pri = rand();
	rev = 0;
}

inline void node::up ( void ) {
	sz = 1, ma = value;
	if ( l ) {
		// l -> down();
		sz += l -> sz;
		ma = max ( ma, l -> ma );
	}
	if ( r ) {
		// r -> down();
		sz += r -> sz;
		ma = max ( ma, r -> ma );
	}
}

inline void node::down ( void ) {
	if ( rev ) {
		swap ( l, r );
		if ( l )
			l -> rev ^= 1;
		if ( r )
			r -> rev ^= 1;
		rev = 0;
	}
}

inline int Size ( node *o ) {
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ) {
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ) {
		a -> down();
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b -> down();
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, int k ) {
	if ( !o ) {
		a = b = nullptr;
		return;
	}

	o -> down();

	if ( Size ( o -> l ) < k ) {
		a = o;
		split ( o -> r, a -> r, b, k - Size ( o -> l ) - 1 );
		a -> up();
	}
	else {
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}

	o -> up();
}

inline void reverse ( node *&o, int L, int R ) {
	if ( L > R )
		swap ( L, R );
	node *l, *r, *mid, *swp;
	split ( o, swp, r, R );
	split ( swp, l, mid, L - 1 );
	if ( mid )
		mid -> rev ^= 1;
	o = merge ( merge ( l, mid ), r );
}

inline int query ( node *&o, int L, int R ) {
	if ( L > R )
		swap ( L, R );
	node *l, *r, *mid, *swp;
	split ( o, swp, r, R );
	split ( swp, l, mid, L - 1 );

	mid -> down();
	int res = ( mid ? mid -> ma : 0 );
	o = merge ( merge ( l, mid ), r );
	return res;
}

inline void update ( node *&o, int idx, int value ) {
	node *l, *mid, *r, *swp;
	split ( o, swp, r, idx );
	split ( swp, l, mid, idx - 1 );
	mid = new node ( value );
	o = merge ( l, merge ( mid, r ) );
}

/*
 * 第一行有兩個整數 N, M，分別代表第二行有一個長度為 N 的初始序列
 * 第三行開始共 M 行，每行會有一個操作，格式如下：
 * 1 l r：將區間 l, r 內的數字反轉
 * 2 l r：將區間 l, r 內的最大值輸出
 * 3 idx val：將 idx 位置的值改成 val
 */

int main() { 
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	srand ( clock() );

	node *root = nullptr;
	int n, m, type, l, r;
	cin >> n >> m;
	for ( int i = 0, in ; i < n ; i++ ) {
		cin >> in;
		root = merge ( root, new node ( in ) );
	}

	while ( m-- ) {
		cin >> type >> l >> r;
		if ( type == 1 )
			reverse ( root, l, r );
		else if ( type == 2 )
			cout << query ( root, l, r ) << endl;
		else if ( type == 3 )
			update ( root, l, r );
	}
}
