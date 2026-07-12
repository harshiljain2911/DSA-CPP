class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

    if(arr.size()<1) return arr;
    
    vector<int> temp = arr;

    sort(temp.begin(),temp.end());

    unordered_map<int,int> ans(temp.size());

    ans[temp[0]]=1;

    for(int i=1;i<temp.size();i++)
    {
        if(temp[i]==temp[i-1])
        {
            ans[temp[i]] = ans[temp[i-1]];
        } 
        else
        {
            ans[temp[i]]=ans[temp[i-1]]+1;
        }
    }

    vector<int> result;

    for(int i=0;i<arr.size();i++)
    {
        result.push_back(ans[arr[i]]);
    }


    return result;

    

    }
};
