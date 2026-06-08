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
    int globalMax = 0;

    // returns {isBST, minVal, maxVal, sum}
    tuple<bool, long, long, int> dfs(TreeNode* root) {

        // base case: null node
        if (!root) return {true, LONG_MAX, LONG_MIN, 0};

        // get info from left and right children first (postorder)
        auto [leftBST,  leftMin,  leftMax,  leftSum]  = dfs(root->left);
        auto [rightBST, rightMin, rightMax, rightSum] = dfs(root->right);

        // check if current node forms a valid BST
        if (leftBST && rightBST
            && root->val > leftMax
            && root->val < rightMin)
        {
            int sum = leftSum + rightSum + root->val;
            globalMax = max(globalMax, sum);

            long minVal = min(leftMin,  (long)root->val);
            long maxVal = max(rightMax, (long)root->val);

            return {true, minVal, maxVal, sum};
        }

        // not a valid BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return globalMax;
    }
};
