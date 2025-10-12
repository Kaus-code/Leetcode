class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n<=2) return n;
        
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int c = 0;
                for(int k = 0;k<n;k++){
                    if((arr[k][1]-arr[i][1])*(arr[j][0]-arr[i][0])==(arr[j][1]-arr[i][1])*(arr[k][0]-arr[i][0])){
                        c++;
                    }
                }
                ans = max(ans,c);
            }
        }
        return ans;
    }
};