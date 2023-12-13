/* by. MiohitoKiri5474 */

#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

// define pair
typedef long long LL;
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// general defines
#define pb push_back
#define ep emplace_back
#define endl '\n'
#define GL ( n ) getline ( cin, n )

// define heap
template < class T > using MaxHeap = priority_queue < T, vector < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 105

int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

int lib[maxN][maxN], delta[maxN][maxN];

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int r, c, m, k, ma = -1, mi = maxN;
	cin >> r >> c >> k >> m;

	memset ( lib, -1, sizeof lib );
	for ( int i = 1 ; i <= r ; i++ ) {
		for ( int j = 1 ; j <= c ; j++ )
			cin >> lib[i][j];
	}

	while ( m-- ) {
		memset ( delta, 0, sizeof delta );
		for ( int i = 1 ; i <= r ; i++ )
			for ( int j = 1 ; j <= c ; j++ ) {
				if ( lib[i][j] == -1 )
					continue;
				int tmp = lib[i][j] / k;
				for ( int k = 0 ; k < 4 ; k++ ) {
					if ( lib[i + dx[k]][j + dy[k]] == -1 )
						continue;
					delta[i + dx[k]][j + dy[k]] += tmp;
					delta[i][j] -= tmp;
				}
			}

		for ( int i = 1 ; i <= r ; i++ )
			for ( int j = 1 ; j <= c ; j++ )
				lib[i][j] += delta[i][j];
	}

	for ( int i = 1 ; i <= r ; i++ )
		for ( int j = 1 ; j <= c ; j++ ) {
			if ( lib[i][j] == -1 )
				continue;
			ma = max ( ma, lib[i][j] ), mi = min ( mi, lib[i][j] );
		}

	cout << mi << endl << ma << endl;

	for ( int i = 0 ; i < r ; i++ ) {
		for ( int j = 0 ; j < c ; j++ ) {
			// count first
		}
	}

	for ( int i = 0 ; i < r ; i++ ) {
		for ( int j = 0 ; j < c ; j++ ) {
			// calc
		}
	}
}


// 8, 3, -1
// 6 , -1, 2
