class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> arr = nums2;
        stack<int> st;
        unordered_map<int,int> nlp;
        for(int i = m-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()) nlp[arr[i]] = st.top();
            else nlp[arr[i]] = -1;
            st.push(arr[i]);
        }
        vector<int> ans;
        for(int i =0;i<n;i++){
            ans.push_back(nlp[nums1[i]]);
        }
        return ans;
    }
};