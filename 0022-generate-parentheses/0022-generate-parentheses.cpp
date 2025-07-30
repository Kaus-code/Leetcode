class Solution {
public:
typedef long long ll;
    void solve(int n,vector<string>& res,int oc,int i,string s,int cc){
        if(i>=2*n){
            res.push_back(s);
            return;
        }
        if(oc<n) solve(n,res,oc+1,i+1,s+'(',cc);
        if(cc<oc) solve(n,res,oc,i+1,s+')',cc+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int i=0;
        solve(n,res,0,i,"",0);
        return res;
    }
};