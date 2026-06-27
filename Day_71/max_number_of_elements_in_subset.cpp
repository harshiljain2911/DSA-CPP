class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long,int> mp;
        
        int maxBase = *max_element(nums.begin(),nums.end()); 
        
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;

        int ans=1;

        if(mp.count(1))
        {
            ans = mp[1];
            if(ans%2==0) ans--;
        } 

        for(auto& [base,cnt] : mp)
        {
            if(base==1) continue;

            long long cur = base;
            int len = 0;

            while(cur<=maxBase && mp.count(cur) && mp[cur]>=2)
            {
                len+=2;
                cur = cur*cur;
            }

            if(mp.count(cur)) len+=1;
            else len-=1;
            
            ans = max(ans,len);

        }

        return ans;

    }
};
