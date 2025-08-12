class Solution {
public:
    const int MOD = 1e9 + 7;

    int back(int n, int i, int sum, int x, vector<vector<int>> &dp) {
        if (sum > n) return 0;
        if (sum == n) return 1;
        if (i > n) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        // Compute i^x without floating point
        long long power = 1;
        for (int k = 0; k < x; k++) power *= i;
        if (power > n) return dp[i][sum] = 0; // avoid overflow

        int ways = 0;
        // Option 1: skip i
        ways = (ways + back(n, i + 1, sum, x, dp)) % MOD;
        // Option 2: take i
        ways = (ways + back(n, i + 1, sum + (int)power, x, dp)) % MOD;

        return dp[i][sum] = ways;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return back(n, 1, 0, x, dp);
    }
};
