class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int m = arr.size();
        vector<vector<int>> dp=arr;
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+arr[i][j];
            }
        }
        return dp[0][0];
    }
};