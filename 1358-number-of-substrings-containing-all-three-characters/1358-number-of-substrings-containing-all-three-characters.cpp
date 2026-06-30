class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l =0;
        int ans=0;
        int a=0,b=0,c=0;
        int i = 0;
        while(i<n){
           if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;
            while (a > 0 && b > 0 && c > 0) {
               
                ans += (n - i); 
                if (s[l] == 'a') a--;
                else if (s[l] == 'b') b--;
                else c--;
                l++;
            }
            i++;
        }
        return ans;
    }
};