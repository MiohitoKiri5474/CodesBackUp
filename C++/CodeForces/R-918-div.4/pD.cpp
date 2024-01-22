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

inline bool isV ( char c ) {
    return c == 'a' || c == 'e';
}

bitset < maxN > lib;

int main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    string str;
    int t, n;
    cin >> t;
    while ( t-- ) {
        cin >> n >> str;
        lib.reset();
        for ( int i = 0 ; i < n ; i++ ) {
            if ( isV ( str[i] ) )
                lib[i] = true;
        }

        cout << str[0];
        for ( int i = 1 ; i < n ; i++ ) {
            if ( lib[i + 1] )
                cout << '.';
            cout << str[i];
        }
        cout << '\n';
    }
}
