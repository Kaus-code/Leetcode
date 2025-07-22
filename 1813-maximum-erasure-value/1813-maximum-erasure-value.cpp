class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0;
        int sum=0;
        int ans=0;
        int n=nums.size();
        unordered_set<int> s;

        for(int right=0;right<=n-1;right++)
        {
            while(s.count(nums[right]))
            {
                s.erase(nums[left]);
                sum-=nums[left];
                left++;

            }
            s.insert(nums[right]);
            sum+=nums[right];
            ans=max(ans,sum);
        }

        return ans;
    }
};