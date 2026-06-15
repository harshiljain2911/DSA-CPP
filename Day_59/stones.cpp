class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(20002);
        rank_.assign(20002, 0);
        for (int i = 0; i < 20002; i++) parent[i] = i;

        for (auto& stone : stones) {
            int r = stone[0];
            int c = stone[1] + 10001; // offset columns
            unite(r, c);
        }

        unordered_set<int> roots;
        for (auto& stone : stones) {
            roots.insert(find(stone[0]));
        }

        return n - (int)roots.size();
    }
};
