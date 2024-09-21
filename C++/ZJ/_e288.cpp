// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <unordered_map>

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

inline int trans ( string str ) {
    int res = 0;
    for ( auto i: str ) {
        if ( i <= 'Z' )
            res |= ( ( LL ) 1 << ( LL ) ( i - 'A' ) );
        else
            res |= ( ( LL ) 1 << ( LL ) ( i - 'a' + 26 ) );
    }
    return res;
}

unordered_map < int, int > lib;

signed main() {
    gura;

    int n, m, full, ans = 0;
    string str;
    cin >> m >> n;
    full = ( ( LL ) 1 << m ) - 1;

    for ( int i = 0 ; i < n ; i++ ) {
        cin >> str;
        lib[trans ( str )]++;
    }

    for ( auto [bits, cnt]: lib ) {
        int another = full ^ bits;

        if ( lib.find ( another ) != lib.end() )
            ans += cnt * lib[another];
    }

    cout << ( ans >> 1 ) << endl;
}
