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
#define maxN 100005

#define int LL

vector < int > lib;

inline int calc ( int n ) {
    int res = 0;
    for ( auto i: lib ) res += ( max ( 0ll, n - i ) );
    return res;
}

inline void mio ( void ) {
    int n, x, mi = INF;
    cin >> n >> x;
    lib.resize ( n );
    for ( auto &i: lib ) {
        cin >> i;
        mi = min ( mi, i );
    }

    LL l = 1, r = 2147483647, mid = ( l + r ) >> 1;
    while ( r - l > 1 ) {
        if ( calc ( mid ) <= x )
            l = mid;
        else
            r = mid;
        mid = ( l + r ) >> 1;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t;
    cin >> t;
    while ( t-- ) {
        mio();
    }
}
