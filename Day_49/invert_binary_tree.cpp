class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        // Swap left and right children
        swap(root->left, root->right);

        // Recurse into both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
