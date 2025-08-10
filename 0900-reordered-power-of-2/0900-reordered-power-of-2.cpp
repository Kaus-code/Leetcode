class Solution {
public:
    string solve(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string op = solve(n);
        for(int i=0;i<=29;i++){
            if(solve(1<<i) == op){
                return true;
            }
        }
        return false;
    }
};