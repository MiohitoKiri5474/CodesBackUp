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

inline void mio ( void ) {
    int n, k;
    LL ans = 0;
    string str, tmp;
    vector < int > idx;
    cin >> n >> k >> str;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( str[i] == 'B' )
            idx.emplace_back ( i );
    }
    if ( idx.empty() ) {
        cout << "0\n";
        return;
    }
    n = idx[0] + k - 1, ans = 1;
    for ( auto i: idx ) {
        if ( n < i ) {
            ans++;
            n = i + k - 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t;
    cin >> t;
    while ( t-- ) {
        mio();
    }
}
