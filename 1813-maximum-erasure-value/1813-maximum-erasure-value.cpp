class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int sum =0;
        int ans = 0;
        int l = 0;
        for(int i=0;i<n;i++){
            while(s.count(nums[i])){
                s.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            sum+=nums[i];
            s.insert(nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};