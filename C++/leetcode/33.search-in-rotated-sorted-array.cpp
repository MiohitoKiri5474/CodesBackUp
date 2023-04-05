#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1, mid = ( l + r ) >> 1;
		while ( l <= r ) {
			if ( nums[mid] == target )
				return mid;
			if ( nums[mid] >= nums[l] ) {
				if ( nums[mid] > target && target >= nums[l] )
					r = mid - 1;
				else
					l = mid + 1;
			}
			else {
				if ( nums[mid] < target && target <= nums[r] )
					l = mid + 1;
				else
					r = mid - 1;
			}

			mid = ( l + r ) >> 1;
		}
        return -1;
    }
};
