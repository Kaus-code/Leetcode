class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int n=height.size();
        long long maxi = 0;
        int e =n-1;
        while(s<e){
            long long temp = (e-s)*(min(height[s],height[e]));
            maxi = max(maxi,temp);
            (height[s]>height[e]) ? e-- : s++;
        }
        return maxi;
    }
};