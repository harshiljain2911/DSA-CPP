class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;  // one is null, other isn't
        if (p->val != q->val)       return false;

        bool leftp  = isSameTree(p->left,  q->left);
        bool rightp = isSameTree(p->right, q->right);

        return leftp && rightp;  // ← your bug was here
    }
};
