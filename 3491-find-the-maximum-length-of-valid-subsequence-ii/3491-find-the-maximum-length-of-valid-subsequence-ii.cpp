class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;
        
        for (int a : nums) {
            int x = a % k;
            for (int y = 0; y < k; ++y) {
                dp[x][y] = dp[y][x] + 1;
                ans = max(ans, dp[x][y]);
            }
        }
        
        return ans;
    }
};