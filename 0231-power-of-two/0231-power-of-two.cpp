class Solution {
public:
    bool isPowerOfTwo(int an) {
        double n = an;
        int c =0;
        if(n<0) return false;
        for(long long i=-1e9;i<1e9;i++){
            if(1==n ){
                return true;
            }

            if(n<1 && n>-1) return false;
            n/=2;
            c++;
        }
        return false;
    }
};