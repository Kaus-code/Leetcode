class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;
        unordered_set<char> letters;
        for(int i =0;i<n;i++){
            letters.insert(s[i]);
        }
        for(char letter : letters){
            unordered_set<char> pals;
            int lm = -1;
            int rm = -1;
            for(int i =0;i<n;i++){
                if(s[i] == letter){
                    if(lm==-1)lm = i;
                    rm = i;
                }
            }
            for(int m =lm+1;m<rm;m++){
                pals.insert(s[m]);
            }
            result+=pals.size();
        }
        return result;
    }
};