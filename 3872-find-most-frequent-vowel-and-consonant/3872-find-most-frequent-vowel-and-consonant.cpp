class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> alpha(26,0);
        for(int i =0;i<s.size();i++){
            alpha[s[i]-'a']++;
        }
        int b = 0;
        int a =max({alpha[0],alpha[4],alpha[8],alpha[14],alpha[20]});
        for(int i =0;i<26;i++){
            if(i!=0 && i!=4 && i!= 8 && i!=14 && i!=20){
                b = max(b,alpha[i]);
            }
        }
        return a+b;
    }
};