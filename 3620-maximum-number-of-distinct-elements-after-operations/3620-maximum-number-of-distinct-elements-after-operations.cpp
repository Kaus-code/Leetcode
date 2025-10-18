class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini = INT_MIN;
        int n = nums.size();
        int c = 0;
        for(int i =0;i<n;i++){
            int value = max(mini+1,nums[i]-k);
            if(value<=(nums[i]+k)){
                c++;
                mini = value;
            }
        }
        return c;
    }
};