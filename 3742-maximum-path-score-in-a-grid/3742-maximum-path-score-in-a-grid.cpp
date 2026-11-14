class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));

        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cost = grid[i][j] == 0 ? 0 : 1;
                int score = grid[i][j];

                for (int c = 0; c <= k; c++) {
                    if (c < cost)
                        continue;
                    int prev_cost = c - cost;

                    if (i > 0 &&dp[i-1][j][prev_cost]!=INT_MIN) {
                        dp[i][j][c] =
                            max(dp[i][j][c], dp[i - 1][j][prev_cost] + score);
                    }

                    if (j > 0 &&dp[i][j-1][prev_cost]!=INT_MIN) {
                        dp[i][j][c] =
                            max(dp[i][j][c], dp[i][j - 1][prev_cost] + score);
                    }
                }
            }
        }

        int ans = INT_MIN;

        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][m - 1][c]);
        }

        if (ans == INT_MIN)
            return -1;

        return ans;
    }
};