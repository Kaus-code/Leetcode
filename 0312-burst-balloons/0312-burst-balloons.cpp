class Solution {
public:
    int maxCoins(vector<int>& nums) {
       // Assume virtual ballons at both ends nums[-1]=1 and nums[n] =1
        nums.insert(nums.begin(),1);
        nums.push_back(1);
       
        int n=nums.size();

        //step2 --> dp table
        vector<vector<int>> dp(n,vector<int>(n,0));

        //step3: --> DP MCM
        for(int len=1;len<=n-2;++len)
        {
for(int l=1;l<=n-len-1;++l)
{
    int r=l+len-1;
    for(int k=l;k<=r;k++)
    {
        int coins=nums[l-1]*nums[k]*nums[r+1];
        coins+=dp[l][k-1]; //coins in left subinterval
        coins+=dp[k+1][r]; //coins in right subinterval
        dp[l][r]=max(dp[l][r],coins);
    }
}
        }
       
return dp[1][n-2];
    }
};