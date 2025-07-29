class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        vector<int> last(32, -1); // last seen index for each bit

        for (int i = n - 1; i >= 0; i--) {
            // update last seen indices for bits set in nums[i]
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }

            int best = 1;
            for (int b = 0; b < 32; b++) {
                if (last[b] != -1) {
                    best = max(best, last[b] - i + 1);
                }
            }
            res[i] = best;
        }
        return res;
    }
};
