class Solution {
public:
    int solve(int ind,vector<int>& arr,vector<int>& dp, int k){
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int l =0;
        int n = arr.size();
        if(ind == n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        for(int i =ind;i<min(ind+k,n);i++){
            l++;
            maxi = max(arr[i],maxi);
            int sum = maxi*l+solve(i+1,arr,dp,k);
            ans = max(sum,ans);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,dp,k);
    }
};