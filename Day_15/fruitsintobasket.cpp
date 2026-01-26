class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
    int left=0;
    int right;
    unordered_map<int,int> m;
    int maxlen = 0;

    for(right = 0;right<fruits.size();right++)
    {
       
            m[fruits[right]]++;
                
            while(m.size()>2)
            {

                m[fruits[left]]--;
                if(m[fruits[left]]==0)
                {
                    m.erase(fruits[left]);
                }
                left++;
        
            }
        
        maxlen = max(maxlen,right-left+1);
    }





    return maxlen;



    }
};
