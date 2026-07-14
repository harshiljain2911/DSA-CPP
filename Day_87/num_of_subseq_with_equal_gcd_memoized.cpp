class Solution {
public:

int mod = 1e9+7;

    long long helper(int i,int g1,int g2,vector<int>& nums,vector<vector<vector<long long>>>& dp) {
        if(i==nums.size())
        {
            if(g1!=0 && g2!=0 && g1==g2) return 1;
            else return 0;
        }

        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];

        long long take1 = helper(i+1,gcd(g1,nums[i]),g2,nums,dp);
        long long take2 = helper(i+1,g1,gcd(g2,nums[i]),nums,dp);
        long long skip = helper(i+1,g1,g2,nums,dp);

        return dp[i][g1][g2]=((skip+take1+take2)%mod);
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int m = *max_element(nums.begin(),nums.end());

        vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(m+1, vector<long long>(m+1,-1)));

        return helper(0,0,0,nums,dp);
    }
};
