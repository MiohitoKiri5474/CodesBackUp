#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	while ( cin >> a ){
		bool ans = true;
		for ( int i = 0, j = a.size() - 1 ; i < a.size() && ans ; i++, j-- )
			if ( a[i] != a[j] )
				ans = false;

		if ( ans )
			cout << "yes";
		else
			cout << "no";
		cout << endl;

		/* ---------------- */
		
		string b = a;
		reverse ( b.begin(), b.end() );
		if ( a == b )
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	return 0;
}
