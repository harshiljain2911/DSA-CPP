class Solution {
public:
    int count;   // counts down from k to 0
    int result;  // stores answer when count hits 0

    void inorder(TreeNode* root) {
        if (root == nullptr) return;  // base case: fell off tree

        inorder(root->left);          // Step 1: go left (smaller values)

        count--;                      // Step 2: we are NOW visiting this node
        if (count == 0) {             // Step 3: this is exactly the kth visit
            result = root->val;
            return;                   // early exit — don't go right
        }

        inorder(root->right);         // Step 4: go right only if answer not found
    }

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        result = -1;
        inorder(root);
        return result;
    }
};
