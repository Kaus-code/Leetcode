class Solution {
public:
    // Precompute lengths of strictly increasing segments starting at each index
    vector<int> computeIncreasingLengths(const vector<int>& nums) {
        int n = nums.size();
        vector<int> incLen(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                incLen[i] = incLen[i + 1] + 1;
            }
        }
        return incLen;
    }

    // Check if there exist two consecutive strictly increasing subarrays of length k
    bool solve(const vector<int>& incLen, int k) {
        int n = incLen.size();
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (incLen[i] >= k && incLen[i + k] >= k) {
                return true;
            }
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> incLen = computeIncreasingLengths(nums);

        int s = 1, e = n / 2, ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (solve(incLen, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};
