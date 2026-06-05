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
    int minDepth(TreeNode* root) {
        
        int count = 0;
        
        if (!root) return count;
        count = 1;

        if(!(root->left) && !(root->right)) return count;
        

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(!(root->left) && (root->right)) return 1+right;
        if((root->left) && !(root->right)) return 1+left;

       


        return (1 + min(left,right));


    }
};
