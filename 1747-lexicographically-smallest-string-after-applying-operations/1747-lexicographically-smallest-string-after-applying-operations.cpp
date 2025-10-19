class Solution {
public:
    string add(string s,int a){
        for(int i =1;i<s.size();i+=2){
            s[i] = ((s[i]-'0')+a)%10+'0';
        }
        return s;
    }
    string rot(string s,int b){
        int n = s.size();
        return s.substr(n-b)+s.substr(0,n-b);
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string small = s;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            if(temp<small){
                small = temp;
            }
            string added = add(temp,a);
            if(vis.find(added)==vis.end()){
                vis.insert(added);
                q.push(added);
            }
            added = rot(temp,b);
            if(vis.find(added)==vis.end()){
                vis.insert(added);
                q.push(added);
            }
        }
        return small;
    }
};