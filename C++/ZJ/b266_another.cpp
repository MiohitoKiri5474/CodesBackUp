#include<bits/stdc++.h>

using namespace std;

int arr[15][15], opt[15];

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int r, c, m, flip_tms = 0;
	cin >> r >> c >> m;
	for ( int i = 0 ; i < r ; i++ )
		for ( int j = 0 ; j < c ; j++ )
			cin >> arr[i][j];

	for ( int i = 0 ; i < m ; i++ )
		cin >> opt[i];

	for ( int k = m - 1 ; k >= 0 ; k-- ) {
		if ( opt[k] == 0 ) {
			if ( flip_tms ) {
				for ( int i = 0 ; i < r / 2 ; i++ )
					for ( int j = 0 ; j < c ; j++ )
						swap ( arr[i][j], arr[r - i - 1][j] );
				flip_tms = 0;
			}
			// 對角線鏡像交換
			for ( int i = 0 ; i < max ( r, c ) ; i++ )
				for ( int j = 0 ; j < i ; j++ )
					swap ( arr[i][j], arr[j][i] );
			swap ( r, c );
		}
		flip_tms ^= 1;
	}

	if ( flip_tms ) {
		for ( int i = 0 ; i < r / 2 ; i++ )
			for ( int j = 0 ; j < c ; j++ )
				swap ( arr[i][j], arr[r - i - 1][j] );
	}

	cout << r << ' ' << c << endl;
	for ( int i = 0 ; i < r ; i++ ) {
		for ( int j = 0 ; j < c ; j++ )
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

/*
   1 2 3
   4 5 6
   0 0 0

   step 1: 沿著對角線鏡像互換一次

   1 4 0
   2 5 0
   3 6 0

   step 2: 做一次翻轉

   3 6 0
   2 5 0
   1 4 0
   */

