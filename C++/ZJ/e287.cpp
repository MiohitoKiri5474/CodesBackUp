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

int arr[maxN][maxN];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

signed main() {
    gura;

    int n, m, x, y, mi = INF, ans = 0, dt;
    cin >> n >> m;
    memset ( arr, INF, sizeof ( arr ) );
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> arr[i][j];
            if ( arr[i][j] < mi )
                mi = arr[i][j], x = i, y = j;
        }

    queue < pii > q;
    q.push ( pii ( x, y ) );
    while ( !q.empty() ) {
        auto [x, y] = q.front();
        q.pop();

        ans += arr[x][y];
        arr[x][y] = INF;

        // 四個方向做檢查
        mi = INF;
        dt = -1;
        for ( int i = 0 ; i < 4 ; i++ )
            if ( arr[x + dx[i]][y + dy[i]] < mi )
                mi = arr[x + dx[i]][y + dy[i]], dt = i;
        if ( dt != -1 && arr[x + dx[dt]][y + dy[dt]] != INF )
            q.push ( pii ( x + dx[dt], y + dy[dt] ) );
    }
    cout << ans << endl;
}
