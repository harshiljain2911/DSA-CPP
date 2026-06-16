class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // min-heap: {elevation, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        int ans = 0;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int elevation = top[0], r = top[1], c = top[2];
            
            ans = max(ans, elevation); // track the highest point crossed so far
            
            if (r == n - 1 && c == n - 1) {
                return ans; // reached destination
            }
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        
        return ans; // fallback, shouldn't be reached for valid input
    }
};
