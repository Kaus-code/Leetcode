class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int>> pq;
        for(int  i=0;i<n;i++){
            pq.push({arr[i],i+1});
        }
        vector<string> ans(n);
        int temp = 1;
        while(!pq.empty()){
            auto [a,b] = pq.top();
            pq.pop();
            if(temp==1){
                ans[b-1] = "Gold Medal"; 
                temp++;
            }
            else if(temp==2){
                ans[b-1] = "Silver Medal"; 
                temp++;
            }
            else if(temp==3){
                ans[b-1] = "Bronze Medal"; 
                temp++;
            }
            else{
                ans[b-1] = to_string(temp);
                temp++; 
            }
        }
        return ans;
    }
};