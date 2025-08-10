class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> st;
        do{
            st.push_back(arr);
        }while(next_permutation(arr.begin(),arr.end()));
        return st;
    }
};