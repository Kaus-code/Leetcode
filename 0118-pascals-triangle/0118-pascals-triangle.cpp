class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr;
        vector<int> temp1;
        temp1.push_back(1);
        for(int i =0;i<n;i++){
            arr.push_back(temp1);
            vector<int> temp2;
            temp2.push_back(1);
            for(int i =1;i<temp1.size();i++){
                temp2.push_back(temp1[i]+temp1[i-1]);
            }
            temp2.push_back(1);
            temp1 = temp2;
        }
        return arr;
    }
};