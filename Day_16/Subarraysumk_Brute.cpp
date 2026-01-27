class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            sum = 0;

            for (int t = i; t <= j; t++) {
                sum += nums[t];
            }

            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}


};
