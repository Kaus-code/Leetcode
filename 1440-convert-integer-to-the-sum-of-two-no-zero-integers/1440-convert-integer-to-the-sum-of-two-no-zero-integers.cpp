class Solution {
public:
    bool countz(int n){
        string s = to_string(n);
        for(char a:s){
            if(a=='0'){
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(countz(i)&& countz(n-i)){
                return {i,n-i};
            }
        }
        return {0,0};
    }
};