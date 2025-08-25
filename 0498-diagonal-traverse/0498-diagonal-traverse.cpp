class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int temp =0;
        vector<int> ans;
        for(int i =0;i<n;i++){
            vector<int> temparr;
            for(int j=0;j<m;j++){
                if(j>temp) break;
                else{
                    temparr.push_back(arr[j][temp-j]);
                }
            }
            temp++;
            int sz = temparr.size();
            if(i%2==0){
                for(int i=sz-1;i>=0;i--){
                    ans.push_back(temparr[i]);
                }
            }
            if(i%2!=0){
                for(int i=0;i<sz;i++){
                    ans.push_back(temparr[i]);
                }
            }
        }
        temp=n;

        for(int i =1;i<m;i++){
            vector<int> temparr;
            for(int j=i;j<m;j++){
                if (n - 1 - (j - i) < 0) break;
                else{
                    temparr.push_back(arr[j][n-1-(j-i)]);
                }
            }
            temp--;
            int sz = temparr.size();
              if ((i + n - 1) % 2 == 0) {
                for (int k = sz - 1; k >= 0; k--) {
                    ans.push_back(temparr[k]);
                }
            } else {
                for (int k = 0; k < sz; k++) {
                    ans.push_back(temparr[k]);
                }
            }
        }
        return ans;
    }
};