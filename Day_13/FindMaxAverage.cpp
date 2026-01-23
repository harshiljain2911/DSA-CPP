class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    double windowsum = 0;

    // first window
    for(int i = 0; i < k; i++)
        windowsum += nums[i];

    double maxsum = windowsum;

    int left = 0;
    int right = k;

    while(right < nums.size())
    {
        windowsum = windowsum - nums[left];
        left++;

        windowsum = windowsum + nums[right];
        right++;

        maxsum = max(maxsum, windowsum);
    }

    return maxsum / k;
}

};
