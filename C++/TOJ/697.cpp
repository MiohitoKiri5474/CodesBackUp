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
// #define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 100005;

int dm[] = { 0, 1, 0, -1, 0 };

signed main() {
    gura;

    int n, m, cnt, nx, ny, tms = 0;
    bool flag = false;
    string str;
    cin >> n >> m;
    vector < string > lib ( n );
    for ( auto &i: lib ) cin >> i;
    do {
        flag = false;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( lib[i][j] == '#' )
                    continue;
                cnt = 0;
                for ( int d = 0 ; d < 4 ; d++ ) {
                    nx = i + dm[d], ny = j + dm[d + 1];
                    if ( nx < 0 || ny < 0 || nx == n || ny == m )
                        continue;
                    if ( lib[nx][ny] == '#' )
                        cnt++;
                }
                if ( cnt >= 2 ) {
                    lib[i][j] = '#';
                    flag = true;
                }
            }
        }
        tms++;
    } while ( flag );
    cout << tms << endl;
    for ( auto i: lib ) cout << i << endl;
}
