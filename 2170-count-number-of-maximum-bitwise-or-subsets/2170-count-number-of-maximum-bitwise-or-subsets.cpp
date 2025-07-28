class Solution {
public:
    void solve(vector<int>& arr,int n,unordered_map<int,int>& mp,int i,int oor){
        if(i==n){
            mp[oor]++;
            return;
        }
        solve(arr,n,mp,i+1,oor | arr[i]);
        solve(arr,n,mp,i+1,oor);

    }
    int countMaxOrSubsets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int i=0;
        solve(arr,n,mp,i,0);
        int ans = 0;
        int maxi = 0;
        for(auto [a,b]:mp){
            if(maxi<a){
                maxi = a;
                ans = b;    
            }
        }
        return ans;
    }
};