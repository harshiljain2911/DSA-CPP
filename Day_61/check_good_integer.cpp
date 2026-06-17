class Solution {
public:
    int digitsum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int r = n%10;
            sum+=r;
            n = n/10;
        }
        return sum;
    }

    int squaresum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int r = n%10;
            sum+=r*r;
            n = n/10;
        }
        return sum;
    }
    
    bool checkGoodInteger(int n) {
        return ((squaresum(n)-digitsum(n))>=50);
    }
};
