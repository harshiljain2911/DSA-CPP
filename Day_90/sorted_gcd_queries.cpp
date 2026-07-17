class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int n = nums.size();

        vector<int> gcdpairs;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                gcdpairs.push_back(gcd(nums[i], nums[j]));
            }
        }

        sort(gcdpairs.begin(), gcdpairs.end());

        vector<int> ans;

        for (auto& q : queries) {
            ans.push_back(gcdpairs[q]);
        }

        return ans;
    }
};
