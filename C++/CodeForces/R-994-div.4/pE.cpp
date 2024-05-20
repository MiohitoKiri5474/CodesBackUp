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

inline void solved ( void ) {
    int n, k, q, d, idx;
    cin >> n >> k >> q;
    vector < int > a ( k + 1 ), b ( k + 1 );
    for ( int i = 1 ; i <= k ; i++ )
        cin >> a[i];
    for ( int i = 1 ; i <= k ; i++ )
        cin >> b[i];
    while ( q-- ) {
        cin >> d;
        idx = lower_bound ( a.begin(), a.end(), d ) - a.begin();
        if ( a[idx] == d )
            cout << b[idx];
        else {
            int tms = ( d - a[idx - 1] ) * ( b[idx] - b[idx - 1] );
            tms /= ( a[idx] - a[idx - 1] );
            tms += b[idx - 1] * 1.0;
            cout << ( int ) tms;
        }
        cout << ' ';
    }
    cout << '\n';
}

signed main() {
    gura;

    int t;
    cin >> t;
    while ( t-- )
        solved();
}
