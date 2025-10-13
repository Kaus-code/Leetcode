class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>& arr,int m,int n,int i,int j,int l,int prev,int& ans,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n || arr[i][j]<=prev){
           
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int len =1;
        for(auto [a,b]:dir){
            len = max(len,1+dfs(arr,m,n,i+a,j+b,l+1,arr[i][j],ans,dp));
        }
        return dp[i][j] = len;
    }
    int longestIncreasingPath(vector<vector<int>>& arr) {
         m = arr.size();
         n = arr[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int l =0;
                ans = max(ans,dfs(arr,m,n,i,j,l,-1,ans,dp));
            }
        }
        return ans;
    }
};