class Solution {
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;       // both null → symmetric
        if (!left || !right) return false;      // one null → not symmetric
        if (left->val != right->val) return false; // values differ → not symmetric

        return isMirror(left->left,  right->right) &&  // outer pair
               isMirror(left->right, right->left);     // inner pair
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};
