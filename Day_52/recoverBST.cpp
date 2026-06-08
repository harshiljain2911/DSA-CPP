class Solution {
public:
    TreeNode* first = nullptr;   // first bad node
    TreeNode* second = nullptr;  // second bad node
    TreeNode* prev = nullptr;    // previous node in inorder

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Check if current node violates BST order
        if (prev && prev->val > root->val) {
            if (!first) first = prev;   // first violation: grab the bigger node
            second = root;              // always update second to current smaller node
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
