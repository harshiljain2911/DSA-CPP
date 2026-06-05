/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int target, vector<int>& level,
             vector<vector<int>>& ans) {
        if (node == NULL) {
            return;
        }
        target = target - (node->val);
        level.push_back(node->val);

        if ((!(node->left) && !(node->right)) && target == 0) {
            ans.push_back(level);
        }

        dfs(node->left, target, level, ans);
        dfs(node->right, target, level, ans);

        level.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> level;

        dfs(root, targetSum, level, ans);

        return ans;
    }
};
