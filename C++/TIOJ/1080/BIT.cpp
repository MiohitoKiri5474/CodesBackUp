#include<bits/stdc++.h>

using namespace std;

int BIT[1000005], n;

inline int sum ( int w ){
	int res = 0;
	while ( w ){
		res += BIT[w];
		w -= w & -w;
	}
	return res;
}

inline void add ( int i, int x ){
	while ( i <= n ){
		BIT[i] += x;
		i += i & -i;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long ans;
    vector < int > v, lib;
	while ( cin >> n ){
		if ( !n )
			break;

		memset ( BIT, 0, sizeof ( BIT ) );
		ans = 0;
        v.resize ( n );
        for ( auto &i: v ) cin >> i;
        lib = v;
        sort ( lib.begin(), lib.end() );

		for ( int i = 0, stp ; i < n ; i++ ){
            stp = lower_bound ( lib.begin(), lib.end(), v[i] ) - lib.begin();
			ans += i - sum ( stp );
			add ( stp, 1 );
		}

		cout << ans << '\n';
	}
}
