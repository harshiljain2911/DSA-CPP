class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list:
        // prereq -> course
        vector<vector<int>> adj(numCourses);

        // indegree[i] = number of prerequisites needed for course i
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all courses having no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Counts how many courses we are able to complete
        int completedCourses = 0;

        // Kahn's Algorithm (BFS Topological Sort)
        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            completedCourses++;

            // Remove current course's outgoing edges
            for (int nextCourse : adj[curr]) {

                indegree[nextCourse]--;

                // If all prerequisites are satisfied
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If we processed all courses, no cycle exists
        // Otherwise, a cycle exists
        return completedCourses == numCourses;
    }
};
