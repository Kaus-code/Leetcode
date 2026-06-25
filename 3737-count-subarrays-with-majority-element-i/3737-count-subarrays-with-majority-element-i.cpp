class Solution {
public:
    int countMajoritySubarrays(vector<int>& arr, int target) {
        int c = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j = i;j<n;j++){
                mp[arr[j]]++;
                if(mp.count(target) && mp[target]>(j-i+1)/2) c++;
            }
        }
        return c;
    }

};