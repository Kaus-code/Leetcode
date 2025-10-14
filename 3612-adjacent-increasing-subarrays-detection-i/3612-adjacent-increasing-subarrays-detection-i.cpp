class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0;i<=n-(2*k);i++){
            bool check = true;
            for(int j = i+1;j<k+i;j++){
                if(nums[j]-nums[j-1]<=0){
                    check = false;
                }
            }
            for(int j = i+k+1;j<2*k+i;j++){
                if(nums[j]-nums[j-1]<=0){
                    check = false;
                }
            }
            if(check) return true;
        }
        return false;
    }
};