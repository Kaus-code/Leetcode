class Solution {
public:
    long long solve(long long i,long long e){
        long long L =1;
        long long S = 1;
        long long steps = 0;
        while(L<=e){
            long long R = L*4-1;
            long long start = max(L,(i));
            long long end = min(R,(e));
            if(start<=end){
                steps += (end-start+1)*S;
            }
            S++;
            L=L*4;
        }
        return (steps+1)/2;
    }
    long long minOperations(vector<vector<int>>& arr) {
        long long res = 0;
        for(auto t:arr){
            long long s = t[0];
            long long e = t[1];
            long long steps = solve(s,e);
            res+=steps;
        }
        return res;
    }
};