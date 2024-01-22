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

// define heap
template < class T > using MaxHeap = priority_queue < T, vector < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// number definition
#define INF 0x3f3f3f3f
#define maxN 200005

#define int LL

inline int calc ( vector < int > &seg, vector < int > &a, int k ) {
    int res = 0;
    int l = 0, r = 0, sum = a[seg[0]];
    while ( r < seg.size() ) {
        if ( sum <= k )
            res = max ( res, r - l + 1 );
        if ( sum <= k ) {
            r++;
            if ( r >= seg.size() )
                break;
            sum += a[seg[r]];
        }
        else {
            sum -= a[seg[l++]];
        }
    }
    return res;
}

inline void mio ( void ) {
    int n, k, ans = 0, sum = 0, l;
    cin >> n >> k;
    vector < int > a ( n ), h ( n ), cur ( 1 );
    vector < vector < int > > lib;
    for ( auto &i: a ) cin >> i;
    for ( auto &i: h ) cin >> i;

    for ( int i = 1 ; i < n ; i++ ) {
        if ( h[i - 1] % h[i] == 0 )
            cur.pb ( i );
        else {
            lib.pb ( cur );
            cur.clear();
            cur.pb ( i );
        }
    }
    ans = calc ( cur, a, k );

    for ( auto i: lib ) {
        ans = max ( ans, calc ( i, a, k ) );
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t;
    cin >> t;
    while ( t-- )
        mio();
}
