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

    int n, exp = 0;
    vector < int > lib;
    cin >> n;
    for ( int i = 0, in ; i < n ; i++ ) {
        cin >> in;
        lib.pb ( in );
    }
    sort ( lib.begin(), lib.end() );
    lib.erase ( unique ( lib.begin(), lib.end() ), lib.end() );
    n = lib.size();
    for ( int i = 0 ; i < n ; i++ ) {
        if ( lib[i] != exp ) break;
        exp++;
    }
    cout << exp << endl;
}
