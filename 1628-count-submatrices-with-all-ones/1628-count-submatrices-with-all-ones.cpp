class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int res = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] == 1) {
                    // Build histogram: number of consecutive 1s to the left, including current cell
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;

                    int min_width = dp[i][j];
                    // Count submatrices ending at (i,j)
                    for (int k = i; k >= 0 && dp[k][j] > 0; --k) {
                        min_width = min(min_width, dp[k][j]);
                        res += min_width;
                    }
                }
            }
        }

        return res;
    }
};
