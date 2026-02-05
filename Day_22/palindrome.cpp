class Solution {
public:
    bool isPalindrome(int x) {

        long r = 0;
        long s = 0;
        long t = x;

        if (x >= 0) {

            while (t != 0) {
                r = t % 10;
                s = 10 * s + r;
                t = t / 10;
            }

            if (x == s)
                return true;
        }

        return false;
    }
};
