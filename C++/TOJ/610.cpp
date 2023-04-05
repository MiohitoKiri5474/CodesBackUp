#include<stdio.h>
#include<math.h>

int main() {
#define int long long
	int l, k, n, ans = 2147483647, mi = 2147483647, idx = -1, cmp;
	scanf ( "%lld %lld %lld", &l, &k, &n );
	cmp = l / k + ( l % k ? 1 : 0 );
	for ( int i = 1, in ; i <= n ; i++ ) {
		scanf ( "%lld", &in );
		if ( mi >= abs ( cmp - in ) ) {
			mi = abs ( cmp - in );
			if ( ans > in )
				ans = in, idx = i;
		}
	}
	printf ( "%lld\n", idx );
}
