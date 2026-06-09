class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans;

        long long min_val = *min_element(nums.begin(), nums.end());
        long long max_val = *max_element(nums.begin(), nums.end());

        ans = (max_val - min_val) * 1LL * k;

        return ans;
    }
};
