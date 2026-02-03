class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int sum = 0;
        set<vector<int>> s = {};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        s.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};
