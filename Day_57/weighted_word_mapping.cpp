class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto& word : words) {
            // Step 1: Compute word weight
            int sum = 0;
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            // Step 2: Modulo 26
            int result = sum % 26;

            // Step 3: Reverse alphabetical mapping
            // 0 → 'z', 1 → 'y', ..., 25 → 'a'
            char mapped = 'z' - result;

            // Step 4: Append
            ans += mapped;
        }

        return ans;
    }
};
