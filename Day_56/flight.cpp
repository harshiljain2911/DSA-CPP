class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][stops] = cheapest cost to reach node using exactly 'stops' stops
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        // Min-heap: {cost, node, stops_used}
        priority_queue<tuple<int,int,int>,
                       vector<tuple<int,int,int>>,
                       greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            // Reached destination
            if (node == dst) return cost;

            // Exceeded stop limit
            if (stops > k) continue;

            for (auto& [neighbor, price] : adj[node]) {
                int newCost = cost + price;
                if (newCost < dist[neighbor][stops + 1]) {
                    dist[neighbor][stops + 1] = newCost;
                    pq.push({newCost, neighbor, stops + 1});
                }
            }
        }

        return -1;
    }
};
