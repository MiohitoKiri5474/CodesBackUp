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

string cells[25];

signed main() {
    gura;

    int n, m, t, x, y, cmd, nx, ny;
    set < char > cnt;
    cin >> n >> m >> t;
    for ( int i = 0 ; i < n ; i++ )
        cin >> cells[i];
    x = n - 1, y = 0;
    while ( t-- ) {
        cin >> cmd;
        if ( cmd == 0 )
            nx = x - 1, ny = y;
        else if ( cmd == 1 )
            nx = x, ny = y + 1;
        else if ( cmd == 2 )
            nx = x + 1, ny = y + 1;
        else if ( cmd == 3 )
            nx = x + 1, ny = y;
        else if ( cmd == 4 )
            nx = x, ny = y - 1;
        else if ( cmd == 5 )
            nx = x - 1, ny = y - 1;

        if ( 0 <= nx && nx < n && 0 <= ny && ny < m )
            x = nx, y = ny;

        cout << cells[x][y];
        cnt.insert ( cells[x][y] );
    }
    cout << endl << cnt.size() << endl;
}
