class Solution {
public:
    string multiply(string num1, string num2) {
		if ( num1.size() == 1 && num2.size() == 1 ) {
			string res = itoa ( atoi ( num1[0] ) * atoi ( num2[0] ) );
			reverse ( res.begin(), res.end() );
			return res;
		}
        string res;
		reverse ( num1.begin(), num1.end() );
		reverse ( num2.begin(), num2.end() );
		vector < int > lib ( 100005 );
		int ma = -1;
		for ( int i = 0 ; i < num1.size() ; i++ ) {
			for ( int j = 0 ; j < num2.size() ; j++ ) {
				lib[i + j] += atoi ( num1[i] ) * atoi ( num2[j] );
				ma = max ( ma, i + j );
			}
		}
		for ( int i = 0 ; i <= ma ; i++ ) {
			if ( lib[i] / 10 ) {
				lib[i + 1] += lib[i] / 10;
				lib[i] %= 10;
				if ( i == ma )
					ma++;
			}
		}
		for ( int i = 0 ; i <= ma ; i++ )
			res += itoa ( lib[i] );
		reverse ( res.begin(), res.end() );
		bool flag = true;
		for ( auto i: res )
			if ( i != '0' ) {
				flag = false;
				break;
			}
		if ( flag )
			return "0";
		return res;
    }

private:
	inline int atoi ( char c ) {
		return c - '0';
	}

	inline string itoa ( int n ) {
		if ( n == 0 )
			return "0";
		string res;
		while ( n ) {
			res += '0' + n % 10;
			n /= 10;
		}
		return res;
	}
};
