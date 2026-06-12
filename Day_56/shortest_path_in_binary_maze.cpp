class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Edge case: start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // Edge case: 1x1 grid
        if (n == 1) return 1;

        // 8 directions: up, down, left, right, 4 diagonals
        vector<pair<int,int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1},
            { 0,-1},          {0,1},
            { 1,-1},  {1,0}, {1,1}
        };

        // BFS queue stores {row, col, distance}
        queue<tuple<int,int,int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1; // mark visited by setting to 1

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            // Try all 8 neighbors
            for (auto& [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                // Check bounds
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                // Check if blocked or visited
                if (grid[nr][nc] == 1)
                    continue;

                // Reached destination
                if (nr == n-1 && nc == n-1)
                    return dist + 1;

                // Mark visited and push
                grid[nr][nc] = 1;
                q.push({nr, nc, dist + 1});
            }
        }

        return -1; // destination unreachable
    }
};
