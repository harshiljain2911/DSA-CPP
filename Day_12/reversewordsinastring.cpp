class Solution {
public:
    string reverseWords(string s) {

    string curword = "";
    vector<string> words;
    string finalans = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            curword.push_back(s[i]);
        }
        else
        {
            if(!curword.empty())
            {
                words.push_back(curword);
                curword = "";
            }
        }
    }

    // last word add karna
    if(!curword.empty())
        words.push_back(curword);

    // reverse order
    for(int i = words.size() - 1; i >= 0; i--)
    {
        finalans += words[i];
        if(i != 0) finalans += " ";
    }

    return finalans;
}

};
