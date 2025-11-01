class Solution {
public:
    void backtrack(int i,int j,int n,int m,vector<vector<int>>& arr,vector<vector<int>> dp,int sum,int check,int& ans){
        if(i<0 || j<0 ||i>=m || j>=n){
            return;
        }
        if(i==m-1 && j==n-1){
            ans = min(ans,check);
        }
        check = min(sum,sum+arr[i][j]);
        backtrack(i+1,j,n,m,arr,dp,sum+arr[i][j],check,ans);
        backtrack(i,j-1,n,m,arr,dp,sum+arr[i][j],check,ans);
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n = arr[0].size();
        int m = arr.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1; 
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans = min(dp[i][j+1],dp[i+1][j])-arr[i][j];
                dp[i][j] =max(1,ans);
            }
        }
        return dp[0][0];
    }

};