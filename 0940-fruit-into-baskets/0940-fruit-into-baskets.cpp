class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        int  s = 0;
        int  ans = -1;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>2){
                mp[arr[s]]--;
                if(mp[arr[s]]==0){
                    mp.erase(arr[s]);
                }
                s++;
            } 
            ans = max(ans,i-s+1);
        }
        return ans;
    }
};