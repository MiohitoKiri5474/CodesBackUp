class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
		vector < int > res;
        sort ( nums.begin(), nums.end() );
		if ( nums.back() < target )
			return res;
		auto l = lower_bound ( nums.begin(), nums.end(), target );
		if ( *l != target )
			return res;
		int r = upper_bound ( nums.begin(), nums.end(), target ) - nums.begin();
		for ( int i = l - nums.begin() ; i < r ; i++ )
			res.emplace_back ( i );

		return res;
    }
};
