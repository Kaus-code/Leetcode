class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto s:strs){
            unordered_map<char,int> mp;
            for(char ch:s){
                mp[ch]++;
            }
            int z = mp['0'];
            int o = mp['1'];
            for(int i = m;i>=z;i--){
                for(int j = n;j>=o;j--){
                    dp[i][j] = max(dp[i][j],dp[i-z][j-o]+1);
                }
            }
        }

        return dp[m][n];
    }
};