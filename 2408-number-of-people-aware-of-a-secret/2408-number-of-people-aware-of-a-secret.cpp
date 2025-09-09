class Solution {
public:
int M=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1);
        dp[1]=1;
        for(int day=2;day<=n;day++)
        {
            long long count=0;
            for(int prev=day-forget+1;prev<=day-delay;prev++)
            {
                if(prev>0)
                count=(count+dp[prev])%M;
            }
            dp[day]=count;
        }

        int result=0;
        for(int day=n-forget+1;day<=n;day++)
        {
            if(day>0)
            result=(result+dp[day])%M;
        }

        return result;
    }
};