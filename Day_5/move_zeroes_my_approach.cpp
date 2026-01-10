class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
    int i=0;
    int j=0;

    for (i=0;i<nums.size();i++)
    {
        if(nums[i]==0 && nums[j]!=0)
        {
            j=i;
        }
        else if(nums[i]!=0 && i>j)
        {
            if(nums[j]==0)
            {

            nums[j]=nums[i];
            nums[i]=0;
            }
            if(i==nums.size()-1)
            {
                break;
            }
            else{
                for(int k=i;k<nums.size();k++)
                {
                    if(nums[j]!=0)
                    {
                        j++;
                    }
                }
            }
        }
    }


}
};
