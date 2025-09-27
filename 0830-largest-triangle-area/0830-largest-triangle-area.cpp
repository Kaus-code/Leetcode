class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& arr) {
        double ans=0;
        int n = arr.size();
        for(int i =0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    double x1 = arr[i][0];
                    double y1 = arr[i][1];
                    double x2 = arr[j][0];
                    double y2 = arr[j][1];
                    double x3 = arr[k][0];
                    double y3 = arr[k][1];
                    double area = abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};