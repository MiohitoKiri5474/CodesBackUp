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

vector < int > edges[maxN];
int p[maxN];
LL ans;

int dfs ( int n ) {
    int ma = 0;
    for ( auto i: edges[n] ) ma = max ( ma, dfs ( i ) + 1 );
    ans += ma;
    return ma;
}

int main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int n;

    memset ( p, -1, sizeof p );

    cin >> n;
    for ( int i = 1, k ; i <= n ; i++ ) {
        cin >> k;
        for ( int j = 0, in ; j < k ; j++ ) {
            cin >> in;
            edges[i].pb ( in );
            p[in] = i;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( p[i] == -1 ) {
            dfs ( i );
            cout << i << endl << ans << endl;
            break;
        }
    }
}
