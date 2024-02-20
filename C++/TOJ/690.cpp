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
const int maxN = 100005;

signed main() {
    gura;

    int n, q, x1, x2, y1, y2;
    vector < vector < int > > ans;
    cin >> n >> q;
    ans.resize ( n, vector < int > ( n ) );
    while ( q-- ) {
        cin >> y1 >> x1 >> y2 >> x2;
        x1--, y1--;
        for ( int i = x1 ; i < x2 ; i++ ) {
            for ( int j = y1 ; j < y2 ; j++ ) {
                ans[i][j] ^= 1;
            }
        }
    }

    for ( int i = n - 1 ; i >= 0 ; i-- ) {
        for ( int j = 0 ; j < n ; j++ )
            cout << ans[i][j];
        cout << '\n';
    }
}
