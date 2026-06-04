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
        queue<TreeNode*> q;


        q.push(root);
        count = 1;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *root = q.front();
                q.pop();

                if(!(root->left) && !(root->right)) return count;

                if(root->left)
                {
                    q.push(root->left);  
                }
                if(root->right)
                {
                    q.push(root->right);
                }

            }
            count++;
        }

        return count;
        
    }
};
