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
const int maxN = 1050;

int bit[maxN][maxN], n;

inline void add1D ( int x, int y, int z ) {
    while ( x <= n ) {
        bit[x][y] += z;
        x += x & -x;
    }
}

inline int sum1D ( int x, int y ) {
    int res = 0;
    while ( x ) {
        res += bit[x][y];
        x -= x & -x;
    }
    return res;
}

inline void add2D ( int x, int y, int z ) {
    while ( y <= n ) {
        add1D ( x, y, z );
        y += y & -y;
    }
}

inline int sum2D ( int x, int y ) {
    int res = 0;
    while ( y ) {
        res += sum1D ( x, y );
        y -= y & -y;
    }
    return res;
}

inline int sum ( int x1, int y1, int x2, int y2 ) {
    return sum2D ( x2, y2 ) - sum2D ( x1, y2 ) - sum2D ( x2, y1 ) + sum2D ( x1, y1 );
}

signed main() {
    gura;

    int x, y, z, x1, y1, type;
    cin >> n;
    while ( cin >> type ) {
        if ( type == 1 ) {
            cin >> x >> y >> z;
            add2D ( x + 1, y + 1, z );
        }
        else {
            cin >> x >> y >> x1 >> y1;
            cout << sum ( x, y, x1 + 1, y1 + 1 ) << '\n';
        }
    }
}
