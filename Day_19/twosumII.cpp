class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            int current = numbers[i];
            int need = target - current;
            if (m.find(need) != m.end()) {
                return {m[need] + 1, i + 1};
            }

            m[current] = i;
        }

        return {};
    }
};
