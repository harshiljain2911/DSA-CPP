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
    int globalMax = 0;

public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return globalMax;
    }

private:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftDepth  = dfs(node->left);
        int rightDepth = dfs(node->right);

        // Can we extend the arm from left child upward through current?
        int leftArm  = (node->left  && node->left->val  == node->val) ? leftDepth  + 1 : 0;
        int rightArm = (node->right && node->right->val == node->val) ? rightDepth + 1 : 0;

        // Path THROUGH current node (both arms combined)
        globalMax = max(globalMax, leftArm + rightArm);

        // Return only the longer arm to parent
        return max(leftArm, rightArm);
    }
};
