class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st; 
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int middleIndex = st.top();
                st.pop();
                if (st.empty()) break;
                int leftIndex = st.top();
                int boundedHeight = min(height[leftIndex], height[i]) - height[middleIndex];
                int width = i - leftIndex - 1;
                totalWater += boundedHeight * width;
            }
            st.push(i);
        }
        return totalWater;
    }
};