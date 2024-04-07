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
const int maxN = 50005;

int dis[maxN];
bool used[maxN];

inline void init ( int n ) {
    for ( int i = 1 ; i <= n ; i++ )
        dis[i] = i;
}

int find ( int n ) {
    return n == dis[n] ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ) {
    dis[find ( a )] = find ( b );
}

signed main() {
    gura;

    int n, m, tms = 0, u, v;
    set < int > st;
    while ( cin >> n >> m ) {
        if ( !n && !m )
            return 0; // break
        init ( n );
        st.clear();
        memset ( used, 0, sizeof ( used ) );

        int ans = 0;

        while ( m-- ) {
            cin >> u >> v;
            Union ( u, v );
        }
        for ( int i = 1 ; i <= n ; i++ )
            st.insert ( find ( i ) );

        cout << "Case " << ++tms << ": " << st.size() << '\n';
    }
}
