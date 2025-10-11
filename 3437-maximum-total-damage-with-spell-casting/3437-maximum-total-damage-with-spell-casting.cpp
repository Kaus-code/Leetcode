class Solution {
public:
    typedef long long ll;
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<ll,ll> mp;
        for(int i =0;i<n;i++){
            mp[power[i]]++;
        }
        vector<ll> arr(mp.size());
        for(auto [a,b]:mp){
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        n = arr.size();
        vector<ll> t(n);
        ll res = INT_MIN;
        for(int i=n-1;i>=0;i--){
            ll skip = (i+1<n)?t[i+1]:0;
            int j = lower_bound(arr.begin() + i + 1, arr.end(), arr[i] + 3) - arr.begin();
            ll take = arr[i]*mp[arr[i]] + ((j<n) ? t[j]:0);
            t[i] = max(skip,take);
            res = max(res,t[i]);
        }
        return res;
    }
};