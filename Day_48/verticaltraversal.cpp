class Solution {
private:
    vector<tuple<int,int,int>> nodes; // (col, row, val)

    void dfs(TreeNode* node, int col, int row) {
        if (!node) return;
        nodes.push_back({col, row, node->val});
        dfs(node->left,  col - 1, row + 1);
        dfs(node->right, col + 1, row + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;
        int prevCol = INT_MIN;

        for (auto& [col, row, val] : nodes) {
            if (col != prevCol) {
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(val);
        }

        return result;
    }
};
