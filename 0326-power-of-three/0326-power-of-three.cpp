class Solution {
public:
    bool isPowerOfThree(int n) {
        long long pow = 1;
        for(int i=0;i<21;i++){
            if(pow==n){
                return true;
            }
            pow = pow*3;
        }
        return false;
    }
};