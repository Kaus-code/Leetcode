class Solution {
public:
    void solve(int& ans, string& ring, string& key, int temp, int steps, int i,
               vector<vector<int>>& dp) {
        int n = ring.size();
        if (temp == key.size()) {
            ans = min(ans, steps);
            return;
        }

        if (steps >= ans) return;  // pruning

        if (dp[i][temp] != -1 && dp[i][temp] <= steps) return;
        dp[i][temp] = steps;

        if (key[temp] == ring[i]) {
            solve(ans, ring, key, temp + 1, steps + 1, i, dp);
        }

        solve(ans, ring, key, temp, steps + 1, (i + 1) % n, dp);
        solve(ans, ring, key, temp, steps + 1, (i - 1 + n) % n, dp);
    }

    int findRotateSteps(string ring, string key) {
        int ans = INT_MAX;
        int n = ring.size();
        int m = key.size();

        // dp[i][temp] = minimum steps needed if we are at ring[i] and at key[temp]
        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(ans, ring, key, 0, 0, 0, dp);
        return ans;
    }
};
