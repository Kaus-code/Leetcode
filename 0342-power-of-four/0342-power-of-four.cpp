class Solution {
public:
    bool isPowerOfFour(int n) {
        bool check = false;
        for(int i=0;i<21;i++){
            if(pow(4,i)==n) check = true;
        }
        return check;
    }
};