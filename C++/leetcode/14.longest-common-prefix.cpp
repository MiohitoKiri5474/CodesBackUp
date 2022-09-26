class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string res;
        int len = 200;
		for ( auto i: strs )
			len = min ( len, ( int ) i.size() );
		for ( int i = 0 ; i < len ; i++ ) {
			string swp;
			for ( auto j: strs )
				swp += j[i];
			swp.erase ( unique ( swp.begin(), swp.end() ), swp.end() );
			if ( swp.size() == 1 )
				res += swp;
			else
				break;
		}

		return res;
    }
};
