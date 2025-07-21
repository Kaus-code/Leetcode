class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        stack<int> st;
        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i] = (st.empty()) ? -1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop(); 
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i] = (st.empty()) ? n:st.top();
            st.push(i);
        }
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        int maxi = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxi = max(maxi,area);
        }
        return maxi;
    }
};