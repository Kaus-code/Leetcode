class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(s.empty()==false && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()==false) pse[i]=s.top();
            s.push(i);
        }
        while(s.empty()==false) s.pop();
        for(int i=n-1;i>=0;i--){
            while(s.empty()==false && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()==false) nse[i]=s.top();
            s.push(i);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            int area = nse[i]-pse[i]-1;
            maxi = max(maxi,area*arr[i]);
        }
        return maxi;
    }
};