class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans;
        int i=0;
        while(i<n){
        char c = s[i];
            int j =i+1;
            while(j<n && s[j]==c){
                j++;
            }
            if(j-i>=2){
                ans+=c;
                ans+=c;
            }
            if(j-i==1){
                ans+=c;
            }
            
           i=j;
        }
        return ans;
    }
};