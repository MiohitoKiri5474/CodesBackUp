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

bool cmp ( int a, int b ) {
    return a > b;
}

map < int, int > lib;
vector < int > v;

signed main() {
    gura;

    #define a v[0]
    #define b v[1]
    #define c v[2]
    vector < int > v ( 3 );
    for ( auto &i: v )
        cin >> i;
    sort ( v.begin(), v.end(), []( int x, int y ) { return x > y; } );
    sort ( v.begin(), v.end(), cmp );
    if ( a == b && b == c )
        cout << "3";
    else if ( a == b || b == c || a == c )
        cout << "2";
    else
        cout << "1";
    v.erase ( unique ( v.begin(), v.end() ), v.end() );
    for ( auto i: v )
        cout << ' ' << i;
    cout << endl;
}
