class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        for(int i =1;i<n;i++){
            for(int j =0;j<i;j++){
                if(arr[j][1]<arr[i][0]){
                    dp[i]= max(dp[i],1+dp[j]);
                } 
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};