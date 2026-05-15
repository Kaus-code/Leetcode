class Solution {
public:
    int ladderLength(string b, string e, vector<string>& dict) {
        int n = dict.size();
        queue<string> q;
        q.push(b);
        unordered_set<string> st;
        for(int i =0;i<dict.size();i++){
            st.insert(dict[i]);
        }
        int t = 1;
        bool check = false;
        while(!q.empty()){
            int lvl = q.size();
            for(int i = 0;i<lvl;i++){
                string temp = q.front();
                q.pop();
                if(temp == e){
                    return t;
                }
                for(int j = 0;j<temp.size();j++){
                    for(char ch = 'a';ch<='z';ch++){
                        string temp2 = temp;
                        temp2[j] = ch;
                        if(st.count(temp2)){
                            q.push(temp2);
                            st.erase(temp2);
                        }
                    }
                }
            }
            t++;
        }
        return (check)?t:0;
    }
};