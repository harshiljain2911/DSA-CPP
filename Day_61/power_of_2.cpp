class Solution {
public:
    int countSetbits(int n) {
        int count = 0;
        while(n>0)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }

    bool isPowerOfTwo(int n) {
        return countSetbits(n)==1;
    }
};
