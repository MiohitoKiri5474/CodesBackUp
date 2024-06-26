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
#define maxN 200005

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

GRE ( int, edges );
int value[maxN], seg[maxN << 2], pa[maxN], sz[maxN], ma[maxN], where[maxN], cnt, link[maxN], D[maxN];

inline void init ( void ){
	REPALL ( i, edges ) CLR ( i );
	MEM ( value, NEG_INF );
	MEM ( pa, -1 );
	MEM ( where, -1 );
	MEM ( link, -1 );
	MEM ( ma, -1 );
	MEM ( D, 0 );
	cnt = 0;
}

void findFa ( int n ){
	sz[n] = 1;
	REPALL ( i, edges[n] ){
		if ( i == pa[n] )
			continue;
		pa[i] = n;
		D[i] = D[n] + 1;
		findFa ( i );
		if ( ma[n] == -1 || sz[i] > sz[ma[n]] )
			ma[n] = i;
		sz[n] += sz[i];
	}
}

void dfs ( int n, int p ){
	link[n] = p;
	where[n] = ++cnt;
	if ( ma[n] == -1 )
		return;
	dfs ( ma[n], p );
	REPALL ( i, edges[n] ){
		if ( i == ma[n] || i == pa[n] )
			continue;
		dfs ( i, i );
	}
}

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, u, v, w, N;
	string type;
	cin >> t;
	while ( t-- ){
		cin >> n;
		N = n << 1;
		N--;
		init();
		REPP ( i, 1, n ){
			cin >> u >> v >> w;
			UNI ( u, i + n, edges );
			UNI ( n + i, v, edges );
			value[n + i] = w;
		}

		pa[1] = 1;
		findFa ( 1 );
		dfs ( 1, 1 );
		REPP ( i, 1, ( n << 1 ) ){
			update ( 1, N, where[i], value[i], 1 );
		}

		while ( cin >> type ){
			if ( type == "DONE" )
				break;
			cin >> u >> v;
			if ( type == "QUERY" ){
				int uPa = u, vPa = v, ans = -1;
				while ( link[uPa] != link[vPa] ){
					if ( D[link[uPa]] > D[link[vPa]] ){
						ans = max ( ans, query ( where[link[uPa]], where[uPa], 1, N, 1 ) );
						uPa = pa[link[uPa]];
					}
					else{
						ans = max ( ans, query ( where[link[vPa]], where[vPa], 1, N, 1 ) );
						vPa = pa[link[vPa]];
					}
				}

				if ( D[uPa] > D[vPa] )
					swap ( uPa, vPa );
				cout << max ( ans, query ( where[uPa], where[vPa], 1, N, 1 ) ) << '\n';
			}
			else
				update ( 1, N, where[n + u], v, 1 );
		}
	}
}