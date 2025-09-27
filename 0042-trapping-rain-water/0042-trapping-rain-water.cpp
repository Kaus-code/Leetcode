class Solution {
public:
    int trap(vector<int>& height) {
       
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                water_trapped += left_max - height[left];
                left++;
            } else {
                right_max = max(right_max, height[right]);
                water_trapped += right_max - height[right];
                right--;
            }
        }

        return water_trapped;
      
    }
};