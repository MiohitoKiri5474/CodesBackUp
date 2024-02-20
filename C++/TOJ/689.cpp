// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <utility>

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

    int n, m, mi, ma;
    string str;
    vector < int > moun;
    vector < string > lib;

    cin >> m >> n;
    moun.resize ( n );
    for ( auto &i: moun ) {
        cin >> i;
        str += ' ';
    }
    lib.resize ( m, str );
    for ( int h = 0 ; h < m ; h++ ) {
        ma = -1, mi = n;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( h < moun[i] ) {
                mi = min ( mi, i );
                ma = max ( ma, i );
                lib[h][i] = '#';
            }
        }
        for ( int i = mi ; i <= ma ; i++ ) {
            if ( lib[h][i] == '#' ) continue;
            lib[h][i] = '-';
        }
    }

    reverse ( lib.begin(), lib.end() );
    for ( auto i: lib ) cout << i << endl;
}
