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

inline int check ( int x, int y ) {
    if ( x == 0 || x == 9 || y == 0 || y == 9 )
        return 1;
    if ( x == 1 || x == 8 || y == 1 || y == 8 )
        return 2;
    if ( x == 2 || x == 7 || y == 2 || y == 7 )
        return 3;
    if ( x == 3 || x == 6 || y == 3 || y == 6 )
        return 4;
    return 5;
}

inline void mio ( void ) {
    string str[15];
    LL ans = 0;
    for ( int i = 0 ; i < 10 ; i++ )
        cin >> str[i];

    for ( int i = 0 ; i < 10 ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
            if ( str[i][j] == 'X' ) {
                ans += check ( i, j );
            }
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
