#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack < char, vector < char > > st;
		for ( auto i: s ) {
			if ( i == '(' || i == '[' || i == '{' )
				st.push ( i );
			else {
				if ( st.empty() )
					return false;
				if ( 	( st.top() == '(' && i == ')' ) ||
						( st.top() == '[' && i == ']' ) ||
						( st.top() == '{' && i == '}' ) ) {
					st.pop();
				}
				else
					return false;
			}
		}
        return st.empty();
    }
};
