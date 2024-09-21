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
const int maxN = 55;

int q[maxN][maxN], tmp[maxN][maxN];

signed main() {
    gura;

    int n, m, k, mi = INF, cnt;
    cin >> n >> m >> k;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            cin >> q[i][j];

    while ( k-- ) {
        cnt = 0;
        memset ( tmp, 0, sizeof tmp );
        for ( int i = 0, city ; i < n ; i++ ) {
            cin >> city;
            for ( int j = 0 ; j < m ; j++ )
                tmp[city][j] += q[i][j];
        }
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                // if ( i == j )
                //     cnt += tmp[i][j];
                cnt += ( i == j ? tmp[i][j] : min ( tmp[i][j], ( int ) 1000 ) * 3 + max ( ( int ) 0, tmp[i][j] - 1000 ) * 2 );
            }
        }
        mi = min ( cnt, mi );
    }
    cout << mi << endl;
}
