class Solution {
public:
    int maxArea(vector<int>& arr) {
      int n = arr.size();
      int s = 0;
      int e = n-1;
      int ans = 0;
      while(s<=e){
        long long temp = (e-s)*min(arr[s],arr[e]);
        ans = max((int)temp,ans);
        (arr[s]<arr[e]) ? s++:e--;
      }
      return ans;
    }
};