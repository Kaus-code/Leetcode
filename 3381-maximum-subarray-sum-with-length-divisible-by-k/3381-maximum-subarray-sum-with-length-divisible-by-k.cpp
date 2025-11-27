class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> Sum_k(k, LONG_LONG_MAX / 2);
        Sum_k[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - Sum_k[i % k]);
            Sum_k[i % k] = min(Sum_k[i % k], prefixSum);
        }
        return maxSum;
    }
};