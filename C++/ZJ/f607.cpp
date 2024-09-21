// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <algorithm>

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

    int n, l, ans = 0;
    set < int > len;
    vector < pii > lib;
    cin >> n >> l;
    len.insert ( 0 );
    len.insert ( l );
    lib.resize ( n );
    for ( auto &[f, s]: lib )
        cin >> f >> s;
    sort ( lib.begin(), lib.end(),
          []( pii &a, pii &b ) {
            return a.S < b.S;
          }
    );
    for ( int i = 0 ; i < n ; i++ ) {
        len.insert ( lib[i].first );
        auto tmp1 = len.find ( lib[i].first );
    }
    for ( auto [f, s]: lib ) {
        len.insert ( f );
        auto tmp1 = len.find ( f ), tmp2 = tmp1;
        ans += *( ++tmp1 ) - *( --tmp2 );
    }
    cout << ans << endl;
}
