class Solution {
public:
    /*
      [0,1,1,1],
      [1,1,2,2],
      [0,1,2,3]
    */

    /*
      [1,0,1],
      [1,1,0],
      [1,2,0]
    */
    
    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));  
        for(int i=0;i<n;i++) dp[i][0] = arr[i][0];
        for(int i=0;i<m;i++) dp[0][i] = arr[0][i];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]==1){
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }        
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        return  sum;
    }
};