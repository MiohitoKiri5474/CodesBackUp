/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector < int > path;
		solve ( root, targetSum, 0, path );
		return ans;
    }
private:
	void solve ( TreeNode *root, int target, int num, vector < int > path ) {
		if ( !root )
			return;
		num += root -> val;
		path.emplace_back ( root -> val );
		if ( !root -> left && !root -> right && target == num )
			ans.emplace_back ( path );
		
		solve ( root -> left, target, num, path );
		solve ( root -> right, target, num, path );
	}
	vector < vector < int > > ans;
};
