#include<bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long LL;

typedef pair < int, int > pii;
vector < pii > lib;
vector < int > swp;
#define pb push_back

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, x, y, l, r, mid;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> x >> y;
		lib.pb ( pii ( x, y ) );
	}
	sort ( lib.begin(), lib.end() );
	swp.pb ( lib[0].second );
	for ( int i = 1 ; i < n ; i++ ) {
		l = 0, r = swp.size();
		while ( l < r ) {
			mid = ( l + r ) >> 1;
			if ( lib[i].second >= swp[mid] )
				l = mid + 1;
			else
				r = mid;
		}

		l = l;
		if ( l >= swp.size() )
			swp.pb ( lib[i].second );
		else
			swp[l] = lib[i].second;
	}
	cout << swp.size() << '\n';
}
