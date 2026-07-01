class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Phase 1: multi-source BFS from all thieves
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (safeness[nr][nc] != -1) continue;
                safeness[nr][nc] = safeness[r][c] + 1;
                q.push({nr, nc});
            }
        }

        // Phase 2: Dijkstra-style max-heap maximizing the minimum safeness on the path
        priority_queue<pair<int,int>> pq; // max-heap by default on first element
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({safeness[0][0], 0});      // encode cell (0,0) as index 0
        visited[0][0] = 1;

        while (!pq.empty()) {
            auto [safe, cell] = pq.top(); pq.pop();
            int r = cell / n, c = cell % n;

            if (r == n - 1 && c == n - 1) return safe;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;
                visited[nr][nc] = 1;
                pq.push({min(safe, safeness[nr][nc]), nr * n + nc});
            }
        }
        return -1; // unreachable — won't actually trigger, grid is fully connected
    }
};
