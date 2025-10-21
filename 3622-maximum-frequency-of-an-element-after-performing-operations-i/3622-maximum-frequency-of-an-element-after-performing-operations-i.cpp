class Solution {
public:
    int maxFrequency(vector<int>& arr, int k, int ops) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 1;
        map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        set<int> st;
        for(auto x:arr){
            st.insert(x);
            st.insert(x-k);
            st.insert(x+k);
        }
        for(auto x:st){
            int al = mp[x];
            auto lw = lower_bound(arr.begin(),arr.end(),x-k);
            auto up = upper_bound(arr.begin(),arr.end(),x+k);
            int r = up-lw;
            int can = r-al;
            ans = max(ans,al+min(ops,can));
        }
        return ans;
    }
};