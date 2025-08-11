class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& arr) {
        vector<int > power;
        vector<int> ans;
        for(int i=0;n>0;i++){
            if(n&1){
                power.push_back(1<<i);
            }
            n>>=1;
        }
        for(auto &q:arr){
            int l= q[0];
            int r= q[1];
            long long p = 1;
            for(int i=l;i<=r;i++){
                p=(p*power[i])%MOD;
            }
            ans.push_back((int)p);
        }
        return ans;
    }
};