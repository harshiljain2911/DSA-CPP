class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;

        // Is current node good?
        int isGood = (node->val >= maxSoFar) ? 1 : 0;

        // Update max for the path going downward
        maxSoFar = max(maxSoFar, node->val);

        // Recurse both subtrees, accumulate count
        int leftCount  = dfs(node->left,  maxSoFar);
        int rightCount = dfs(node->right, maxSoFar);

        return isGood + leftCount + rightCount;
    }
};
