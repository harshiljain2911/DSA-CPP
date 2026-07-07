class Solution {
public:
    long long rev(int n)
    {
        long long ans=0;
        while(n>0)
        {
            int r = n%10;    
            ans = (ans*10) + r;
            n=n/10;
        }

        return ans;
    }

    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        while(n>0)
        {
            int r = n%10;
            if(r!=0){
                
                sum += r;
                num = (num*10) + r;

            }

            n=n/10;
        }

        return sum*rev(num);
    }
};
