class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
    int i;
    int j;

    for(i=0;i<nums.size();i++)
    {
      for(j = 0;j<nums.size();j++)
      {
        if(nums[i]==nums[j])
        {
            if(i==j)
            {
                continue;
            }
            return true;
        }
      }
    }

return false;

    }
};
