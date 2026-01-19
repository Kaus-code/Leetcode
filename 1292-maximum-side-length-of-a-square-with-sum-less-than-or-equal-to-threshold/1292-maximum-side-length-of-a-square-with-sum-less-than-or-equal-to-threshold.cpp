class Solution {
public:
    bool check(int& mid,int& t,vector<vector<int>>& mat,vector<vector<int>>& pref){
        int m = mat.size();
        int n = mat[0].size();
        for (int i = mid; i <= m; i++) {
            for (int j = mid; j <= n; j++) {
                int currentSum = pref[i][j] - pref[i-mid][j] - pref[i][j-mid] + pref[i-mid][j-mid];
                if (currentSum <= t) {
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        int s = 0;
        int e = min(m,n);
         vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        while(s<=e){
            int mid = (s+e)/2;
            if(check(mid,threshold,mat,pref)){
                ans = mid;
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};