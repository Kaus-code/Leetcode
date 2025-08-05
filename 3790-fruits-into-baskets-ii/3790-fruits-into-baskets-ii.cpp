class Solution {
public:
    int numOfUnplacedFruits(vector<int>& arr, vector<int>& bas) {
        int n = arr.size();
        unordered_map<int,int> mp;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<bool> fruits(1001,false);
        int c =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i]<=bas[j] && !vis[j]){
                    if(c==n) return 0;
                    c++;
                    fruits[arr[i]] = true;
                    vis[j] = true;
                    break;
                    
                }
            }
        }
        return (n-c)<=0 ? 0:n-c;
    }
};