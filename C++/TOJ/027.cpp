// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 2000005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

int seg[maxN << 2];

void build ( int l, int r, int n ) {
    if ( l == r )
        cin >> seg[n];
    else{
        int mid = ( l + r ) >> 1;
        build ( l, mid, n << 1 );
        build ( mid + 1, r, ( n << 1 ) | 1 );
        seg[n] = max ( seg[n << 1], seg[( n << 1 ) | 1] );
    }
}

void update ( int l, int r, int index, int value, int n ) {
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1;
		if ( index <= mid )
			update ( l, mid, index, value, n << 1 );
		else
			update ( mid + 1, r, index, value, ( n << 1 ) | 1 );

		seg[n] = max ( seg[n << 1], seg[( n << 1 ) | 1] );
	}
}

int query ( int l, int r, int nowL, int nowR, int n ) {
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, n << 1 );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, ( n << 1 ) | 1 );
	return max ( query ( l, mid, nowL, mid, n << 1 ), query ( mid + 1, r, mid + 1, nowR, ( n << 1 ) | 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, in, l, r;
	char type;
	cin >> n;
    build ( 1, n, 1 );
	cin >> m;
	while ( m-- ) {
		cin >> type >> l >> r;
		if ( type == 'C' )
			update ( 1, n, l, r, 1 );
		else{
			if ( l > r )
				swap ( l, r );
			cout << ( query ( l, r, 1, n, 1 ) >> 1 ) << '\n';
		}
	}
}
