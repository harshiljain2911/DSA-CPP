class Solution {
public:
    string reverseByType(string s) {
        int ans;
        int i=0;
        int j = s.length()-1;
        while(i<j)
        {
            if( !isalpha(s[i])) i++;
            if( !isalpha(s[j])) j--;

            if( isalpha(s[i]) && isalpha(s[j]) ){
                swap(s[i],s[j]);
                i++;
                j--;
            } 
        }

        i=0;
        j = s.length()-1;
        while(i<j)
        {
            if( isalpha(s[i])) i++;
            if( isalpha(s[j])) j--;

            if( !isalpha(s[i]) && !isalpha(s[j]) ){
                swap(s[i],s[j]);
                i++;
                j--;
            } 
        }

        return s;

    }
};
