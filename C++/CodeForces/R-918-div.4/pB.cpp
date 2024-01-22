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
#define maxN 100005

int main() {
    ios::sync_with_stdio ( false );
    cin.tie ( 0 );
    cout.tie ( 0 );

    int t, tmp = ( ( int ) 'A' ^ ( int ) 'B' ^ ( int ) 'C' ), cur;
    string str[3];
    bool flag;
    cin >> t;
    while ( t-- ) {
        for ( int i = 0 ; i < 3 ; i++ ) {
            cin >> str[i];
        }

        for ( int i = 0 ; i < 3 ; i++ ) {
            cur = tmp;
            for ( int j = 0 ; j < 3 ; j++ ) {
                if ( str[i][j] != '?' ) {
                    cur ^= ( int ) str[i][j];
                }
            }
            if ( cur ) {
                cout << ( char ) cur << endl;
                break;
            }
        }
    }
}
