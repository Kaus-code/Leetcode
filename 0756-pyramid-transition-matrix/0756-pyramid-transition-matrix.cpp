class Solution {
public:
    unordered_map<string,vector<char>> mp;
    void solve(int i,int n,string temp,bool &ans,vector<string>& al,string s){
        if(ans){
            return;
        }
        if(n-1==0){
            ans = true;
            return;
        }
        if(i==n-1){
            solve(0,n-1,"",ans,al,temp);
            return;
        }
        string a ="";
        a+= s[i];
        a+= s[i+1];
        for(auto c:mp[a]){
            temp.push_back(c);
            solve(i+1,n,temp,ans,al,s);
            temp.pop_back();
        }
    }
    bool pyramidTransition(string s, vector<string>& a) {
        int n = s.size();
        string temp = "";
        bool ans = false;
        for(auto s:a){
            string temp = "";
            temp+=s[0];
            temp+=s[1];
            mp[temp].push_back(s[2]);
        }
        solve(0,n,temp,ans,a,s);
        return ans;
    }
};