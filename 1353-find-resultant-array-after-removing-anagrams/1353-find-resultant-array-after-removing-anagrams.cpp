class Solution {
public:
    vector<string> removeAnagrams(vector<string>& arr) {
        int n = arr.size();
        vector<string> ans;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            string s = arr[i];
            sort(s.begin(), s.end());

            // move j forward while arr[j] is an anagram of arr[i]
            while (j < n) {
                string t = arr[j];
                sort(t.begin(), t.end());
                if (s == t) j++;
                else break;
            }

            // keep the first one in the group
            ans.push_back(arr[i]);
            i = j; // move to next distinct word group
        }

        return ans;
    }
};
