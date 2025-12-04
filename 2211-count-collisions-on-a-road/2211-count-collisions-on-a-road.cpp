class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int c = 0;
        bool stat = false;
        stack<int> st;
        for(int i =0;i<n;i++){
            if(s[i]=='R'){
                st.push('R');
            }
            else if(s[i]=='S'){
                while(!st.empty()){
                    st.pop();
                    c++;
                }
                stat = true;
            }
            else{
                if(!st.empty()){
                    st.pop();
                    c+=2;
                    stat = true;
                }
                else if(stat){
                    c++;
                }
                while(!st.empty()){
                    c++;
                    st.pop();
                }
            }
        }
        return c;
    }
};