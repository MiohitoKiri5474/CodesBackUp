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

map < int, int > visited;
map < int, vector < int > > edges;

int bfs ( int n, int dist ) {
    if ( edges.count ( n ) == 0 )
        return edges.size();
    int res = edges.size();
    queue < int > q;
    q.push ( n );
    visited[n] = dist;
    while ( !q.empty() ) {
        int now = q.front();
        q.pop();
        res--;
        if ( !visited[now] )
            continue;
        for ( auto i: edges[now] ) {
            if ( visited.count ( i ) == 0 ) {
                visited[i] = visited[now] - 1;
                q.push ( i );
            }
        }
    }
    return res;
}

signed main() {
    gura;

    int n, u, v, cnt;
    int cs = 1;
    while ( cin >> n ) {
        if ( !n )
            break;

        edges.clear();

        for ( int i = 0 ; i < n ; i++ ) {
            cin >> u >> v;
            edges[u].pb ( v );
            edges[v].pb ( u );
        }

        while ( cin >> u >> v ) {
            if ( !u && !v )
                break;

            visited.clear();
            cnt = bfs ( u, v );

            cout << "Case " << cs++ << ": " << cnt << " nodes not reachable from node " << u << " with TTL = " << v << ".\n";
        }
    }
}
