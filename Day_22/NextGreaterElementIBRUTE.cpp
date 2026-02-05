class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans(nums1.size(), -1);
    stack<int> st;
    int t = 0;
    int temp = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        st.push(i);
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                t = j;
            }
        }
        for (int k = t + 1; k < nums2.size(); k++)
        {

            if (nums2[k] > nums1[i])
            {
                temp = st.top();
                st.pop();
                ans[temp] = nums2[k];
                break;
            }
        }
    }

    return ans;
}
};
