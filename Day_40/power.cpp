class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;   // overflow avoid
        double ans = 1.0;

        // handle negative powers
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }

        while(N > 0) {

            // if power is odd
            if(N % 2 == 1) {
                ans *= x;
            }

            // square the base
            x *= x;

            // divide power by 2
            N /= 2;
        }

        return ans;
    }
};
