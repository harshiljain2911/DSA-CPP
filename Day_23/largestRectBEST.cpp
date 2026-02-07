class Solution {
public:
    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pse(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {

        int maxi = 0;
        int n = heights.size();

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }

        return maxi;
    }
};
