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
    inline bool hasPathSum(TreeNode* root, int targetSum) {
        return solve ( root, targetSum, 0 );
    }

private:
	bool solve ( TreeNode *root, int target, int num ) {
		if ( !root )
			return false;
		num += root -> val;
		if ( target == num && !root -> left && !root -> right )
			return true;

		return solve ( root -> left, target, num ) || solve ( root -> right, target, num );
	}
};
