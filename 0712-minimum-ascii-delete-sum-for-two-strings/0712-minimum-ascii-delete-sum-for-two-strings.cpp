class Solution {
public:
    int ASCII_longestCommonSubsequence(string text1, string text2) {
       int m=text1.length();
       int n=text2.length();
       vector<vector<int>> dp(m+1,vector<int>(n+1,0));
       for(int i=1;i<=m;i++)
       {
        for(int j=1;j<=n;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+text1[i-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       } 
       return dp[m][n];
    }
int asciisum(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans+=s[i];
    }
    return ans;
}
    int minimumDeleteSum(string s1, string s2) {
        int LCS_z=ASCII_longestCommonSubsequence(s1,s2);
        int  x=asciisum(s1);
        int y=asciisum(s2);

        return (x-LCS_z)+(y -LCS_z);
    }
};