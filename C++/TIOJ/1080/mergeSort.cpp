#include<bits/stdc++.h>

using namespace std;

int arr[100005], stop[100005];
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
			ans+=(m-p+1);
			stop[index++] = arr[q++];
		}
	}

	memcpy ( arr + l, stop + l, sizeof ( int ) * ( r - l + 1 ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, ca = 0;
	while ( cin >> n ){
		if  ( n == 0 )
			break;
		ca++;
		ans = 0;
		for ( int i = 0 ; i < n ; i++ )
			cin >> arr[i];

		mergeSort ( 0, n - 1 );

		cout << "Case #" << ca << ": " << ans << '\n';
	}
}
