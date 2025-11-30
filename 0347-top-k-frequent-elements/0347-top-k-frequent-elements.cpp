class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto [a,b]: mp){
            pq.push({b,a});
        }
        for(int i =0;i<k;i++){
            int temp = pq.top().second;
            pq.pop();
            res.push_back(temp);
        }
        return res;
    }
};