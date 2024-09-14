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
const int maxN = 105;

int lib[maxN][maxN], dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

signed main() {
    gura;
    memset ( lib, -1, sizeof ( lib ) );

    int n, m, tms, cur = 0, ma = 0, x, y, t;
    bool flag;
    cin >> n >> m >> tms;
    while ( tms-- ) {
        cin >> x >> y >> t;
        for ( int d = 0 ; d < 4 ; d++ ) {
            flag = false;
            for ( int i = 1 ; 0 <= x + dx[d] * i && x + dx[d] * i < n && 0 <= y + dy[d] * i && y + dy[d] * i < m ; i++ ) {
                if ( lib[x + dx[d] * i][y + dy[d] * i] == 0 ) {
                    flag = true;
                    break;
                }
                else if ( lib[x + dx[d] * i][y + dy[d] * i] == -1 )
                    break;
            }
            for ( int i = 1 ; flag && 0 <= x + dx[d] * i && x + dx[d] * i < n && 0 <= y + dy[d] * i && y + dy[d] * i < m ; i++ ) {
                if ( lib[x + dx[d] * i][y + dy[d] * i] == 0 )
                    break;
                lib[x + dx[d] * i][y + dy[d] * i]--;
                if ( lib[x + dx[d] * i][y + dy[d] * i] == 0 )
                    lib[x + dx[d] * i][y + dy[d] * i] = -1;
            }
        }
        lib[x][y] = -1;
        if ( !t ) { // add
            for ( int d = 0 ; d < 4 ; d++ ) {
                flag = false;
                for ( int i = 1 ; 0 <= x + dx[d] * i && x + dx[d] * i < n && 0 <= y + dy[d] * i && y + dy[d] * i < m ; i++ )
                    if ( lib[x + dx[d] * i][y + dy[d] * i] == 0 ) {
                        flag = true;
                        break;
                    }
                for ( int i = 1 ; flag && 0 <= x + dx[d] * i && x + dx[d] * i < n && 0 <= y + dy[d] * i && y + dy[d] * i < m ; i++ ) {
                    if ( lib[x + dx[d] * i][y + dy[d] * i] == 0 )
                        break;
                    if ( lib[x + dx[d] * i][y + dy[d] * i] == -1 )
                        lib[x + dx[d] * i][y + dy[d] * i] = 0;
                    lib[x + dx[d] * i][y + dy[d] * i]++;
                }
            }
            lib[x][y] = 0;
        }
        cur = 0;
        for ( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < m ; j++ )
                lib[i][j] == -1 ? cur : cur++;
        ma = max ( ma, cur );
    }
    cout << ma << '\n' << cur << '\n';
}
