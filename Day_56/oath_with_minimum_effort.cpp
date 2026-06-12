class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // effort[r][c] = minimum effort to reach (r,c) from (0,0)
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        // Min-heap: {effort, row, col}
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<tuple<int,int,int>>> pq;
        pq.push({0, 0, 0});

        // 4 directions only
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!pq.empty()) {
            auto [eff, r, c] = pq.top();
            pq.pop();

            // Reached destination
            if (r == rows-1 && c == cols-1)
                return eff;

            // Stale check
            if (eff > effort[r][c]) continue;

            for (auto& [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                // Bounds check
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                // New effort = max of current path effort and this step
                int newEff = max(eff, abs(heights[r][c] - heights[nr][nc]));

                // Relaxation
                if (newEff < effort[nr][nc]) {
                    effort[nr][nc] = newEff;
                    pq.push({newEff, nr, nc});
                }
            }
        }

        return 0;
    }
};
