class Solution {
public:
    typedef long long ll;

    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> res(n,0);
        for(ll i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(!s.empty()) res[i] = s.top()-i;
            s.push(i);
        }
        return res;
    }
};