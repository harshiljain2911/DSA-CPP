class Solution {
public:
    // state: 0 = unvisited, 1 = visiting, 2 = visited
    bool dfs(vector<vector<int>>& adj, vector<int>& state, int node) {
        
        if (state[node] == 1) return false; // cycle detected
        if (state[node] == 2) return true;  // already safe, skip

        state[node] = 1; // mark as currently visiting

        for (int neighbor : adj[node]) {
            if (!dfs(adj, state, neighbor))
                return false; // cycle found deeper in
        }

        state[node] = 2; // fully processed, mark safe
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Step 1: build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            // pre[1] must be taken before pre[0]
            // so edge goes pre[1] → pre[0]
        }

        // Step 2: run DFS from every unvisited node
        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(adj, state, i))
                    return false;
            }
        }

        return true;
    }
};
