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
const int maxN = 2000005;

int seg[maxN << 1];

inline void init ( int &n ) {
    for ( int i = 0; i < n; i++ )
        cin >> seg[i + n];
    for ( int i = n - 1; i > 0; i-- )
        seg[i] = max ( seg[i << 1], seg[i << 1 | 1] );
}

void update ( int &p, int &v, int &n ) {
    for ( seg[p += n - 1] = v; p > 1; p >>= 1 )
        seg[p >> 1] = max ( seg[( p >> 1 ) << 1], seg[p | 1] );
}

int query ( int &l, int &r, int &n ) {
    int res = -2147483648;
    for ( l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1 ) {
        if ( l & 1 )
            res = max ( res, seg[l++]) ;
        if ( r & 1 ^ 1 )
            res= max ( res, seg[r--] );
    }

    return res;
}

signed main() {
    gura;

    int n, m, l, r;
    char op;
    cin >> n;
    init ( n );
    cin >> m;
    while ( m-- ) {
        cin >> op >> l >> r;
        if ( op == 'C' )
            update ( l, r, n );
        else {
            if ( l > r )
                swap ( l, r );
            cout << query ( l, r, n ) / 2 << '\n';
        }
    }
}
