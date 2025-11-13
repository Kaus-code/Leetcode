class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int c = 0;
        int zero = 0;
        int i =n-1;
        bool check = false;
        while(i>=0){
           if(s[i]=='0' && !check){
                i--;
                zero++;
                check = true;
           }
            else if(s[i]=='0' && check){
                i--;
            }
            else if(i>=0 && s[i]=='1'){
                check = false;
                c+=(zero);
                i--;
            }
        }
        return c;
    }
};