class Solution {
public:
    bool fun(int target, vector<int>& nums, vector<vector<bool>>& dp) {

        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                bool skip = dp[i-1][j];
                bool take = (nums[i]<=j)?dp[i-1][j-nums[i]]:false;

                dp[i][j] = skip || take;
            }
        }

        return dp[nums.size()-1][target];
    }

    bool canPartition(vector<int>& nums) {

        if ((accumulate(nums.begin(), nums.end(), 0) % 2 != 0))
            return false;
        else {

            int target = (accumulate(nums.begin(), nums.end(), 0)) / 2;

            vector<vector<bool>> dp(nums.size(),
                                    vector<bool>(target + 1, false));

            return fun(target, nums, dp);
        }
    }
};
