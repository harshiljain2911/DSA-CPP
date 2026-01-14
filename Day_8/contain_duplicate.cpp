class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    
    unordered_set<int> s;

    for(int i=0;i<nums.size();i++)
    {
        if(s.find(nums[i])!=s.end()) // is line ka matlab aisa hai ki joh set ki working hoti woh yhi hoti ki agar set mai nums[i] hai toh fir woh true return krega aur agar nahi hai toh fir woh s.end() return krega ; s.end() is like a marker
        {
            return true;
        }
        else
        {
            s.insert(nums[i]);
        }
    }
   
    return false;
    }
};
