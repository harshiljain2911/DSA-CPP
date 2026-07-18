class Solution {
public:
    int lenn(int n) {

        if(n==0) return 1;

        int count;
        if (n < 0) {
            count = 1;
            while (abs(n) > 0) {
                count++;
                n /= 10;
            }

        } else {
            count = 0;
            while (n > 0) {
                count++;
                n /= 10;
            }
        }
        return count;
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j] = max(ans[j], lenn(grid[i][j]));
            }
        }

        return ans;
    }
};
