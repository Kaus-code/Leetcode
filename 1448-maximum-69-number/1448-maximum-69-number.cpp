class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        string ans ="";
        bool check = true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
            
        }
        int nums = 0;
        for(int i=0;i<s.size();i++){
            int temp = s[i]-'0';
            nums = nums * 10 + temp; 
        }
        return nums;
    }
};