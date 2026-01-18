class Solution {
public:
    bool ispal(string t, int l, int r) {

        while (l <= r) {
            if (t[l] != t[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            if (s[left] != s[right]) {
                return ispal(s, left + 1, right) || ispal(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};
