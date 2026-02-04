class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int fix;
        int left;
        int right;
        int sum = 0;
        for (fix = 0; fix < nums.size(); fix++) {

            if (fix > 0 && nums[fix] == nums[fix - 1])
                continue; // yha par hum kar kya rhe ahi ki hum humare FIX
                          // pointer ko check kr rhe hai ki woh pichle wale fix
                          // position ke element se same toh nhi hai na aur agr
                          // hai toh fir tab hume fix ko ++ krna hai aur yha pr
                          // yeh cheez jab fix 0 hoga tab nhi check kr skte as 0
                          // se pehle koi element nhi hai isiliye yeh condition
                          // use kari

            left = fix + 1;
            right = nums.size() - 1;

            while (left < right) {

                sum = nums[fix] + nums[left] + nums[right];

                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    vector<int> temp = {nums[fix], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return ans;
    }
};
