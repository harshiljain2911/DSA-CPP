class Solution {
public:
    int removeDuplicates(vector<int>& t) {
        int p = t.size();
    int i = 0;

    for(int j = 1; j < p; j++) {
        if(t[i] != t[j]) {
            i++;
            t[i] = t[j];
        }
    }
    return i + 1;
    }
};
