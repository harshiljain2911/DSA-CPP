class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
    
    int first=0;
    int last=nums.size()-1;
    int mid;
    int ansl=-1;
    int ansr=-1;

    if(nums.empty())
    {
        return {ansl,ansr};
    }



    while(first<=last)
    {

        mid = (first+last)/2;
        
        if(nums[mid]==target)
        {
            ansl = mid;
            last = mid-1;    
        }
        else if(nums[mid]>target)
        {
            last = mid-1;
        }
        else
        {
            first = mid+1;
        }
    
    }

    first = 0;
    last = nums.size()-1;

    while(first<=last)
    {

        mid = (first+last)/2;
        
        if(nums[mid]==target)
        {
            ansr = mid;
            first = mid+1;    
        }
        else if(nums[mid]>target)
        {
            last = mid-1;
        }
        else
        {
            first = mid+1;
        }
    
    }

    return {ansl,ansr};

    }
};
