// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;
using namespace __gnu_pbds;

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
#define maxN 200005

#define int LL

signed main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t, n, ans;
    vector < pii > v;
    cin >> t;
    while ( t-- ) {
        v.clear();
        ans = 0;
        ordered_set s;

        cin >> n;
        for ( int i = 0, a, b ; i < n ; i++ ) {
            cin >> a >> b;
            v.pb ( pii ( a, b ) );
        }

        sort ( v.rbegin(), v.rend() );

        for ( auto [l, r]: v ) {
            ans += s.order_of_key ( r + 1 );
            s.insert ( r );
        }
        cout << ans << '\n';
    }
}
