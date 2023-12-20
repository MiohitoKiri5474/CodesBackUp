#include<bits/stdc++.h>

using namespace std;

int lib[50005];
int n, k;

inline bool calc ( int dis ) {
	int res = 0, i = 0, cent;
	while ( i < n ) {
		cent = lib[i] + dis;
		res++;
		if ( res > k )
			return false;
		if ( lib[n - 1] <= cent )
			return true;

		i = lower_bound ( lib, lib + n, cent ) - lib;
		lib[i] <= cent ? i++ : i;
	}
	return false;
}

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	
	int l = 1, r, mid;
	cin >> n >> k;
	for ( int i = 0 ; i < n ; i++ )
		cin >> lib[i];

	sort ( lib, lib + n );

	r = lib[n - 1] - lib[0];
	mid = ( l + r ) >> 1;
	if ( k == 1 ) {
		cout << r << endl;
		return 0;
	}
	while ( calc ( r - 1 ) && l != r ) {
		mid = ( l + r ) >> 1;
		if ( calc ( mid ) )
			r = mid;
		else
			l = mid + 1;
	}
	cout << r << endl;
}
