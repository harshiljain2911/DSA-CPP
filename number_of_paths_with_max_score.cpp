class Solution {
public:
    static const int MOD = 1'000'000'007;

    pair<int,int> fun(int i, int j, vector<vector<pair<int,int>>>& dp, vector<string>& board) {
        if (i < 0 || j < 0 || board[i][j] == 'X') return {-1, 0};  // unreachable
        if (i == 0 && j == 0) return {0, 1};                        // reached 'E'
        if (dp[i][j].first != -2) return dp[i][j];                  // -2 = uncomputed

        auto d = fun(i-1, j-1, dp, board);   // diagonal
        auto u = fun(i-1, j,   dp, board);   // up
        auto l = fun(i,   j-1, dp, board);   // left

        int best = max({d.first, u.first, l.first});
        if (best == -1) return dp[i][j] = {-1, 0};   // no reachable predecessor

        long long ways = 0;
        if (d.first == best) ways += d.second;
        if (u.first == best) ways += u.second;
        if (l.first == best) ways += l.second;
        ways %= MOD;

        int val = isdigit(board[i][j]) ? board[i][j] - '0' : 0;   // 'S' contributes 0
        return dp[i][j] = {best + val, (int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-2, 0}));
        auto [score, count] = fun(n-1, n-1, dp, board);
        if (score == -1) return {0, 0};
        return {score, count};
    }
};
