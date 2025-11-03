class Solution {
public:
    int minCost(string s, vector<int>& need) {
        int ans = 0;
        int n = s.size();
        int i =0;
        while(i<n){
            int j = i+1;
            while(s[i]==s[j]){
                if(need[i]<need[j]){
                    ans+=need[i];
                    i=j;
                    j++;
                }
                else{
                    ans+=need[j];
                    j++;
                }
            }
            i=j;
            j=j+1;
        }
        return ans;
    }
};