class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = m;
        vector<vector<int>> dp=arr;
        for(int i=n-2;i>=0;i--){
            dp[i][0] = dp[i+1][0]+arr[i][0];
            dp[i][n-1] = dp[i+1][n-1]+arr[i][n-1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int mini = dp[i+1][j];
                if(j>0) mini = min(mini,dp[i+1][j-1]);
                if(j<n-1) mini = min(mini,dp[i+1][j+1]);
                dp[i][j] = mini+arr[i][j];
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};