class Solution {
public:
    string smallestPalindrome(string s) {

        if (s.length() <= 1) return s;

        string ans = "";
        string temp = "";

        if (s.length() % 2 == 0) {
            int t = s.length() / 2;

            for (int i = 0; i < t; i++) {
                temp += s[i];
            }

            sort(temp.begin(), temp.end());
            ans += temp;

            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        else {
            int t = s.length() / 2;

            // First half only
            for (int i = 0; i < t; i++) {
                temp += s[i];
            }

            sort(temp.begin(), temp.end());
            ans += temp;

            // Middle character
            ans += s[t];

            reverse(temp.begin(), temp.end());
            ans += temp;
        }

        return ans;
    }
};
