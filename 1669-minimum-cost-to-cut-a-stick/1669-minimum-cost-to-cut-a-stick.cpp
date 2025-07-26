class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the two ends
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        for (int i = c - 1; i >= 0; i--) {
            for (int j = i + 2; j < c; j++) {
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][c - 1];
    }
};
