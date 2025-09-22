class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mp(101,0);
        for(auto num:nums){
            mp[num]++;
        }
        int maxf = 0;
        for(int i =0;i<101;i++){
            maxf = max(mp[i],maxf);
        }
        int sum = 0;
        for(int i =0;i<101;i++){
            if(mp[i]==maxf){
                sum+=maxf;
            }
        }
        return sum;
    }
};