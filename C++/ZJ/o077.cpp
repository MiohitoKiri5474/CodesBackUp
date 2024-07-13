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

int arr[maxN][maxN], painted[maxN][maxN];

signed main() {
    gura;

    int n, m, q, x, y, t, value, _x, _y;
    cin >> n >> m >> q;

    while ( q ) {
        cin >> x >> y >> t >> value;
        for ( int i = 0 ; i <= t ; i++ )
            for ( int j = 0 ; i + j <= t ; j++ )
                // 前兩個是在枚舉曼哈頓距離組合
                for ( int dx = -1 ; dx < 2 ; dx++ )
                    for ( int dy = -1 ; dy < 2 ; dy++ ) {
                        // 後兩個是在枚舉八個方向組合
                        _x = x + i * dx, _y = y + j * dy;
                        if ( 0 <= _x && _x < n &&
                             0 <= _y && _y < m &&
                             painted[_x][_y] != q )
                            arr[_x][_y] += value, painted[_x][_y] = q;
                    }
        q--;
    }

    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            cout << arr[i][j] << " \n"[j == m - 1];
}
