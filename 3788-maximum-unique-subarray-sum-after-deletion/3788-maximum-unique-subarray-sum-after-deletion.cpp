class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size( );
        int c=0;
        int sum2=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++ ){
            if( s.count( nums[i])){

            }
            else if(nums[i]>0){
                sum+=nums[i];
                s.insert( nums[i]);
            }
            else{
                c++;
                    sum2=max(nums[i],sum2 );
            }
        }
        return (c==n )?sum2:sum;
    }
};