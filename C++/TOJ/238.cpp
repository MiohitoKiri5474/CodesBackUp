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
#define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 100005;

int mi, ma;
vector < pii > edges[maxN];

bool dfs ( int n, int p, int sum ) {
    if ( mi <= sum && sum <= ma )
        return true;

    for ( auto [to, w]: edges[n] ) {
        if ( to == p )
            continue;
        if ( dfs ( to, n, sum + w ) )
            return true;
    }

    return false;
}

signed main() {
    gura;

    int n, u, v, w;
    cin >> n >> mi >> ma;
    for ( int i = 1 ; i < n ; i++ ) {
        cin >> u >> v >> w;
        edges[u].pb ( pii ( v, w ) );
        edges[v].pb ( pii ( u, w ) );
    }

    cout << ( dfs ( 0, -1, 0 ) ? "Eat Eat Eat\n" : "Go find other chickens\n" );
}
