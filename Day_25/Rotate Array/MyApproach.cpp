class Solution {
public:
void rotateArrayByOne(vector<int> & nums) {

                int temp = nums[nums.size()-1];

                for (int i = nums.size()-1; i > 0; i--) {
                    nums[i] = nums[i - 1];
                }
                nums[0] = temp;
            }
    void rotate(vector<int>& nums, int k) {

        for (int j = 0; j < k; j++) {

            rotateArrayByOne(nums);
        }
    }
};
