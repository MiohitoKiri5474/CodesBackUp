#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_pot ( on )

using namespace std;

int arr[2000005], stop[2000005];
long long ans;

void mergeSort ( int l, int r ){
	if ( l == r )
		return ;
	int m = ( l + r ) / 2, p = l, q = m + 1, index = l;

	mergeSort ( l, m );
	mergeSort ( m + 1, r );

	while ( p <= m || q <= r ){
		if ( p <= m && ( q > r || arr[p] <= arr[q] ) )
			stop[index++] = arr[p++];
		else{
			ans += ( m - p + 1 );
			stop[index++] = arr[q++];
		}
	}

	memcpy ( arr + l, stop + l, sizeof ( int ) * ( r - l + 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n;
	cin >> n;
	ans = 0;
	for ( int i = 0 ; i < n ; i++ )
		cin >> arr[i];

	mergeSort ( 0, n - 1 );

	cout << ans << '\n';

	// sort ( begin pointer, end pointer );
}

// 複雜度
// merge sort
// | 2 4 3 7 1 9 |
// | [ 2 3 1 ] 4 [ 7 9 ] |
