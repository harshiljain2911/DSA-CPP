class Solution {
public:

int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int m = *max_element(nums.begin(),nums.end());

        vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(m+1, vector<long long>(m+1,0)));

        for(int i=1;i<=m;i++)
        {
            dp[n][i][i]=1;
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int g1=0;g1<=m;g1++)
            {
                for(int g2 = 0;g2<=m;g2++)
                {
                    

                    long long take1 = dp[i+1][gcd(nums[i],g1)][g2];
                    long long take2 = dp[i+1][g1][gcd(nums[i],g2)];
                    long long skip = dp[i+1][g1][g2];

                    dp[i][g1][g2]=((skip+take1+take2)%mod);
                }
            }
        }

        return dp[0][0][0];
    }
};
