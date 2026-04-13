class Solution {
public:
    void backtrack(vector<vector<int>>& res,vector<int>& arr,vector<int> temp,int k,int i,int sum){
        if(i==arr.size() || sum>k){
            return;
        }
        if(sum==k){
            res.push_back(temp);
            return;
        }
        backtrack(res,arr,temp,k,i+1,sum);
        temp.push_back(arr[i]);
        backtrack(res,arr,temp,k,i,sum+arr[i]);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res,arr,temp,k,0,0);
        return res;
    }
};