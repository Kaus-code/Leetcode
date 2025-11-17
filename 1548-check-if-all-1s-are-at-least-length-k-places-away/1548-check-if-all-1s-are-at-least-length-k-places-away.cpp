class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c = -1;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]==1){
                if(c==-1){
                    c = i;
                }
                else{
                    if(abs(i-c)<=k) return false;
                    c=i;
                }
            }
        }
        return true;
    }
};