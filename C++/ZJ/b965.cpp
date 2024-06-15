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
const int maxN = 105;

int n, m;
int arr[maxN][maxN];

void op ( int k ) {
    int ops;
    cin >> ops;
    if ( k )
        op ( k - 1 );
    if ( !ops ) {
        for ( int i = 0 ; i < max ( n, m ) ; i++ )
            for ( int j = i + 1 ; j < max ( n, m ) ; j++ )
                swap ( arr[i][j], arr[j][i] );
        swap ( n, m );
    }
    for ( int i = 0 ; i < ( n >> 1 ) ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            swap ( arr[n - i - 1][j], arr[i][j] );
}

signed main() {
    gura;

    int q;
    cin >> n >> m >> q;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            cin >> arr[i][j];

    op ( q - 1 );

    cout << n << ' ' << m << endl;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            cout << arr[i][j] << " \n"[j == m - 1];
}
