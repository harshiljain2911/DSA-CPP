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

    // FIXED: pass min/max range instead of checking only immediate children
    bool validBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;                          // FIX 1: null = valid, not false
        if (root->val <= minVal || root->val >= maxVal)  // FIX 2: range check, not child check
            return false;
        return validBST(root->left,  minVal,    root->val)   // FIX 3: removed dead code + typo
            && validBST(root->right, root->val, maxVal);
    }

    // FIXED: parameter name was 'node' but body used 'root' — unified to root
    vector<int> inorder(TreeNode* root) {
        vector<int> ans;

        if (!root) return ans;                           // FIX 4: was 'root' in a 'node' param

        vector<int> left  = inorder(root->left);
        vector<int> right = inorder(root->right);

        ans.insert(ans.end(), left.begin(),  left.end());
        ans.push_back(root->val);                        // FIX 5: was push_back(root), need ->val
        ans.insert(ans.end(), right.begin(), right.end()); // FIX 6: was left again, should be right

        return ans;
    }

    int BSTsum(vector<int>& ans) {                       // FIX 7: pass by reference, not copy
        int sum = 0;
        for (int i = 0; i < ans.size(); i++)
            sum += ans[i];
        return sum;
    }

    // FIXED: now actually implemented
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;

        int currentSum = 0;

        // check if current subtree is a valid BST
        if (validBST(root, LONG_MIN, LONG_MAX)) {        // FIX 8: pass range bounds
            vector<int> nodes = inorder(root);
            currentSum = BSTsum(nodes);
        }

        // recurse into left and right subtrees regardless
        int leftSum  = maxSumBST(root->left);
        int rightSum = maxSumBST(root->right);

        return max({currentSum, leftSum, rightSum});      // FIX 9: was empty, now returns max
    }
};
