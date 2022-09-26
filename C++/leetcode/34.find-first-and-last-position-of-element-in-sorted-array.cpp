class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector < int > res;
		if ( nums.empty() || target > nums.back() ) {
			res.push_back ( -1 );
			res.push_back ( -1 );
			return res;
		}
		auto l = lower_bound ( nums.begin(), nums.end(), target ), r = upper_bound ( nums.begin(), nums.end(), target );
		if ( *l != target ) {
			res.push_back ( -1 );
			res.push_back ( -1 );
			return res;
		}
		res.push_back ( l - nums.begin() );
		res.push_back ( r - nums.begin() - 1 );
		return res;
    }
};
