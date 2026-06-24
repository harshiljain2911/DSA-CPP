class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        if ((accumulate(nums.begin(), nums.end(), 0) % 2 != 0))
            return false;
        else {

            int target = (accumulate(nums.begin(), nums.end(), 0)) / 2;

            vector<bool> dp(target + 1, false);

            dp[0] = true;
            if (nums[0] <= target)
                dp[nums[0]] = true;

            for (int i = 1; i < n; i++) {
                for (int j = target; j >= nums[i]; j--) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }

            return dp[target];
        }
    }
};
