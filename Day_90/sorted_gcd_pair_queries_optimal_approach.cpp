class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // cnt[d] = numbers divisible by d
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        vector<long long> gcdCnt(mx + 1, 0);

        // inclusion-exclusion
        for (int d = mx; d >= 1; d--) {

            gcdCnt[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int m = 2 * d; m <= mx; m += d)
                gcdCnt[d] -= gcdCnt[m];
        }

        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + gcdCnt[i];

        vector<int> ans;

        for (long long q : queries) {

            int lo = 1, hi = mx;

            while (lo < hi) {

                int mid = (lo + hi) / 2;

                if (prefix[mid] > q)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans.push_back(lo);
        }

        return ans;
    }
};
