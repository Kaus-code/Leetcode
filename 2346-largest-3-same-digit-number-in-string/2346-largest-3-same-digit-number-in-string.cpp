class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        int maxi = -1;
        int n = num.size();
        for(int i=1;i<n-1;i++){
            if(num[i]==num[i-1] && num[i]==num[i+1]){
                maxi = max(maxi,num[i]-'0');
            }
        }
        char i = maxi+'0';
        s+=i;
        s+=i;
        s+=i;
        return (maxi==-1)? "":s;
    }
};