class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for ( int i = 0 ; i < nums.size() ; i++ ) {
			for ( int j = i + 1 ; j < nums.size() ; j++ ) {
				if ( nums[i] + nums[j] == target ) {
					vector < int > res;
					res.emplace_back ( i );
					res.emplace_back ( j );
					return res;
				}
			}
		}
		vector < int > bruh;
		return bruh;
    }
};
