class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n; // yeh kara hai taki agr k>nums.size() hua toh usko handlke krle as array rotations cycle mai hote hai

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
