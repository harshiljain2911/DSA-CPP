class Solution {
public:
    int maxVowels(string s, int k) {

    int count = 0;
    int maxcount = 0;

    // first window
    for(int i = 0; i < k; i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            count++;
    }

    maxcount = count;

    // slide window
    for(int right = k; right < s.size(); right++)
    {
        int left = right - k;

        // remove left
        if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u')
            count--;

        // add right
        if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u')
            count++;

        maxcount = max(maxcount, count);
    }

    return maxcount;
}

};
