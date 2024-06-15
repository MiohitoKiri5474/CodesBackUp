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

struct node {
    node *l, *r;
    int val;
    node ( int _val ) {
        l = r = nullptr;
        val = _val;
    }
};

void build ( int l, int r, node *&o ) {
    o = new node ( 0 );
    if ( l == r ) return;
    else {
        int mid = ( l + r ) >> 1;
        build ( l, mid, o -> l );
        build ( mid + 1, r, o -> r );
    }
}

void update ( int l, int r, int index, int value, node *&o ) {
    if ( l == r ) o -> val = value;
    else {
        int mid = ( l + r ) >> 1;
        if ( index <= mid ) update ( l, mid, index, value, o -> l );
        else update ( mid + 1, r, index, value, o -> r );

        o -> val = max ( o -> l -> val, o -> r -> val );
    }
}

int query ( int l, int r, int nowL, int nowR, node *o ) {
    if ( l <= nowL && nowR <= r ) return o -> val;
    int mid = ( nowL + nowR ) >> 1;
    if ( r <= mid ) return query ( l, r, nowL, mid, o -> l );
    if ( mid < l ) return query ( l, r, mid + 1, nowR, o -> r );

    return max ( query ( l, r, nowL, mid, o -> l ), query ( l, r, mid + 1, nowR, o -> r ) );
}

signed main() {
    gura;

    node *root;
    int n, m, l, r;
    cin >> n;
    build ( 1, n, root );
    for ( int i = 1, in ; i <= n ; i++ ) {
        cin >> in;
        update ( 1, n, i, in, root );
    }
    cin >> m;
    while ( m-- ) {
        cin >> l >> r;
        if ( l > r ) swap ( l, r );
        cout << query ( l, r, 1, n, root ) << '\n';
    }
}
