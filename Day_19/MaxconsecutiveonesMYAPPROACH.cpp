#include<iostream>
#include<vector>
#include<map>
using namespace std;

     int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int right;
        map<int, int> m;
        int maxlen = 0;

        for (right = 0; right < nums.size(); right++)

        {

            m[nums[right]]++;

            while (m[0] > k) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    m.erase(nums[left]);
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
