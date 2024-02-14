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
const int maxN = 1205;

int ans[maxN][maxN];

signed main() {
    gura;

    int n, m, q, ma, x, y;
    cin >> n >> m;
    for ( int i = 1, in ; i <= n ; i++ ) {
        ma = 0;
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> in;
            ans[i][j] = ma;
            ma = max ( ma, in );
        }
    }
    cin >> q;
    while ( q-- ) {
        cin >> x >> y;
        cout << ans[x][y] << '\n';
    }
}
