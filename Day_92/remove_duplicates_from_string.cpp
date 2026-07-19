class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> last;

        for(int i=0;i<s.length();i++)
        {
            last[s[i]] = i;
        }

        stack<char> st;
        unordered_set<char> instack;

        for(int i=0;i<s.length();i++)
        {
            if(instack.count(s[i]))
            {
                continue;
            }

            while(!st.empty() && last[st.top()]>i && st.top()>s[i])
            {
                instack.erase(st.top());
                st.pop();
            }
                st.push(s[i]);
                instack.insert(s[i]);
        }

        string ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};
