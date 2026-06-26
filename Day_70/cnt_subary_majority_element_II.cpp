class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefix = 0;
        long long ans = 0;
        long long countLess =
            0; // # of past prefix values strictly < current prefix

        for (int num : nums) {
            if (num == target) {
                prefix++;
                countLess += freq[prefix - 1]; // prev prefix is now < current
            } else {
                prefix--;
                countLess -=
                    freq[prefix]; // some prev prefixes are now >= current
            }
            ans += countLess;
            freq[prefix]++;
        }

        return ans;
    }
};
