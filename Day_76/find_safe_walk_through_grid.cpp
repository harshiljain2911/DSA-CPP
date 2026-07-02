class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0] =  grid[0][0];

        q.push({0,0});

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(auto& d:dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                int cost = dist[r][c];

                if(nr<0 || nr>=m || nc<0 || nc>=n) continue;

                cost = dist[r][c]+grid[nr][nc];

                if(nr==m-1 && nc==n-1 && cost<health) return true;

                if (cost >= health) continue;                

                if(cost<dist[nr][nc])
                {
                    dist[nr][nc] = cost;
                    q.push({nr,nc});
                }
                
            }
        }

        return false;

    }
};
