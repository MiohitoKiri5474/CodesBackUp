#include<bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	set < int > check;
	vector < int > data;
	int n, t;
	cin >> n;

	int arr[105];
	while ( n-- ){
		cin >> t;
		if ( check.find ( t ) == check.end() ){
			// check.insert ( t );
			data.push_back ( t );
		}
	}

	sort ( data.begin(), data.end() );

	cin >> t;
	while ( t-- ){
		cin >> n;
		auto i = lower_bound ( data.begin(), data.end(), n );
		int *j = lower_bound ( arr + 3, arr + 15, t );

		if ( *i == n )
			cout << n;
		else if ( n < data[0] )
			cout << "no " << data[0];
		else if ( data.back() < n )
			cout << data.back() << " no";
		else{
			cout << *( i - 1 ) << ' ' << *i;
		}
		cout << '\n';
	}
}

// |_____|_____|
//      mid
// target > mid
//
//
//
