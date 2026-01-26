class Solution {
public:
    int characterReplacement(string s, int k) {
  
    int left = 0;
    int right;
    int maxlen = 0;
    unordered_map<int,int> freq;
    int maxfreq = 0;
    

    for(right = 0;right<s.size();right++)
    {
        
        freq[s[right]]++;

        maxfreq = max(maxfreq,freq[s[right]]);

        while((right - left + 1) - maxfreq > k)
        {
            freq[s[left]]--;
            left++;
        }

        maxlen = max(maxlen,right-left+1);
    }




    return maxlen;


    }
};
