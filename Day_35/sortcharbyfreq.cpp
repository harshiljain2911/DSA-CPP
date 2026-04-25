class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Move to vector
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Step 3: Sort by frequency
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Step 4: Build result
        string ans = "";
        for (auto &p : vec) {
            ans += string(p.second, p.first);
        }

        return ans;
    }
};
