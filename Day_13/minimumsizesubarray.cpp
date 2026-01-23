class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    int minlength = INT_MAX;   // 1️⃣ 0 → INT_MAX
    int left = 0;
    int sum = 0;               // 2️⃣ nums[left] se 0
     
    for(int right = 0; right < nums.size(); right++)   // 3️⃣ single loop for right
    {
        sum += nums[right];    // window expand

        while(sum >= target)   // 4️⃣ shrink window
        {
            minlength = min(minlength, right - left + 1);
            sum -= nums[left]; // 5️⃣ sum shrink
            left++;
        }
    }

    return (minlength == INT_MAX) ? 0 : minlength;
}

};
