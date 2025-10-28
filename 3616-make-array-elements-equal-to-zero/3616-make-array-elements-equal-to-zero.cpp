class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> zeroindex;
        vector<int> directions = {-1, 1};
        int ans = 0;

       
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeroindex.push_back(i);
        }

  
        for (int i = 0; i < zeroindex.size(); i++) {
            for (int dIndex = 0; dIndex < 2; dIndex++) {
                int dir = directions[dIndex];
                vector<int> arr = nums;
                int remaining = 0;

               
                for (int val : arr)
                    if (val > 0)
                        remaining++;

                int curr = zeroindex[i];
                int step = dir;

                while (curr >= 0 && curr < n) {
                    if (arr[curr] == 0) {
                        curr += step;
                    } else {
                        arr[curr]--;
                        if (arr[curr] == 0)
                            remaining--;
                        step = -step; 
                        curr += step;
                    }
                }

                if (remaining == 0)
                    ans++;
            }
        }

        return ans;
    }
};
