/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> postorder(TreeNode* root){
           vector<int> ans;

        if(root == NULL)
            return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty())
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode* temp = st.top()->right;

                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();

                        ans.push_back(temp->datal);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }

        return ans;
    }
        

		}
};
