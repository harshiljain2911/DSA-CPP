class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        vector<int> result;

        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int pre = p[1];
            int crs = p[0];

            adj[pre].push_back(crs);
            indegree[crs]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (result.size() == numCourses) {
            return result;
        }
        return {}; // Clean and explicit
    }
};
