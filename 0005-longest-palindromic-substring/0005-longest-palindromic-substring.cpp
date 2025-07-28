class Solution {
public:
    void check(string s,int i,int e,int& str,int& end,int& maxi){
        while(i>=0 && e<=s.size() && s[i]==s[e]){
            if(e-i+1>maxi){
                maxi = e-i+1;
                str = i;
                end = e;
            }
            i--;
            e++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int str =-1,end=-1,maxi=0;
        for(int i=0;i<n;i++){
            check(s,i,i,str,end,maxi);
            check(s,i-1,i,str,end,maxi);
        }
        return (maxi==0) ? "": s.substr(str,end-str+1);
    }
};