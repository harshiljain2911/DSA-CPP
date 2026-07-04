class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        int ans = INT_MAX;

        for(int i=0;i<roads.size();i++)
        {
            int a = roads[i][0];
            int b = roads[i][1];
            int d = roads[i][2];

            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }

        vector<int> vis(n+1,0);

        queue<int> q;
        q.push(1);
        vis[1]=1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto& [city,dist]:adj[node])
            {
                ans = min(ans,dist);

                if(!vis[city])
                {
                    vis[city]=1;
                    q.push(city);
                }
            }


        }


        return ans;


    }
};
