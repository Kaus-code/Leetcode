class Solution {
public:
bool palindrome(int i,int j,string &s)
{
while(i<=j)
{
    if(s[i]!=s[j]) return false;
    i++;
    j--;
}
return true;
}
int solve(int i,int j,string &s,vector<vector<int>>&dp)
{
    if(i>=j || palindrome(i,j,s)) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
int result=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        if(palindrome(i,k,s))
        {
            int temp=1+solve(k+1,j,s,dp);
            result=min(result,temp);

        }
    }
    return dp[i][j]=result;

}
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
return solve(0,n-1,s,dp);
    }
};