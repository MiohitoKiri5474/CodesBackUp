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
#define maxN 200005

LL odd[maxN], eve[maxN];

int main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t, n;
    bool ans;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        set < LL > s;
        s.insert ( 0 );
        ans = false;
        for ( LL i = 1, in ; i <= n ; i++ ) {
            cin >> in;
            odd[i] = odd[i - 1], eve[i] = eve[i - 1];
            if ( i & 1 )
                odd[i] += in;
            else
                eve[i] += in;

            if ( s.find ( odd[i] - eve[i] ) != s.end() )
                ans = true;

            s.insert ( odd[i] - eve[i] );
        }

        cout << ( ans ? "Yes" : "No" ) << '\n';
    }
}
