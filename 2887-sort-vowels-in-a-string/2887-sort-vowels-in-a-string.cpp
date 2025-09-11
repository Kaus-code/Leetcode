class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string temp = s;
        vector<int> ind;
        vector<char> up;
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(st.count(ch)){
                up.push_back(ch);
                ind.push_back(i);
            }
        }
        sort(up.begin(),up.end());
        for(int i=0;i<up.size();i++){
            temp[ind[i]]=up[i];
        }
        return temp;
    }
};