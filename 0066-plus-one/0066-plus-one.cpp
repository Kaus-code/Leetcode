class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool check = true;
        int n = digits.size();
        for(int i = n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i] = 0;
            }
            else{
                digits[i]++;
                check = false;
                break;
            }
        }
        if(check){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};