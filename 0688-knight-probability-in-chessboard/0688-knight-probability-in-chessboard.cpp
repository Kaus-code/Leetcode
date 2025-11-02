class Solution {
public:
    unordered_map<string,double> mp;
    int n;
    vector<pair<int,int>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
    double solve(int r,int c,int k){
        if(r>=n ||r<0||c>=n||c<0){
            return 0;
        }
        if(k==0){
            return 1;
        }
        string check = to_string(k)+"_"+to_string(r)+"_"+to_string(c);
        if(mp.find(check)!=mp.end()){
            return mp[check];
        }
        double ans =0;
        for(auto [a,b]:dir){
            ans+=(double)solve(r+a,c+b,k-1);
        }
        return mp[check]=(double)ans/8.0;
    }
    double knightProbability(int N, int k, int row, int column) {
        n=N;
        return solve(row,column,k);
    }
};