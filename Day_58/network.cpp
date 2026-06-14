class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] == x) return parent[x];
            return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank_[px] < rank_[py]) 
        {
            parent[px] = py;
        }
        else if(rank_[py]<rank_[px])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank_[px]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        parent.resize(n);
        rank_.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto &c : connections) {
            unite(c[0], c[1]);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) components++;
        }

        return components - 1;
    }
};
