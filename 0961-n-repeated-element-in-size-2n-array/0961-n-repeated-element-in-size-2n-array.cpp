class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int pivot = n/2;
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto [a,b]:mp){
            if(b==pivot){
                return a;
            }
        }
        return 0;
    }
};