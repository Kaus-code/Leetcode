class Solution {
public:
    int binary_str_int(string s, vector<int>& ans, int& i) {
        int decimalValue = 0;
        for (char c : s) {
            decimalValue = (decimalValue * 2 + (c - '0')) % 5;
        }

        ans[i] = decimalValue;

        return decimalValue;
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> a(n, false);
        vector<int> ans(n, 0);
        string s = "";
        for (int i = 0; i < nums.size(); i++) {

            s += (nums[i] + '0');

            binary_str_int(s, ans, i);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] % 5 == 0) {
                a[i] = true;
            } else {
                a[i] = false;
            }
        }

        return a;
    }
};