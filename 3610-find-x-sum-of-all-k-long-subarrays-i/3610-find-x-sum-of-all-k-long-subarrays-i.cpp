class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            priority_queue<pair<int, int>> pq;
            for (auto& t : mp) {
                pq.push({t.second, t.first});
            }
            int x_sum = 0;
            for (int j = 0; j < x && !pq.empty(); j++) {
                auto top = pq.top();
                pq.pop();
                x_sum += top.first * top.second; // freq * value
            }
            ans.push_back(x_sum);
        }
        return ans;
    }
};