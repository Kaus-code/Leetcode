class Solution {
public:
    int canBeTypedWords(string t, string b) {
        unordered_set<char> st(b.begin(),b.end());
        bool check = true;
        int c = 0;
        for(int i =0;i<t.size();i++){
            if(t[i]==' '){
                if(check)c++;
                check = true;
            }
            else{
                if(st.count(t[i])){
                    check = false;
                }
            }
        }
        if(check)c++;
        return c;
    }
};