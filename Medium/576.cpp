// https://leetcode.com/problems/out-of-boundary-paths/description/
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        auto dfs = [&](int i, int j, int moves, auto&& self) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) {
                return 1;
            }

            if (moves == 0) {
                return 0;
            }
            if (dp[i][j][moves] != -1) {
                return dp[i][j][moves];
            }
            int ways = 0;
            ways = (ways + self(i + 1, j, moves - 1, self)) % MOD;
            ways = (ways + self(i - 1, j, moves - 1, self)) % MOD;
            ways = (ways + self(i, j + 1, moves - 1, self)) % MOD;
            ways = (ways + self(i, j - 1, moves - 1, self)) % MOD;

            return dp[i][j][moves] = ways;
        };
        return dfs(startRow, startColumn, maxMove, dfs);
    }

private:
    static const int MOD = 1000000007;
};
