class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            int need = target - current;

            if(m.find(need) != m.end()) {
                return {m[need], i};
            }

            m[current] = i;
        }

        return {};
    }
};
