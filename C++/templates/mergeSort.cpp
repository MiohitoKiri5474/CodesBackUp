// merge sort
#include<bits/stdc++.h>
using namespace std;

int arr[8], swp[8];

// basic version
void mergeSort ( int l, int r ){
	if ( l == r )
		return ;

	int m = ( l + r ) / 2, p = l, q = m + 1, idx = l;

	mergeSort ( l, m );
	mergeSort ( m + 1, r );
	
	while ( p <= m && q <= r )
		if ( p <= m && arr[p] <= arr[q] )
			swp[idx++] = arr[p++];
		else
			swp[idx++] = arr[q++];

	while ( p <= m )
		swp[idx++] = arr[p++];

	while ( q <= r )
		swp[idx++] = arr[q++];

	for ( int i = l ; i <= r ; i++ )
		arr[i] = swp[i];
}

// advanced version
void mergeSort2 ( int l, int r ){
	if ( l == r )
		return ;

	int m = ( l + r ) / 2, p = l, q = m + 1, index = l;

	mergeSort2 ( l, m );
	mergeSort2 ( m + 1, r );
	
	while ( p <= m || q <= r )
		if ( p <= m && ( q > r || arr[p] <= arr[q] ) )
			swap ( swp[index++], arr[p++] );
		else
			swap ( swp[index++], arr[q++] );
	
	memcpy ( arr + l, swp + l, sizeof ( int ) * ( r - l + 1 ) );
	// memcpy ( 想要複製的位置ptr, 來源ptr, size );
	// memcpy ( arr, swp, sizeof ( arr ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	for ( int i = 0 ; i < 8 ; i++ )
		cin >> arr[i];

	mergeSort ( 0, 7 );

	for ( int i = 0 ; i < 8 ; i++ )
		cout << arr[i] << ' ';
	cout << '\n';
}
