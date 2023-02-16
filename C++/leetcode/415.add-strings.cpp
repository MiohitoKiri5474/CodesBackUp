#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
		int carry = 0;
		reverse ( num1.begin(), num1.end() );
		reverse ( num2.begin(), num2.end() );
		if ( num1.size() > num2.size() )
			swap ( num1, num2 );
		for ( int i = 0 ; i < num1.size() ; i++ ) {
			carry += ctoi ( num1[i] ) + ctoi ( num2[i] );
			res += itoc ( carry );
			carry /= 10;
		}
		for ( int i = num1.size() - 1 ; i < num2.size() ; i++ ) {
			carry += ctoi ( num2[i] );
			res += itoc ( carry );
			carry /= 10;
		}
		while ( carry ) {
			res += itoc ( carry );
			carry /= 10;
		}
		reverse ( res.begin(), res.end() );
		return res;
    }
private:
	inline int ctoi ( char c ) {
		return c - '0';
	}

	inline char itoc ( int n ) {
		return n % 10 + '0';
	}
};
