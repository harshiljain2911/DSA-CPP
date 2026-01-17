class Solution {
public:
    bool isAnagram(string s, string t) {
    
    
    unordered_map<char,int> freq;

    if(s.length()!=t.length())
    {
        return false;
    }
    for(char c:s)
    {
        freq[c]++;
    }
    for(char c:t)
    {
        freq[c]--;
    }
    for(auto it:freq)
    {
        if(it.second!=0)
        {
            return false;
        }
    }
        return true;
    

    }
};
