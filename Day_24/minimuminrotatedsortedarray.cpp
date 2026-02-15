class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // minimum right side me
                left = mid + 1;
            } else {
                // minimum left side me including mid
                right = mid;
            }
        }

        return nums[left];
    }

};
