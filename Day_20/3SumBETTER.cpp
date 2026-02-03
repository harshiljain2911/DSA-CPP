class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> s;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            set<int> hashset;

            for (int j = i + 1; j < nums.size(); j++) {

                int third = -(nums[i] + nums[j]);

                if (hashset.find(third) != hashset.end()) {

                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        ans.assign(s.begin(), s.end());
        return ans;
    }
};
