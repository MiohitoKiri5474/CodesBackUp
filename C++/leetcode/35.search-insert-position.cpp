class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		if ( nums.back() < target )
			return nums.size();
        return lower_bound ( nums.begin(), nums.end(), target ) - nums.begin();
    }
};
