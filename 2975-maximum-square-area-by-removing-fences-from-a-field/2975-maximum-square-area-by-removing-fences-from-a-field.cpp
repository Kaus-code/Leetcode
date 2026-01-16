class Solution {
public:
    const int MOD = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_set<int> hset;
        unordered_set<int> vset;

        for(int i =0;i<h.size();i++){
            for(int j = i+1;j<h.size();j++){
                hset.insert(h[j]-h[i]);
            }
        }
        int maxi = 0;
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                int w = v[j]-v[i];
                if(hset.count(w)){
                    maxi = max(maxi,w);
                }
            }
        }
        if(maxi==0) return -1;
        return (long long)maxi*maxi%MOD;
    }
};