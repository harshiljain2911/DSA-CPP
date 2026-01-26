class Solution {
public:
    int countatmostk(vector<int>& nums, int k) {

        int left = 0;
        int right;
        int count = 0;
        unordered_map<int, int> s;

        for (right = 0; right < nums.size(); right++)

        {
            s[nums[right]]++;

            while (s.size() > k) {
                s[nums[left]]--;
                if (s[nums[left]] == 0) {
                    s.erase(nums[left]);
                }
                left++;
            }

            count = count + right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countatmostk(nums, k) - countatmostk(nums, k - 1);
    }
};
